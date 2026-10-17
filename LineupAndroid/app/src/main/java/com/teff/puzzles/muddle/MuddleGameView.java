package com.teff.puzzles.muddle;

import android.app.AlertDialog;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.os.Handler;
import android.os.Looper;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.ControlPad;
import com.teff.puzzles.common.GameAudio;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;

/**
 * Muddled Casino game view.  640×430 logical canvas, 40×32 cells for the 14×10 board.
 * Arrow keys select a group direction; SPACE moves, TAB knocks off.
 */
final class MuddleGameView extends View implements Game.Listener, Game.LevelSource {

    private static final int W = 640, H = 430;
    private static final int BAR_Y = 400, BAR_H = 30;
    private static final int TICK_MS = 50;

    // Board layout
    private static final int CELL_W = 40, CELL_H = 30;
    private static final int BOARD_OX = 20, BOARD_OY = 52;

    // Card face labels and colors
    private static final String[] CARD_LABEL = {"","♠","♣","♦","♥","■","▪","◆","●"};
    private static final int[] CARD_COLOR = {0,
        0xFF303030, 0xFF303030, 0xFFCC2020, 0xFFCC2020,
        0xFF303030, 0xFF303030, 0xFFCC2020, 0xFFCC2020
    };

    private static final RectF BTN_PLAY    = new RectF(4,   BAR_Y, 80,  BAR_Y + BAR_H - 2);
    private static final RectF BTN_NEW     = new RectF(84,  BAR_Y, 160, BAR_Y + BAR_H - 2);
    private static final RectF BTN_RESET   = new RectF(164, BAR_Y, 240, BAR_Y + BAR_H - 2);
    private static final RectF BTN_OPTIONS = new RectF(244, BAR_Y, 340, BAR_Y + BAR_H - 2);
    private static final RectF BTN_SCORES  = new RectF(344, BAR_Y, 440, BAR_Y + BAR_H - 2);
    private static final RectF BTN_EXIT    = new RectF(540, BAR_Y, 636, BAR_Y + BAR_H - 2);
    private static final RectF[] BUTTONS   = {BTN_PLAY, BTN_NEW, BTN_RESET, BTN_OPTIONS, BTN_SCORES, BTN_EXIT};

    private final Game game = new Game();
    private final GameAudio audio;
    private final SharedPreferences prefs;
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint fill  = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint tp    = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final ControlPad pad;
    private final Handler handler = new Handler(Looper.getMainLooper());

    private float scale = 1f, offsetX, offsetY;
    private boolean running;
    private RectF pressed;

    private final Runnable loop = new Runnable() {
        @Override public void run() {
            game.tick();
            invalidate();
            handler.postDelayed(this, TICK_MS);
        }
    };

    MuddleGameView(Context context) {
        super(context);
        prefs = context.getSharedPreferences("muddle", Context.MODE_PRIVATE);
        audio = new GameAudio(context, "muddle");
        game.listener = this;
        game.levels   = this;
        game.difficulty = prefs.getInt("difficulty", Game.TRAINING);
        game.startLevel = prefs.getInt("startLevel", 1);

        pad = new ControlPad(null);
        pad.addArrows(460, 300, 56, true);
        pad.add(KeyEvent.KEYCODE_SPACE, 350, 328, 68, 28, "Move");
        pad.add(KeyEvent.KEYCODE_TAB,   350, 360, 68, 28, "Knock");

        tp.setTextSize(14);
        tp.setColor(Color.WHITE);
        tp.setTextAlign(Paint.Align.CENTER);
    }

    // ---- lifecycle ----------------------------------------------------------------------------

    void onHostResume() {
        if (!running) { running = true; handler.post(loop); }
        if (audio.musicOn) { audio.startMusic("MUDMUSIC"); audio.resumeMusic(); }
    }

    void onHostPause() {
        if (game.state == Game.State.PLAYING) game.state = Game.State.PAUSED;
        audio.pauseMusic();
        running = false;
        handler.removeCallbacks(loop);
    }

    void release() {
        handler.removeCallbacksAndMessages(null);
        audio.release();
    }

    // ---- Game.LevelSource ---------------------------------------------------------------------

    @Override
    public byte[] load(String name) {
        try (InputStream in = getContext().getAssets().open("muddle/data/" + name + ".bin")) {
            byte[] buf = new byte[4096];
            int got = 0, n;
            while ((n = in.read(buf, got, buf.length - got)) > 0) got += n;
            byte[] out = new byte[got];
            System.arraycopy(buf, 0, out, 0, got);
            return out;
        } catch (IOException e) {
            return null;
        }
    }

    // ---- Game.Listener ------------------------------------------------------------------------

    @Override public void sound(String name) { audio.play(name); }
    @Override public void tip(int kind) { /* no overlay for now */ }
    @Override public void gameOver(int score) {
        int best = prefs.getInt("best", 0);
        if (score > best) prefs.edit().putInt("best", score).apply();
    }

    // ---- layout -------------------------------------------------------------------------------

    @Override
    protected void onSizeChanged(int w, int h, int ow, int oh) {
        scale = Math.min(w / (float) W, h / (float) H);
        offsetX = (w - W * scale) / 2f;
        offsetY = (h - H * scale) / 2f;
    }

    // ---- drawing ------------------------------------------------------------------------------

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(0xFF1A1200);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);

        switch (game.state) {
            case TITLE:
                drawCenteredText(canvas, "Muddled Casino", W / 2f, H / 2f - 20);
                drawCenteredText(canvas, "Tap Play to start", W / 2f, H / 2f + 10);
                break;
            case OVER:
                drawBoard(canvas);
                drawImg(canvas, "gameoverbmp", (W - 200) / 2f, 120);
                break;
            default:
                drawBoard(canvas);
                break;
        }

        drawButtonBar(canvas);
        canvas.restore();
    }

    private void drawBoard(Canvas canvas) {
        // Board background
        fill.setColor(0xFF2A1E06);
        canvas.drawRect(BOARD_OX - 2, BOARD_OY - 2,
                BOARD_OX + Game.COLS * CELL_W + 2, BOARD_OY + Game.ROWS * CELL_H + 2, fill);

        // Cells — row 0 = bottom of original, draw top-down so r=ROWS-1 at y=BOARD_OY
        for (int row = 0; row < Game.ROWS; row++) {
            int drawRow = Game.ROWS - 1 - row; // flip: row 0 is at the bottom
            for (int col = 0; col < Game.COLS; col++) {
                int v = game.board[row][col];
                float cx = BOARD_OX + col * CELL_W;
                float cy = BOARD_OY + drawRow * CELL_H;
                drawCell(canvas, v, cx, cy, row, col);
            }
        }

        // Exit marker (right of col 13, row 0 = bottom draw row = ROWS-1)
        fill.setColor(0xFFFFD700);
        float ey = BOARD_OY + (Game.ROWS - 1) * CELL_H;
        canvas.drawRect(BOARD_OX + Game.COLS * CELL_W, ey, BOARD_OX + Game.COLS * CELL_W + 8, ey + CELL_H, fill);

        // HUD
        tp.setTextSize(12);
        tp.setTextAlign(Paint.Align.LEFT);
        tp.setColor(Color.WHITE);
        canvas.drawText("Score: " + game.score, 8, 14, tp);
        canvas.drawText("Lvl " + game.level + "  Dir:" + game.dir, 180, 14, tp);
        canvas.drawText("P:" + game.playerCoins + " C:" + game.casinoCoins, 380, 14, tp);
        String next = game.order[0] > 0 ? ("Next: " + CARD_LABEL[game.order[0]]) : "Done!";
        canvas.drawText(next, 8, 28, tp);
        if (game.betting) canvas.drawText("Set bet before moving", 180, 28, tp);

        // Group direction arrows
        drawDirectionHud(canvas);

        // ControlPad
        pad.draw(canvas);

        if (game.state == Game.State.PAUSED) drawCenteredText(canvas, "Paused", W / 2f, H / 2f - 40);
    }

    private void drawCell(Canvas canvas, int v, float cx, float cy, int row, int col) {
        if (v == Game.EMPTY) {
            fill.setColor(0xFF1A0E00);
            canvas.drawRect(cx + 1, cy + 1, cx + CELL_W - 1, cy + CELL_H - 1, fill);
            return;
        }
        // Choose cell background
        int bg;
        if (Game.isCard(v)) {
            int mf = game.moveFrame(row, col);
            boolean blink = game.blinkBold() && game.order[0] == v;
            bg = blink ? 0xFFFFFFCC : (mf > 0 ? 0xFFD0F0D0 : 0xFFF5E0C0);
        } else {
            switch (v) {
                case Game.JOKER:  bg = 0xFF80C080; break;
                case Game.HOLE:   bg = 0xFF101010; break;
                case Game.BUMPER: bg = 0xFF6080C0; break;
                case Game.DICE:   bg = 0xFF9060A0; break;
                default: bg = 0xFF808080;
            }
        }
        fill.setColor(bg);
        canvas.drawRect(cx + 1, cy + 1, cx + CELL_W - 1, cy + CELL_H - 1, fill);
        fill.setColor(0xFF806040);
        fill.setStyle(Paint.Style.STROKE);
        fill.setStrokeWidth(1);
        canvas.drawRect(cx + 1, cy + 1, cx + CELL_W - 1, cy + CELL_H - 1, fill);
        fill.setStyle(Paint.Style.FILL);

        tp.setTextAlign(Paint.Align.CENTER);
        tp.setTextSize(13);
        if (Game.isCard(v)) {
            tp.setColor(CARD_COLOR[v]);
            canvas.drawText(CARD_LABEL[v], cx + CELL_W / 2f, cy + CELL_H / 2f + 5, tp);
        } else {
            tp.setColor(0xFFFFFFFF);
            String label = v == Game.JOKER ? "J" : v == Game.HOLE ? "O" : v == Game.BUMPER ? "B" : "D";
            canvas.drawText(label, cx + CELL_W / 2f, cy + CELL_H / 2f + 5, tp);
        }
    }

    private void drawDirectionHud(Canvas canvas) {
        String[] labels = {"","◇","□","◀","▶","▲","▼","◁","▷"};
        for (int d = 1; d <= 8; d++) {
            float x = 8 + (d - 1) * 32f;
            float y = 38;
            fill.setColor(game.dir == d ? 0xFF60A060 : 0xFF304030);
            canvas.drawRoundRect(x, y - 12, x + 28, y + 4, 4, 4, fill);
            tp.setColor(Color.WHITE);
            tp.setTextSize(11);
            tp.setTextAlign(Paint.Align.CENTER);
            canvas.drawText(d + "", x + 14, y, tp);
        }
    }

    private void drawButtonBar(Canvas canvas) {
        fill.setColor(0xFF1A1200);
        canvas.drawRect(0, BAR_Y - 2, W, H, fill);
        String play = game.state == Game.State.PLAYING ? "Pause" : "Play";
        drawBtn(canvas, BTN_PLAY, play);
        drawBtn(canvas, BTN_NEW, "New");
        drawBtn(canvas, BTN_RESET, "Reset");
        drawBtn(canvas, BTN_OPTIONS, "Options");
        drawBtn(canvas, BTN_SCORES, "Scores");
        drawBtn(canvas, BTN_EXIT, "Exit");
    }

    private void drawBtn(Canvas canvas, RectF r, String label) {
        fill.setColor(pressed == r ? 0xFF806020 : 0xFF3A2A00);
        canvas.drawRoundRect(r, 6, 6, fill);
        tp.setTextSize(12);
        tp.setColor(Color.WHITE);
        tp.setTextAlign(Paint.Align.CENTER);
        canvas.drawText(label, r.centerX(), r.centerY() + 5, tp);
    }

    private void drawCenteredText(Canvas canvas, String s, float cx, float cy) {
        tp.setTextSize(20);
        tp.setColor(Color.WHITE);
        tp.setTextAlign(Paint.Align.CENTER);
        fill.setColor(0xA0000000);
        float tw = tp.measureText(s);
        canvas.drawRect(cx - tw / 2 - 10, cy - 18, cx + tw / 2 + 10, cy + 8, fill);
        canvas.drawText(s, cx, cy, tp);
    }

    private void drawImg(Canvas canvas, String name, float x, float y) {
        if (!images.containsKey(name)) {
            Bitmap b = null;
            try (InputStream in = getContext().getAssets().open("muddle/img/" + name + ".png")) {
                b = BitmapFactory.decodeStream(in);
            } catch (IOException ignored) {}
            images.put(name, b);
        }
        Bitmap b = images.get(name);
        if (b != null) canvas.drawBitmap(b, x, y, paint);
    }

    // ---- touch --------------------------------------------------------------------------------

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        float lx = (e.getX() - offsetX) / scale;
        float ly = (e.getY() - offsetY) / scale;
        pad.onTouch(e, offsetX, offsetY, scale);
        handlePadKeys();

        switch (e.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                pressed = btnAt(lx, ly);
                if (pressed == null && ly < BAR_Y) tapField(lx, ly);
                invalidate();
                return true;
            case MotionEvent.ACTION_UP:
                if (pressed != null && pressed == btnAt(lx, ly)) {
                    performClick();
                    pressBtn(pressed);
                }
                pressed = null;
                invalidate();
                return true;
            case MotionEvent.ACTION_CANCEL:
                pressed = null; invalidate(); return true;
            default: return true;
        }
    }

    @Override public boolean performClick() { return super.performClick(); }

    private void handlePadKeys() {
        if (game.state != Game.State.PLAYING) return;
        if (pad.isDown(KeyEvent.KEYCODE_DPAD_UP))    game.arrow(Game.SIDE_UP);
        if (pad.isDown(KeyEvent.KEYCODE_DPAD_LEFT))  game.arrow(Game.SIDE_LEFT);
        if (pad.isDown(KeyEvent.KEYCODE_DPAD_RIGHT)) game.arrow(Game.SIDE_RIGHT);
        if (pad.isDown(KeyEvent.KEYCODE_DPAD_DOWN))  game.arrow(Game.SIDE_DOWN);
        if (pad.isDown(KeyEvent.KEYCODE_SPACE)) game.move(false);
        if (pad.isDown(KeyEvent.KEYCODE_TAB))   game.move(true);
    }

    private void tapField(float lx, float ly) {
        // Tap direction HUD boxes to select group directly
        for (int d = 1; d <= 8; d++) {
            float x = 8 + (d - 1) * 32f;
            if (lx >= x && lx <= x + 28 && ly >= 26 && ly <= 42) {
                game.selectGroup(d);
                return;
            }
        }
        // Tap the board
        if (game.state == Game.State.TITLE || game.state == Game.State.OVER) {
            startNewGame();
            return;
        }
        if (lx < BOARD_OX || lx > BOARD_OX + Game.COLS * CELL_W) return;
        if (ly < BOARD_OY || ly > BOARD_OY + Game.ROWS * CELL_H) return;
        game.move(false);
    }

    private RectF btnAt(float x, float y) {
        for (RectF r : BUTTONS) if (r.contains(x, y)) return r;
        return null;
    }

    private void pressBtn(RectF btn) {
        if (btn == BTN_PLAY) {
            switch (game.state) {
                case PLAYING: game.state = Game.State.PAUSED; break;
                case PAUSED:  game.state = Game.State.PLAYING; break;
                default:      startNewGame(); break;
            }
        } else if (btn == BTN_NEW)     { startNewGame(); }
        else if (btn == BTN_RESET)     { game.restartLevel(); }
        else if (btn == BTN_OPTIONS)   { if (game.state == Game.State.PLAYING) game.state = Game.State.PAUSED; showOptions(); }
        else if (btn == BTN_SCORES)    { showScores(); }
        else if (btn == BTN_EXIT)      { ((MuddleActivity) getContext()).exitToMenu(); }
    }

    private void startNewGame() {
        game.difficulty = prefs.getInt("difficulty", Game.TRAINING);
        game.startLevel  = prefs.getInt("startLevel", 1);
        game.newGame();
    }

    private void showOptions() {
        String[] modes = {"Training", "Easy", "Medium", "Hard", "Challenge"};
        int cur = game.difficulty - 1;
        new AlertDialog.Builder(getContext())
                .setTitle("Difficulty")
                .setSingleChoiceItems(modes, cur, (d, w) -> {
                    prefs.edit().putInt("difficulty", w + 1).apply();
                    game.difficulty = w + 1;
                })
                .setPositiveButton("OK", null).show();
    }

    private void showScores() {
        new AlertDialog.Builder(getContext())
                .setTitle("Muddled Casino — Best Score")
                .setMessage("Your best: " + prefs.getInt("best", 0))
                .setPositiveButton("OK", null).show();
    }
}
