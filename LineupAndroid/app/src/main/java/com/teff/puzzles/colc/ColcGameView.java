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

import com.teff.puzzles.common.GameAudio;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

/**
 * Draws Color Collision on a 600×520 logical canvas (600×400 field + 120px button bar).
 * Each arrow key press nudges the collider's velocity in that direction.
 */
final class ColcGameView extends View implements Game.Listener {

    // Logical layout
    private static final int W = 600, H = 520;
    private static final int FIELD_TOP = 0, FIELD_H = 400;
    private static final int BAR_Y = 405, BAR_H = 44, BAR_PAD = 6;
    private static final int FRAME_MS = 50;

    // Button indices
    private static final int B_PLAY = 0, B_NEW = 1, B_HELP = 2, B_EXIT = 3;
    private static final String[] BUTTONS = {"Play", "New", "Help", "Exit"};

    // On-screen arrow zones (bottom-right quadrant of field)
    private static final int ARROW_SIZE = 56;
    private static final int AX = W - ARROW_SIZE * 3 - 8, AY = FIELD_H - ARROW_SIZE * 3 - 8;

    // Sprite IDs: 1000-1005 = collider ball per colour; 1007-1036 = circle rings (colour*5+size)
    private static final int SPR_BALL_BASE  = 1000;
    private static final int SPR_RING_BASE  = 1007;   // size 0 = 132px, the largest
    private static final int SPR_RING_SIZES = 5;

    final Game game = new Game();
    private final GameAudio audio;
    private final SharedPreferences prefs;
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Paint paint   = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint fill    = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint textP   = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Handler handler = new Handler(Looper.getMainLooper());
    private final RectF dst = new RectF();

    private float scale = 1f, offsetX, offsetY;
    private boolean running;
    private long lastFrame;
    private int song;

    // Colour table matching the 6 sprite colour groups (R, orange, yellow, G, B, purple)
    private static final int[] COLORS = {
        0xFFE03030, 0xFFE08020, 0xFFD0C020, 0xFF30C030, 0xFF3090E0, 0xFFA040E0
    };

    private String tip;

    private final Runnable loop = new Runnable() {
        @Override public void run() {
            long now = SystemClock.uptimeMillis();
            int ms = (int) Math.min(500, now - lastFrame);
            lastFrame = now;
            if (tip == null) game.tick(ms);
            invalidate();
            handler.postDelayed(this, FRAME_MS);
        }
    };

    ColcGameView(Context context) {
        super(context);
        prefs = context.getSharedPreferences("colc", Context.MODE_PRIVATE);
        audio = new GameAudio(context, "colc");
        game.listener = this;
        textP.setColor(Color.WHITE);
        textP.setTextSize(18f);
        loadOptions();
        setFocusable(true);
        setFocusableInTouchMode(true);
    }

    // ---- lifecycle ---------------------------------------------------------------------------

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
    }

    void release() {
        handler.removeCallbacks(loop);
        audio.release();
    }

    void loadOptions() {
        game.difficulty  = prefs.getInt("difficulty", 1);
        game.startLevel  = prefs.getInt("startLevel", 1);
        audio.musicOn    = prefs.getBoolean("music", true);
        audio.soundOn    = prefs.getBoolean("sound", true);
    }

    void startNewGame() {
        loadOptions();
        game.newGame();
        song ^= 1;
        audio.startMusic("MIDIGAME" + (song + 1));
        invalidate();
    }

    private void pauseGame() {
        if (game.state == Game.State.PLAYING) {
            game.state = Game.State.PAUSED;
            audio.pauseMusic();
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

    // ---- Game.Listener -----------------------------------------------------------------------

    @Override public void sound(int id) { audio.play(String.valueOf(id)); }

    @Override public void tip(int kind) {
        // tips not shown this build
    }

    @Override public void levelDone(int score) {
        tip = "Level " + game.level + " done!  Score: " + score + "\n\nTap Play to continue.";
    }

    @Override public void gameOver(int score) {
        audio.stopMusic();
        tip = "Game Over\n\nFinal score: " + score + "\n\nTap Play to play again.";
    }

    // ---- drawing -----------------------------------------------------------------------------

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        scale   = Math.min(w / (float) W, h / (float) H);
        offsetX = (w - W * scale) / 2f;
        offsetY = (h - H * scale) / 2f;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(0xFF101010);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);

        drawField(canvas);
        drawCircles(canvas);
        drawBall(canvas);
        drawHUD(canvas);
        drawArrows(canvas);
        drawButtons(canvas);

        if (game.state == Game.State.PAUSED)  drawOverlay(canvas, "PAUSED");
        if (game.state == Game.State.TITLE)   drawOverlay(canvas, "Tap Play to start");
        if (tip != null)                      drawTip(canvas);

        canvas.restore();
    }

    private void drawField(Canvas canvas) {
        // Background: use LEVEL0N.png for current level
        String bg = "LEVEL" + String.format(Locale.US, "%02d", Math.max(1, Math.min(10, game.level)));
        Bitmap b = imgAsset("colc/img/" + bg + ".png");
        if (b != null) {
            dst.set(0, 0, W, FIELD_H);
            canvas.drawBitmap(b, null, dst, paint);
        } else {
            fill.setColor(0xFF1A1A40);
            canvas.drawRect(0, 0, W, FIELD_H, fill);
        }
    }

    private void drawCircles(Canvas canvas) {
        for (Game.Circle c : game.circles) {
            if (c.state == Game.CS_GONE) continue;
            if (c.state == Game.CS_FLASH) {
                // Draw flashing white ring
                fill.setColor(0x80FFFFFF);
                canvas.drawCircle(c.x, c.y, Game.CIRCLE_R, fill);
                continue;
            }
            int sprId = SPR_RING_BASE + c.color * SPR_RING_SIZES;
            Bitmap b = spriteImg(sprId);
            if (b != null) {
                float hw = b.getWidth() / 2f, hh = b.getHeight() / 2f;
                dst.set(c.x - hw, c.y - hh, c.x + hw, c.y + hh);
                if (c.state == Game.CS_STICK) {
                    // Tint grey to show it's a stick
                    paint.setColorFilter(new android.graphics.ColorMatrixColorFilter(
                            new android.graphics.ColorMatrix(new float[]{
                                    0.4f,0.4f,0.4f,0,0,
                                    0.4f,0.4f,0.4f,0,0,
                                    0.4f,0.4f,0.4f,0,0,
                                    0,0,0,1,0})));
                    canvas.drawBitmap(b, null, dst, paint);
                    paint.setColorFilter(null);
                } else {
                    canvas.drawBitmap(b, null, dst, paint);
                }
            } else {
                // Fallback: coloured ring using Paint
                fill.setStyle(Paint.Style.STROKE);
                fill.setStrokeWidth(8);
                fill.setColor(c.state == Game.CS_STICK ? 0xFF808080 : COLORS[c.color]);
                canvas.drawCircle(c.x, c.y, Game.CIRCLE_R, fill);
                fill.setStyle(Paint.Style.FILL);
            }
        }
    }

    private void drawBall(Canvas canvas) {
        if (game.state == Game.State.TITLE) return;
        int sprId = SPR_BALL_BASE + game.ballColor;
        Bitmap b = spriteImg(sprId);
        if (b != null) {
            float hw = b.getWidth() / 2f, hh = b.getHeight() / 2f;
            dst.set(game.bx - hw, game.by - hh, game.bx + hw, game.by + hh);
            canvas.drawBitmap(b, null, dst, paint);
        } else {
            fill.setColor(COLORS[game.ballColor]);
            canvas.drawCircle(game.bx, game.by, Game.BALL_R, fill);
        }
    }

    private void drawHUD(Canvas canvas) {
        // Dark strip at bottom of field for score/lives/level
        fill.setColor(0xCC000000);
        canvas.drawRect(0, FIELD_H - 30, W, FIELD_H, fill);

        textP.setTextSize(18f);
        textP.setColor(Color.WHITE);
        canvas.drawText("Score: " + game.score, 10, FIELD_H - 10, textP);
        canvas.drawText("Level: " + game.level, 220, FIELD_H - 10, textP);
        StringBuilder lives = new StringBuilder("Lives: ");
        for (int i = 0; i < game.lives; i++) lives.append('●');
        canvas.drawText(lives.toString(), 430, FIELD_H - 10, textP);
    }

    private void drawArrows(Canvas canvas) {
        if (game.state != Game.State.PLAYING) return;
        int s = ARROW_SIZE;
        int[][] defs = {
                {s, 0, s, Game.KEY_UP,    "▲"},    // up
                {0, s, s, Game.KEY_LEFT,  "◄"},    // left
                {s*2,s, s, Game.KEY_RIGHT,"►"},    // right
                {s, s*2,s, Game.KEY_DOWN, "▼"},    // down
        };
        for (int[] d : defs) {
            float x = AX + d[0], y = AY + d[1];
            fill.setColor(0x80203060);
            canvas.drawRoundRect(x, y, x + s, y + s, 8, 8, fill);
            textP.setTextSize(22f);
            textP.setTextAlign(Paint.Align.CENTER);
            canvas.drawText(d[4], x + s / 2f, y + s / 2f + 8, textP);
            textP.setTextAlign(Paint.Align.LEFT);
        }
    }

    private void drawButtons(Canvas canvas) {
        float bw = (W - BAR_PAD * 2f) / BUTTONS.length;
        textP.setTextSize(16f);
        textP.setFakeBoldText(true);
        for (int i = 0; i < BUTTONS.length; i++) {
            float x = BAR_PAD + i * bw;
            fill.setColor(0xFF1C4C8C);
            canvas.drawRoundRect(x + 2, BAR_Y, x + bw - 2, BAR_Y + BAR_H, 8, 8, fill);
            String label = BUTTONS[i];
            if (i == B_PLAY && game.state == Game.State.PLAYING) label = "Pause";
            textP.setTextAlign(Paint.Align.CENTER);
            canvas.drawText(label, x + bw / 2f, BAR_Y + BAR_H / 2f + 6, textP);
            textP.setTextAlign(Paint.Align.LEFT);
        }
        textP.setFakeBoldText(false);
    }

    private void drawOverlay(Canvas canvas, String msg) {
        fill.setColor(0xC0000000);
        canvas.drawRect(0, 0, W, FIELD_H, fill);
        Bitmap b = (game.state == Game.State.PAUSED) ? imgAsset("colc/img/PAUSEBMP.png")
                : imgAsset("colc/img/TITLEBMP.png");
        if (b != null) {
            float x = (W - b.getWidth()) / 2f, y = (FIELD_H - b.getHeight()) / 2f;
            canvas.drawBitmap(b, x, y, paint);
        } else {
            textP.setTextSize(36f);
            textP.setTextAlign(Paint.Align.CENTER);
            textP.setColor(Color.WHITE);
            canvas.drawText(msg, W / 2f, FIELD_H / 2f, textP);
            textP.setTextAlign(Paint.Align.LEFT);
        }
    }

    private void drawTip(Canvas canvas) {
        if (tip == null) return;
        fill.setColor(0xF0102040);
        canvas.drawRoundRect(40, 80, W - 40, FIELD_H - 80, 14, 14, fill);
        fill.setStyle(Paint.Style.STROKE);
        fill.setStrokeWidth(2);
        fill.setColor(0xFF7FB2FF);
        canvas.drawRoundRect(40, 80, W - 40, FIELD_H - 80, 14, 14, fill);
        fill.setStyle(Paint.Style.FILL);
        textP.setColor(Color.WHITE);
        textP.setTextSize(18f);
        float y = 120;
        for (String line : tip.split("\n", -1)) {
            canvas.drawText(line, 60, y, textP);
            y += 26;
        }
        textP.setTextSize(14f);
        textP.setColor(0xFFAAAAAA);
        canvas.drawText("(Tap to continue)", 60, FIELD_H - 98, textP);
        textP.setColor(Color.WHITE);
    }

    // ---- assets ------------------------------------------------------------------------------

    private Bitmap spriteImg(int id) {
        return imgAsset("colc/spr/" + id + ".png");
    }

    private Bitmap imgAsset(String path) {
        if (images.containsKey(path)) return images.get(path);
        BitmapFactory.Options o = new BitmapFactory.Options();
        o.inScaled = false;
        Bitmap b = null;
        try (InputStream in = getContext().getAssets().open(path)) {
            b = BitmapFactory.decodeStream(in, null, o);
        } catch (IOException ignored) {}
        images.put(path, b);
        return b;
    }

    // ---- input -------------------------------------------------------------------------------

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        if (e.getActionMasked() != MotionEvent.ACTION_DOWN) return true;
        float lx = (e.getX() - offsetX) / scale;
        float ly = (e.getY() - offsetY) / scale;

        if (tip != null) { tip = null; invalidate(); return true; }

        // Arrow pad
        if (game.state == Game.State.PLAYING && ly < FIELD_H) {
            int key = arrowAt(lx, ly);
            if (key != -1) { game.pressKey(key); invalidate(); return true; }
        }

        // Button bar
        if (ly >= BAR_Y && ly < BAR_Y + BAR_H) {
            float bw = (W - BAR_PAD * 2f) / BUTTONS.length;
            int b = (int) ((lx - BAR_PAD) / bw);
            if (b >= 0 && b < BUTTONS.length) {
                pressButton(b);
                performClick();
                return true;
            }
        }
        return true;
    }

    @Override public boolean performClick() { return super.performClick(); }

    private int arrowAt(float x, float y) {
        int s = ARROW_SIZE;
        int[][] defs = {
                {s, 0, s, Game.KEY_UP},
                {0, s, s, Game.KEY_LEFT},
                {s*2, s, s, Game.KEY_RIGHT},
                {s, s*2, s, Game.KEY_DOWN},
        };
        for (int[] d : defs) {
            float bx = AX + d[0], by = AY + d[1];
            if (x >= bx && x < bx + d[2] && y >= by && y < by + d[2]) return d[3];
        }
        return -1;
    }

    private void pressButton(int b) {
        ColcActivity act = (ColcActivity) getContext();
        switch (b) {
            case B_PLAY:
                if (game.state == Game.State.PLAYING) pauseGame();
                else if (game.state == Game.State.PAUSED) resumeGame();
                else startNewGame();
                break;
            case B_NEW:
                if (game.state == Game.State.PLAYING || game.state == Game.State.PAUSED) {
                    pauseGame();
                    new AlertDialog.Builder(act)
                            .setTitle("Color Collision")
                            .setMessage("Start a new game?")
                            .setPositiveButton("OK",     (d, w) -> startNewGame())
                            .setNegativeButton("Cancel", null)
                            .show();
                } else { startNewGame(); }
                break;
            case B_HELP:
                pauseGame();
                Bitmap hb = imgAsset("colc/img/QUICKHELPBMP.png");
                if (hb != null) {
                    tip = "Hit circles that match the collider colour.\n"
                        + "Wrong colour turns a circle into a stick.\n"
                        + "Hitting a wrong-colour stick costs a life.\n"
                        + "Use arrows (or hardware keys) to steer.\n"
                        + "Collect all circles to complete the level.";
                } else {
                    tip = "Hit same-colour circles to collect them.\nWrong colour = stick, stick hit = lose life.";
                }
                break;
            case B_EXIT:
                pauseGame();
                act.exitToMenu();
                break;
        }
        invalidate();
    }
}
