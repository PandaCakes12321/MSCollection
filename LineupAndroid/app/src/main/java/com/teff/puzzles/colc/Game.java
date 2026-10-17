package com.teff.puzzles.colc;

import java.util.Random;

// Key-code constants mirroring android.view.KeyEvent so Game.java stays pure Java.
// Values are identical to the Android constants.

/**
 * Color Collision rules engine, recovered from COLC.EXE.
 * Plain Java (no Android imports) so it can be simulated headless.
 *
 * The game field is 600x400 logical pixels. The collider bounces around; arrow keys nudge its
 * velocity. There are up to 8 coloured circle targets. Hit a circle of the same colour: collect it
 * (remove a green ball from the counter). Hit the wrong colour circle: it turns into a stick. Hit
 * the wrong colour stick: lose a life. Level done when all green balls (one per circle) are gone.
 *
 * One {@link #tick(int)} is called on every frame (target 100 ms, matching the original SetTimer).
 */
final class Game {

    // ---- constants ----------------------------------------------------------------------------

    static final int FIELD_W = 600, FIELD_H = 400;
    static final int NUM_COLORS = 6;           // 0..5

    // Number of circles and lives per difficulty
    static final int[] CIRCLES_BY_DIFF = {0, 6, 8, 10, 12};   // index 1..4
    static final int LIVES = 3;

    // Speed (px per tick) per difficulty
    static final int[] SPEED_BY_DIFF = {0, 2, 3, 4, 5};        // index 1..4

    // Collider size (radius)
    static final int BALL_R = 20;

    // Circle radius used for hit-testing
    static final int CIRCLE_R = 45;

    // How long a collected circle flashes before disappearing (ticks)
    static final int FLASH_TICKS = 5;

    // Tip IDs
    static final int TIP_WRONG_COLOR = 1, TIP_STICK = 2, TIP_BONUS = 3;

    // Sound IDs (matching filenames in snd/ by number)
    static final int SND_HIT_RIGHT = 17;    // collected circle
    static final int SND_HIT_WRONG = 18;    // turned to stick
    static final int SND_LIFE_LOST = 19;    // hit wrong stick
    static final int SND_LEVEL_DONE = 11;   // level cleared
    static final int SND_GAME_OVER = 21;    // all lives gone

    // Circle states
    static final int CS_CIRCLE = 0, CS_STICK = 1, CS_FLASH = 2, CS_GONE = 3;

    // ---- types --------------------------------------------------------------------------------

    enum State { TITLE, PLAYING, PAUSED, LEVEL_DONE, OVER }

    interface Listener {
        void sound(int id);
        void tip(int kind);
        void levelDone(int score);
        void gameOver(int score);
    }

    static final class Circle {
        int x, y;
        int color;   // 0..5
        int state;   // CS_*
        int flash;   // countdown when flashing
    }

    // ---- game state ---------------------------------------------------------------------------

    Listener listener;
    final Random rnd;

    int difficulty = 1;    // 1 Easy .. 4 Crazy
    int startLevel = 1;    // 1..10

    State state = State.TITLE;
    int level;
    int score;
    int lives;
    int greenBalls;         // how many remain to collect to finish the level

    // Collider
    float bx, by;          // position (centre)
    float dx, dy;          // velocity (px/tick)
    int ballColor;         // 0..5

    // Color-change counter (collider changes colour every N ticks)
    private int colorTimer;
    private int colorPeriod;

    // Circles
    final Circle[] circles = new Circle[12];

    // ---- construction -------------------------------------------------------------------------

    Game() {
        this(new Random());
    }

    Game(Random rnd) {
        this.rnd = rnd;
        for (int i = 0; i < circles.length; i++) circles[i] = new Circle();
    }

    // ---- public API ---------------------------------------------------------------------------

    void newGame() {
        level = startLevel - 1;
        score = 0;
        lives = LIVES;
        state = State.PLAYING;
        startLevel(level + 1);
    }

    void pressKey(int keyCode) {
        nudge(keyCode);
    }

    void tick(int ms) {
        if (state != State.PLAYING) return;
        moveBall(ms);
        tickColorChange(ms);
        checkCollisions();
        tickFlash();
        checkLevelDone();
    }

    // ---- private helpers ---------------------------------------------------------------------

    private void startLevel(int lvl) {
        level = lvl;
        int numCircles = Math.min(CIRCLES_BY_DIFF[Math.min(difficulty, 4)], circles.length);
        greenBalls = numCircles;

        // Place circles
        for (int i = 0; i < circles.length; i++) {
            Circle c = circles[i];
            if (i < numCircles) {
                c.state = CS_CIRCLE;
                c.color = rnd.nextInt(NUM_COLORS);
                // Scatter in the play field away from edges
                c.x = 80 + rnd.nextInt(FIELD_W - 160);
                c.y = 80 + rnd.nextInt(FIELD_H - 160);
            } else {
                c.state = CS_GONE;
            }
        }
        // Ensure at least one circle matches ball color
        // (start ball in centre, random color)
        bx = FIELD_W / 2f;
        by = FIELD_H / 2f;
        int spd = SPEED_BY_DIFF[Math.min(difficulty, 4)];
        dx = spd * (rnd.nextBoolean() ? 1 : -1);
        dy = spd * (rnd.nextBoolean() ? 1 : -1);
        ballColor = rnd.nextInt(NUM_COLORS);
        // Make sure there is at least one matching circle
        circles[0].color = ballColor;

        colorPeriod = 50 / Math.max(1, difficulty);   // ~5s at easy, ~1.5s at crazy
        colorTimer = colorPeriod;
    }

    private void moveBall(int ms) {
        float ticks = ms / 100f;
        bx += dx * ticks;
        by += dy * ticks;

        // Bounce off walls
        if (bx - BALL_R < 0) { bx = BALL_R; dx = Math.abs(dx); }
        if (bx + BALL_R > FIELD_W) { bx = FIELD_W - BALL_R; dx = -Math.abs(dx); }
        if (by - BALL_R < 0) { by = BALL_R; dy = Math.abs(dy); }
        if (by + BALL_R > FIELD_H) { by = FIELD_H - BALL_R; dy = -Math.abs(dy); }
    }

    private void tickColorChange(int ms) {
        colorTimer -= ms / 100;
        if (colorTimer <= 0) {
            colorTimer = colorPeriod;
            ballColor = (ballColor + 1) % NUM_COLORS;
        }
    }

    // KEYCODE values (= android.view.KeyEvent constants, identical values)
    static final int KEY_LEFT = 21, KEY_RIGHT = 22, KEY_UP = 19, KEY_DOWN = 20;

    private void nudge(int keyCode) {
        int spd = SPEED_BY_DIFF[Math.min(difficulty, 4)];
        if      (keyCode == KEY_LEFT)  dx = -spd;
        else if (keyCode == KEY_RIGHT) dx =  spd;
        else if (keyCode == KEY_UP)    dy = -spd;
        else if (keyCode == KEY_DOWN)  dy =  spd;
    }

    private void checkCollisions() {
        for (Circle c : circles) {
            if (c.state == CS_GONE || c.state == CS_FLASH) continue;
            float ddx = bx - c.x;
            float ddy = by - c.y;
            float dist = (float) Math.sqrt(ddx * ddx + ddy * ddy);
            if (dist > BALL_R + CIRCLE_R) continue;

            // Bounce the ball away from the circle centre
            if (dist > 0) {
                float nx = ddx / dist, ny = ddy / dist;
                float dot = dx * nx + dy * ny;
                dx -= 2 * dot * nx;
                dy -= 2 * dot * ny;
                // Keep speed constant
                float spd = SPEED_BY_DIFF[Math.min(difficulty, 4)];
                float len = (float) Math.sqrt(dx * dx + dy * dy);
                if (len > 0) { dx = dx / len * spd; dy = dy / len * spd; }
            }
            bx += dx; by += dy;

            if (c.state == CS_CIRCLE) {
                if (c.color == ballColor) {
                    // Correct colour: collect
                    c.state = CS_FLASH;
                    c.flash = FLASH_TICKS;
                    greenBalls = Math.max(0, greenBalls - 1);
                    score += 100 * level;
                    if (listener != null) listener.sound(SND_HIT_RIGHT);
                } else {
                    // Wrong colour: becomes a stick
                    c.state = CS_STICK;
                    if (listener != null) listener.sound(SND_HIT_WRONG);
                    if (listener != null) listener.tip(TIP_WRONG_COLOR);
                }
            } else if (c.state == CS_STICK) {
                if (c.color == ballColor) {
                    // Right colour stick: just bounce (no penalty)
                } else {
                    // Wrong colour stick: lose a life
                    lives--;
                    if (listener != null) listener.sound(SND_LIFE_LOST);
                    if (listener != null) listener.tip(TIP_STICK);
                    if (lives <= 0) {
                        state = State.OVER;
                        if (listener != null) listener.gameOver(score);
                    } else {
                        // Respawn ball in centre
                        bx = FIELD_W / 2f;
                        by = FIELD_H / 2f;
                    }
                }
            }
            break; // one collision per tick
        }
    }

    private void tickFlash() {
        for (Circle c : circles) {
            if (c.state == CS_FLASH) {
                c.flash--;
                if (c.flash <= 0) c.state = CS_GONE;
            }
        }
    }

    private void checkLevelDone() {
        if (greenBalls > 0) return;
        // Also check no flash circles remain
        for (Circle c : circles) {
            if (c.state == CS_FLASH) return;
        }
        score += 500 * level;
        if (listener != null) listener.sound(SND_LEVEL_DONE);
        if (level >= 10) {
            state = State.OVER;
            if (listener != null) listener.gameOver(score);
        } else {
            state = State.LEVEL_DONE;
            if (listener != null) listener.levelDone(score);
        }
    }

    void nextLevel() {
        startLevel(level + 1);
        state = State.PLAYING;
    }

    /** Total circles placed this level (includes sticks and gone ones, just not CS_GONE from start). */
    int totalCircles() {
        int n = 0;
        for (Circle c : circles) if (c.state != CS_GONE || c.flash > 0) n++;
        return n;
    }
}
