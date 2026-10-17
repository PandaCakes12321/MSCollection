package com.teff.puzzles.sweekend;

import android.app.AlertDialog;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.RectF;
import android.os.Handler;
import android.os.Looper;
import android.os.SystemClock;
import android.text.Layout;
import android.text.StaticLayout;
import android.text.TextPaint;
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.GameAudio;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

/**
 * Draws Spring Weekend with the original art on its 628x400 window plus a button panel on the
 * right, scaled to the screen, and turns taps into the original left/right mouse clicks.
 */
final class GameView extends View implements Game.Listener {
    // Logical layout, in original-art pixels.
    private static final int ART_W = 628, W = 756, H = 400;
    private static final int PX = 632, PW = 120;
    private static final RectF BTN_CCW = new RectF(PX, 6, PX + 58, 68);
    private static final RectF BTN_CW = new RectF(PX + 62, 6, PX + PW, 68);
    private static final RectF BTN_UNDO = new RectF(PX, 74, PX + PW, 114);
    private static final RectF BTN_RETRY = new RectF(PX, 120, PX + PW, 160);
    private static final RectF BTN_PLAY = new RectF(PX, 172, PX + PW, 222);
    private static final RectF BTN_NEW = new RectF(PX, 228, PX + PW, 268);
    private static final RectF BTN_OPTIONS = new RectF(PX, 280, PX + 58, 316);
    private static final RectF BTN_SCORES = new RectF(PX + 62, 280, PX + PW, 316);
    private static final RectF BTN_EXIT = new RectF(PX, 352, PX + PW, 394);
    private static final RectF[] BUTTONS = {BTN_CCW, BTN_CW, BTN_UNDO, BTN_RETRY, BTN_PLAY, BTN_NEW,
            BTN_OPTIONS, BTN_SCORES, BTN_EXIT};

    private static final int TICK_MS = 50;            // original SetTimer period
    private static final long LONG_PRESS_MS = 450;
    private static final float TOUCH_RADIUS = 40f;    // original hit radius is 27 px; wider for fingers
    private static final float RING_RADIUS = 54f;     // 0x41300c: figures travel on this circle
    private static final long TIP_MS = 9000;
    private static final String[] SOUNDS = {"", "ROTATEWAV", "NOROTATEWAV", "NEXTLEVELWAV", "GAMEOVER1WAV",
            "GAMEOVER2WAV", "BEEWAV", "TIME1WAV", "TIME2WAV", "TIME3WAV"};

    final Game game;
    private final Bugs bugs = new Bugs(new Random());
    private final GameAudio audio;
    private final SharedPreferences prefs;
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG | Paint.ANTI_ALIAS_FLAG);
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint stroke = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final TextPaint text = new TextPaint(Paint.ANTI_ALIAS_FLAG);
    private final Path path = new Path();
    private final Handler handler = new Handler(Looper.getMainLooper());

    private float scale = 1f, offsetX, offsetY;
    private boolean running;
    private boolean clockwise = true;     // what a plain tap does (right mouse button)

    // turn animation timing (drawn smoothly between the 50 ms ticks)
    private int seenAnimSerial;
    private long animStartMs;

    // touch state
    private RectF pressed;
    private int pressCell = -1;
    private boolean pondDown, longFired;

    private String tip;
    private long tipUntil;

    private final Runnable loop = new Runnable() {
        @Override
        public void run() {
            game.tick();
            if (game.state != Game.State.PAUSED) {
                int snd = bugs.tick();
                if (snd != 0) {
                    sound(snd);
                }
            }
            invalidate();
            handler.postDelayed(this, TICK_MS);
        }
    };

    private final Runnable longPress = new Runnable() {
        @Override
        public void run() {
            if (pressCell >= 0 && !longFired) {
                longFired = true;
                game.turnAt(pressCell, !clockwise);
                invalidate();
            }
        }
    };

    GameView(Context context) {
        super(context);
        prefs = Dialogs.prefs(context);
        audio = new GameAudio(context, "sweekend");
        game = new Game(loadLevels(context), new Random());
        game.listener = this;
        text.setColor(Color.WHITE);
        stroke.setStyle(Paint.Style.STROKE);
        clockwise = prefs.getBoolean("clockwise", true);
        loadOptions();
        if (!prefs.getBoolean("seenHelp", false)) {
            showTip(Tips.QUICK_HELP);
            prefs.edit().putBoolean("seenHelp", true).apply();
        }
    }

    private static short[][] loadLevels(Context context) {
        short[][] levels = new short[50][Game.N];
        for (int i = 0; i < 50; i++) {
            String name = String.format(java.util.Locale.US, "sweekend/data/level%03d.bin", i);
            try (InputStream in = context.getAssets().open(name)) {
                byte[] b = new byte[Game.N * 2];
                int got = 0;
                while (got < b.length) {
                    int n = in.read(b, got, b.length - got);
                    if (n < 0) {
                        break;
                    }
                    got += n;
                }
                for (int c = 0; c < Game.N; c++) {
                    levels[i][c] = (short) ((b[2 * c] & 0xff) | (b[2 * c + 1] << 8));
                }
            } catch (IOException e) {
                // leave the level blank; it still loads (one flower kind)
            }
        }
        return levels;
    }

    // ---- lifecycle ---------------------------------------------------------------------------

    void onHostResume() {
        if (!running) {
            running = true;
            handler.post(loop);
        }
        if (audio.musicOn) {
            if (audio.hasMusic()) {
                audio.resumeMusic();
            } else {
                audio.startMusic("MELODY1", "MELODY2");
            }
        }
    }

    void onHostPause() {
        pauseGame();
        audio.pauseMusic();
        running = false;
        handler.removeCallbacks(loop);
        handler.removeCallbacks(longPress);
    }

    void release() {
        handler.removeCallbacksAndMessages(null);
        audio.release();
    }

    private void loadOptions() {
        game.startLevel = Math.max(1, Math.min(50, prefs.getInt("startLevel", 1)));
        audio.musicOn = prefs.getBoolean("music", true);
        audio.soundOn = prefs.getBoolean("sound", true);
    }

    void startNewGame() {
        loadOptions();
        game.mode = prefs.getInt("mode", Game.TOURNAMENT);
        game.newGame();
        bugs.chance = 400;
        invalidate();
    }

    private void pauseGame() {
        if (game.state == Game.State.PLAYING) {
            game.state = Game.State.PAUSED;
            invalidate();
        }
    }

    private void resumeGame() {
        if (game.state == Game.State.PAUSED) {
            game.state = Game.State.PLAYING;
            invalidate();
        }
    }

    /** After the options dialog: sound/music now, mode or start level via a new game. */
    void optionsChanged(boolean restart) {
        loadOptions();
        if (!audio.musicOn) {
            audio.stopMusic();
        } else if (!audio.hasMusic()) {
            audio.startMusic("MELODY1", "MELODY2");
        }
        if (!restart) {
            return;
        }
        if (game.state == Game.State.PLAYING || game.state == Game.State.PAUSED
                || game.state == Game.State.LEVEL_DONE) {
            confirmNewGame();
        } else if (game.state == Game.State.OVER) {
            startNewGame();
        }
        invalidate();
    }

    private void confirmNewGame() {
        pauseGame();
        new AlertDialog.Builder(getContext())
                .setTitle(Dialogs.TITLE)
                .setMessage("This will start a new Spring Weekend game.")
                .setPositiveButton("OK", (d, w) -> startNewGame())
                .setNegativeButton("Cancel", null)
                .show();
    }

    // ---- Game.Listener -----------------------------------------------------------------------

    @Override
    public void sound(int id) {
        if (id > 0 && id < SOUNDS.length) {
            audio.play(SOUNDS[id]);
        }
    }

    @Override
    public void gameOver(int score) {
        bugs.chance = 100;   // FUN_00405b01: bugs come more often on the game-over screen
        SweekendActivity activity = (SweekendActivity) getContext();
        if (Dialogs.qualifies(activity, score)) {
            sound(Game.SND_GAMEOVER2);
            handler.postDelayed(() -> Dialogs.askHighScoreName(activity, score), 700);
        } else {
            sound(Game.SND_GAMEOVER1);
            if (!prefs.getBoolean("tipLost", false)) {
                prefs.edit().putBoolean("tipLost", true).apply();
                showTip(Tips.LOST_GAME);
            }
        }
    }

    private void showTip(String message) {
        tip = message;
        tipUntil = SystemClock.uptimeMillis() + TIP_MS;
        invalidate();
    }

    // ---- drawing -----------------------------------------------------------------------------

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        scale = Math.min(w / (float) W, h / (float) H);
        offsetX = (w - W * scale) / 2f;
        offsetY = (h - H * scale) / 2f;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(0xFF1E3410);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);
        canvas.save();
        canvas.clipRect(0, 0, ART_W, H);
        if (game.state == Game.State.TITLE) {
            draw(canvas, "title", 0, 0);
        } else {
            draw(canvas, "background", 0, 0);
            if (game.state == Game.State.OVER) {
                draw(canvas, "gameover", 85, 115);
            }
            drawModel(canvas);
            drawPond(canvas);
            drawCounters(canvas);
            if (game.state == Game.State.PAUSED) {
                drawPaused(canvas);
            }
        }
        drawBugs(canvas);
        drawTip(canvas);
        canvas.restore();
        drawPanel(canvas);
        canvas.restore();
        if (game.busy()) {
            postInvalidateOnAnimation();
        }
    }

    private void drawModel(Canvas canvas) {
        for (int i = 0; i < Game.N; i++) {
            float x = (int) (Game.CX[i] * 0.5) + Game.MODEL_X;
            float y = Game.MODEL_Y - (int) (Game.CY[i] * 0.5);
            sprite(canvas, "flowers1", Sprites.FLOWERS1, game.model[i], x, y);
        }
    }

    private void drawPond(Canvas canvas) {
        if (!game.pondVisible()) {
            return;
        }
        if (pressCell >= 0 && game.state == Game.State.PLAYING && !game.busy()) {
            fill.setColor(0x40FFF6A0);
            canvas.drawCircle(pondX(pressCell), pondY(pressCell), RING_RADIUS + 26, fill);
        }
        int ring = game.animRing;
        float t = 1f;
        if (ring >= 0) {
            if (game.animSerial != seenAnimSerial) {
                seenAnimSerial = game.animSerial;
                animStartMs = SystemClock.uptimeMillis();
            }
            t = Math.min(1f, (SystemClock.uptimeMillis() - animStartMs) / (float) (Game.ANIM_TICKS * TICK_MS));
        }
        boolean[] moving = new boolean[Game.N];
        if (ring >= 0) {
            int c = Game.RING_CENTRE[ring];
            for (int[] pr : Game.RING_PAIRS[ring]) {
                int src = game.animCw ? pr[0] : pr[1];
                int dst = game.animCw ? pr[1] : pr[0];
                moving[dst] = true;
                float cx = pondX(c), cy = pondY(c);
                double a0 = Math.atan2(pondY(src) - cy, pondX(src) - cx);
                double a1 = Math.atan2(pondY(dst) - cy, pondX(dst) - cx);
                double d = a1 - a0;
                while (d > Math.PI) d -= 2 * Math.PI;
                while (d < -Math.PI) d += 2 * Math.PI;
                double a = a0 + d * t;
                float x = cx + (float) (Math.cos(a) * RING_RADIUS);
                float y = cy + (float) (Math.sin(a) * RING_RADIUS);
                if (t >= 1f) {
                    x = pondX(dst);
                    y = pondY(dst);
                }
                // drawn after the still figures, below
                movingX[dst] = x;
                movingY[dst] = y;
            }
        }
        for (int i = 0; i < Game.N; i++) {
            if (!moving[i]) {
                sprite(canvas, "flowers", Sprites.FLOWERS, game.board[i], pondX(i), pondY(i));
            }
        }
        for (int i = 0; i < Game.N; i++) {
            if (moving[i]) {
                sprite(canvas, "flowers", Sprites.FLOWERS, game.board[i], movingX[i], movingY[i]);
            }
        }
    }

    private final float[] movingX = new float[Game.N], movingY = new float[Game.N];

    private static float pondX(int cell) {
        return Game.CX[cell] + Game.POND_X;
    }

    private static float pondY(int cell) {
        return Game.POND_Y - Game.CY[cell];
    }

    /** Moves (bucket), level (stone) and score (pool) digits, as placed in FUN_00403bd6. */
    private void drawCounters(Canvas canvas) {
        int m = game.moves;
        sprite(canvas, "digits_mov", Sprites.DIGITS_MOV, (m / 10) % 10, 462, 258);
        sprite(canvas, "digits_mov", Sprites.DIGITS_MOV, m % 10, 480, 258);
        int l = game.level;
        sprite(canvas, "digits_lev", Sprites.DIGITS_LEV, (l / 10) % 10, 521, 165);
        sprite(canvas, "digits_lev", Sprites.DIGITS_LEV, l % 10, 539, 165);
        int s = game.score;
        for (int i = 0; i < 5; i++) {
            sprite(canvas, "digits_sco", Sprites.DIGITS_SCO, s % 10, 599 - 18 * i, 362);
            s /= 10;
        }
    }

    private void drawPaused(Canvas canvas) {
        fill.setColor(0xB0203010);
        canvas.drawCircle(Game.POND_X, Game.POND_Y, 150, fill);
        text.setTextSize(28);
        text.setFakeBoldText(true);
        String s = "Paused";
        canvas.drawText(s, Game.POND_X - text.measureText(s) / 2, Game.POND_Y, text);
        text.setTextSize(14);
        text.setFakeBoldText(false);
        s = "Tap to go on";
        canvas.drawText(s, Game.POND_X - text.measureText(s) / 2, Game.POND_Y + 26, text);
    }

    private void drawBugs(Canvas canvas) {
        if (bugs.bee) {
            sprite(canvas, "bee", Sprites.BEE, bugs.frame, bugs.x, H - bugs.y);
        }
        if (bugs.butterfly) {
            sprite(canvas, "butterfly", Sprites.BUTTERFLY, bugs.frame, bugs.x, H - bugs.y);
        }
    }

    private void drawPanel(Canvas canvas) {
        fill.setColor(0xFF3B2A14);
        canvas.drawRect(ART_W, 0, W, H, fill);

        drawTurnButton(canvas, BTN_CCW, false);
        drawTurnButton(canvas, BTN_CW, true);
        drawTextButton(canvas, BTN_UNDO, "Undo", game.canUndo());
        drawTextButton(canvas, BTN_RETRY, "Restart puzzle", game.canRetry());
        String play = game.state == Game.State.PLAYING ? "Pause" : "Play";
        drawTextButton(canvas, BTN_PLAY, play, game.state != Game.State.LEVEL_DONE);
        drawTextButton(canvas, BTN_NEW, "New", true);
        drawTextButton(canvas, BTN_OPTIONS, "Options", true);
        drawTextButton(canvas, BTN_SCORES, "Scores", true);
        drawTextButton(canvas, BTN_EXIT, "Exit", true);

        text.setTextSize(11);
        text.setColor(0xFFE8D9A8);
        int mode = game.state == Game.State.TITLE ? prefs.getInt("mode", Game.TOURNAMENT) : game.mode;
        String s = mode == Game.TRAINING ? "Training mode" : "Tournament mode";
        canvas.drawText(s, PX + PW / 2f - text.measureText(s) / 2, 336, text);
        text.setColor(Color.WHITE);
    }

    /** The two turn-direction buttons: a circular arrow, highlighted when selected. */
    private void drawTurnButton(Canvas canvas, RectF r, boolean cw) {
        boolean selected = clockwise == cw;
        fill.setColor(pressed == r ? 0xFF8FBF4A : selected ? 0xFF6E9E2E : 0xFF4A3A20);
        canvas.drawRoundRect(r, 8, 8, fill);
        if (selected) {
            stroke.setColor(0xFFFFE04A);
            stroke.setStrokeWidth(3f);
            canvas.drawRoundRect(r.left + 1.5f, r.top + 1.5f, r.right - 1.5f, r.bottom - 1.5f, 8, 8, stroke);
        }
        float cx = r.centerX(), cy = r.top + 25, rad = 13;
        stroke.setColor(Color.WHITE);
        stroke.setStrokeWidth(4f);
        RectF oval = new RectF(cx - rad, cy - rad, cx + rad, cy + rad);
        // open circle with an arrow head at its end
        float startDeg = cw ? -60 : 240, sweep = cw ? 270 : -270;
        canvas.drawArc(oval, startDeg, sweep, false, stroke);
        double end = Math.toRadians(startDeg + sweep);
        float ex = cx + (float) (Math.cos(end) * rad), ey = cy + (float) (Math.sin(end) * rad);
        // tangent direction of travel
        double tang = end + (cw ? Math.PI / 2 : -Math.PI / 2);
        float tx = (float) Math.cos(tang), ty = (float) Math.sin(tang);
        float nx = -ty, ny = tx;
        path.reset();
        path.moveTo(ex + tx * 7, ey + ty * 7);
        path.lineTo(ex - tx * 3 + nx * 7, ey - ty * 3 + ny * 7);
        path.lineTo(ex - tx * 3 - nx * 7, ey - ty * 3 - ny * 7);
        path.close();
        fill.setColor(Color.WHITE);
        canvas.drawPath(path, fill);
        text.setTextSize(11);
        text.setFakeBoldText(true);
        String label = cw ? "Right" : "Left";
        canvas.drawText(label, cx - text.measureText(label) / 2, r.bottom - 6, text);
        text.setFakeBoldText(false);
    }

    private void drawTextButton(Canvas canvas, RectF r, String label, boolean enabled) {
        fill.setColor(!enabled ? 0xFF4A3A20 : pressed == r ? 0xFF8FBF4A : 0xFF6E9E2E);
        canvas.drawRoundRect(r, 8, 8, fill);
        text.setTextSize(label.length() > 8 ? 12 : 15);
        text.setFakeBoldText(true);
        text.setColor(enabled ? Color.WHITE : 0xFF9A8A6A);
        float w = text.measureText(label);
        canvas.drawText(label, r.centerX() - w / 2, r.centerY() + 5, text);
        text.setFakeBoldText(false);
        text.setColor(Color.WHITE);
    }

    private void drawTip(Canvas canvas) {
        if (tip == null) {
            return;
        }
        if (SystemClock.uptimeMillis() > tipUntil) {
            tip = null;
            return;
        }
        text.setTextSize(14);
        int boxW = 340;
        StaticLayout layout = StaticLayout.Builder.obtain(tip, 0, tip.length(), text, boxW - 24)
                .setAlignment(Layout.Alignment.ALIGN_NORMAL)
                .build();
        float h = layout.getHeight() + 20;
        fill.setColor(0xE0101010);
        canvas.drawRoundRect(30, 20, 30 + boxW, 20 + h, 8, 8, fill);
        canvas.save();
        canvas.translate(42, 30);
        layout.draw(canvas);
        canvas.restore();
    }

    private void sprite(Canvas canvas, String name, int[][] hot, int frame, float x, float y) {
        if (frame < 0 || frame >= hot.length) {
            return;
        }
        draw(canvas, name + "_" + frame, x - hot[frame][0], y - hot[frame][1]);
    }

    private void draw(Canvas canvas, String name, float x, float y) {
        Bitmap b = image(name);
        if (b != null) {
            canvas.drawBitmap(b, x, y, paint);
        }
    }

    private Bitmap image(String name) {
        Bitmap b = images.get(name);
        if (b == null && !images.containsKey(name)) {
            try (InputStream in = getContext().getAssets().open("sweekend/img/" + name + ".png")) {
                b = BitmapFactory.decodeStream(in);
            } catch (IOException e) {
                b = null;
            }
            images.put(name, b);
        }
        return b;
    }

    // ---- touch -------------------------------------------------------------------------------

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        float x = (e.getX() - offsetX) / scale, y = (e.getY() - offsetY) / scale;
        switch (e.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                tip = null;
                pressed = buttonAt(x, y);
                pressCell = -1;
                longFired = false;
                pondDown = pressed == null && x < ART_W;
                if (pondDown && game.state == Game.State.PLAYING) {
                    pressCell = Game.cellAt(x, y, TOUCH_RADIUS);
                    if (pressCell >= 0) {
                        handler.postDelayed(longPress, LONG_PRESS_MS);
                    }
                }
                invalidate();
                return true;
            case MotionEvent.ACTION_MOVE:
                if (pressCell >= 0 && !longFired && Game.cellAt(x, y, TOUCH_RADIUS) != pressCell) {
                    handler.removeCallbacks(longPress);
                    pressCell = -1;
                    invalidate();
                }
                return true;
            case MotionEvent.ACTION_UP:
                handler.removeCallbacks(longPress);
                if (pressed != null) {
                    if (pressed == buttonAt(x, y)) {
                        performClick();
                        pressButton(pressed);
                    }
                } else if (pondDown && x < ART_W) {
                    tapArt(x, y);
                }
                pressed = null;
                pressCell = -1;
                pondDown = false;
                invalidate();
                return true;
            case MotionEvent.ACTION_CANCEL:
                handler.removeCallbacks(longPress);
                pressed = null;
                pressCell = -1;
                pondDown = false;
                invalidate();
                return true;
            default:
                return true;
        }
    }

    private void tapArt(float x, float y) {
        switch (game.state) {
            case TITLE:
            case OVER:
                startNewGame();     // any click on the title or game-over screen starts a game
                break;
            case PAUSED:
                resumeGame();
                break;
            case PLAYING:
                if (longFired) {
                    break;
                }
                if (pressCell >= 0) {
                    if (Game.cellAt(x, y, TOUCH_RADIUS) == pressCell) {
                        game.turnAt(pressCell, clockwise);
                    }
                } else if (inPond(x, y)) {
                    game.miss();
                }
                break;
            default:
                break;
        }
    }

    private static boolean inPond(float x, float y) {
        float dx = x - Game.POND_X, dy = y - Game.POND_Y;
        return dx * dx + dy * dy < 150 * 150;
    }

    @Override
    public boolean performClick() {
        return super.performClick();
    }

    private RectF buttonAt(float x, float y) {
        for (RectF r : BUTTONS) {
            if (r.contains(x, y)) {
                return r;
            }
        }
        return null;
    }

    private void pressButton(RectF button) {
        SweekendActivity activity = (SweekendActivity) getContext();
        if (button == BTN_CCW || button == BTN_CW) {
            clockwise = button == BTN_CW;
            prefs.edit().putBoolean("clockwise", clockwise).apply();
        } else if (button == BTN_UNDO) {
            game.undo();
        } else if (button == BTN_RETRY) {
            game.retry();
        } else if (button == BTN_PLAY) {
            switch (game.state) {
                case PLAYING:
                    pauseGame();
                    break;
                case LEVEL_DONE:
                    break;
                case PAUSED:
                    resumeGame();
                    break;
                default:
                    startNewGame();
                    break;
            }
        } else if (button == BTN_NEW) {
            if (game.state == Game.State.PLAYING || game.state == Game.State.PAUSED
                    || game.state == Game.State.LEVEL_DONE) {
                confirmNewGame();
            } else {
                startNewGame();
            }
        } else if (button == BTN_OPTIONS) {
            pauseGame();
            Dialogs.showOptions(activity);
        } else if (button == BTN_SCORES) {
            pauseGame();
            Dialogs.showHighScores(activity);
        } else if (button == BTN_EXIT) {
            pauseGame();
            activity.exitToMenu();
        }
    }
}
