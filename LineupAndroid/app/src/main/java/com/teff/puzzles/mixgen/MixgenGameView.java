package com.teff.puzzles.mixgen;

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
import android.text.Layout;
import android.text.StaticLayout;
import android.text.TextPaint;
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.GameAudio;

import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

/**
 * Mixed Genetics game view. Renders on the original 630×430 logical canvas scaled to fit
 * the screen. Touch = drag-and-drop; a "Breed" button handles the original right-click action.
 */
final class MixgenGameView extends View implements Game.Listener, Sprites.Source {

    private static final int W = 640, H = 430;
    private static final int PX = 0, BAR_Y = 400, BAR_H = 30;

    // Button strip at the bottom
    private static final RectF BTN_PLAY    = new RectF(4,   BAR_Y, 100, BAR_Y + BAR_H - 2);
    private static final RectF BTN_NEW     = new RectF(104, BAR_Y, 200, BAR_Y + BAR_H - 2);
    private static final RectF BTN_BREED   = new RectF(204, BAR_Y, 330, BAR_Y + BAR_H - 2);
    private static final RectF BTN_OPTIONS = new RectF(334, BAR_Y, 430, BAR_Y + BAR_H - 2);
    private static final RectF BTN_SCORES  = new RectF(434, BAR_Y, 530, BAR_Y + BAR_H - 2);
    private static final RectF BTN_EXIT    = new RectF(534, BAR_Y, 636, BAR_Y + BAR_H - 2);
    private static final RectF[] BUTTONS = {BTN_PLAY, BTN_NEW, BTN_BREED, BTN_OPTIONS, BTN_SCORES, BTN_EXIT};

    private static final int TICK_MS = Game.TICK_MS;
    private static final long TIP_MS = 8000;

    private final Game game;
    private final Sprites sprites;
    private final int[] palette = new int[256];
    private final GameAudio audio;
    private final SharedPreferences prefs;
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Map<Integer, Bitmap> spriteBitmaps = new HashMap<>();
    private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final TextPaint text = new TextPaint(Paint.ANTI_ALIAS_FLAG);
    private final Handler handler = new Handler(Looper.getMainLooper());

    private float scale = 1f, offsetX, offsetY;
    private boolean running;

    // Touch/drag state
    private boolean dragging;
    private float touchX, touchY;
    private RectF pressed;
    private boolean breedMode;  // next tap is a breed action

    private String tip;
    private long tipUntil;

    private final Runnable loop = new Runnable() {
        @Override
        public void run() {
            game.tick();
            invalidate();
            handler.postDelayed(this, TICK_MS);
        }
    };

    MixgenGameView(Context context) {
        super(context);
        prefs = context.getSharedPreferences("mixgen", Context.MODE_PRIVATE);
        audio = new GameAudio(context, "mixgen");

        // Load palette from palette.bin
        int[] pal = new int[256];
        try (InputStream in = context.getAssets().open("mixgen/data/palette.bin")) {
            byte[] buf = new byte[1024];
            int got = 0;
            while (got < buf.length) {
                int n = in.read(buf, got, buf.length - got);
                if (n < 0) break;
                got += n;
            }
            for (int i = 0; i < 256; i++) {
                int b = buf[i * 4] & 0xFF;
                int g = buf[i * 4 + 1] & 0xFF;
                int r = buf[i * 4 + 2] & 0xFF;
                pal[i] = 0xFF000000 | (r << 16) | (g << 8) | b;
            }
        } catch (IOException e) {
            // fallback: identity greyscale
            for (int i = 0; i < 256; i++) pal[i] = 0xFF000000 | (i * 0x10101);
        }
        pal[0] = 0; // index 0 is transparent
        System.arraycopy(pal, 0, palette, 0, 256);

        Sprites sp;
        try {
            sp = Sprites.load(this);
        } catch (IOException e) {
            sp = new Sprites() {{ /* empty */ }};
        }
        sprites = sp;

        game = new Game(sprites, new Random());
        game.listener = this;
        loadOptions();

        text.setColor(Color.WHITE);
        fill.setAntiAlias(true);
    }

    // ---- Sprites.Source -----------------------------------------------------------------------

    @Override
    public InputStream open(int id) throws IOException {
        return getContext().getAssets().open("mixgen/spr/" + id + ".bin");
    }

    // ---- lifecycle ----------------------------------------------------------------------------

    void onHostResume() {
        if (!running) {
            running = true;
            handler.post(loop);
        }
        if (audio.musicOn && !audio.hasMusic()) {
            audio.startMusic("MIDIGAME1", "MIDIGAME2");
        }
        if (audio.musicOn) audio.resumeMusic();
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

    private void loadOptions() {
        game.startLevel = Math.max(1, Math.min(Game.MAX_LEVEL, prefs.getInt("startLevel", 1)));
        audio.musicOn = prefs.getBoolean("music", true);
        audio.soundOn = prefs.getBoolean("sound", true);
    }

    private void startNewGame() {
        loadOptions();
        game.newGame();
        breedMode = false;
        invalidate();
    }

    // ---- Game.Listener ------------------------------------------------------------------------

    @Override
    public void sound(int id) {
        audio.play("S" + id);
    }

    @Override
    public void tip(int kind) {
        // show a brief overlay tip
        String msg = tipText(kind);
        if (msg != null) showTip(msg);
    }

    @Override
    public void gameOver(int score, boolean won) {
        MixgenActivity act = (MixgenActivity) getContext();
        int best = prefs.getInt("best", 0);
        if (score > best) {
            prefs.edit().putInt("best", score).apply();
        }
        handler.postDelayed(() -> {
            if (won) {
                new AlertDialog.Builder(getContext())
                        .setTitle("Mixed Genetics")
                        .setMessage("You won! Score: " + score)
                        .setPositiveButton("OK", null)
                        .show();
            }
        }, 800);
    }

    private String tipText(int kind) {
        switch (kind) {
            case Game.TIP_IDENTICAL: return "Those animals are identical — try a different combination.";
            case Game.TIP_BOOK:     return "Tap the book to see which animal species are in play.";
            case Game.TIP_WON:     return "Congratulations! You rescued all the animals!";
            default: return null;
        }
    }

    private void showTip(String msg) {
        tip = msg;
        tipUntil = System.currentTimeMillis() + TIP_MS;
        invalidate();
    }

    // ---- layout -------------------------------------------------------------------------------

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        scale = Math.min(w / (float) W, h / (float) H);
        offsetX = (w - W * scale) / 2f;
        offsetY = (h - H * scale) / 2f;
    }

    // ---- drawing ------------------------------------------------------------------------------

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(0xFF182820);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);

        if (game.state == Game.State.TITLE) {
            drawImg(canvas, "TITLEBMP", 0, 0);
            drawOverlay(canvas, "Tap to play", 0x80000000, W / 2f, 200);
        } else {
            drawImg(canvas, "GAMEBOX", 0, 0);
            drawScenery(canvas);
            drawAnimals(canvas);
            drawScoreHud(canvas);
            if (game.state == Game.State.PAUSED) {
                drawOverlay(canvas, "Paused — tap to continue", 0xA0000000, W / 2f, 200);
            } else if (game.state == Game.State.OVER) {
                drawImg(canvas, "GAMEOVERBMP", 150, 150);
            }
        }

        drawTip(canvas);
        drawButtonBar(canvas);
        canvas.restore();
    }

    private void drawScenery(Canvas canvas) {
        // Door: frame 0..3 at position (295,0)
        // DOORFRAME sprites not included, just use the background for now
        // Pipe bubble
        if (game.pipeFrame >= 0 && game.pipeFrame < Game.PIPE.length) {
            int[] pipe = Game.PIPE[game.pipeFrame];
            drawSprite(canvas, 3100 + game.pipeFrame, Game.PIPE_X + pipe[0], Game.PIPE_Y + pipe[1]);
        }
        // Valve steam
        if (game.valveFrame >= 0 && game.valveFrame < Game.VALVE.length) {
            int[] valve = Game.VALVE[game.valveFrame];
            drawSprite(canvas, 3300 + game.valveFrame, Game.VALVE_X + valve[0], Game.VALVE_Y + valve[1]);
        }
        // Book
        if (game.bookOpen) {
            drawImg(canvas, "BOOKOPENBMP", 5, 140);
        }
    }

    private void drawAnimals(Canvas canvas) {
        // Sort alive animals by z (ascending = bottom to top)
        Game.Animal[] alive = Arrays.stream(game.animals)
                .filter(a -> a.alive)
                .sorted(Comparator.comparingInt(a -> a.z))
                .toArray(Game.Animal[]::new);

        for (Game.Animal a : alive) {
            drawAnimal(canvas, a);
        }
    }

    private void drawAnimal(Canvas canvas, Game.Animal a) {
        // Draw body parts 0..5 (genes[p] chooses the species for each part)
        for (int p = 0; p < 6; p++) {
            int[] q = game.partOf(a, p);
            drawSprite(canvas, q[0], a.x + q[1], a.y + q[2]);
        }
        // Draw heart if breeding used
        if (a.breeds > 0) {
            int[] q = game.partOf(a, 6);
            drawSprite(canvas, q[0], a.x + q[1], a.y + q[2]);
        }
        // Highlight held animal
        if (game.held == a.idx) {
            fill.setColor(0x30FFFF00);
            fill.setStyle(Paint.Style.STROKE);
            fill.setStrokeWidth(2);
            int w = game.width(a), h = game.height(a);
            canvas.drawRect(a.x - 2, a.y - 2, a.x + w + 2, a.y + h + 2, fill);
            fill.setStyle(Paint.Style.FILL);
        }
    }

    private void drawScoreHud(Canvas canvas) {
        text.setTextSize(13);
        text.setColor(Color.WHITE);
        canvas.drawText("Score: " + game.score, 5, 12, text);
        canvas.drawText("Level: " + game.level, 5, 28, text);
        canvas.drawText("To rescue: " + game.toRescue, 5, 44, text);
    }

    private void drawButtonBar(Canvas canvas) {
        fill.setColor(0xFF1A2E20);
        canvas.drawRect(0, BAR_Y - 2, W, H, fill);

        String play = game.state == Game.State.PLAYING ? "Pause" : "Play";
        drawBtn(canvas, BTN_PLAY, play, true);
        drawBtn(canvas, BTN_NEW, "New", true);
        String breedLabel = breedMode ? "Breed ●" : "Breed";
        drawBtn(canvas, BTN_BREED, breedLabel, game.state == Game.State.PLAYING);
        drawBtn(canvas, BTN_OPTIONS, "Options", true);
        drawBtn(canvas, BTN_SCORES, "Scores", true);
        drawBtn(canvas, BTN_EXIT, "Exit", true);
    }

    private void drawBtn(Canvas canvas, RectF r, String label, boolean enabled) {
        boolean hi = r == pressed;
        boolean isBreed = r == BTN_BREED && breedMode;
        fill.setColor(!enabled ? 0xFF334433 : hi ? 0xFF5FAF5F : isBreed ? 0xFF4F9F7F : 0xFF3A6A3A);
        canvas.drawRoundRect(r, 6, 6, fill);
        text.setTextSize(12);
        text.setColor(enabled ? Color.WHITE : 0xFF6A8A6A);
        float tw = text.measureText(label);
        canvas.drawText(label, r.centerX() - tw / 2, r.centerY() + 5, text);
    }

    private void drawOverlay(Canvas canvas, String msg, int bg, float cx, float y) {
        fill.setColor(bg);
        canvas.drawRect(cx - 200, y - 20, cx + 200, y + 30, fill);
        text.setTextSize(20);
        text.setColor(Color.WHITE);
        canvas.drawText(msg, cx - text.measureText(msg) / 2, y + 10, text);
    }

    private void drawTip(Canvas canvas) {
        if (tip == null) return;
        if (System.currentTimeMillis() > tipUntil) { tip = null; return; }
        int boxW = 400;
        text.setTextSize(13);
        StaticLayout sl = StaticLayout.Builder.obtain(tip, 0, tip.length(), text, boxW - 16)
                .setAlignment(Layout.Alignment.ALIGN_NORMAL).build();
        float bh = sl.getHeight() + 16;
        fill.setColor(0xE0101820);
        canvas.drawRoundRect(10, 60, 10 + boxW, 60 + bh, 8, 8, fill);
        canvas.save();
        canvas.translate(18, 68);
        sl.draw(canvas);
        canvas.restore();
    }

    // ---- sprite rendering ---------------------------------------------------------------------

    private void drawSprite(Canvas canvas, int id, int x, int y) {
        Sprites.Sprite s = sprites.get(id);
        if (s == null) return;
        Bitmap bmp = spriteBitmaps.get(id);
        if (bmp == null) {
            int[] pixels = new int[s.w * s.h];
            for (int i = 0; i < pixels.length; i++) {
                int idx = s.px[i] & 0xFF;
                pixels[i] = idx == 0 ? 0 : palette[idx];
            }
            bmp = Bitmap.createBitmap(pixels, s.w, s.h, Bitmap.Config.ARGB_8888);
            spriteBitmaps.put(id, bmp);
        }
        canvas.drawBitmap(bmp, x, y, paint);
    }

    private void drawImg(Canvas canvas, String name, float x, float y) {
        Bitmap b = images.get(name);
        if (b == null && !images.containsKey(name)) {
            try (InputStream in = getContext().getAssets().open("mixgen/img/" + name + ".png")) {
                b = BitmapFactory.decodeStream(in);
            } catch (IOException e) {
                b = null;
            }
            images.put(name, b);
        }
        if (b != null) canvas.drawBitmap(b, x, y, paint);
    }

    // ---- touch --------------------------------------------------------------------------------

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        float lx = (e.getX() - offsetX) / scale;
        float ly = (e.getY() - offsetY) / scale;

        switch (e.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                tip = null;
                pressed = buttonAt(lx, ly);
                if (pressed == null && ly < BAR_Y) {
                    handleGameTap(lx, ly, false);
                }
                invalidate();
                return true;
            case MotionEvent.ACTION_MOVE:
                if (dragging) {
                    game.moveHeld((int) lx, (int) ly);
                    invalidate();
                }
                return true;
            case MotionEvent.ACTION_UP:
                if (pressed != null) {
                    if (pressed == buttonAt(lx, ly)) {
                        performClick();
                        pressButton(pressed);
                    }
                    pressed = null;
                } else if (dragging) {
                    dragging = false;
                    game.drop((int) lx, (int) ly);
                    invalidate();
                }
                return true;
            case MotionEvent.ACTION_CANCEL:
                pressed = null;
                dragging = false;
                invalidate();
                return true;
            default:
                return true;
        }
    }

    private void handleGameTap(float x, float y, boolean isBreed) {
        switch (game.state) {
            case TITLE:
            case OVER:
                startNewGame();
                break;
            case PAUSED:
                game.state = Game.State.PLAYING;
                break;
            case PLAYING:
                if (isBreed || breedMode) {
                    int result = game.breedAt((int) x, (int) y);
                    if (result == Game.BREED_OK) {
                        breedMode = false;
                        dragging = true;
                    }
                } else if (game.held == -1) {
                    // Check pipe first
                    if (Game.inPipe((int) x, (int) y)) {
                        game.spawnNow();
                    } else if (game.pickUp((int) x, (int) y)) {
                        dragging = true;
                        game.centreHeldOn((int) x, (int) y);
                    }
                }
                break;
        }
        invalidate();
    }

    @Override
    public boolean performClick() {
        return super.performClick();
    }

    private RectF buttonAt(float x, float y) {
        for (RectF r : BUTTONS) {
            if (r.contains(x, y)) return r;
        }
        return null;
    }

    private void pressButton(RectF btn) {
        MixgenActivity act = (MixgenActivity) getContext();
        if (btn == BTN_PLAY) {
            switch (game.state) {
                case PLAYING: game.state = Game.State.PAUSED; break;
                case PAUSED:  game.state = Game.State.PLAYING; break;
                default:      startNewGame(); break;
            }
        } else if (btn == BTN_NEW) {
            if (game.state == Game.State.PLAYING || game.state == Game.State.PAUSED) {
                new AlertDialog.Builder(getContext())
                        .setTitle("Mixed Genetics")
                        .setMessage("Start a new game?")
                        .setPositiveButton("OK", (d, w) -> startNewGame())
                        .setNegativeButton("Cancel", null)
                        .show();
            } else {
                startNewGame();
            }
        } else if (btn == BTN_BREED) {
            if (game.state == Game.State.PLAYING) {
                breedMode = !breedMode;
            }
        } else if (btn == BTN_OPTIONS) {
            if (game.state == Game.State.PLAYING) game.state = Game.State.PAUSED;
            showOptionsDialog();
        } else if (btn == BTN_SCORES) {
            if (game.state == Game.State.PLAYING) game.state = Game.State.PAUSED;
            showScoresDialog();
        } else if (btn == BTN_EXIT) {
            act.exitToMenu();
        }
        invalidate();
    }

    private void showOptionsDialog() {
        int[] levels = new int[Game.MAX_LEVEL];
        String[] labels = new String[Game.MAX_LEVEL];
        for (int i = 0; i < Game.MAX_LEVEL; i++) {
            levels[i] = i + 1;
            labels[i] = "Level " + (i + 1);
        }
        int cur = prefs.getInt("startLevel", 1) - 1;
        new AlertDialog.Builder(getContext())
                .setTitle("Start Level")
                .setSingleChoiceItems(labels, cur, (d, w) -> {
                    prefs.edit().putInt("startLevel", w + 1).apply();
                    game.startLevel = w + 1;
                })
                .setPositiveButton("OK", null)
                .show();
    }

    private void showScoresDialog() {
        int best = prefs.getInt("best", 0);
        new AlertDialog.Builder(getContext())
                .setTitle("Mixed Genetics — Best Score")
                .setMessage("Your best score: " + best)
                .setPositiveButton("OK", null)
                .show();
    }
}
