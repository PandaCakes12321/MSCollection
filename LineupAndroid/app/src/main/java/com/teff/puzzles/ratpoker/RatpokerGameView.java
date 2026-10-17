package com.teff.puzzles.ratpoker;

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
import android.os.SystemClock;
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
 * Rat Poker game view.  640×430 logical canvas, letterboxed.
 * Belt runs left-to-right across the screen; arms trap rats; platform scores hands.
 */
final class RatpokerGameView extends View implements Game.Listener {

    private static final int W = 640, H = 430;
    private static final int BAR_Y = 400, BAR_H = 30;
    private static final int TICK_MS = 50;

    // Rat belt geometry
    private static final int BELT_Y  = 80;
    private static final int BELT_H  = 50;
    private static final int BELT_OX = 40;
    private static final int BELT_SLOT_W = 45;

    // Arm row
    private static final int ARM_Y = 148;
    private static final int ARM_H = 40;

    // Platform row (left side)
    private static final int PLAT_Y  = 240;
    private static final int PLAT_OX = 30;
    private static final int PLAT_SLOT_W = 50;
    private static final int PLAT_H = 50;

    // Rat colours -> paint colours
    private static final int[] RAT_COLORS = {
        0xFF888888,   // 0 none
        0xFF4070E0,   // B blue
        0xFF30CCCC,   // C cyan
        0xFFC08040,   // D dark brown
        0xFF40B840,   // G green
        0xFFCC40CC,   // M magenta
        0xFFE08020,   // O orange
        0xFFE03030,   // R red
        0xFFE8E8E8,   // W white
        0xFFD0C020,   // Y yellow
    };

    private static final RectF BTN_PLAY    = new RectF(4,   BAR_Y, 80,  BAR_Y + BAR_H - 2);
    private static final RectF BTN_NEW     = new RectF(84,  BAR_Y, 160, BAR_Y + BAR_H - 2);
    private static final RectF BTN_OPTIONS = new RectF(164, BAR_Y, 280, BAR_Y + BAR_H - 2);
    private static final RectF BTN_SCORES  = new RectF(284, BAR_Y, 380, BAR_Y + BAR_H - 2);
    private static final RectF BTN_EXIT    = new RectF(540, BAR_Y, 636, BAR_Y + BAR_H - 2);
    private static final RectF[] BUTTONS   = {BTN_PLAY, BTN_NEW, BTN_OPTIONS, BTN_SCORES, BTN_EXIT};

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
    private long lastTick;
    private boolean running;
    private RectF pressed;

    private final Runnable loop = new Runnable() {
        @Override public void run() {
            long now = SystemClock.uptimeMillis();
            int ms = (int) Math.min(now - lastTick, 500);
            lastTick = now;
            if (game.state == Game.State.PLAYING) {
                handleKeys();
                game.tick(ms);
            }
            invalidate();
            handler.postDelayed(this, TICK_MS);
        }
    };

    RatpokerGameView(Context context) {
        super(context);
        prefs = context.getSharedPreferences("ratpoker", Context.MODE_PRIVATE);
        audio = new GameAudio(context, "ratpoker");
        game.listener = this;
        game.startLevel = prefs.getInt("startLevel", 1);
        game.difficulty  = prefs.getInt("difficulty", 1);

        pad = new ControlPad();
        // Left/right to switch arms; SPACE to trap/release; TAB to switch slots
        pad.add(KeyEvent.KEYCODE_DPAD_LEFT,  440, 300, 52, 40, "◀");
        pad.add(KeyEvent.KEYCODE_DPAD_RIGHT, 560, 300, 52, 40, "▶");
        pad.add(KeyEvent.KEYCODE_SPACE,      494, 300, 62, 40, "SPACE");
        pad.add(KeyEvent.KEYCODE_TAB,        494, 344, 62, 28, "TAB");

        tp.setAntiAlias(true);
        tp.setColor(Color.WHITE);
    }

    // ---- lifecycle ----------------------------------------------------------------------------

    void onHostResume() {
        if (!running) {
            running = true;
            lastTick = SystemClock.uptimeMillis();
            handler.post(loop);
        }
        if (audio.musicOn) { audio.startMusic("RAT_MUS"); audio.resumeMusic(); }
    }

    void onHostPause() {
        if (game.state == Game.State.PLAYING) game.pressPause();
        audio.pauseMusic();
        running = false;
        handler.removeCallbacks(loop);
    }

    void release() {
        handler.removeCallbacksAndMessages(null);
        audio.release();
    }

    // ---- Game.Listener ------------------------------------------------------------------------

    @Override public void sound(String name) { audio.play(name); }
    @Override public void tip(int level) { /* no overlay */ }
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
        canvas.drawColor(0xFF0A1A0A);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);

        switch (game.state) {
            case TITLE:
                Bitmap title = img("TITLEBMP");
                if (title != null) canvas.drawBitmap(title, 0, 0, paint);
                else drawCenteredText(canvas, "Rat Poker — Tap Play", W / 2f, H / 2f);
                break;
            case OVER:
                drawGame(canvas);
                Bitmap go = img("GAMEOVERBMP");
                if (go != null) canvas.drawBitmap(go, (W - go.getWidth()) / 2f, 100, paint);
                else drawCenteredText(canvas, "Game Over", W / 2f, 130);
                break;
            default:
                drawGame(canvas);
                break;
        }

        drawButtonBar(canvas);
        canvas.restore();
    }

    private void drawGame(Canvas canvas) {
        // Background
        int bgIdx = Math.min(6, (game.level - 1) % 7);
        String bgName = String.format("BACKGROUND%02d", bgIdx);
        Bitmap bg = img(bgName);
        if (bg != null) canvas.drawBitmap(bg, 0, 0, paint);

        // Belt track
        fill.setColor(0xFF3A2000);
        canvas.drawRect(BELT_OX, BELT_Y, BELT_OX + Game.MAX_BELT * BELT_SLOT_W, BELT_Y + BELT_H, fill);
        fill.setColor(0xFF604020);
        fill.setStyle(Paint.Style.STROKE);
        fill.setStrokeWidth(2);
        canvas.drawRect(BELT_OX, BELT_Y, BELT_OX + Game.MAX_BELT * BELT_SLOT_W, BELT_Y + BELT_H, fill);
        fill.setStyle(Paint.Style.FILL);

        // Rats on belt
        for (Game.Rat r : game.belt) {
            int slot = r.beltPos;
            float rx = BELT_OX + (Game.MAX_BELT - 1 - slot) * BELT_SLOT_W + 4;
            float ry = BELT_Y + 4;
            drawRat(canvas, rx, ry, r.color, r.modifier, false);
        }

        // Arms
        for (int i = 0; i < game.numArms; i++) {
            Game.Arm arm = game.arms[i];
            float ax = BELT_OX + (Game.MAX_BELT - 1 - arm.beltPos) * BELT_SLOT_W;
            boolean active = (i == game.activeArm);

            // Arm visual
            fill.setColor(active ? 0xFF60A040 : 0xFF306020);
            canvas.drawRect(ax, BELT_Y + BELT_H, ax + BELT_SLOT_W - 2, ARM_Y + ARM_H, fill);

            // Trapped rats in arm slots
            for (int s = 0; s < arm.numSlots; s++) {
                if (arm.trapped[s] != Game.NONE) {
                    float sx = ax + 2 + s * (BELT_SLOT_W / 2);
                    float sy = ARM_Y + 4;
                    boolean activeSlot = active && s == game.activeSlot;
                    if (activeSlot) {
                        fill.setColor(0xFFFFFF40);
                        canvas.drawRect(sx - 2, sy - 2, sx + 36, sy + 38, fill);
                    }
                    drawRat(canvas, sx, sy, arm.trapped[s], arm.trapMod[s], true);
                }
            }
        }

        // Platform
        fill.setColor(0xFF2A3A2A);
        canvas.drawRect(PLAT_OX, PLAT_Y, PLAT_OX + Game.MAX_PLAT * PLAT_SLOT_W, PLAT_Y + PLAT_H, fill);
        for (int i = 0; i < game.platCount; i++) {
            int c = game.platform[i];
            if (c != Game.NONE) {
                drawRat(canvas, PLAT_OX + i * PLAT_SLOT_W + 4, PLAT_Y + 4, c, 0, false);
            }
        }

        // "Escaped!" flash
        if (game.escaped) {
            fill.setColor(0x80FFFF80);
            canvas.drawRect(PLAT_OX, PLAT_Y - 8, PLAT_OX + Game.MAX_PLAT * PLAT_SLOT_W, PLAT_Y + PLAT_H + 8, fill);
        }

        // HUD
        tp.setTextSize(13);
        tp.setColor(Color.WHITE);
        canvas.drawText("Score: " + game.score + "  Lv " + game.level
                + "  Rescued:" + game.rescued + "/" + getTarget(), 8, 18, tp);
        canvas.drawText("Infested: " + game.infested, 8, 34, tp);

        if (game.state == Game.State.PAUSED) drawCenteredText(canvas, "Paused", W / 2f, 200);
        if (game.state == Game.State.LEVEL_DONE) {
            drawCenteredText(canvas, "Level " + game.level + " done!", W / 2f, 200);
        }

        pad.draw(canvas);
    }

    private int getTarget() {
        int lv = Math.min(game.level, Game.LEVELS.length - 1);
        return Game.LEVELS[lv][2];
    }

    private void drawRat(Canvas canvas, float x, float y, int color, int mod, boolean small) {
        float size = small ? 30 : 38;
        int col = RAT_COLORS[Math.min(color, RAT_COLORS.length - 1)];
        fill.setColor(col);
        canvas.drawRoundRect(x, y, x + size, y + size * 0.8f, 6, 6, fill);
        fill.setColor(0xA0000000);
        fill.setStyle(Paint.Style.STROKE);
        fill.setStrokeWidth(1.5f);
        canvas.drawRoundRect(x, y, x + size, y + size * 0.8f, 6, 6, fill);
        fill.setStyle(Paint.Style.FILL);
        // Modifier symbol
        if (mod != 0) {
            tp.setTextSize(12);
            tp.setColor(Color.WHITE);
            canvas.drawText(mod > 0 ? "+" : "−", x + size / 2 - 4, y + size * 0.55f, tp);
        }
    }

    private void drawButtonBar(Canvas canvas) {
        fill.setColor(0xFF0A1A0A);
        canvas.drawRect(0, BAR_Y - 2, W, H, fill);
        String play = game.state == Game.State.PLAYING ? "Pause" : "Play";
        drawBtn(canvas, BTN_PLAY, play);
        drawBtn(canvas, BTN_NEW, "New");
        drawBtn(canvas, BTN_OPTIONS, "Options");
        drawBtn(canvas, BTN_SCORES, "Scores");
        drawBtn(canvas, BTN_EXIT, "Exit");
    }

    private void drawBtn(Canvas canvas, RectF r, String label) {
        fill.setColor(pressed == r ? 0xFF305040 : 0xFF183020);
        canvas.drawRoundRect(r, 6, 6, fill);
        tp.setTextSize(12);
        tp.setColor(Color.WHITE);
        float tw = tp.measureText(label);
        canvas.drawText(label, r.centerX() - tw / 2, r.centerY() + 5, tp);
    }

    private void drawCenteredText(Canvas canvas, String s, float cx, float cy) {
        tp.setTextSize(20);
        tp.setColor(Color.WHITE);
        fill.setColor(0xA0000000);
        float tw = tp.measureText(s);
        canvas.drawRect(cx - tw / 2 - 10, cy - 20, cx + tw / 2 + 10, cy + 6, fill);
        canvas.drawText(s, cx - tw / 2, cy, tp);
    }

    private Bitmap img(String name) {
        if (!images.containsKey(name)) {
            Bitmap b = null;
            try (InputStream in = getContext().getAssets().open("ratpoker/img/" + name + ".png")) {
                b = BitmapFactory.decodeStream(in);
            } catch (IOException ignored) {}
            images.put(name, b);
        }
        return images.get(name);
    }

    // ---- touch / keys -------------------------------------------------------------------------

    private void handleKeys() {
        if (pad.isDown(KeyEvent.KEYCODE_DPAD_LEFT))  { game.pressLeft();  }
        if (pad.isDown(KeyEvent.KEYCODE_DPAD_RIGHT)) { game.pressRight(); }
        if (pad.isDown(KeyEvent.KEYCODE_SPACE))      { game.pressSpace(); }
        if (pad.isDown(KeyEvent.KEYCODE_TAB))        { game.pressTab();   }
    }

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        float lx = (e.getX() - offsetX) / scale;
        float ly = (e.getY() - offsetY) / scale;
        pad.onTouch(e, offsetX, offsetY, scale);

        switch (e.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                pressed = btnAt(lx, ly);
                if (pressed == null && ly < BAR_Y) tapGame(lx, ly);
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

    private void tapGame(float lx, float ly) {
        switch (game.state) {
            case TITLE:
            case OVER:
                startNewGame();
                break;
            case LEVEL_DONE:
                game.level++;
                game.startLevel();
                break;
            case PAUSED:
                game.pressPause();
                break;
            case PLAYING:
                // Tap on belt slot to select arm near that slot
                if (ly >= BELT_Y && ly <= BELT_Y + BELT_H + ARM_H) {
                    int slot = Game.MAX_BELT - 1 - (int) ((lx - BELT_OX) / BELT_SLOT_W);
                    for (int i = 0; i < game.numArms; i++) {
                        if (Math.abs(game.arms[i].beltPos - slot) <= 1) {
                            game.activeArm  = i;
                            game.activeSlot = 0;
                        }
                    }
                    game.pressSpace();
                }
                break;
        }
    }

    private RectF btnAt(float x, float y) {
        for (RectF r : BUTTONS) if (r.contains(x, y)) return r;
        return null;
    }

    private void pressBtn(RectF btn) {
        if (btn == BTN_PLAY) {
            switch (game.state) {
                case PLAYING: game.pressPause(); break;
                case PAUSED:  game.pressPause(); break;
                default:      startNewGame();    break;
            }
        } else if (btn == BTN_NEW)     { startNewGame(); }
        else if (btn == BTN_OPTIONS)   { showOptions(); }
        else if (btn == BTN_SCORES)    { showScores(); }
        else if (btn == BTN_EXIT)      { ((RatpokerActivity) getContext()).exitToMenu(); }
    }

    private void startNewGame() {
        game.startLevel = prefs.getInt("startLevel", 1);
        game.difficulty  = prefs.getInt("difficulty", 1);
        game.startGame();
    }

    private void showOptions() {
        if (game.state == Game.State.PLAYING) game.pressPause();
        String[] diffs = {"Easy", "Medium", "Hard", "Expert"};
        int cur = Math.max(0, game.difficulty - 1);
        new AlertDialog.Builder(getContext())
                .setTitle("Difficulty")
                .setSingleChoiceItems(diffs, cur, (d, w) -> {
                    prefs.edit().putInt("difficulty", w + 1).apply();
                    game.difficulty = w + 1;
                })
                .setPositiveButton("OK", null).show();
    }

    private void showScores() {
        new AlertDialog.Builder(getContext())
                .setTitle("Rat Poker — Best Score")
                .setMessage("Your best: " + prefs.getInt("best", 0))
                .setPositiveButton("OK", null).show();
    }
}
