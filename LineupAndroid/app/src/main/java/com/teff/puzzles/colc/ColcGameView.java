package com.teff.puzzles.colc;

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

/** Color Collision game view. 640×430 logical canvas, letterboxed. */
final class ColcGameView extends View implements Game.Listener {

    private static final int W = 640, H = 430;
    private static final int BAR_Y = 400, BAR_H = 30;
    private static final int FIELD_OX = 20, FIELD_OY = 15; // field offset inside canvas
    private static final int TICK_MS = 100;

    // Circle colours (index 0-5)
    private static final int[] COLORS = {
        0xFFE04040, 0xFF4060E0, 0xFF30B030, 0xFFD0C020, 0xFFB030C0, 0xFF20C0C0
    };

    private static final RectF BTN_PLAY    = new RectF(4,   BAR_Y, 100, BAR_Y + BAR_H - 2);
    private static final RectF BTN_NEW     = new RectF(104, BAR_Y, 200, BAR_Y + BAR_H - 2);
    private static final RectF BTN_OPTIONS = new RectF(204, BAR_Y, 330, BAR_Y + BAR_H - 2);
    private static final RectF BTN_SCORES  = new RectF(334, BAR_Y, 430, BAR_Y + BAR_H - 2);
    private static final RectF BTN_EXIT    = new RectF(504, BAR_Y, 636, BAR_Y + BAR_H - 2);
    private static final RectF[] BUTTONS   = {BTN_PLAY, BTN_NEW, BTN_OPTIONS, BTN_SCORES, BTN_EXIT};

    private final Game game = new Game();
    private final GameAudio audio;
    private final SharedPreferences prefs;
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint fill  = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint text  = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final ControlPad pad;
    private final Handler handler = new Handler(Looper.getMainLooper());

    private float scale = 1f, offsetX, offsetY;
    private long lastTick;
    private boolean running;
    private RectF pressed;

    private final Runnable loop = new Runnable() {
        @Override public void run() {
            long now = SystemClock.uptimeMillis();
            int ms = (int) Math.min(now - lastTick, 200);
            lastTick = now;
            if (game.state == Game.State.PLAYING) {
                // feed ControlPad keys
                if (pad.isDown(KeyEvent.KEYCODE_DPAD_LEFT))  game.pressKey(KeyEvent.KEYCODE_DPAD_LEFT);
                if (pad.isDown(KeyEvent.KEYCODE_DPAD_RIGHT)) game.pressKey(KeyEvent.KEYCODE_DPAD_RIGHT);
                if (pad.isDown(KeyEvent.KEYCODE_DPAD_UP))    game.pressKey(KeyEvent.KEYCODE_DPAD_UP);
                if (pad.isDown(KeyEvent.KEYCODE_DPAD_DOWN))  game.pressKey(KeyEvent.KEYCODE_DPAD_DOWN);
                game.tick(ms);
            }
            invalidate();
            handler.postDelayed(this, TICK_MS);
        }
    };

    ColcGameView(Context context) {
        super(context);
        prefs = context.getSharedPreferences("colc", Context.MODE_PRIVATE);
        audio = new GameAudio(context, "colc");
        game.listener = this;
        game.difficulty = prefs.getInt("difficulty", 1);
        game.startLevel  = prefs.getInt("startLevel", 1);

        pad = new ControlPad();
        pad.addArrows(8, 340, 54, true);

        text.setColor(Color.WHITE);
        text.setTextSize(13);
    }

    // ---- lifecycle ----------------------------------------------------------------------------

    void onHostResume() {
        if (!running) {
            running = true;
            lastTick = SystemClock.uptimeMillis();
            handler.post(loop);
        }
        if (audio.musicOn) audio.startMusic("MIDIGAME1", "MIDIGAME2", "MIDIGAME3");
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

    // ---- Game.Listener ------------------------------------------------------------------------

    @Override public void sound(int id) { audio.play(String.valueOf(id)); }
    @Override public void tip(int kind) { /* no-op for now */ }
    @Override public void levelDone(int score) {
        handler.postDelayed(() -> game.nextLevel(), 1200);
    }
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
        canvas.drawColor(0xFF0A1A28);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);

        switch (game.state) {
            case TITLE:
                drawImg(canvas, "TITLEBMP", 0, 0);
                drawCenteredText(canvas, "Tap to play", W / 2f, H / 2f);
                break;
            case OVER:
                drawField(canvas);
                drawImg(canvas, "GAMEOVERBMP", (W - 200) / 2f, 120);
                break;
            default:
                drawField(canvas);
                break;
        }

        drawButtonBar(canvas);
        canvas.restore();
    }

    private void drawField(Canvas canvas) {
        // Level background
        String bg = "LEVEL" + String.format("%02d", ((game.level - 1) % 10) + 1);
        Bitmap bgBmp = img(bg);
        if (bgBmp != null) {
            canvas.drawBitmap(bgBmp, FIELD_OX, FIELD_OY, paint);
        } else {
            fill.setColor(0xFF0A2040);
            canvas.drawRect(FIELD_OX, FIELD_OY, FIELD_OX + Game.FIELD_W, FIELD_OY + Game.FIELD_H, fill);
        }

        // Circles
        for (Game.Circle c : game.circles) {
            if (c.state == Game.CS_GONE) continue;
            int col = COLORS[c.color % COLORS.length];
            float cx = FIELD_OX + c.x, cy = FIELD_OY + c.y;
            if (c.state == Game.CS_STICK) {
                fill.setColor(col);
                fill.setStyle(Paint.Style.FILL);
                canvas.drawRect(cx - 8, cy - Game.CIRCLE_R, cx + 8, cy + Game.CIRCLE_R, fill);
                fill.setColor(0xFFFFFFFF);
                fill.setStyle(Paint.Style.STROKE);
                fill.setStrokeWidth(2);
                canvas.drawRect(cx - 8, cy - Game.CIRCLE_R, cx + 8, cy + Game.CIRCLE_R, fill);
                fill.setStyle(Paint.Style.FILL);
            } else if (c.state == Game.CS_FLASH) {
                fill.setColor(0xFFFFFFFF);
                canvas.drawCircle(cx, cy, Game.CIRCLE_R + 4, fill);
            } else {
                fill.setColor(col);
                canvas.drawCircle(cx, cy, Game.CIRCLE_R, fill);
                fill.setColor(0xA0FFFFFF);
                fill.setStyle(Paint.Style.STROKE);
                fill.setStrokeWidth(2);
                canvas.drawCircle(cx, cy, Game.CIRCLE_R, fill);
                fill.setStyle(Paint.Style.FILL);
            }
        }

        // Ball
        float bx = FIELD_OX + game.bx, by = FIELD_OY + game.by;
        int bcol = COLORS[game.ballColor % COLORS.length];
        fill.setColor(bcol);
        canvas.drawCircle(bx, by, Game.BALL_R, fill);
        fill.setColor(0xFFFFFFFF);
        fill.setStyle(Paint.Style.STROKE);
        fill.setStrokeWidth(2);
        canvas.drawCircle(bx, by, Game.BALL_R, fill);
        fill.setStyle(Paint.Style.FILL);

        // HUD
        text.setTextSize(13);
        text.setColor(Color.WHITE);
        canvas.drawText("Score: " + game.score, 8, 12, text);
        canvas.drawText("Level: " + game.level, 180, 12, text);
        canvas.drawText("Lives: " + game.lives, 340, 12, text);
        canvas.drawText("Balls: " + game.greenBalls, 500, 12, text);

        if (game.state == Game.State.PAUSED) drawCenteredText(canvas, "Paused", W / 2f, H / 2f - 20);
        if (game.state == Game.State.LEVEL_DONE) drawCenteredText(canvas, "Level done!", W / 2f, H / 2f - 20);

        // ControlPad
        pad.draw(canvas);
    }

    private void drawButtonBar(Canvas canvas) {
        fill.setColor(0xFF0A1A28);
        canvas.drawRect(0, BAR_Y - 2, W, H, fill);
        String play = game.state == Game.State.PLAYING ? "Pause" : "Play";
        drawBtn(canvas, BTN_PLAY, play);
        drawBtn(canvas, BTN_NEW, "New");
        drawBtn(canvas, BTN_OPTIONS, "Options");
        drawBtn(canvas, BTN_SCORES, "Scores");
        drawBtn(canvas, BTN_EXIT, "Exit");
    }

    private void drawBtn(Canvas canvas, RectF r, String label) {
        fill.setColor(pressed == r ? 0xFF4080A0 : 0xFF204060);
        canvas.drawRoundRect(r, 6, 6, fill);
        text.setTextSize(12);
        text.setColor(Color.WHITE);
        float tw = text.measureText(label);
        canvas.drawText(label, r.centerX() - tw / 2, r.centerY() + 5, text);
    }

    private void drawCenteredText(Canvas canvas, String s, float cx, float cy) {
        text.setTextSize(22);
        text.setColor(Color.WHITE);
        fill.setColor(0xA0000020);
        float tw = text.measureText(s);
        canvas.drawRect(cx - tw / 2 - 8, cy - 18, cx + tw / 2 + 8, cy + 8, fill);
        canvas.drawText(s, cx - tw / 2, cy, text);
    }

    private Bitmap img(String name) {
        if (!images.containsKey(name)) {
            Bitmap b = null;
            try (InputStream in = getContext().getAssets().open("colc/img/" + name + ".png")) {
                b = BitmapFactory.decodeStream(in);
            } catch (IOException ignored) {}
            images.put(name, b);
        }
        return images.get(name);
    }

    private void drawImg(Canvas canvas, String name, float x, float y) {
        Bitmap b = img(name);
        if (b != null) canvas.drawBitmap(b, x, y, paint);
    }

    // ---- touch --------------------------------------------------------------------------------

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        float lx = (e.getX() - offsetX) / scale;
        float ly = (e.getY() - offsetY) / scale;
        pad.onTouch(e, offsetX, offsetY, scale);
        switch (e.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                pressed = btnAt(lx, ly);
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
                pressed = null;
                invalidate();
                return true;
            default: return true;
        }
    }

    @Override public boolean performClick() { return super.performClick(); }

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
        } else if (btn == BTN_NEW) {
            startNewGame();
        } else if (btn == BTN_OPTIONS) {
            if (game.state == Game.State.PLAYING) game.state = Game.State.PAUSED;
            showOptions();
        } else if (btn == BTN_SCORES) {
            showScores();
        } else if (btn == BTN_EXIT) {
            ((ColcActivity) getContext()).exitToMenu();
        }
    }

    private void startNewGame() {
        game.difficulty = prefs.getInt("difficulty", 1);
        game.startLevel  = prefs.getInt("startLevel", 1);
        game.newGame();
    }

    private void showOptions() {
        String[] diffs = {"Easy", "Medium", "Hard", "Crazy"};
        int cur = game.difficulty - 1;
        new AlertDialog.Builder(getContext())
                .setTitle("Difficulty")
                .setSingleChoiceItems(diffs, cur, (d, w) -> {
                    prefs.edit().putInt("difficulty", w + 1).apply();
                    game.difficulty = w + 1;
                })
                .setPositiveButton("OK", null)
                .show();
    }

    private void showScores() {
        new AlertDialog.Builder(getContext())
                .setTitle("Color Collision — Best Score")
                .setMessage("Your best: " + prefs.getInt("best", 0))
                .setPositiveButton("OK", null)
                .show();
    }
}
