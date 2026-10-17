package com.teff.puzzles.jewelch;

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
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;

import com.teff.puzzles.common.ControlPad;
import com.teff.puzzles.common.GameAudio;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

/**
 * Draws Jewel Chase with the original art on a fixed 860x400 layout scaled to the screen:
 * the original 540x400 game screen on the left, buttons and arrow keys on the right.
 */
final class GameView extends View implements Game.Listener, ControlPad.Listener {
    private static final int W = 860, H = 400;
    private static final int PX = 552;  // right panel
    private static final RectF BTN_PLAY = new RectF(PX, 6, PX + 148, 52);
    private static final RectF BTN_NEW = new RectF(PX + 156, 6, PX + 302, 52);
    private static final RectF BTN_OPTIONS = new RectF(PX, 58, PX + 96, 92);
    private static final RectF BTN_SCORES = new RectF(PX + 103, 58, PX + 199, 92);
    private static final RectF BTN_EXIT = new RectF(PX + 206, 58, PX + 302, 92);
    private static final float KEY = 92;
    private static final long TICK_MS = 15;     // Sleep(10) in the idle loop ~ one 15.6 ms timer slice
    private static final long REPEAT_DELAY = 330, REPEAT_RATE = 140;
    private static final long TIP_MS = 9000;

    /** Sprite sheet rectangles (x, y, w, h, dx, dy) of types 1..28, table at 0x4205D0. */
    private static final int[][] SPRITE = {
            {155, 268, 18, 26, 9, 5}, {0, 195, 18, 24, 7, 3}, {0, 220, 22, 23, 5, 5}, {0, 244, 21, 23, 5, 5},
            {174, 268, 25, 20, 5, 8}, {199, 268, 25, 20, 5, 8}, {224, 268, 25, 20, 5, 8}, {250, 268, 32, 33, 2, 1},
            {111, 268, 21, 36, 7, 0}, {174, 289, 31, 13, 2, 11}, {283, 268, 22, 27, 4, 4}, {0, 305, 23, 20, 6, 8},
            {24, 305, 19, 19, 8, 8}, {0, 268, 36, 36, 0, 0}, {37, 268, 36, 36, 0, 0}, {74, 268, 36, 36, 0, 0},
            {101, 32, 26, 32, 5, 2}, {101, 97, 26, 32, 5, 2}, {101, 162, 26, 32, 5, 2},
            {0, 0, 33, 27, 1, 5}, {0, 65, 33, 27, 1, 5}, {0, 130, 33, 27, 1, 5},
            {0, 28, 25, 36, 5, 0}, {0, 93, 25, 36, 5, 0}, {0, 159, 25, 36, 5, 0},
            {133, 0, 33, 28, 1, 6}, {133, 65, 33, 28, 1, 6}, {133, 130, 33, 28, 1, 6}};

    final Game game = new Game();
    private final GameAudio audio;
    private final SharedPreferences prefs;
    private final ControlPad pad = new ControlPad(this);
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final TextPaint text = new TextPaint(Paint.ANTI_ALIAS_FLAG);
    private final Handler handler = new Handler(Looper.getMainLooper());
    private final Rect src = new Rect();
    private final RectF dst = new RectF();

    private byte[] palette, tiles;
    private final byte[][] pattern = new byte[2][];
    private Bitmap board;
    private int boardLevel = -1;

    private float scale = 1f, offsetX, offsetY;
    private boolean running;
    private long lastTime;
    private long debt;
    private RectF pressed;
    private int heldDir = -1;
    private long nextRepeat;
    private String tip;
    private long tipUntil;

    private final Runnable loop = new Runnable() {
        @Override
        public void run() {
            long now = SystemClock.uptimeMillis();
            debt += now - lastTime;
            lastTime = now;
            if (debt > 500) debt = 500;
            while (debt >= TICK_MS) {
                debt -= TICK_MS;
                game.tick();
            }
            if (heldDir >= 0 && now >= nextRepeat) {
                nextRepeat = now + REPEAT_RATE;
                game.movePlayer(heldDir);
            }
            invalidate();
            handler.postDelayed(this, 16);
        }
    };

    GameView(Context context) {
        super(context);
        setFocusable(true);
        setFocusableInTouchMode(true);
        prefs = context.getSharedPreferences("jewelch", Context.MODE_PRIVATE);
        audio = new GameAudio(context, "jewelch");
        game.listener = this;
        game.source = this::readLevel;
        text.setColor(Color.WHITE);
        float x = PX + (302 - 3 * KEY) / 2f;
        pad.addArrows(x, H - 3 * KEY - 6, KEY, true);
        palette = readAsset("jewelch/data/palette.bin");
        tiles = readAsset("jewelch/data/tiles.bin");
        loadOptions();
        if (!prefs.getBoolean("seenHelp", false)) {
            showTip(Tips.QUICK_HELP);
            prefs.edit().putBoolean("seenHelp", true).apply();
        }
    }

    // ---- lifecycle ---------------------------------------------------------------------------------

    void onHostResume() {
        if (!running) {
            running = true;
            lastTime = SystemClock.uptimeMillis();
            debt = 0;
            handler.post(loop);
        }
        requestFocus();
    }

    void onHostPause() {
        pauseGame();
        pad.releaseAll();
        running = false;
        handler.removeCallbacks(loop);
    }

    void release() {
        handler.removeCallbacks(loop);
        audio.release();
    }

    void loadOptions() {
        game.difficulty = prefs.getInt("difficulty", 2);
        game.startLevel = prefs.getInt("startLevel", 1);
        audio.musicOn = prefs.getBoolean("music", true);
        audio.soundOn = prefs.getBoolean("sound", true);
    }

    void startNewGame() {
        loadOptions();
        game.newGame();
        audio.startMusic("MIDIGAME1", "MIDIGAME2", "MIDIGAME3", "MIDIGAME4");
        invalidate();
    }

    void pauseGame() {
        if (game.state == Game.State.PLAYING) {
            game.pause();
            heldDir = -1;
            audio.pauseMusic();
            invalidate();
        }
    }

    private void resumeGame() {
        if (game.state == Game.State.PAUSED) {
            game.resume();
            lastTime = SystemClock.uptimeMillis();
            if (audio.musicOn && !audio.hasMusic()) {
                audio.startMusic("MIDIGAME1", "MIDIGAME2", "MIDIGAME3", "MIDIGAME4");
            } else {
                audio.resumeMusic();
            }
            invalidate();
        }
    }

    void optionsChanged() {
        loadOptions();
        if (!audio.musicOn) {
            audio.stopMusic();
        }
    }

    // ---- Game.Listener -------------------------------------------------------------------------------

    @Override
    public void sound(int id) {
        audio.play("S" + id);
    }

    @Override
    public void levelStarted(int level) {
        boardLevel = -1;  // rebuild the floor picture
    }

    @Override
    public void gameOver(boolean won, int score) {
        heldDir = -1;
        audio.startMusic("MIDIPROMPT");
        if (won) {
            handler.post(() -> new AlertDialog.Builder(getContext())
                    .setTitle("Congratulations!")
                    .setMessage("You won the last level of Jewel Chase! For an added challenge, try improving "
                            + "your score or playing on a higher difficulty level!")
                    .setPositiveButton("OK", (d, w) -> checkScore(score))
                    .setCancelable(false)
                    .show());
        } else {
            handler.post(() -> checkScore(score));
        }
    }

    private void checkScore(int score) {
        // Training games never enter the high-score list (1 < DAT_00420ac0 check).
        if (game.difficulty > Game.TRAINING) {
            Dialogs.checkHighScore((JewelchActivity) getContext(), score);
        }
    }

    private void showTip(String message) {
        tip = message;
        tipUntil = SystemClock.uptimeMillis() + TIP_MS;
        invalidate();
    }

    // ---- ControlPad / keyboard ---------------------------------------------------------------------

    @Override
    public void keyDown(int keyCode) {
        int d = dirFor(keyCode);
        if (d < 0) {
            return;
        }
        tip = null;
        if (game.state == Game.State.PAUSED) {
            resumeGame();
            return;
        }
        if (game.state != Game.State.PLAYING) {
            return;
        }
        heldDir = d;
        nextRepeat = SystemClock.uptimeMillis() + REPEAT_DELAY;
        game.movePlayer(d);
        invalidate();
    }

    @Override
    public void keyUp(int keyCode) {
        if (dirFor(keyCode) == heldDir) {
            heldDir = -1;
        }
    }

    private static int dirFor(int keyCode) {
        switch (keyCode) {
            case ControlPad.UP: return Game.UP;
            case ControlPad.RIGHT: return Game.RIGHT;
            case ControlPad.DOWN: return Game.DOWN;
            case ControlPad.LEFT: return Game.LEFT;
            default: return -1;
        }
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (dirFor(keyCode) >= 0) {
            if (event.getRepeatCount() == 0) keyDown(keyCode);
            return true;
        }
        if (keyCode == KeyEvent.KEYCODE_SPACE || keyCode == KeyEvent.KEYCODE_ENTER) {
            if (game.state == Game.State.PLAYING) pauseGame();
            else if (game.state == Game.State.PAUSED) resumeGame();
            else startNewGame();
            return true;
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
        if (dirFor(keyCode) >= 0) {
            keyUp(keyCode);
            return true;
        }
        return super.onKeyUp(keyCode, event);
    }

    // ---- drawing -----------------------------------------------------------------------------------

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        scale = Math.min(w / (float) W, h / (float) H);
        offsetX = (w - W * scale) / 2f;
        offsetY = (h - H * scale) / 2f;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(0xFF000020);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);
        canvas.clipRect(0, 0, W, H);
        if (game.state == Game.State.TITLE) {
            draw(canvas, "TITLEBMP", 0, 0);
        } else {
            drawPlayfield(canvas);
            if (game.state == Game.State.PAUSED) {
                draw(canvas, "PAUSEBMP", 0, Game.TOP);
            } else if (game.state == Game.State.OVER) {
                draw(canvas, "GAMEOVERBMP", 0, Game.TOP);
            } else if (game.state == Game.State.WON) {
                draw(canvas, "GAMEOVERBMP", 0, Game.TOP);
                draw(canvas, "CUPBMP", 226, 176);
            }
        }
        drawPanel(canvas);
        pad.draw(canvas);
        drawTip(canvas);
        canvas.restore();
    }

    private void drawPlayfield(Canvas canvas) {
        if (boardLevel != game.level || board == null) {
            board = buildBoard(game.level);
            boardLevel = game.level;
        }
        if (board != null) {
            canvas.drawBitmap(board, 0, 0, paint);
        }
        draw(canvas, "LEVSCORE", 0, 0);
        // level: 2 digits at rect (122,5) + 15 / + 33; score: 5 digits at (412,5) + 3 + 17 i (FUN_00406c42)
        draw(canvas, "DIGIT" + (game.level / 10) % 10, 122 + 15, 5);
        draw(canvas, "DIGIT" + game.level % 10, 122 + 33, 5);
        int s = Math.max(0, game.score) % 100000;
        for (int i = 4; i >= 0; i--) {
            draw(canvas, "DIGIT" + s % 10, 412 + i * 17 + 3, 5);
            s /= 10;
        }
        Bitmap sheet = image("sheet");
        if (sheet == null) {
            return;
        }
        for (int r = 0; r < Game.ROWS; r++) {
            for (int c = 0; c < Game.COLS; c++) {
                int it = game.item[r][c];
                if (it > 0 && it <= 12) {
                    sprite(canvas, sheet, it, game.itemFrame[r][c], r, c);
                }
                int i2 = game.item2[r][c];
                if (i2 >= Game.BALL && i2 <= Game.GATE) {
                    sprite(canvas, sheet, i2, game.item2Frame[r][c], r, c);
                }
            }
        }
        for (int who = 0; who < 3; who++) {
            if (game.present[who]) {
                sprite(canvas, sheet, game.thiefSprite(who), game.frame[who], game.row[who], game.col[who]);
            }
        }
    }

    private void sprite(Canvas canvas, Bitmap sheet, int type, int frame, int r, int c) {
        int[] s = SPRITE[type - 1];
        int frames = Game.FRAMES[type - 1];
        int f = frames > 0 ? frame % frames : 0;
        src.set(s[0] + f * s[2], s[1], s[0] + (f + 1) * s[2], s[1] + s[3]);
        float x = c * Game.CELL + s[4], y = Game.TOP + r * Game.CELL + s[5];
        dst.set(x, y, x + s[2], y + s[3]);
        canvas.drawBitmap(sheet, src, dst, paint);
    }

    /**
     * The floor: tile shading from sprite 1000 added onto the grey stone PATTERN of the level
     * (pixel = tile + pattern - 23, FUN_00407685), coloured with the shared 256-colour palette.
     */
    private Bitmap buildBoard(int level) {
        int which = level & 1;
        if (pattern[which] == null) {
            pattern[which] = readAsset("jewelch/data/pattern" + which + ".bin");
        }
        byte[] pat = pattern[which];
        if (pat == null || palette == null || tiles == null || pat.length < 540 * 400) {
            return null;
        }
        byte[] idx = pat.clone();
        int tw = (tiles[0] & 0xFF) | (tiles[1] & 0xFF) << 8;
        for (int r = 0; r < Game.ROWS; r++) {
            for (int c = 0; c < Game.COLS; c++) {
                int t = game.tile[r][c];
                for (int q = 0; q < 4; q++) {
                    int colour = Level.quarterColour(t, q);
                    int srow = colour == 0 ? 5 : colour - 1;
                    for (int y = 0; y < 36; y++) {
                        int so = 4 + (srow * 36 + y) * tw + q * 36;
                        int dp = (Game.TOP + r * 36 + y) * 540 + c * 36;
                        for (int x = 0; x < 36; x++) {
                            int sv = tiles[so + x] & 0xFF;
                            if (sv != 0) {
                                idx[dp + x] = (byte) (sv + (pat[dp + x] & 0xFF) - 23);
                            }
                        }
                    }
                }
            }
        }
        int[] argb = new int[540 * 400];
        for (int i = 0; i < argb.length; i++) {
            int p = (idx[i] & 0xFF) * 3;
            argb[i] = 0xFF000000 | (palette[p] & 0xFF) << 16 | (palette[p + 1] & 0xFF) << 8 | (palette[p + 2] & 0xFF);
        }
        return Bitmap.createBitmap(argb, 540, 400, Bitmap.Config.ARGB_8888);
    }

    private void drawPanel(Canvas canvas) {
        String play = game.state == Game.State.PLAYING ? "Pause" : game.state == Game.State.PAUSED ? "Resume" : "Play!";
        drawButton(canvas, BTN_PLAY, play, 18);
        drawButton(canvas, BTN_NEW, "New", 18);
        drawButton(canvas, BTN_OPTIONS, "Options", 13);
        drawButton(canvas, BTN_SCORES, "Scores", 13);
        drawButton(canvas, BTN_EXIT, "Exit", 13);
        text.setTextSize(13);
        String mode = Dialogs.DIFFICULTIES[Math.max(0, Math.min(3, game.difficulty - 1))];
        String info = game.state == Game.State.TITLE
                ? String.format(Locale.US, "%s - start level %d", mode, game.startLevel)
                : String.format(Locale.US, "%s - level %d", mode, game.level);
        canvas.drawText(info, PX + 2, 112, text);
    }

    private void drawButton(Canvas canvas, RectF r, String label, float size) {
        fill.setColor(pressed == r ? 0xFF3C64C8 : 0xFF1E3C8C);
        canvas.drawRoundRect(r, 8, 8, fill);
        text.setTextSize(size);
        text.setFakeBoldText(true);
        float w = text.measureText(label);
        canvas.drawText(label, r.centerX() - w / 2, r.centerY() + size / 3f, text);
        text.setFakeBoldText(false);
    }

    private void drawTip(Canvas canvas) {
        if (tip == null) {
            return;
        }
        if (SystemClock.uptimeMillis() > tipUntil) {
            tip = null;
            return;
        }
        text.setTextSize(15);
        StaticLayout layout = StaticLayout.Builder.obtain(tip, 0, tip.length(), text, 540 - 60)
                .setAlignment(Layout.Alignment.ALIGN_NORMAL)
                .build();
        float h = layout.getHeight() + 24;
        fill.setColor(0xE0101030);
        canvas.drawRoundRect(18, 60, 522, 60 + h, 10, 10, fill);
        canvas.save();
        canvas.translate(30, 72);
        layout.draw(canvas);
        canvas.restore();
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
            BitmapFactory.Options o = new BitmapFactory.Options();
            o.inScaled = false;
            try (InputStream in = getContext().getAssets().open("jewelch/img/" + name + ".png")) {
                b = BitmapFactory.decodeStream(in, null, o);
            } catch (IOException e) {
                b = null;
            }
            images.put(name, b);
        }
        return b;
    }

    private byte[] readLevel(int level) {
        byte[] d = readAsset(String.format(Locale.US, "jewelch/data/LEVEL%03d.bin", level));
        if (d == null) {
            throw new IllegalStateException("missing level " + level);
        }
        return d;
    }

    private byte[] readAsset(String path) {
        try (InputStream in = getContext().getAssets().open(path)) {
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            byte[] buf = new byte[16384];
            int n;
            while ((n = in.read(buf)) > 0) {
                out.write(buf, 0, n);
            }
            return out.toByteArray();
        } catch (IOException e) {
            return null;
        }
    }

    // ---- touch -------------------------------------------------------------------------------------

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        if (pad.onTouch(e, offsetX, offsetY, scale)) {
            invalidate();
            return true;
        }
        int i = e.getActionIndex();
        float x = (e.getX(i) - offsetX) / scale, y = (e.getY(i) - offsetY) / scale;
        switch (e.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                tip = null;
                pressed = buttonAt(x, y);
                if (pressed == null && x < 540 && game.state == Game.State.PAUSED) {
                    resumeGame();
                }
                invalidate();
                return true;
            case MotionEvent.ACTION_UP:
                if (pressed != null && pressed == buttonAt(x, y)) {
                    performClick();
                    pressButton(pressed);
                }
                pressed = null;
                invalidate();
                return true;
            case MotionEvent.ACTION_CANCEL:
                pressed = null;
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

    private RectF buttonAt(float x, float y) {
        for (RectF r : new RectF[] {BTN_PLAY, BTN_NEW, BTN_OPTIONS, BTN_SCORES, BTN_EXIT}) {
            if (r.contains(x, y)) {
                return r;
            }
        }
        return null;
    }

    private void pressButton(RectF button) {
        JewelchActivity activity = (JewelchActivity) getContext();
        if (button == BTN_PLAY) {
            switch (game.state) {
                case PLAYING:
                    pauseGame();
                    break;
                case PAUSED:
                    resumeGame();
                    break;
                default:
                    startNewGame();
                    break;
            }
        } else if (button == BTN_NEW) {
            if (game.state == Game.State.PLAYING || game.state == Game.State.PAUSED) {
                pauseGame();
                new AlertDialog.Builder(activity)
                        .setTitle("Jewel Chase")
                        .setMessage("This will start a new Jewel Chase game.")
                        .setPositiveButton("OK", (d, w) -> startNewGame())
                        .setNegativeButton("Cancel", null)
                        .show();
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
