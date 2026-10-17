package com.teff.puzzles.muddle;

import android.app.AlertDialog;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.RectF;
import android.os.Handler;
import android.os.Looper;
import android.os.SystemClock;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.ControlPad;
import com.teff.puzzles.common.GameAudio;

import java.io.IOException;
import java.io.InputStream;

/** Muddled Casino game view, 628×404 table + button bar scaled to fit the screen. */
final class MuddleGameView extends View implements Game.Listener, ControlPad.Listener {

    // Logical dimensions: table background + bottom button strip
    private static final int W = 628, H = 470;
    private static final int TABLE_H = 404;
    private static final int BAR_Y = TABLE_H + 4, BAR_H = 52;

    // Board cell geometry (from decompile: col*35+44, row 0 at bottom)
    private static final int CELL = 35;
    private static final int BX = 44;   // board x origin
    private static final int BY = 44;   // board y origin (row 9 at top)

    // Feature sprite frame width (featurespr 104px / 4 frames = 26px each)
    private static final int FEAT_FW = 26, FEAT_FH = 35;

    // Button strip layout
    private static final RectF BTN_NEW   = new RectF(4,   BAR_Y, 120, BAR_Y + BAR_H - 2);
    private static final RectF BTN_RESET = new RectF(124, BAR_Y, 240, BAR_Y + BAR_H - 2);
    private static final RectF BTN_BET1  = new RectF(260, BAR_Y, 310, BAR_Y + BAR_H - 2);
    private static final RectF BTN_BET2  = new RectF(314, BAR_Y, 364, BAR_Y + BAR_H - 2);
    private static final RectF BTN_BET3  = new RectF(368, BAR_Y, 418, BAR_Y + BAR_H - 2);
    private static final RectF BTN_BET4  = new RectF(422, BAR_Y, 472, BAR_Y + BAR_H - 2);
    private static final RectF BTN_EXIT  = new RectF(500, BAR_Y, 624, BAR_Y + BAR_H - 2);

    private static final long TICK_MS = 50;
    private static final float KEY = 60;   // control-pad key size

    // Scale / offset for letterbox
    private float scale = 1f, ox, oy;

    private final Game game = new Game();
    private final GameAudio audio;
    private final ControlPad pad;

    // Bitmaps
    private Bitmap bmpTable, bmpTitle, bmpGameOver;
    private Bitmap bmpRound, bmpSquare, bmpBRound, bmpBSquare;
    private Bitmap bmpFeature;

    // Card side sprites: s_h_0000-0007 (48x25)
    private final Bitmap[] cardH = new Bitmap[8];

    private final Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint textPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Rect srcRect = new Rect();
    private final RectF dstRect = new RectF();

    // Tick loop
    private final Handler handler = new Handler(Looper.getMainLooper());
    private long lastTime;
    private long debt;
    private boolean running;

    private final Runnable loop = new Runnable() {
        @Override
        public void run() {
            if (!running) return;
            long now = SystemClock.uptimeMillis();
            debt += now - lastTime;
            lastTime = now;
            while (debt >= TICK_MS) {
                debt -= TICK_MS;
                game.tick();
            }
            invalidate();
            handler.postDelayed(this, TICK_MS / 2);
        }
    };

    MuddleGameView(Context ctx) {
        super(ctx);
        setFocusable(true);
        audio = new GameAudio(ctx, "muddle");
        pad = new ControlPad(this);

        game.listener = this;
        game.levels = name -> {
            try (InputStream is = ctx.getAssets().open("muddle/lev/" + name + ".bin")) {
                byte[] buf = new byte[is.available()];
                is.read(buf);
                return buf;
            } catch (IOException e) {
                return null;
            }
        };

        loadBitmaps(ctx);

        textPaint.setColor(Color.WHITE);
        textPaint.setTextSize(18);
        textPaint.setTextAlign(Paint.Align.CENTER);
    }

    private void loadBitmaps(Context ctx) {
        bmpTable    = loadImg(ctx, "tablebmp");
        bmpTitle    = loadImg(ctx, "titlebmp");
        bmpGameOver = loadImg(ctx, "gameoverbmp");
        bmpRound    = loadImg(ctx, "roundcardspr");
        bmpSquare   = loadImg(ctx, "squarecardspr");
        bmpBRound   = loadImg(ctx, "broundcardspr");
        bmpBSquare  = loadImg(ctx, "bsquarecardspr");
        bmpFeature  = loadImg(ctx, "featurespr");
        for (int i = 0; i < 8; i++) {
            cardH[i] = loadImg(ctx, String.format("s_h_%04d", i));
        }
    }

    private Bitmap loadImg(Context ctx, String name) {
        try (InputStream is = ctx.getAssets().open("muddle/img/" + name + ".png")) {
            return BitmapFactory.decodeStream(is);
        } catch (IOException e) {
            return null;
        }
    }

    // ---- layout ----

    @Override
    protected void onSizeChanged(int w, int h, int oldW, int oldH) {
        scale = Math.min(w / (float) W, h / (float) H);
        ox = (w - W * scale) / 2f;
        oy = (h - H * scale) / 2f;

        // Control pad: arrow cluster at bottom-left, SPACE + TAB buttons nearby
        float padX = 2, padY = H - 3 * KEY - 2;
        pad.addArrows(padX, padY, KEY, true);
        pad.add(ControlPad.SPACE, padX + 3 * KEY + 4, padY + KEY, KEY * 1.5f, KEY, "Move");
        pad.add(ControlPad.TAB,   padX + 3 * KEY + 4, padY, KEY * 1.5f, KEY, "Knock");
    }

    // ---- drawing ----

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(Color.BLACK);
        canvas.save();
        canvas.translate(ox, oy);
        canvas.scale(scale, scale);

        if (game.state == Game.State.TITLE && bmpTitle != null) {
            canvas.drawBitmap(bmpTitle, 0, 0, paint);
        } else if (game.state == Game.State.OVER && bmpGameOver != null) {
            canvas.drawBitmap(bmpGameOver, 0, 0, paint);
        } else {
            drawTable(canvas);
        }
        drawButtonBar(canvas);
        pad.draw(canvas);
        canvas.restore();
    }

    private void drawTable(Canvas canvas) {
        if (bmpTable != null) canvas.drawBitmap(bmpTable, 0, 0, paint);

        // Board cells: row 0 is bottom, row 9 is top
        for (int r = 0; r < Game.ROWS; r++) {
            int vy = BY + (Game.ROWS - 1 - r) * CELL;
            for (int c = 0; c < Game.COLS; c++) {
                int vx = BX + c * CELL;
                int v = game.board[r][c];
                if (v == Game.EMPTY) continue;
                if (Game.isCard(v)) {
                    drawCard(canvas, v, game.moveFrame(r, c), vx, vy);
                } else if (v >= Game.JOKER && v <= Game.DICE) {
                    drawFeature(canvas, v, vx, vy);
                }
            }
        }

        drawOrderStrip(canvas);
        drawHud(canvas);
    }

    private void drawCard(Canvas canvas, int v, int moveFrame, int vx, int vy) {
        int cardIdx = v - 1;  // 0-7
        boolean round = (v <= 4);
        Bitmap sh = cardH[cardIdx];
        if (sh != null) {
            // s_h sprites are 48×25; draw into the CELL×CELL area
            dstRect.set(vx, vy + 5, vx + CELL, vy + CELL);
            if (moveFrame > 0) {
                paint.setColorFilter(new android.graphics.ColorMatrixColorFilter(
                        highlightMatrix(moveFrame)));
            }
            canvas.drawBitmap(sh, null, dstRect, paint);
            paint.setColorFilter(null);
        } else {
            // Fallback: colored rect
            int[] CARD_COLORS = {
                Color.rgb(255, 240, 200), Color.rgb(200, 120, 80),
                Color.rgb(80, 160, 255), Color.rgb(160, 80, 200),
                Color.rgb(100, 200, 100), Color.rgb(255, 200, 60),
                Color.rgb(255, 80, 80), Color.rgb(180, 180, 180)
            };
            paint.setColor(CARD_COLORS[cardIdx]);
            paint.setStyle(Paint.Style.FILL);
            canvas.drawRect(vx, vy, vx + CELL, vy + CELL, paint);
            paint.setColor(Color.BLACK);
            paint.setStyle(Paint.Style.STROKE);
            paint.setStrokeWidth(1f);
            canvas.drawRect(vx, vy, vx + CELL, vy + CELL, paint);
            textPaint.setTextSize(14);
            textPaint.setColor(Color.BLACK);
            textPaint.setTextAlign(Paint.Align.CENTER);
            canvas.drawText(String.valueOf(v), vx + CELL / 2f, vy + CELL / 2f + 5, textPaint);
            textPaint.setColor(Color.WHITE);
            textPaint.setTextAlign(Paint.Align.CENTER);
        }
    }

    private static float[] highlightMatrix(int frame) {
        // Simple tint matrix based on group frame (1-4)
        float r = frame == 1 || frame == 4 ? 1.4f : 1f;
        float g = frame == 2 || frame == 3 ? 1.4f : 1f;
        float b = frame == 1 || frame == 2 ? 1.4f : 1f;
        return new float[]{
                r,0,0,0,0,  0,g,0,0,0,  0,0,b,0,0,  0,0,0,1,0
        };
    }

    private void drawFeature(Canvas canvas, int v, int vx, int vy) {
        int fi = v - Game.JOKER;  // JOKER=0, HOLE=1, BUMPER=2, DICE=3
        if (bmpFeature != null) {
            srcRect.set(fi * FEAT_FW, 0, fi * FEAT_FW + FEAT_FW, FEAT_FH);
            dstRect.set(vx, vy, vx + CELL, vy + CELL);
            canvas.drawBitmap(bmpFeature, srcRect, dstRect, paint);
        } else {
            int[] FEAT_COLORS = {Color.YELLOW, Color.BLACK, Color.RED, Color.GREEN};
            paint.setColor(FEAT_COLORS[fi]);
            paint.setStyle(Paint.Style.FILL);
            canvas.drawRect(vx, vy, vx + CELL, vy + CELL, paint);
        }
    }

    private void drawOrderStrip(Canvas canvas) {
        // Order indicator strip: cards yet to exit, shown at right side of table
        int stripX = BX + Game.COLS * CELL + 4;
        int stripY = BY;
        for (int i = 0; i < Game.CARDS; i++) {
            int v = game.order[i];
            if (v == 0) break;
            int cardIdx = v - 1;
            boolean blink = (i == 0 && game.blinkBold());
            Bitmap sh = cardH[cardIdx];
            int cy = stripY + i * 26;
            if (sh != null) {
                paint.setAlpha(blink ? 255 : 160);
                dstRect.set(stripX, cy, stripX + 46, cy + 22);
                canvas.drawBitmap(sh, null, dstRect, paint);
                paint.setAlpha(255);
            } else {
                paint.setColor(blink ? Color.YELLOW : Color.WHITE);
                paint.setStyle(Paint.Style.FILL);
                canvas.drawRect(stripX, cy, stripX + 20, cy + 20, paint);
                textPaint.setTextSize(12);
                textPaint.setColor(Color.BLACK);
                canvas.drawText(String.valueOf(v), stripX + 10, cy + 14, textPaint);
                textPaint.setColor(Color.WHITE);
            }
        }
    }

    private void drawHud(Canvas canvas) {
        paint.setColor(Color.WHITE);
        paint.setStyle(Paint.Style.FILL);
        paint.setTextSize(16);
        paint.setTextAlign(Paint.Align.LEFT);
        canvas.drawText("Score: " + game.score, 44, 395, paint);
        canvas.drawText("P:" + game.playerCoins + " C:" + game.casinoCoins, 200, 395, paint);
        if (game.betting) {
            canvas.drawText("BET " + Game.DENOM[game.bet], 360, 395, paint);
        }
        canvas.drawText("Lv " + game.level, 500, 395, paint);
    }

    private void drawButtonBar(Canvas canvas) {
        paint.setColor(Color.rgb(30, 30, 60));
        paint.setStyle(Paint.Style.FILL);
        canvas.drawRect(0, BAR_Y - 4, W, TABLE_H + BAR_H + 8, paint);

        drawBtn(canvas, BTN_NEW,   "New");
        drawBtn(canvas, BTN_RESET, "Reset");
        drawBtn(canvas, BTN_BET1,  "1¢");
        drawBtn(canvas, BTN_BET2,  "5¢");
        drawBtn(canvas, BTN_BET3,  "10¢");
        drawBtn(canvas, BTN_BET4,  "25¢");
        drawBtn(canvas, BTN_EXIT,  "Exit");
    }

    private void drawBtn(Canvas canvas, RectF r, String label) {
        paint.setColor(Color.rgb(60, 60, 100));
        paint.setStyle(Paint.Style.FILL);
        canvas.drawRoundRect(r, 6, 6, paint);
        paint.setColor(Color.rgb(120, 120, 180));
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(1.5f);
        canvas.drawRoundRect(r, 6, 6, paint);
        textPaint.setTextSize(15);
        textPaint.setColor(Color.WHITE);
        textPaint.setTextAlign(Paint.Align.CENTER);
        canvas.drawText(label, r.centerX(), r.centerY() + 6, textPaint);
    }

    // ---- touch ----

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        if (pad.onTouch(e, ox, oy, scale)) {
            invalidate();
            return true;
        }

        float lx = (e.getX() - ox) / scale;
        float ly = (e.getY() - oy) / scale;

        if (e.getActionMasked() == MotionEvent.ACTION_DOWN) {
            if (game.state == Game.State.TITLE || game.state == Game.State.OVER) {
                game.newGame();
                invalidate();
                return true;
            }
            if (BTN_EXIT.contains(lx, ly)) {
                ((MuddleActivity) getContext()).exitToMenu();
                return true;
            }
            if (BTN_NEW.contains(lx, ly)) {
                confirmNewGame();
                return true;
            }
            if (BTN_RESET.contains(lx, ly)) {
                game.restartLevel();
                invalidate();
                return true;
            }
            if (BTN_BET1.contains(lx, ly)) { game.chooseBet(1); invalidate(); return true; }
            if (BTN_BET2.contains(lx, ly)) { game.chooseBet(2); invalidate(); return true; }
            if (BTN_BET3.contains(lx, ly)) { game.chooseBet(3); invalidate(); return true; }
            if (BTN_BET4.contains(lx, ly)) { game.chooseBet(4); invalidate(); return true; }
        }
        return true;
    }

    private void confirmNewGame() {
        new AlertDialog.Builder(getContext())
                .setTitle("New Game?")
                .setMessage("Start a new game?")
                .setPositiveButton("Yes", (d, w) -> { game.newGame(); invalidate(); })
                .setNegativeButton("No", null)
                .show();
    }

    // ---- ControlPad.Listener ----

    @Override
    public void keyDown(int keyCode) {
        switch (keyCode) {
            case ControlPad.LEFT:  game.arrow(Game.SIDE_LEFT);  break;
            case ControlPad.RIGHT: game.arrow(Game.SIDE_RIGHT); break;
            case ControlPad.UP:    game.arrow(Game.SIDE_UP);    break;
            case ControlPad.DOWN:  game.arrow(Game.SIDE_DOWN);  break;
            case ControlPad.SPACE: game.move(false); break;
            case ControlPad.TAB:   game.move(true);  break;
        }
    }

    @Override
    public void keyUp(int keyCode) { /* nothing for Muddle */ }

    // ---- hardware keyboard ----

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (event.getRepeatCount() == 0) keyDown(keyCode);
        return true;
    }

    // ---- Game.Listener ----

    @Override
    public void sound(String name) {
        audio.playSound(name);
    }

    @Override
    public void tip(int kind) { /* tips shown in HUD area */ }

    @Override
    public void gameOver(int score) {
        post(() -> new AlertDialog.Builder(getContext())
                .setTitle("Game Over")
                .setMessage("Final score: " + score)
                .setPositiveButton("New Game", (d, w) -> game.newGame())
                .setNegativeButton("Exit", (d, w) -> ((MuddleActivity) getContext()).exitToMenu())
                .show());
    }

    // ---- lifecycle ----

    void onHostResume() {
        lastTime = SystemClock.uptimeMillis();
        debt = 0;
        running = true;
        if (game.state == Game.State.TITLE) {
            game.newGame();
        }
        handler.post(loop);
    }

    void onHostPause() {
        running = false;
        handler.removeCallbacks(loop);
        pad.releaseAll();
        audio.pause();
    }

    void release() {
        running = false;
        handler.removeCallbacks(loop);
        audio.release();
        recycleBitmaps();
    }

    private void recycleBitmaps() {
        Bitmap[] all = {bmpTable, bmpTitle, bmpGameOver, bmpRound, bmpSquare,
                bmpBRound, bmpBSquare, bmpFeature};
        for (Bitmap b : all) { if (b != null) b.recycle(); }
        for (int i = 0; i < 8; i++) {
            if (cardH[i] != null) cardH[i].recycle();
        }
    }
}
