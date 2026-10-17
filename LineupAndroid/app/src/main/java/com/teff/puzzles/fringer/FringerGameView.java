package com.teff.puzzles.fringer;

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
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.ControlPad;
import com.teff.puzzles.common.GameAudio;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;

/**
 * Renders Fringer on its original 600x400 canvas scaled to fit the screen.
 * Arrow keys move the frame left/right; SPACE untwists the knot at the bar.
 */
final class FringerGameView extends View implements Game.Listener {
    // Logical canvas
    private static final int W = 600, H = 460;  // extra 60px for button bar
    private static final int BAR_Y = 410, BAR_H = 50;
    private static final String[] BUTTONS = {"Play", "New", "Brush", "Exit"};
    private static final int B_PLAY = 0, B_NEW = 1, B_BRUSH = 2, B_EXIT = 3;

    // Thread rope colors (one per THREAD*.png background palette)
    private static final int[] ROPE_COLORS = {
        0xFFCC2222, 0xFF2222CC, 0xFF22AA22, 0xFFCC8800,
        0xFF8822CC, 0xFF22CCCC, 0xFFCC22CC, 0xFF888800, 0xFF666666
    };
    private static final int KNOT_COLOR = 0xFFFFFFFF;
    private static final int BAR_LINE_COLOR = 0xFFFFFF00;
    private static final int FRAME_COLOR = 0xFFFFFFFF;

    private static final long FRAME_MS = 50;

    final Game game = new Game();
    private final GameAudio audio;
    private final SharedPreferences prefs;
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint textPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Handler handler = new Handler(Looper.getMainLooper());
    private final Rect src = new Rect();
    private final RectF dst = new RectF();

    private float scale = 1f, offsetX, offsetY;
    private boolean running;
    private long lastTick;

    // ControlPad for arrow keys + SPACE + TAB
    private final ControlPad pad;

    // Touch
    private int touchZone = -1;
    private long downAt;

    private final Runnable loop = new Runnable() {
        @Override
        public void run() {
            if (!running) return;
            long now = SystemClock.uptimeMillis();
            int ms = (int) Math.min(200, now - lastTick);
            lastTick = now;

            // Apply held keys
            if (pad.isDown(ControlPad.SPACE)) {
                game.pressSpace();
            }

            game.tick(ms);
            invalidate();
            handler.postDelayed(this, FRAME_MS);
        }
    };

    FringerGameView(Context ctx) {
        super(ctx);
        audio = new GameAudio(ctx, "fringer");
        prefs = ctx.getSharedPreferences("fringer", Context.MODE_PRIVATE);
        game.listener = this;
        game.difficulty = prefs.getInt("difficulty", 1);
        game.startLevel = prefs.getInt("startLevel", 1);

        // ControlPad: arrows + SPACE + TAB, placed below the game field
        pad = new ControlPad(new ControlPad.Listener() {
            @Override public void keyDown(int key) {
                switch (key) {
                    case ControlPad.LEFT:  game.moveLeft(); break;
                    case ControlPad.RIGHT: game.moveRight(); break;
                    case ControlPad.SPACE: game.pressSpace(); break;
                    case ControlPad.TAB:   game.pressTab(); break;
                }
            }
            @Override public void keyUp(int key) {}
        });
        float padY = Game.FIELD_H + 5;
        pad.addArrows(10, padY, 55, false);   // left/right only (no up/down)
        pad.add(ControlPad.SPACE, 180, padY + 55, 80, 50, "SPACE");
        pad.add(ControlPad.TAB,   270, padY + 55, 60, 50, "TAB");

        loadImages(ctx);
    }

    private void loadImages(Context ctx) {
        String[] names = {
            "img/TITLEBMP", "img/GAMEOVERBMP", "img/PAUSEBMP",
            "img/THREAD0", "img/THREAD1", "img/THREAD2", "img/THREAD3",
            "img/THREAD4", "img/THREAD5", "img/THREAD6", "img/THREAD7", "img/THREAD8"
        };
        for (String n : names) {
            try (InputStream in = ctx.getAssets().open("fringer/" + n + ".png")) {
                images.put(n, BitmapFactory.decodeStream(in));
            } catch (IOException ignored) {}
        }
    }

    void onHostResume() {
        if (!running) {
            running = true;
            lastTick = SystemClock.uptimeMillis();
            if (game.state == Game.State.TITLE) {
                game.newGame();
            }
            handler.post(loop);
        }
    }

    void onHostPause() {
        running = false;
        handler.removeCallbacks(loop);
        if (game.state == Game.State.PLAYING) {
            game.state = Game.State.PAUSED;
        }
        audio.stopMusic();
    }

    void release() {
        running = false;
        handler.removeCallbacks(loop);
        audio.release();
    }

    @Override
    protected void onSizeChanged(int w, int h, int ow, int oh) {
        float sx = (float) w / W, sy = (float) h / H;
        scale = Math.min(sx, sy);
        offsetX = (w - W * scale) / 2f;
        offsetY = (h - H * scale) / 2f;
    }

    @Override
    protected void onDraw(Canvas c) {
        c.drawColor(Color.BLACK);
        c.save();
        c.translate(offsetX, offsetY);
        c.scale(scale, scale);

        Game.State st = game.state;
        if (st == Game.State.TITLE) {
            drawBitmap(c, "img/TITLEBMP", 0, 0, W, Game.FIELD_H);
        } else if (st == Game.State.OVER) {
            drawBitmap(c, "img/GAMEOVERBMP", 0, 0, W, Game.FIELD_H);
        } else {
            drawPlayField(c);
        }
        drawButtonBar(c);
        pad.draw(c);
        c.restore();
    }

    private void drawPlayField(Canvas c) {
        // Background: use thread0 as base background
        drawBitmap(c, "img/THREAD0", 0, 0, W, Game.FIELD_H);

        // Draw each rope as a vertical line
        for (int col = 0; col < game.numRopes; col++) {
            Game.Rope rope = game.ropes[col];
            if (!rope.present) continue;
            int rx = game.ropeX(col);
            int color = ROPE_COLORS[rope.color % ROPE_COLORS.length];
            fill.setColor(color);
            fill.setStrokeWidth(4);
            fill.setStyle(Paint.Style.FILL);
            c.drawRect(rx - 2, Game.ROPE_TOP, rx + 2, Game.ROPE_BOTTOM, fill);

            // Draw knots as X shapes
            for (Game.Knot k : rope.knots) {
                int ky = game.knotAbsY(k);
                drawKnot(c, rx, ky, color, col == game.frameCol);
            }
        }

        // Draw bar (horizontal line across field)
        fill.setColor(BAR_LINE_COLOR);
        fill.setStrokeWidth(3);
        c.drawLine(30, game.barAbsY(), W - 30, game.barAbsY(), fill);

        // Draw frame cursor (highlight around current column)
        int fx = game.ropeX(game.frameCol);
        fill.setColor(FRAME_COLOR);
        fill.setStyle(Paint.Style.STROKE);
        fill.setStrokeWidth(2);
        c.drawRect(fx - 15, game.barAbsY() - 20, fx + 15, game.barAbsY() + 20, fill);
        fill.setStyle(Paint.Style.FILL);

        // HUD: score, lives, level, bonuses
        textPaint.setColor(Color.WHITE);
        textPaint.setTextSize(18);
        c.drawText("Lvl " + game.level, 10, 20, textPaint);
        c.drawText("Score: " + game.score, 200, 20, textPaint);
        c.drawText("Lives: " + game.lives, 420, 20, textPaint);
        if (game.sparkle > 0) {
            textPaint.setColor(Color.YELLOW);
            c.drawText("*" + game.sparkle, 520, 20, textPaint);
        }
        if (game.brush > 0) {
            textPaint.setColor(Color.CYAN);
            c.drawText("B" + game.brush, 550, 20, textPaint);
        }

        // Pause overlay
        if (game.state == Game.State.PAUSED) {
            drawBitmap(c, "img/PAUSEBMP", 0, 0, W, Game.FIELD_H);
        }
    }

    private void drawKnot(Canvas c, int x, int y, int ropeColor, boolean atFrame) {
        int size = atFrame ? 14 : 10;
        int kColor = atFrame ? Color.WHITE : ropeColor;
        fill.setColor(kColor);
        fill.setStyle(Paint.Style.FILL);
        // Draw as a diamond
        android.graphics.Path path = new android.graphics.Path();
        path.moveTo(x, y - size);
        path.lineTo(x + size, y);
        path.lineTo(x, y + size);
        path.lineTo(x - size, y);
        path.close();
        c.drawPath(path, fill);
        fill.setColor(Color.BLACK);
        fill.setStyle(Paint.Style.STROKE);
        fill.setStrokeWidth(2);
        c.drawPath(path, fill);
        fill.setStyle(Paint.Style.FILL);
    }

    private void drawBitmap(Canvas c, String key, float x, float y, float w, float h) {
        Bitmap bm = images.get(key);
        if (bm == null) return;
        src.set(0, 0, bm.getWidth(), bm.getHeight());
        dst.set(x, y, x + w, y + h);
        c.drawBitmap(bm, src, dst, paint);
    }

    private void drawButtonBar(Canvas c) {
        fill.setColor(0xFF222244);
        c.drawRect(0, BAR_Y, W, BAR_Y + BAR_H, fill);
        float btnW = W / (float) BUTTONS.length;
        textPaint.setTextSize(20);
        textPaint.setTextAlign(Paint.Align.CENTER);
        for (int i = 0; i < BUTTONS.length; i++) {
            float cx = btnW * i + btnW / 2;
            float cy = BAR_Y + BAR_H / 2 + 7;
            boolean active = (i == B_PLAY && game.state == Game.State.PLAYING);
            fill.setColor(active ? 0xFF334466 : 0xFF2A2A2A);
            c.drawRoundRect(btnW * i + 4, BAR_Y + 4, btnW * (i + 1) - 4, BAR_Y + BAR_H - 4, 6, 6, fill);
            textPaint.setColor(i == B_EXIT ? 0xFFFF6666 : Color.WHITE);
            c.drawText(BUTTONS[i], cx, cy, textPaint);
        }
        textPaint.setTextAlign(Paint.Align.LEFT);
    }

    // ---- touch ----

    @Override
    public boolean onTouchEvent(MotionEvent ev) {
        float lx = (ev.getX() - offsetX) / scale;
        float ly = (ev.getY() - offsetY) / scale;

        if (pad.onTouch(ev, offsetX, offsetY, scale)) return true;

        if (ev.getActionMasked() == MotionEvent.ACTION_DOWN) {
            downAt = SystemClock.uptimeMillis();
            if (ly >= BAR_Y) {
                // Button bar tap
                int btn = (int)(lx / (W / (float) BUTTONS.length));
                touchZone = btn;
            }
        } else if (ev.getActionMasked() == MotionEvent.ACTION_UP) {
            long dur = SystemClock.uptimeMillis() - downAt;
            if (touchZone >= 0 && dur < 500) {
                handleButton(touchZone);
            }
            touchZone = -1;
        }
        return true;
    }

    private void handleButton(int b) {
        switch (b) {
            case B_PLAY:
                if (game.state == Game.State.PLAYING) {
                    game.state = Game.State.PAUSED;
                } else if (game.state == Game.State.PAUSED || game.state == Game.State.TITLE) {
                    game.state = Game.State.PLAYING;
                }
                break;
            case B_NEW:
                confirmNew();
                break;
            case B_BRUSH:
                game.pressBrush();
                break;
            case B_EXIT:
                exitToMenu();
                break;
        }
    }

    private void confirmNew() {
        new AlertDialog.Builder(getContext())
            .setTitle("Fringer")
            .setMessage("This will start a new Fringer game.")
            .setPositiveButton("OK", (d, w) -> game.newGame())
            .setNegativeButton("Cancel", null)
            .show();
    }

    private void exitToMenu() {
        if (getContext() instanceof com.teff.puzzles.common.BaseGameActivity) {
            ((com.teff.puzzles.common.BaseGameActivity) getContext()).exitToMenu();
        }
    }

    // ---- Game.Listener ----

    @Override
    public void sound(String name) {
        audio.play(name);
    }

    @Override
    public void tip(int kind) { /* tips not implemented */ }

    @Override
    public void levelDone(int score) {
        audio.play("NEWLEVELWAV");
    }

    @Override
    public void gameOver(int score) {
        saveScore(score);
    }

    private void saveScore(int score) {
        int best = prefs.getInt("best", 0);
        if (score > best) {
            prefs.edit().putInt("best", score).apply();
        }
    }
}
