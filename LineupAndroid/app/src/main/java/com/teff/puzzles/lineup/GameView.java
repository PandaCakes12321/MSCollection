package com.teff.puzzles.lineup;

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
import android.text.Layout;
import android.text.StaticLayout;
import android.text.TextPaint;
import android.view.MotionEvent;
import android.view.View;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

/**
 * Draws the game with the original 1997 art on a fixed 650x400 layout scaled to the screen,
 * and turns touches into the original mouse clicks.
 */
final class GameView extends View implements Game.Listener {
    // Logical layout, in original-art pixels.
    private static final int W = 650, H = 400;
    private static final int CELL = 27, BX = 11, BY = 11;       // board: 14 x 27 = 378 px square
    private static final int TX = 397;                          // bonus tube, 54 px wide
    private static final int QX = 459, SLOT = 77, SMALL = 14;   // piece queue, 70 px wide
    private static final int PX = 539;                          // right panel, 100 px wide
    private static final RectF BTN_PLAY = new RectF(PX, 211, PX + 100, 265);
    private static final RectF BTN_NEW = new RectF(PX, 271, PX + 100, 325);
    private static final RectF BTN_OPTIONS = new RectF(PX, 331, PX + 49, 359);
    private static final RectF BTN_SCORES = new RectF(PX + 51, 331, PX + 100, 359);
    private static final RectF BTN_EXIT = new RectF(PX, 363, PX + 100, 391);
    private static final long TIP_MS = 7000;

    final Game game = new Game();
    private final Audio audio;
    private final SharedPreferences prefs;
    private final Map<String, Bitmap> images = new HashMap<>();
    private final Paint paint = new Paint(Paint.FILTER_BITMAP_FLAG | Paint.ANTI_ALIAS_FLAG);
    private final Paint ghost = new Paint(Paint.FILTER_BITMAP_FLAG | Paint.ANTI_ALIAS_FLAG);
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final TextPaint text = new TextPaint(Paint.ANTI_ALIAS_FLAG);
    private final Handler handler = new Handler(Looper.getMainLooper());

    private float scale = 1f, offsetX, offsetY;
    private int anim;
    private boolean running;

    // Touch state
    private boolean onBoard;
    private int touchR, touchC, downR, downC;
    private RectF pressed;

    private String tip;
    private long tipUntil;

    private final Runnable loop = new Runnable() {
        @Override
        public void run() {
            anim++;
            game.tick();
            invalidate();
            handler.postDelayed(this, 100);
        }
    };

    GameView(Context context) {
        super(context);
        prefs = context.getSharedPreferences("lineup", Context.MODE_PRIVATE);
        audio = new Audio(context);
        game.listener = this;
        text.setColor(Color.WHITE);
        loadOptions();
        if (!prefs.getBoolean("seenHelp", false)) {
            showTip(Tips.QUICK_HELP);
            prefs.edit().putBoolean("seenHelp", true).apply();
        }
    }

    // ---- lifecycle ---------------------------------------------------------------------------

    void onHostResume() {
        if (!running) {
            running = true;
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
    }

    void startNewGame() {
        loadOptions();
        game.newGame();
        audio.startMusic();
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
                audio.startMusic();
            } else {
                audio.resumeMusic();
            }
            invalidate();
        }
    }

    /** Called after the options dialog closes, so music on/off takes effect right away. */
    void optionsChanged() {
        loadOptions();
        if (!audio.musicOn) {
            audio.stopMusic();
        }
    }

    // ---- Game.Listener -----------------------------------------------------------------------

    @Override
    public void sound(int id) {
        audio.play(id);
    }

    @Override
    public void tip(int kind) {
        String key = "tip" + kind;
        if (!prefs.getBoolean(key, false)) {
            prefs.edit().putBoolean(key, true).apply();
            showTip(Tips.forKind(kind));
        }
    }

    @Override
    public void gameOver(int score) {
        audio.stopMusic();
        handler.postDelayed(() -> audio.play(Game.SND_WHISTLE), 200);
        handler.post(() -> Dialogs.checkHighScore((LineupActivity) getContext(), score));
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
        canvas.drawColor(0xFF163016);
        canvas.save();
        canvas.translate(offsetX, offsetY);
        canvas.scale(scale, scale);
        drawFrames(canvas);
        drawBoard(canvas);
        drawGhost(canvas);
        drawTube(canvas);
        drawQueue(canvas);
        drawPanel(canvas);
        drawTip(canvas);
        canvas.restore();
    }

    private void drawFrames(Canvas canvas) {
        fill.setColor(0xFF0B1A0B);
        canvas.drawRect(BX - 4, BY - 4, BX + 14 * CELL + 4, BY + 14 * CELL + 4, fill);
        canvas.drawRect(TX - 4, BY - 4, TX + 54 + 4, BY + 14 * CELL + 4, fill);
        canvas.drawRect(QX - 4, BY - 11, QX + 70 + 4, BY + 5 * SLOT + 4, fill);
    }

    private void drawBoard(Canvas canvas) {
        boolean live = game.state == Game.State.PLAYING;
        for (int r = 1; r <= Game.N; r++) {
            for (int c = 1; c <= Game.N; c++) {
                float x = BX + (c - 1) * CELL, y = BY + (r - 1) * CELL;
                draw(canvas, live ? cellImage(r, c) : "SQUARE_E", x, y);
            }
        }
        if (!live) {
            String banner = game.state == Game.State.PAUSED ? "BREAK"
                    : game.state == Game.State.OVER ? "GAMEOVER" : "TITLE";
            draw(canvas, banner, BX, BY + 81);
        }
    }

    private String cellImage(int r, int c) {
        switch (game.type[r][c]) {
            case Game.BALL:
                return "SQUARE_" + Pieces.look(game.look[r][c]);
            case Game.DIRT:
                return "BREAK_E" + game.look[r][c];
            case Game.CLOCK:
                return frame("TIMEBONUS", 12, countdownFrame(game.timer[r][c], 12));
            case Game.MEDAL:
                return frame("CLEARBONUS", 9, anim / 2);
            case Game.SCORECARD:
                return frame("SCOREBONUS", 12, countdownFrame(game.timer[r][c], 12));
            case Game.GARBAGE:
                return frame("GARBAGE", 9, anim / 2);
            case Game.GOLF:
                return frame("BONUSADD", 9, anim / 2);
            default:
                return "SQUARE_E";
        }
    }

    /** Clocks and scorecards show later frames as their time runs out (FUN_00406934). */
    private static int countdownFrame(int timer, int frames) {
        return timer > frames - 1 ? 0 : frames - 1 - timer;
    }

    private static String frame(String name, int frames, int index) {
        return String.format(Locale.US, "%s%02d", name, index % frames);
    }

    /** While a finger is on the board, show where the next piece would land. */
    private void drawGhost(Canvas canvas) {
        int id = game.queue[1];
        if (!onBoard || game.state != Game.State.PLAYING || id == 0) {
            return;
        }
        ghost.setAlpha(game.canPlace(touchR, touchC, id) ? 170 : 70);
        for (int[] cell : Pieces.SHAPE[id]) {
            int r = touchR + cell[0], c = touchC + cell[1];
            if (r >= 1 && r <= Game.N && c >= 1 && c <= Game.N) {
                Bitmap b = image(cell[0] == 0 && cell[1] == 0 ? "SMALLSQUARE_6" : "SQUARE_" + Pieces.look(id));
                if (b != null) {
                    float x = BX + (c - 1) * CELL, y = BY + (r - 1) * CELL;
                    canvas.drawBitmap(b, null, new RectF(x, y, x + CELL, y + CELL), ghost);
                }
            }
        }
    }

    /** Bonus balls: golf balls stacked from the bottom of the tube, max 12. */
    private void drawTube(Canvas canvas) {
        for (int i = 1; i <= Game.MAX_BONUS; i++) {
            boolean full = i <= game.bonus;
            String name = i == 1 ? "B_D_" : i == Game.MAX_BONUS ? "B_U_" : "B_M_";
            draw(canvas, name + (full ? 2 : 0), TX, BY + (14 - i) * CELL);
        }
    }

    /** The piece line: slot 1 (the piece to place) at the bottom, slot 5 at the top. */
    private void drawQueue(Canvas canvas) {
        for (int k = 1; k <= Game.QUEUE; k++) {
            float sy = BY + (Game.QUEUE - k) * SLOT;
            if (k < Game.QUEUE) {
                draw(canvas, "ARROW_D", QX, sy - 7);
            }
            int id = game.queue[k];
            int shiftR = 0, shiftC = 0;
            if (id != 0) {
                // Shift long pieces so they fit the 5x5 preview (FUN_00407f65).
                for (int[] cell : Pieces.SHAPE[id]) {
                    if (cell[0] == -3) shiftR = 1;
                    if (cell[0] == 3) shiftR = -1;
                    if (cell[1] == -3) shiftC = 1;
                    if (cell[1] == 3) shiftC = -1;
                }
            }
            for (int r = -2; r <= 2; r++) {
                for (int c = -2; c <= 2; c++) {
                    draw(canvas, "SMALLSQUARE_E", QX + 28 + c * SMALL, sy + 28 + r * SMALL);
                }
            }
            if (id != 0) {
                for (int[] cell : Pieces.SHAPE[id]) {
                    int r = cell[0] + shiftR, c = cell[1] + shiftC;
                    String name = cell[0] == 0 && cell[1] == 0 ? "SMALLSQUARE_6" : "SMALLSQUARE_" + Pieces.look(id);
                    draw(canvas, name, QX + 28 + c * SMALL, sy + 28 + r * SMALL);
                }
            }
            if (k == 1 && game.state == Game.State.PLAYING) {
                fill.setStyle(Paint.Style.STROKE);
                fill.setStrokeWidth(2f);
                fill.setColor((anim / 4) % 2 == 0 ? 0xFFFFE04A : 0xFFFFFFFF);
                canvas.drawRect(QX - 1, sy - 1, QX + 71, sy + 71, fill);
                fill.setStyle(Paint.Style.FILL);
            }
        }
    }

    private void drawPanel(Canvas canvas) {
        draw(canvas, "SCORE", PX, 11);
        drawNumber(canvas, game.score, PX, 11);
        draw(canvas, "LEVEL", PX, 111);
        drawNumber(canvas, game.state == Game.State.TITLE ? game.startLevel : game.level, PX, 111);

        String play = game.state == Game.State.PLAYING ? "PAUSE_" : "PLAY_";
        draw(canvas, play + (pressed == BTN_PLAY ? 1 : 0), BTN_PLAY.left, BTN_PLAY.top);
        draw(canvas, "NEW_" + (pressed == BTN_NEW ? 1 : 0), BTN_NEW.left, BTN_NEW.top);
        drawTextButton(canvas, BTN_OPTIONS, "Options");
        drawTextButton(canvas, BTN_SCORES, "Scores");
        drawTextButton(canvas, BTN_EXIT, "Exit");
    }

    /** Five digits like the original: leading zeros blank, last digit always shown. */
    private void drawNumber(Canvas canvas, int value, float x, float y) {
        String digits = String.format(Locale.US, "%05d", Math.max(0, value) % 100000);
        boolean started = false;
        for (int i = 0; i < 5; i++) {
            char ch = digits.charAt(i);
            started |= ch != '0' || i == 4;
            draw(canvas, started ? "DIGIT_" + ch : "DIGIT_E", x + 9 + i * 17, y + 47);
        }
    }

    private void drawTextButton(Canvas canvas, RectF r, String label) {
        fill.setColor(pressed == r ? 0xFF4F8F3A : 0xFF2F6B24);
        canvas.drawRoundRect(r, 6, 6, fill);
        text.setTextSize(13);
        text.setFakeBoldText(true);
        float w = text.measureText(label);
        canvas.drawText(label, r.centerX() - w / 2, r.centerY() + 5, text);
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
        text.setTextSize(14);
        StaticLayout layout = StaticLayout.Builder.obtain(tip, 0, tip.length(), text, 14 * CELL - 24)
                .setAlignment(Layout.Alignment.ALIGN_NORMAL)
                .build();
        float h = layout.getHeight() + 20;
        fill.setColor(0xE0101010);
        canvas.drawRoundRect(BX + 4, BY + 4, BX + 14 * CELL - 4, BY + 4 + h, 8, 8, fill);
        canvas.save();
        canvas.translate(BX + 12, BY + 14);
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
            try (InputStream in = getContext().getAssets().open("lineup/img/" + name + ".png")) {
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
                pressed = null;
                onBoard = boardCell(x, y);
                if (onBoard) {
                    downR = touchR;
                    downC = touchC;
                } else {
                    pressed = buttonAt(x, y);
                }
                invalidate();
                return true;
            case MotionEvent.ACTION_MOVE:
                if (onBoard) {
                    onBoard = boardCell(x, y);
                    invalidate();
                }
                return true;
            case MotionEvent.ACTION_UP:
                if (onBoard && boardCell(x, y)) {
                    // Deleting a piece needs a plain tap, so a mis-aimed drag never costs a bonus ball.
                    game.tapBoard(touchR, touchC, touchR == downR && touchC == downC);
                } else if (pressed != null && pressed == buttonAt(x, y)) {
                    performClick();
                    pressButton(pressed);
                } else if (pressed == null && !onBoard) {
                    int slot = queueSlotAt(x, y);
                    if (slot > 0) {
                        game.tapQueue(slot);
                    }
                }
                onBoard = false;
                pressed = null;
                invalidate();
                return true;
            case MotionEvent.ACTION_CANCEL:
                onBoard = false;
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

    private boolean boardCell(float x, float y) {
        if (x < BX || y < BY || x >= BX + 14 * CELL || y >= BY + 14 * CELL) {
            return false;
        }
        touchC = (int) ((x - BX) / CELL) + 1;
        touchR = (int) ((y - BY) / CELL) + 1;
        return true;
    }

    private RectF buttonAt(float x, float y) {
        for (RectF r : new RectF[] {BTN_PLAY, BTN_NEW, BTN_OPTIONS, BTN_SCORES, BTN_EXIT}) {
            if (r.contains(x, y)) {
                return r;
            }
        }
        return null;
    }

    private int queueSlotAt(float x, float y) {
        if (x < QX - 4 || x > QX + 74 || y < BY || y >= BY + Game.QUEUE * SLOT) {
            return 0;
        }
        return Game.QUEUE - (int) ((y - BY) / SLOT);
    }

    private void pressButton(RectF button) {
        LineupActivity activity = (LineupActivity) getContext();
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
                        .setTitle("Lineup")
                        .setMessage("This will start a new Lineup game.")
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
