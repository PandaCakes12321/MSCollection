package com.teff.puzzles.fflush;

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
import android.text.Layout;
import android.text.StaticLayout;
import android.text.TextPaint;
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.GameAudio;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

/**
 * Draws Finty Flush with the original art on its 614x295 window layout (plus a button bar),
 * scaled to fit the screen, and turns taps into the original mouse clicks.
 */
final class GameView extends View implements Game.Listener {
    // Logical layout in original pixels: the 614x295 game window, then a button bar.
    private static final int W = 614, H = 345;
    private static final int BAR_Y = 301, BAR_H = 40;
    private static final String[] BUTTONS = {"Play", "New", "Options", "Scores", "Help", "Exit"};
    private static final int B_PLAY = 0, B_NEW = 1, B_OPTIONS = 2, B_SCORES = 3, B_HELP = 4, B_EXIT = 5;

    // Touch zones (generous versions of the original click rectangles in FUN_0040b281).
    private static final int UPPER_TOP = 10, UPPER_BOTTOM = 157;
    private static final int DROP_LEFT = Game.DROP_X - 16, DROP_RIGHT = Game.DROP_X + 36;
    private static final int LOWER_LEFT = 216, LOWER_RIGHT = 398, LOWER_BOTTOM = 296;

    private static final int Z_NONE = 0, Z_UP_LEFT = 1, Z_UP_RIGHT = 2, Z_LO_LEFT = 3, Z_LO_RIGHT = 4,
            Z_ROTATE = 5, Z_DROP = 6, Z_GRID = 7, Z_BUTTON = 8;
    private static final long REPEAT_DELAY = 400, REPEAT_EVERY = 100, LONG_PRESS = 450;
    private static final int FRAME_MS = 30;

    final Game game = new Game();
    private final GameAudio audio;
    private final SharedPreferences prefs;
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint fx = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final TextPaint text = new TextPaint(Paint.ANTI_ALIAS_FLAG);
    private final Handler handler = new Handler(Looper.getMainLooper());
    private final Rect src = new Rect();
    private final RectF dst = new RectF();

    private float scale = 1f, offsetX, offsetY;
    private boolean running;
    private long lastFrame;
    private boolean tipsOn = true;
    private final boolean[] tipShown = new boolean[8];
    private int song;

    // Slide/drop animation offsets (logical px, decay to 0).
    private float upperShift, gapShift, lowerShift;
    private int gapIndex;
    private int[] fallBalls;
    private long fallStart;
    private int[][] doneBalls;
    private long doneStart;
    private String banner;
    private long bannerUntil;

    // Touch state
    private int zone = Z_NONE, zoneArg, downArg;
    private long downAt, nextRepeat;
    private boolean longFired;
    private float touchX, touchY;

    private String tip;

    private final Runnable loop = new Runnable() {
        @Override
        public void run() {
            long now = SystemClock.uptimeMillis();
            int ms = (int) Math.min(200, now - lastFrame);
            lastFrame = now;
            if (tip == null) {
                game.tick(ms);
            }
            holdRepeat(now);
            decay(ms);
            invalidate();
            handler.postDelayed(this, FRAME_MS);
        }
    };

    GameView(Context context) {
        super(context);
        prefs = context.getSharedPreferences("fflush", Context.MODE_PRIVATE);
        audio = new GameAudio(context, "fflush");
        game.listener = this;
        text.setColor(Color.WHITE);
        loadOptions();
        if (!prefs.getBoolean("seenHelp", false)) {
            tip = Tips.QUICK_HELP;
            prefs.edit().putBoolean("seenHelp", true).apply();
        }
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
        game.difficulty = prefs.getInt("difficulty", 1);
        game.startLevel = prefs.getInt("startLevel", 1);
        audio.musicOn = prefs.getBoolean("music", true);
        audio.soundOn = prefs.getBoolean("sound", true);
        tipsOn = prefs.getBoolean("tips", true);
    }

    void optionsChanged() {
        loadOptions();
        if (!audio.musicOn) {
            audio.stopMusic();
        }
    }

    void startNewGame() {
        loadOptions();
        java.util.Arrays.fill(tipShown, false);
        upperShift = gapShift = lowerShift = 0;
        fallBalls = null;
        doneBalls = null;
        game.newGame();
        // The original alternates its two game songs from one new game to the next.
        song ^= 1;
        audio.startMusic(song == 0 ? "MIDIGAME1" : "MIDIGAME2");
        invalidate();
    }

    void pauseGame() {
        if (game.state == Game.State.PLAYING) {
            game.state = Game.State.PAUSED;
            audio.pauseMusic();
            invalidate();
        }
    }

    private void resumeGame() {
        if (game.state == Game.State.PAUSED) {
            game.state = Game.State.PLAYING;
            if (audio.musicOn && !audio.hasMusic()) {
                audio.startMusic(song == 0 ? "MIDIGAME1" : "MIDIGAME2");
            } else {
                audio.resumeMusic();
            }
            invalidate();
        }
    }

    // ---- Game.Listener -----------------------------------------------------------------------

    @Override
    public void sound(String name) {
        audio.play(name);
    }

    @Override
    public void tip(int kind) {
        if (tipsOn && kind < tipShown.length && !tipShown[kind]) {
            tipShown[kind] = true;
            tip = Tips.forKind(kind);
        }
    }

    @Override
    public void dropped(int[] balls, int lowerCol) {
        fallBalls = balls;
        fallStart = SystemClock.uptimeMillis();
    }

    @Override
    public void gridCompleted(int grid, int[][] balls, boolean levelUp) {
        doneBalls = balls;
        doneStart = SystemClock.uptimeMillis();
        if (levelUp) {
            banner = "Level " + (game.level + 1) + "!";
            bannerUntil = doneStart + 2000;
        }
    }

    @Override
    public void gameOver(int score) {
        audio.stopMusic();
        handler.post(() -> Dialogs.checkHighScore((FflushActivity) getContext(), score));
    }

    // ---- animation helpers -------------------------------------------------------------------

    private void decay(int ms) {
        float k = (float) Math.pow(0.80, ms / 16.0);
        upperShift = Math.abs(upperShift) < 0.5f ? 0 : upperShift * k;
        gapShift = Math.abs(gapShift) < 0.5f ? 0 : gapShift * k;
        lowerShift = Math.abs(lowerShift) < 0.5f ? 0 : lowerShift * k;
    }

    private void doSlideUpper(boolean left) {
        if (left ? game.slideUpperLeft() : game.slideUpperRight()) {
            upperShift += left ? 20 : -20;
        }
    }

    private void doSlideLower(boolean left) {
        if (left ? game.slideLowerLeft() : game.slideLowerRight()) {
            lowerShift += left ? 20 : -20;
        }
    }

    private void doDrop() {
        int base = game.base, hl = game.hl, level = game.level;
        if (game.drop()) {
            if (game.level != level || game.state != Game.State.PLAYING) {
                return;
            }
            if (game.base != base && game.count > 0) {
                upperShift += 20;               // dropped the left-most column: grid moved left
            } else if (game.base == base) {
                gapIndex = hl;                  // columns to the left close the gap
                gapShift = -20;
            }
        }
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
        canvas.drawColor(0xFF06152E);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);
        draw(canvas, "BACK", 0, 0);
        drawStrip(canvas);
        boolean live = game.state == Game.State.PLAYING;
        if (live || game.state == Game.State.TITLE) {
            drawUpper(canvas);
            drawLower(canvas);
        }
        drawMiniGrids(canvas);
        drawNumbers(canvas);
        if (game.state == Game.State.PAUSED || game.state == Game.State.OVER) {
            draw(canvas, game.state == Game.State.PAUSED ? "BREAKBMP" : "GAMEOVERBMP", 16, 16);
            draw(canvas, "BREAKBMP1", 216, 157);
            draw(canvas, "BREAKBMP2", 297, 137);
        }
        if (live) {
            drawEffects(canvas);
        }
        if (game.state == Game.State.TITLE) {
            drawCenterText(canvas, "Tap Play to start", 16, 60, 581);
        }
        if (banner != null && SystemClock.uptimeMillis() < bannerUntil) {
            drawCenterText(canvas, banner, 16, 60, 581);
        }
        drawButtons(canvas);
        drawTip(canvas);
        canvas.restore();
    }

    private void drawStrip(Canvas canvas) {
        String lvl = "LEVEL" + (game.state == Game.State.TITLE
                ? 1 + Math.floorMod(game.startLevel, 4) : game.backgroundIndex());
        blit(canvas, lvl, 0, 0, 581, 121, 16, 16);
        blit(canvas, lvl, 763, 0, 20, 22, 297, 137);
        blit(canvas, lvl, 581, 0, 182, 121, 216, 157);
    }

    private void drawUpper(Canvas canvas) {
        canvas.save();
        canvas.clipRect(17, 16, 597, 137);
        boolean focus = game.upperFocus;
        for (int i = 0; i < game.count; i++) {
            float x = game.base - 20 * i + upperShift + (i >= gapIndex ? gapShift : 0);
            for (int r = 0; r < 4; r++) {
                int v = game.upper[i][r];
                float y = Game.UPPER_Y + 20 * r;
                if (i == game.hl) {
                    blit(canvas, "LIGHTED", focus ? 0 : 20, v * 20, 20, 20, x, y);
                } else {
                    blit(canvas, "SHEET", focus ? 481 : 501, v * 20, 20, 20, x, y);
                }
            }
        }
        canvas.restore();
    }

    private void drawLower(Canvas canvas) {
        canvas.save();
        canvas.clipRect(216, 157, 398, 278);
        boolean focus = !game.upperFocus;
        float gx = game.gridX() + lowerShift;
        int frame = game.rotFrame();
        blit(canvas, "SHEET", frame * 120, focus ? 0 : 120, 120, 120, gx, Game.GRID_Y);
        if (!game.rotating()) {
            int[][] g = game.lower[game.current];
            for (int c = 0; c < 4; c++) {
                for (int r = 0; r < 4; r++) {
                    float x = gx + 20 + 20 * c, y = Game.GRID_Y + 20 + 20 * r;
                    if (c == game.lowerCol) {
                        blit(canvas, "LIGHTED", focus ? 0 : 20, g[c][r] * 20, 20, 20, x, y);
                    } else {
                        blit(canvas, "SHEET", focus ? 481 : 501, g[c][r] * 20, 20, 20, x, y);
                    }
                }
            }
        }
        canvas.restore();
    }

    /** FUN_0040657c: the four small grids, the current one drawn lighter. */
    private void drawMiniGrids(Canvas canvas) {
        for (int g = 0; g < 4; g++) {
            float ox = 153 + ((g == 1 || g == 2) ? 256 : 0), oy = 158 + (g >= 2 ? 67 : 0);
            int sy = g == game.current && game.state != Game.State.TITLE ? 215 : 228;
            for (int c = 0; c < 4; c++) {
                for (int r = 0; r < 4; r++) {
                    blit(canvas, "SHEET", 481 + 13 * game.lower[g][c][r], sy, 13, 13, ox + 13 * c, oy + 13 * r);
                }
            }
        }
    }

    private void drawNumbers(Canvas canvas) {
        boolean title = game.state == Game.State.TITLE;
        drawDigits(canvas, title ? game.startLevel : game.level, 2, 101, 157);
        drawDigits(canvas, title ? Game.gridsForLevel(game.startLevel) : game.toGo, 2, 101, 203);
        drawDigits(canvas, game.bonus, 2, 101, 249);
        drawDigits(canvas, game.square[game.current], 5, 500, 187);
        drawDigits(canvas, game.score, 5, 500, 250);
    }

    /** FUN_00407bb3: 18x25 LCD digits, leading zeros shown like the original. */
    private void drawDigits(Canvas canvas, int value, int n, float x, float y) {
        int mod = n == 2 ? 100 : 100000;
        String s = String.format(Locale.US, n == 2 ? "%02d" : "%05d", Math.max(0, value) % mod);
        for (int i = 0; i < n; i++) {
            blit(canvas, "DIGITS", (s.charAt(i) - '0') * 18, 0, 18, 25, x + 18 * i, y);
        }
    }

    private void drawEffects(Canvas canvas) {
        long now = SystemClock.uptimeMillis();
        if (fallBalls != null) {
            float t = (now - fallStart) / 220f;
            if (t >= 1f) {
                fallBalls = null;
            } else {
                float y0 = Game.UPPER_Y + t * (Game.GRID_Y + 20 - Game.UPPER_Y);
                fx.setAlpha((int) (255 * (1f - t * 0.6f)));
                for (int r = 0; r < 4; r++) {
                    if (fallBalls[r] != 0) {
                        blitFx(canvas, "SHEET", 481, fallBalls[r] * 20, 20, 20, Game.DROP_X, y0 + 20 * r);
                    }
                }
            }
        }
        if (doneBalls != null) {
            float t = (now - doneStart) / 900f;
            if (t >= 1f) {
                doneBalls = null;
            } else {
                // The full grid shrinks away (the original squeezes it out of view).
                float s = 1f - t;
                float cx = game.gridX() + 60, cy = Game.GRID_Y + 60;
                fx.setAlpha((int) (255 * Math.min(1f, 2f * s)));
                for (int c = 0; c < 4; c++) {
                    for (int r = 0; r < 4; r++) {
                        float x = cx + (-40 + 20 * c) * s, y = cy + (-40 + 20 * r) * s;
                        src.set(481, doneBalls[c][r] * 20, 501, doneBalls[c][r] * 20 + 20);
                        dst.set(x, y, x + 20 * s, y + 20 * s);
                        Bitmap b = image("SHEET");
                        if (b != null) {
                            canvas.drawBitmap(b, src, dst, fx);
                        }
                    }
                }
            }
        }
    }

    private void drawButtons(Canvas canvas) {
        float w = (W - 8f) / BUTTONS.length;
        text.setTextSize(15);
        text.setFakeBoldText(true);
        for (int i = 0; i < BUTTONS.length; i++) {
            float x = 4 + i * w;
            boolean down = zone == Z_BUTTON && downArg == i;
            fill.setColor(down ? 0xFF3A78C8 : 0xFF1C4C8C);
            canvas.drawRoundRect(x + 2, BAR_Y, x + w - 2, BAR_Y + BAR_H, 8, 8, fill);
            String label = BUTTONS[i];
            if (i == B_PLAY && game.state == Game.State.PLAYING) {
                label = "Pause";
            }
            float tw = text.measureText(label);
            canvas.drawText(label, x + w / 2 - tw / 2, BAR_Y + BAR_H / 2f + 5, text);
        }
        text.setFakeBoldText(false);
    }

    private void drawCenterText(Canvas canvas, String s, float x, float y, float w) {
        text.setTextSize(28);
        text.setFakeBoldText(true);
        float tw = text.measureText(s);
        fill.setColor(0xC0000000);
        canvas.drawRoundRect(x + w / 2 - tw / 2 - 14, y - 4, x + w / 2 + tw / 2 + 14, y + 40, 10, 10, fill);
        canvas.drawText(s, x + w / 2 - tw / 2, y + 27, text);
        text.setFakeBoldText(false);
    }

    private void drawTip(Canvas canvas) {
        if (tip == null) {
            return;
        }
        text.setTextSize(15);
        int width = 420;
        String body = tip + "\n\n(Tap to continue)";
        StaticLayout layout = StaticLayout.Builder.obtain(body, 0, body.length(), text, width)
                .setAlignment(Layout.Alignment.ALIGN_NORMAL)
                .build();
        float h = layout.getHeight() + 28;
        float x = (W - width) / 2f - 14, y = Math.max(8, (295 - h) / 2f);
        fill.setColor(0xF0102040);
        canvas.drawRoundRect(x, y, x + width + 28, y + h, 10, 10, fill);
        fill.setStyle(Paint.Style.STROKE);
        fill.setStrokeWidth(2);
        fill.setColor(0xFF7FB2FF);
        canvas.drawRoundRect(x, y, x + width + 28, y + h, 10, 10, fill);
        fill.setStyle(Paint.Style.FILL);
        canvas.save();
        canvas.translate(x + 14, y + 14);
        layout.draw(canvas);
        canvas.restore();
    }

    private void draw(Canvas canvas, String name, float x, float y) {
        Bitmap b = image(name);
        if (b != null) {
            canvas.drawBitmap(b, x, y, paint);
        }
    }

    private void blit(Canvas canvas, String name, int sx, int sy, int w, int h, float x, float y) {
        Bitmap b = image(name);
        if (b != null) {
            src.set(sx, sy, sx + w, sy + h);
            dst.set(x, y, x + w, y + h);
            canvas.drawBitmap(b, src, dst, paint);
        }
    }

    private void blitFx(Canvas canvas, String name, int sx, int sy, int w, int h, float x, float y) {
        Bitmap b = image(name);
        if (b != null) {
            src.set(sx, sy, sx + w, sy + h);
            dst.set(x, y, x + w, y + h);
            canvas.drawBitmap(b, src, dst, fx);
        }
    }

    private Bitmap image(String name) {
        Bitmap b = images.get(name);
        if (b == null && !images.containsKey(name)) {
            BitmapFactory.Options o = new BitmapFactory.Options();
            o.inScaled = false;
            try (InputStream in = getContext().getAssets().open("fflush/img/" + name + ".png")) {
                b = BitmapFactory.decodeStream(in, null, o);
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
                touchX = x;
                touchY = y;
                if (tip != null) {
                    tip = null;
                    zone = Z_NONE;
                    invalidate();
                    return true;
                }
                zone = zoneAt(x, y);
                downArg = zoneArg;
                downAt = SystemClock.uptimeMillis();
                nextRepeat = downAt + REPEAT_DELAY;
                longFired = false;
                if (zone != Z_BUTTON && zone != Z_ROTATE) {
                    act(zone, downArg);
                }
                invalidate();
                return true;
            case MotionEvent.ACTION_MOVE:
                touchX = x;
                touchY = y;
                return true;
            case MotionEvent.ACTION_UP:
                if (zone == Z_BUTTON && zoneAt(x, y) == Z_BUTTON && zoneArg == downArg) {
                    int b = downArg;
                    zone = Z_NONE;
                    performClick();
                    pressButton(b);
                } else if (zone == Z_ROTATE && !longFired) {
                    game.rotate(false);            // left click: anticlockwise (FUN_0040cd55)
                }
                zone = Z_NONE;
                invalidate();
                return true;
            case MotionEvent.ACTION_CANCEL:
                zone = Z_NONE;
                invalidate();
                return true;
            default:
                return true;
        }
    }

    @Override
    public boolean performClick() {
        return super.performClick();
    }

    /** FUN_0040a9d6: holding the finger down repeats a slide every 100 ms. */
    private void holdRepeat(long now) {
        if (zone == Z_ROTATE && !longFired && now - downAt >= LONG_PRESS) {
            longFired = true;
            game.rotate(true);                     // long press = right click: clockwise
            return;
        }
        if ((zone == Z_UP_LEFT || zone == Z_UP_RIGHT || zone == Z_LO_LEFT || zone == Z_LO_RIGHT)
                && now >= nextRepeat && tip == null) {
            nextRepeat = now + REPEAT_EVERY;
            if (zoneAt(touchX, touchY) == zone) {
                act(zone, downArg);
            }
        }
    }

    private void act(int z, int arg) {
        switch (z) {
            case Z_UP_LEFT:
                doSlideUpper(true);
                break;
            case Z_UP_RIGHT:
                doSlideUpper(false);
                break;
            case Z_LO_LEFT:
                doSlideLower(true);
                break;
            case Z_LO_RIGHT:
                doSlideLower(false);
                break;
            case Z_DROP:
                doDrop();
                break;
            case Z_GRID:
                game.selectGrid(arg);
                break;
            default:
                break;
        }
    }

    private int zoneAt(float x, float y) {
        if (y >= BAR_Y - 2) {
            float w = (W - 8f) / BUTTONS.length;
            int i = (int) ((x - 4) / w);
            if (i >= 0 && i < BUTTONS.length) {
                zoneArg = i;
                return Z_BUTTON;
            }
            return Z_NONE;
        }
        if (game.state != Game.State.PLAYING) {
            return Z_NONE;
        }
        if (y >= UPPER_TOP && y < UPPER_BOTTOM) {
            if (x >= DROP_LEFT && x < DROP_RIGHT) {
                return Z_DROP;
            }
            if (y < 140) {
                return x < DROP_LEFT ? Z_UP_LEFT : Z_UP_RIGHT;
            }
        }
        if (y >= UPPER_BOTTOM - 3 && y < LOWER_BOTTOM) {
            // Small grids: left column = grids 0 (top) and 3 (bottom), right column = 1 and 2.
            if (x >= 136 && x < LOWER_LEFT) {
                zoneArg = y < 219 ? 0 : 3;
                return Z_GRID;
            }
            if (x >= LOWER_RIGHT && x < 480) {
                zoneArg = y < 219 ? 1 : 2;
                return Z_GRID;
            }
            if (x >= LOWER_LEFT && x < LOWER_RIGHT) {
                int gx = game.gridX();
                if (x >= gx + 20 && x <= gx + 100 && y > 176 && y < 259) {
                    return Z_ROTATE;
                }
                return x < Game.DROP_X + 10 ? Z_LO_LEFT : Z_LO_RIGHT;
            }
        }
        return Z_NONE;
    }

    private void pressButton(int button) {
        FflushActivity activity = (FflushActivity) getContext();
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
                    new AlertDialog.Builder(activity)
                            .setTitle("Finty Flush")
                            .setMessage("This will start a new Finty Flush game.")
                            .setPositiveButton("OK", (d, w) -> startNewGame())
                            .setNegativeButton("Cancel", null)
                            .show();
                } else {
                    startNewGame();
                }
                break;
            case B_OPTIONS:
                pauseGame();
                Dialogs.showOptions(activity);
                break;
            case B_SCORES:
                pauseGame();
                Dialogs.showHighScores(activity);
                break;
            case B_HELP:
                pauseGame();
                tip = Tips.QUICK_HELP;
                break;
            case B_EXIT:
                pauseGame();
                activity.exitToMenu();
                break;
            default:
                break;
        }
    }
}
