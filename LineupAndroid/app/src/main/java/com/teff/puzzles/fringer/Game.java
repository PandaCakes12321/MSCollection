package com.teff.puzzles.fringer;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * Fringer rules engine, based on original Microsoft Puzzle Collection 1997.
 * Plain Java (no Android imports).
 *
 * Field: up to 9 rope columns. Each rope has knots at Y positions 0..FIELD_H.
 * A bar descends from the top at a speed determined by difficulty/level.
 * The player moves a frame (cursor) LEFT/RIGHT and presses SPACE to untwist the
 * knot nearest the bar on the current rope.
 * Knots pushed to FIELD_H → life lost.
 * All knots on a rope cleared → rope disappears.
 * All ropes cleared → level done.
 */
final class Game {

    // Logical field dimensions (original 600x400 window, ropes in centre band)
    static final int FIELD_W = 600, FIELD_H = 400;
    static final int ROPE_TOP = 40;         // y where ropes start
    static final int ROPE_BOTTOM = 360;     // y where knots are lost
    static final int ROPE_BAND = ROPE_BOTTOM - ROPE_TOP;   // 320 px
    static final int TICK_MS = 100;         // original SetTimer(1, 100)

    // Bar speed: pixels per tick (ROPE_BAND / ticks_per_full_pass)
    // Level 1: ~600 ticks per pass (~60s), faster each level
    static final int MAX_LEVEL = 9;
    static final int BONUS_LEVEL_START = 10;

    // Knot types (bit field low 3 bits from original)
    static final int KNOT_A = 0;  // left-over-right
    static final int KNOT_B = 1;  // right-over-left
    static final int KNOT_DONE = 2; // already untwisted (transparent / no draw needed)

    enum State { TITLE, PLAYING, PAUSED, LIFE_LOST, LEVEL_DONE, OVER }

    interface Listener {
        void sound(String name);
        void tip(int kind);
        void levelDone(int score);
        void gameOver(int score);
    }

    static final class Knot {
        int y;      // top of knot relative to ROPE_TOP, 0 = at top
        int type;   // KNOT_A or KNOT_B

        Knot(int y, int type) { this.y = y; this.type = type; }
    }

    static final class Rope {
        int color;          // 0..8 which thread color
        boolean present;    // false after all knots cleared
        final List<Knot> knots = new ArrayList<>();
    }

    // ---- options ----
    int difficulty = 1;   // 1 Easy 2 Medium 3 Hard (sets bar speed)
    int startLevel = 1;

    // ---- state ----
    State state = State.TITLE;
    int level;
    int score;
    int lives = 3;
    int sparkle;   // sparkle bonus count
    int brush;     // brush bonus count
    Listener listener;
    final Random rnd;

    // Rope field
    int numRopes;
    final Rope[] ropes = new Rope[9];
    int frameCol;      // 0..numRopes-1 current frame column
    float barY;        // current bar Y position 0..ROPE_BAND (pixels from ROPE_TOP)
    float barSpeed;    // pixels per tick
    boolean paused;
    int lifeLostTimer;  // countdown in ticks
    int levelDoneTimer;
    int lastKnotCol;   // col where last knot was cleared (for sound)

    Game() { this(new Random()); }
    Game(Random rnd) {
        this.rnd = rnd;
        for (int i = 0; i < ropes.length; i++) ropes[i] = new Rope();
    }

    // ---- level setup ----

    void newGame() {
        score = 0;
        lives = 3;
        sparkle = 0;
        brush = 0;
        level = Math.max(1, Math.min(MAX_LEVEL, startLevel)) - 1;
        nextLevel();
    }

    private void nextLevel() {
        level++;
        state = State.PLAYING;
        frameCol = 0;
        barY = 0;
        lifeLostTimer = 0;
        levelDoneTimer = 0;
        setupLevel(level);
        setBarSpeed();
        sound("NEWLEVELWAV");
    }

    private void setBarSpeed() {
        // Slower at low levels (ROPE_BAND / ticksPerPass)
        // Level 1: ~600 ticks; level 9: ~120 ticks. Difficulty speeds up by 30%.
        float ticksBase = 600f - (level - 1) * 50f;
        float diffMult = 1f - (difficulty - 1) * 0.15f;
        float ticks = ticksBase * diffMult;
        barSpeed = ROPE_BAND / Math.max(ticks, 60f);
    }

    private void setupLevel(int lv) {
        // Number of ropes: 5 for level 1, up to 9 for level 9+
        numRopes = Math.min(4 + lv, 9);
        frameCol = Math.min(frameCol, numRopes - 1);
        int knotsPerRope = 2 + (lv / 3); // 2 for levels 1-2, 3 for 3-5, 4 for 6-9

        for (int c = 0; c < numRopes; c++) {
            Rope r = ropes[c];
            r.color = c % 9;
            r.present = true;
            r.knots.clear();
            // Space knots evenly across the rope
            int spacing = ROPE_BAND / (knotsPerRope + 1);
            for (int k = 0; k < knotsPerRope; k++) {
                int y = spacing * (k + 1) - spacing / 2;
                r.knots.add(new Knot(y, rnd.nextInt(2)));
            }
        }
        // Give a sparkle bonus every few levels
        if (lv % 3 == 0) sparkle++;
        if (lv % 4 == 0) brush++;
    }

    // ---- public controls ----

    void moveLeft() {
        if (state != State.PLAYING) return;
        if (frameCol > 0) {
            frameCol--;
            sound("LEFTWAV");
        }
    }

    void moveRight() {
        if (state != State.PLAYING) return;
        if (frameCol < numRopes - 1) {
            frameCol++;
            sound("RIGHTWAV");
        }
    }

    /** SPACE: untwist the knot nearest to the bar on the current rope. */
    void pressSpace() {
        if (state != State.PLAYING) return;
        Rope r = ropes[frameCol];
        if (!r.present || r.knots.isEmpty()) return;

        // Find knot nearest to bar
        Knot target = null;
        int minDist = Integer.MAX_VALUE;
        for (Knot k : r.knots) {
            int dist = Math.abs(k.y - (int) barY);
            if (dist < minDist) {
                minDist = dist;
                target = k;
            }
        }
        if (target == null) return;

        // Can untwist if close enough to bar
        if (minDist > 60) return;

        r.knots.remove(target);
        score += 10;
        sound("DELLINEWAV");

        if (r.knots.isEmpty()) {
            r.present = false;
            score += 50 * level;
            sound("GETSTARWAV");
            checkLevelDone();
        }
    }

    /** TAB: use sparkle bonus to change all knots on current rope to untwistable. */
    void pressTab() {
        if (state != State.PLAYING || sparkle <= 0) return;
        sparkle--;
        Rope r = ropes[frameCol];
        // Move all knots on this rope closer to bar so they can be untwisted
        if (r.present) {
            for (Knot k : r.knots) {
                k.y = (int) barY + rnd.nextInt(30) - 15;
                k.y = Math.max(0, Math.min(k.y, ROPE_BAND - 20));
            }
            sound("USESTARWAV");
        }
    }

    /** ENTER: use brush bonus to repaint rope colors. */
    void pressBrush() {
        if (state != State.PLAYING || brush <= 0) return;
        brush--;
        for (int i = 0; i < numRopes; i++) {
            ropes[i].color = (ropes[i].color + 1) % 9;
        }
        sound("USEBRUSHWAV");
    }

    // ---- tick ----

    void tick(int ms) {
        if (state == State.LIFE_LOST) {
            lifeLostTimer -= ms;
            if (lifeLostTimer <= 0) {
                if (lives <= 0) {
                    state = State.OVER;
                    if (listener != null) listener.gameOver(score);
                } else {
                    // Restart bar at top, knots regenerated for this rope
                    restartAfterLoss();
                }
            }
            return;
        }
        if (state == State.LEVEL_DONE) {
            levelDoneTimer -= ms;
            if (levelDoneTimer <= 0) {
                if (level >= MAX_LEVEL + (difficulty > 1 ? 5 : 0)) {
                    state = State.OVER;
                    if (listener != null) listener.gameOver(score);
                } else {
                    nextLevel();
                }
            }
            return;
        }
        if (state != State.PLAYING) return;

        // Advance bar
        barY += barSpeed * (ms / (float) TICK_MS);
        if (barY >= ROPE_BAND) {
            barY = 0;  // bar wraps back to top
        }

        // Push knots downward based on how far bar has passed them
        for (int c = 0; c < numRopes; c++) {
            Rope r = ropes[c];
            if (!r.present) continue;
            for (int i = r.knots.size() - 1; i >= 0; i--) {
                Knot k = r.knots.get(i);
                // Knots below the bar get pushed down slightly each tick
                if (k.y < barY) {
                    k.y += barSpeed * (ms / (float) TICK_MS) * 0.5f;
                }
                if (k.y >= ROPE_BAND) {
                    // Knot fell off bottom
                    r.knots.remove(i);
                    lives--;
                    score = Math.max(0, score - 20);
                    sound("ENDCURRWAV");
                    state = State.LIFE_LOST;
                    lifeLostTimer = 1500;
                    return;
                }
            }
        }
    }

    private void restartAfterLoss() {
        barY = 0;
        state = State.PLAYING;
        // Re-add a knot for any ropes that lost their last knot in the fall
        for (int c = 0; c < numRopes; c++) {
            Rope r = ropes[c];
            if (r.present && r.knots.isEmpty()) {
                // Replace with a single knot at mid-field
                r.knots.add(new Knot(ROPE_BAND / 2, rnd.nextInt(2)));
            }
        }
    }

    private void checkLevelDone() {
        for (int c = 0; c < numRopes; c++) {
            if (ropes[c].present) return;
        }
        // All ropes cleared
        state = State.LEVEL_DONE;
        levelDoneTimer = 2000;
        sound("ENDBESTWAV");
        if (listener != null) listener.levelDone(score);
    }

    // ---- accessors ----

    int ropeX(int col) {
        // Evenly distribute N ropes across the field width (60..540 range)
        int margin = 60;
        int span = FIELD_W - 2 * margin;
        if (numRopes <= 1) return FIELD_W / 2;
        return margin + col * span / (numRopes - 1);
    }

    int knotAbsY(Knot k) {
        return ROPE_TOP + (int) k.y;
    }

    int barAbsY() {
        return ROPE_TOP + (int) barY;
    }

    private void sound(String name) {
        if (listener != null) listener.sound(name);
    }
}
