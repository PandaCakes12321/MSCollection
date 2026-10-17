package com.teff.puzzles.charmer;

import android.app.AlertDialog;
import android.content.Context;
import android.content.SharedPreferences;
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
import android.text.TextPaint;
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.ControlPad;
import com.teff.puzzles.common.GameAudio;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

/**
 * Draws Charmer with the original art on its 600x400 playfield, scaled to fit the screen.
 * Arrow keys LEFT/RIGHT move the flute between columns; SPACE changes the flute type.
 */
final class CharmerGameView extends View implements Game.Listener, ControlPad.Listener {

    private static final int W = 600, H = 450;  // logical canvas: 600x400 game + 50 button bar
    private static final int GAME_H = 400;
    private static final int BAR_Y = 405, BAR_H = 40;
    private static final String[] BUTTONS = {"Play", "New", "Exit"};
    private static final int B_PLAY = 0, B_NEW = 1, B_EXIT = 2;
    private static final int FRAME_MS = Game.TICK_MS;

    // Heart niche positions (approximate, original has 3 niches on right side)
    private static final int HEART_X = 530, HEART_Y0 = 60;
    private static final int MARGIN_X = 500; // right margin start

    final Game game = new Game();
    private final GameAudio audio;
    private final SharedPreferences prefs;
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final TextPaint text = new TextPaint(Paint.ANTI_ALIAS_FLAG);
    private final Handler handler = new Handler(Looper.getMainLooper());
    private final Rect src = new Rect();
    private final RectF dst = new RectF();
    private final ControlPad pad;

    private float scale = 1f, offsetX, offsetY;
    private boolean running;
    private long lastFrame;

    // Touch for buttons
    private int buttonDown = -1;

    private String tipText;

    private final Runnable loop = new Runnable() {
        @Override
        public void run() {
            long now = SystemClock.uptimeMillis();
            lastFrame = now;
            if (tipText == null) {
                game.tick();
            }
            invalidate();
            handler.postDelayed(this, FRAME_MS);
        }
    };

    CharmerGameView(Context context) {
        super(context);
        prefs = context.getSharedPreferences("charmer", Context.MODE_PRIVATE);
        audio = new GameAudio(context, "charmer");
        game.listener = this;
        text.setColor(Color.WHITE);
        loadOptions();

        // LEFT/RIGHT move flute between columns; SPACE cycles flute type
        // Place arrow pad in lower-left, SPACE key next to it
        pad = new ControlPad(this);
        pad.addArrows(10, GAME_H + 2, 36, false);
        pad.add(ControlPad.SPACE, 130, GAME_H + 2, 60, 36, "Flute");
    }

    // ---- lifecycle -----------------------------------------------------------------------

    void onHostResume() {
        if (!running) {
            running = true;
            lastFrame = SystemClock.uptimeMillis();
            handler.post(loop);
        }
    }

    void onHostPause() {
        pauseGame();
        running = false;
        handler.removeCallbacks(loop);
        pad.releaseAll();
    }

    void release() {
        handler.removeCallbacks(loop);
        audio.release();
    }

    void loadOptions() {
        game.difficulty = prefs.getInt("difficulty", 1);
        game.startLevel = prefs.getInt("startLevel", 1);
        audio.musicOn = prefs.getBoolean("music", true);
        audio.soundOn = prefs.getBoolean("sound", true);
    }

    void startNewGame() {
        loadOptions();
        game.newGame();
        audio.startMusic("MIDIGAME1");
        invalidate();
    }

    void pauseGame() {
        if (game.state == Game.State.PLAYING) {
            game.state = Game.State.PAUSED;
            audio.pauseMusic();
            pad.releaseAll();
            invalidate();
        }
    }

    private void resumeGame() {
        if (game.state == Game.State.PAUSED) {
            game.state = Game.State.PLAYING;
            audio.resumeMusic();
            invalidate();
        }
    }

    // ---- Game.Listener -------------------------------------------------------------------

    @Override
    public void sound(String name) {
        audio.play(name);
    }

    @Override
    public void tip(String key) {
        // tips are short strings from the original; show as a brief overlay
        tipText = key;
        handler.postDelayed(() -> {
            tipText = null;
            invalidate();
        }, 3000);
    }

    @Override
    public void gameOver(int score, boolean won) {
        audio.stopMusic();
        handler.post(() -> {
            CharmerActivity act = (CharmerActivity) getContext();
            new AlertDialog.Builder(act)
                    .setTitle("Charmer")
                    .setMessage(won ? "You won! Score: " + score : "Game over! Score: " + score)
                    .setPositiveButton("OK", null)
                    .show();
        });
    }

    // ---- ControlPad.Listener -------------------------------------------------------------

    @Override
    public void keyDown(int keyCode) {
        if (!game.controlsLive()) return;
        switch (keyCode) {
            case ControlPad.LEFT:
                game.moveFlute(-1);
                break;
            case ControlPad.RIGHT:
                game.moveFlute(1);
                break;
            case ControlPad.SPACE:
                game.nextFlute();
                break;
        }
    }

    @Override
    public void keyUp(int keyCode) { /* no hold actions needed */ }

    // ---- drawing -------------------------------------------------------------------------

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        scale = Math.min(w / (float) W, h / (float) H);
        offsetX = (w - W * scale) / 2f;
        offsetY = (h - H * scale) / 2f;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(0xFF1A0A00);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);

        drawBackground(canvas);
        drawColumns(canvas);
        drawUi(canvas);
        drawButtons(canvas);
        pad.draw(canvas);
        drawTip(canvas);

        canvas.restore();
    }

    private void drawBackground(Canvas canvas) {
        String lvlKey;
        if (game.state == Game.State.TITLE || game.state == Game.State.OVER) {
            lvlKey = game.state == Game.State.OVER ? "GAMEOVERBMP" : "STARTBMP";
            Bitmap b = img(lvlKey);
            if (b == null) b = img("STARTBMP");
            if (b != null) canvas.drawBitmap(b, 0, 0, paint);
        } else if (game.state == Game.State.PAUSED) {
            drawLevel(canvas, game.level);
            Bitmap pb = img("PAUSEBMP");
            if (pb != null) canvas.drawBitmap(pb, (W - pb.getWidth()) / 2f, (GAME_H - pb.getHeight()) / 2f, paint);
        } else {
            drawLevel(canvas, game.level);
        }
    }

    private void drawLevel(Canvas canvas, int level) {
        String key = String.format(Locale.US, "LEVEL%02d", Math.max(1, Math.min(10, level)));
        Bitmap b = img(key);
        if (b != null) {
            src.set(0, 0, b.getWidth(), b.getHeight());
            dst.set(0, 0, MARGIN_X, GAME_H);
            canvas.drawBitmap(b, src, dst, paint);
        }
        Bitmap m = img("MARGIN");
        if (m != null) canvas.drawBitmap(m, MARGIN_X, 0, paint);
    }

    private void drawColumns(Canvas canvas) {
        if (game.state != Game.State.PLAYING && game.state != Game.State.PAUSED
                && game.state != Game.State.LIFE_LOST && game.state != Game.State.LEVEL_DONE) {
            return;
        }
        for (Game.Column col : game.cols) {
            if (!col.active) continue;
            drawColumn(canvas, col);
        }
        // Draw flute indicator on the active column
        if (game.fluteCol >= 0 && game.fluteCol < game.cols.length) {
            Game.Column fc = game.cols[game.fluteCol];
            if (fc.active) {
                Bitmap flute = img("FLUTES");
                if (flute != null) {
                    int fw = flute.getWidth() / 3;
                    int fh = flute.getHeight();
                    src.set(game.flute * fw, 0, (game.flute + 1) * fw, fh);
                    float dx = fc.x - fw / 2f;
                    float dy = Game.BASE_Y - fh + 5;
                    dst.set(dx, dy, dx + fw, dy + fh);
                    canvas.drawBitmap(flute, src, dst, paint);
                }
            }
        }
    }

    private void drawColumn(Canvas canvas, Game.Column col) {
        // Draw the snake body and head
        String snakeKey = "SNAKE" + col.type + col.color;
        Bitmap snakeBmp = img(snakeKey);

        // Draw snake head at col.y
        if (snakeBmp != null && col.state != Game.S_IDLE) {
            int f = Math.min(col.frame, 7);
            int sw = snakeBmp.getWidth() / 8;
            int sh = snakeBmp.getHeight();
            src.set(f * sw, 0, (f + 1) * sw, sh);
            dst.set(col.x - sw / 2f, col.y, col.x + sw / 2f, col.y + sh);
            canvas.drawBitmap(snakeBmp, src, dst, paint);
        }

        // Draw pot stack
        Bitmap baseBmp = img("SNAKEBAS");
        for (int i = 1; i <= col.n; i++) {
            float py = Game.BASE_Y - Game.POT_H * i;
            String potKey = "SNAKE" + col.potType[i] + col.potColor[i];
            Bitmap potBmp = img(potKey);
            if (potBmp == null && baseBmp != null) {
                // fallback: draw base sprite
                canvas.drawBitmap(baseBmp, col.x - baseBmp.getWidth() / 2f, py, paint);
            } else if (potBmp != null) {
                // draw first frame of pot sprite as static pot representation
                int pw = potBmp.getWidth() / 8;
                int ph = potBmp.getHeight();
                src.set(0, 0, pw, ph);
                dst.set(col.x - pw / 2f, py, col.x + pw / 2f, py + ph);
                canvas.drawBitmap(potBmp, src, dst, paint);
            }
        }

        // Draw lid if falling
        if (col.lidState == Game.L_FALL || col.lidState == Game.L_HELD) {
            Bitmap light = img("LIGHT1");
            if (light != null) {
                canvas.drawBitmap(light, col.x - light.getWidth() / 2f, col.lidY, paint);
            }
        }
    }

    private void drawUi(Canvas canvas) {
        // Draw score digits on the right margin area
        drawScoreDigits(canvas, game.score, 506, 150);
        drawScoreDigits(canvas, game.level, 506, 200);
        // Draw lives/hearts
        Bitmap heartBmp = img("HEARTS");
        if (heartBmp != null) {
            int hw = heartBmp.getWidth() / 4; // 4 states
            int hh = heartBmp.getHeight() / 3; // 3 slots
            for (int s = 0; s < 3; s++) {
                int inSlot = game.heartsIn(s);
                // Simplified: draw filled or empty heart
                int frame = inSlot > 0 ? 0 : 3;
                src.set(frame * hw, s * hh, (frame + 1) * hw, (s + 1) * hh);
                dst.set(HEART_X, HEART_Y0 + s * (hh + 4), HEART_X + hw, HEART_Y0 + s * (hh + 4) + hh);
                canvas.drawBitmap(heartBmp, src, dst, paint);
            }
        }
        // Draw parrot if active
        if (game.parrot) {
            int pf = game.parrotSprite();
            Bitmap parrot = img("PARROT" + pf);
            if (parrot != null) canvas.drawBitmap(parrot, HEART_X, HEART_Y0 + 90, paint);
        }
        // Draw old man if active
        if (game.oldMan) {
            int of = game.oldManSprite();
            Bitmap om = img("OLD_MAN" + of);
            if (om != null) canvas.drawBitmap(om, HEART_X - 20, HEART_Y0 + 160, paint);
        }
    }

    private void drawScoreDigits(Canvas canvas, int value, float x, float y) {
        String s = String.format(Locale.US, "%06d", Math.max(0, value) % 1000000);
        float dx = x;
        for (char c : s.toCharArray()) {
            Bitmap d = img("DIGIT_" + c);
            if (d != null) {
                canvas.drawBitmap(d, dx, y, paint);
                dx += d.getWidth() + 1;
            }
        }
    }

    private void drawButtons(Canvas canvas) {
        float bw = (W - 8f) / BUTTONS.length;
        text.setTextSize(15);
        text.setFakeBoldText(true);
        for (int i = 0; i < BUTTONS.length; i++) {
            float bx = 4 + i * bw;
            boolean down = buttonDown == i;
            fill.setColor(down ? 0xFF3A78C8 : 0xFF1C4C8C);
            canvas.drawRoundRect(bx + 2, BAR_Y, bx + bw - 2, BAR_Y + BAR_H, 8, 8, fill);
            String label = BUTTONS[i];
            if (i == B_PLAY && game.state == Game.State.PLAYING) label = "Pause";
            float tw = text.measureText(label);
            canvas.drawText(label, bx + bw / 2 - tw / 2, BAR_Y + BAR_H / 2f + 5, text);
        }
        text.setFakeBoldText(false);
    }

    private void drawTip(Canvas canvas) {
        if (tipText == null) return;
        fill.setColor(0xCC102040);
        canvas.drawRoundRect(60, 160, W - 60, 230, 10, 10, fill);
        text.setTextSize(14);
        float tw = text.measureText(tipText);
        canvas.drawText(tipText, (W - tw) / 2f, 202, text);
    }

    private Bitmap img(String name) {
        if (images.containsKey(name)) return images.get(name);
        BitmapFactory.Options o = new BitmapFactory.Options();
        o.inScaled = false;
        Bitmap b = null;
        try (InputStream in = getContext().getAssets().open("charmer/img/" + name + ".png")) {
            b = BitmapFactory.decodeStream(in, null, o);
        } catch (IOException ignored) {}
        images.put(name, b);
        return b;
    }

    // ---- touch ---------------------------------------------------------------------------

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        if (pad.onTouch(e, offsetX, offsetY, scale)) {
            invalidate();
            return true;
        }
        float x = (e.getX() - offsetX) / scale;
        float y = (e.getY() - offsetY) / scale;
        switch (e.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                if (tipText != null) {
                    tipText = null;
                    invalidate();
                    return true;
                }
                buttonDown = buttonAt(x, y);
                invalidate();
                return true;
            case MotionEvent.ACTION_UP:
                int b = buttonDown;
                buttonDown = -1;
                if (b >= 0 && buttonAt(x, y) == b) {
                    performClick();
                    pressButton(b);
                }
                invalidate();
                return true;
            case MotionEvent.ACTION_CANCEL:
                buttonDown = -1;
                invalidate();
                return true;
        }
        return true;
    }

    @Override
    public boolean performClick() {
        return super.performClick();
    }

    private int buttonAt(float x, float y) {
        if (y >= BAR_Y && y < BAR_Y + BAR_H) {
            float bw = (W - 8f) / BUTTONS.length;
            int i = (int) ((x - 4) / bw);
            if (i >= 0 && i < BUTTONS.length) return i;
        }
        return -1;
    }

    private void pressButton(int button) {
        CharmerActivity act = (CharmerActivity) getContext();
        switch (button) {
            case B_PLAY:
                if (game.state == Game.State.PLAYING) {
                    pauseGame();
                } else if (game.state == Game.State.PAUSED) {
                    resumeGame();
                } else {
                    startNewGame();
                }
                break;
            case B_NEW:
                if (game.state == Game.State.PLAYING || game.state == Game.State.PAUSED) {
                    pauseGame();
                    new AlertDialog.Builder(act)
                            .setTitle("Charmer")
                            .setMessage("This will start a new Charmer game.")
                            .setPositiveButton("OK", (d, w) -> startNewGame())
                            .setNegativeButton("Cancel", null)
                            .show();
                } else {
                    startNewGame();
                }
                break;
            case B_EXIT:
                pauseGame();
                act.exitToMenu();
                break;
        }
    }
}
