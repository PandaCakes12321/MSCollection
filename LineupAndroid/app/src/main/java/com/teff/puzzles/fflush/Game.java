package com.teff.puzzles.fflush;

import java.util.Random;

/**
 * Finty Flush rules engine, recovered from FFLUSH.EXE (see PuzzlePort/FFLUSH/NOTES.md).
 * Plain Java (no Android imports) so it can be simulated headless.
 *
 * Coordinates are the original 614x295 window pixels.
 *  - Upper grid: up to 27 columns of 4 balls. Column i is drawn at x = base - 20*i, rows at
 *    y = 37 + 20*r. The highlighted column (index {@link #hl}) always sits at x = 297 (the drop point).
 *  - Lower grids: 4 grids of 4x4. The current one is drawn at x = gridX(), y = 157 (120x120 image);
 *    its column {@link #lowerCol} sits under the drop point.
 */
final class Game {
    // Cell values (the row index into the ball sprites).
    static final int EMPTY = 0, BLACK = 1, BLUE = 2, RED = 3, GREEN = 4, PALETTE = 5, BOMB = 6, CYCLE = 7;

    static final int MAX_COLUMNS = 27;          // 0x1b: the upper grid is full -> game over
    static final int ALARM_COLUMNS = 25;        // 0x19: alarm sound from here on
    static final int DROP_X = 297;              // 0x129
    static final int UPPER_Y = 37;              // 0x25
    static final int GRID_Y = 157;              // 0x9d
    static final int GRID_X0 = 277;             // 0x115: gridX when lowerCol == 0
    static final int ROTATE_FRAME_MS = 50;      // timers 1/5: 0x32 ms

    // Sounds (FUN_0040181e table, FUN_004014f3 index).
    static final String SND_BALL = "BALLWAVE", SND_FINAL = "FINALWAVE", SND_HOME = "HOMEWAVE",
            SND_LOST = "LOSTWAVE", SND_ROTATE = "ROTATEWAVE", SND_CLICK = "CLICKWAVE",
            SND_ALARM = "ALARMWAVE", SND_TICK = "TICKWAVE";

    // Tip kinds.
    static final int TIP_PALETTE = 5, TIP_BOMB = 6, TIP_NO_BONUS = 7;

    enum State { TITLE, PLAYING, PAUSED, OVER }

    interface Listener {
        void sound(String name);

        void tip(int kind);

        /** A column was dropped from the upper grid onto lower column {@code lowerCol}. */
        void dropped(int[] balls, int lowerCol);

        /** Grid {@code grid} was filled with one colour (before it was cleared). */
        void gridCompleted(int grid, int[][] balls, boolean levelUp);

        void gameOver(int score);
    }

    Listener listener;
    final Random rnd;

    // Options
    int difficulty = 1;     // 1 Easy .. 4 Crazy
    int startLevel = 1;     // 1..10

    State state = State.TITLE;
    int level, score, bonus, toGo;
    final int[] square = new int[4];            // DAT_004126c8: "SQUARE" score per lower grid
    final int[] collisions = new int[4];        // byte 4 of each lower grid (counted, not shown)

    // Upper grid
    final int[][] upper = new int[MAX_COLUMNS + 1][4];
    int count;                                  // DAT_00412828
    int base = DROP_X;                          // DAT_0041282c: x of column 0 (right end)
    int hl;                                     // DAT_0041280c: column at the drop point

    // Lower grids [grid][col][row]
    final int[][][] lower = new int[4][4][4];
    int current;                                // DAT_0041281c
    int previous = 3;                           // DAT_00412820
    int lowerCol;                               // DAT_00412824 (gridX = 277 - 20*lowerCol)
    boolean upperFocus;                         // DAT_00412790: which grid looks "raised"

    // Rotation animation (FUN_0040c988 / FUN_0040cd55)
    int rotStep;                                // 0 = idle, 1..3 = frames shown so far
    boolean rotClockwise;
    private int rotMs;

    private int columnMs;                       // timer 2 accumulator

    Game() {
        this(new Random());
    }

    Game(Random rnd) {
        this.rnd = rnd;
    }

    int gridX() {
        return GRID_X0 - 20 * lowerCol;
    }

    /** Timer 2 period: 10 s on Easy, else 9000 - 1500*difficulty ms. */
    int columnInterval() {
        return difficulty == 1 ? 10000 : 9000 - 1500 * difficulty;
    }

    boolean rotating() {
        return rotStep != 0;
    }

    /** Frame of the rotating grid picture in the sheet (1..3), or 0 when idle. */
    int rotFrame() {
        if (rotStep == 0) {
            return 0;
        }
        return rotClockwise ? rotStep : 4 - rotStep;
    }

    // ---- new game / levels (WM_COMMAND 0x65, FUN_00409a80, FUN_00409275) -----------------------

    void newGame() {
        level = Math.max(1, Math.min(10, startLevel));
        difficulty = Math.max(1, Math.min(4, difficulty));
        score = 0;
        bonus = 0;
        for (int g = 0; g < 4; g++) {
            square[g] = 0;
            collisions[g] = 0;
            for (int c = 0; c < 4; c++) {
                for (int r = 0; r < 4; r++) {
                    lower[g][c][r] = EMPTY;
                }
            }
        }
        columnMs = 0;
        state = State.PLAYING;
        startLevel();
    }

    private void startLevel() {
        toGo = gridsForLevel(level);
        count = 0;
        base = DROP_X;
        hl = 0;
        lowerCol = 0;
        current = 0;
        previous = 3;
        rotStep = 0;
        for (int i = 0; i < 10; i++) {
            addColumn();
        }
    }

    /** FUN_00409238: 3 grids per level, one more for every level past 10. */
    static int gridsForLevel(int level) {
        return 3 + Math.max(0, level - 10);
    }

    /** Background strip for a level: resource 101 + level%4 (returned as 1..4). */
    int backgroundIndex() {
        return 1 + Math.floorMod(level, 4);
    }

    // ---- timer ---------------------------------------------------------------------------------

    void tick(int ms) {
        if (state != State.PLAYING) {
            return;
        }
        if (rotStep != 0) {
            rotMs += ms;
            while (rotStep != 0 && rotMs >= ROTATE_FRAME_MS) {
                rotMs -= ROTATE_FRAME_MS;
                stepRotation();
            }
        }
        columnMs += ms;
        if (columnMs >= columnInterval()) {
            columnMs -= columnInterval();
            timedColumn();
        }
    }

    /** FUN_0040d12d: timer 2 adds a column; a full upper grid ends the game. */
    private void timedColumn() {
        if (count < ALARM_COLUMNS) {
            sound(SND_TICK);
        } else if (count < ALARM_COLUMNS + 1) {
            sound(SND_ALARM);
        }
        addColumn();
        if (count == MAX_COLUMNS) {
            endGame();
            return;
        }
        if (count > ALARM_COLUMNS - 1 && count < MAX_COLUMNS) {
            sound(SND_ALARM);
        }
    }

    private void endGame() {
        state = State.OVER;
        rotStep = 0;
        // FUN_004067ef adds every other grid's collision counter into the current one (unused).
        sound(SND_FINAL);
        if (listener != null) {
            listener.gameOver(score);
        }
    }

    // ---- upper grid ----------------------------------------------------------------------------

    /** FUN_00409344 + FUN_004098ab: make a new random column and add it to the shorter side. */
    void addColumn() {
        if (count == 0) {
            base = DROP_X;
            hl = 0;
        }
        if (count == MAX_COLUMNS) {
            return;
        }
        int at;
        if (hl < count / 2) {
            for (int i = count; i > 0; i--) {
                System.arraycopy(upper[i - 1], 0, upper[i], 0, 4);
            }
            at = 0;
            base += 20;
            hl++;
        } else {
            at = count;
        }
        int[] col = upper[at];
        do {
            for (int r = 0; r < 4; r++) {
                col[r] = rand(2);
            }
        } while (col[0] == 0 && col[1] == 0 && col[2] == 0 && col[3] == 0);
        int colour = 1 + (level < 4 ? rand(level) : rand(4));
        for (int r = 0; r < 4; r++) {
            col[r] = col[r] == 0 ? EMPTY : colour;
        }
        if (level > 4) {
            if (level > 6) {
                for (int r = 0; r < 4; r++) {
                    if (col[r] != 0 && rand(16) == 4) {
                        while (col[r] == colour) {
                            col[r] = rand(4) + 1;
                        }
                    }
                }
            }
            if (level == 5) {
                if (rand(8) == 4) {
                    for (int r = 0; r < 4; r++) {
                        col[r] = EMPTY;
                    }
                    int r = rand(4);
                    col[r] = rand(2) + 4;
                }
            } else {
                for (int r = 0; r < 4; r++) {
                    if (col[r] != 0 && rand(16) == 6 && col[r] == colour) {
                        col[r] = PALETTE;
                    }
                }
                if (level == 6) {
                    if (rand(8) == 4) {
                        for (int r = 0; r < 4; r++) {
                            col[r] = EMPTY;
                        }
                        col[rand(4)] = BOMB;
                    }
                } else {
                    for (int r = 0; r < 4; r++) {
                        if (col[r] != 0 && rand(16) == 6 && col[r] == colour) {
                            col[r] = BOMB;
                        }
                    }
                }
            }
        }
        count++;
        for (int r = 0; r < 4; r++) {
            if (col[r] == PALETTE || col[r] == BOMB) {
                tip(col[r]);
            }
        }
    }

    /** FUN_0040a135: tap left of the upper grid - it moves one column to the left. */
    boolean slideUpperLeft() {
        if (state != State.PLAYING) {
            return false;
        }
        upperFocus = true;
        if (count > 0 && base - 20 * (count - 1) > 0x11 && base > 0x13c) {
            sound(SND_CLICK);
            base -= 20;
            hl--;
            return true;
        }
        return false;
    }

    /** FUN_00409e3d: tap right of the upper grid - it moves one column to the right. */
    boolean slideUpperRight() {
        if (state != State.PLAYING) {
            return false;
        }
        upperFocus = true;
        if (count > 0 && base < 0x22e && base - 20 * (count - 1) < 0x116) {
            sound(SND_CLICK);
            base += 20;
            hl++;
            return true;
        }
        return false;
    }

    // ---- lower grid ----------------------------------------------------------------------------

    /** FUN_0040a6a0: tap left of the lower grid - it moves one column to the left. */
    boolean slideLowerLeft() {
        if (state != State.PLAYING || rotating()) {
            return false;
        }
        upperFocus = false;
        if (lowerCol < 3) {
            sound(SND_CLICK);
            lowerCol++;
            return true;
        }
        return false;
    }

    /** FUN_0040a415: tap right of the lower grid - it moves one column to the right. */
    boolean slideLowerRight() {
        if (state != State.PLAYING || rotating()) {
            return false;
        }
        upperFocus = false;
        if (lowerCol > 0) {
            sound(SND_CLICK);
            lowerCol--;
            return true;
        }
        return false;
    }

    /** Tap on the lower grid: left click rotates anticlockwise, right click clockwise. */
    boolean rotate(boolean clockwise) {
        if (state != State.PLAYING || rotating()) {
            return false;
        }
        upperFocus = false;
        sound(SND_ROTATE);
        rotClockwise = clockwise;
        rotStep = 1;
        rotMs = 0;
        return true;
    }

    private void stepRotation() {
        if (rotStep < 3) {
            rotStep++;
            return;
        }
        rotStep = 0;
        int[][] g = lower[current];
        int[][] old = new int[4][4];
        for (int c = 0; c < 4; c++) {
            System.arraycopy(g[c], 0, old[c], 0, 4);
        }
        for (int c = 0; c < 4; c++) {
            for (int r = 0; r < 4; r++) {
                // FUN_0040c988 (clockwise): new(c,r) = old(r, 3-c); FUN_0040cd55: new(c,r) = old(3-r, c)
                g[c][r] = rotClockwise ? old[r][3 - c] : old[3 - r][c];
            }
        }
    }

    /** Finish a running rotation at once (used by the simulation and before a drop). */
    void finishRotation() {
        while (rotStep != 0) {
            stepRotation();
        }
    }

    /** FUN_00407e2e: tap one of the four small grids to work on it. */
    boolean selectGrid(int g) {
        if (state != State.PLAYING || g < 0 || g > 3 || g == current || rotating()) {
            return false;
        }
        sound(SND_CLICK);
        previous = current;
        current = g;
        return true;
    }

    // ---- dropping (FUN_00406959) ---------------------------------------------------------------

    /** Tap on the highlighted column: drop it onto the lower grid. Returns true if it fell. */
    boolean drop() {
        upperFocus = true;
        if (state != State.PLAYING || rotating() || count == 0 || hl < 0 || hl >= count) {
            return false;
        }
        sound(SND_BALL);
        int[] col = upper[hl];
        int[] g = lower[current][lowerCol];
        int balls = 0;
        for (int r = 0; r < 4; r++) {
            if (col[r] != 0) {
                balls++;
            }
        }
        if (bonus == 0) {
            for (int r = 0; r < 4; r++) {
                if (isColour(g[r]) && isColour(col[r])) {
                    // No bonus points to pay with: the column stays, a new one is added instead.
                    penaltyColumn();
                    square[current] = 0;
                    sound(SND_LOST);
                    tip(TIP_NO_BONUS);
                    return false;
                }
            }
        }
        // Dominant colour of the grid, for the palette.
        int[] n = new int[5];
        for (int c = 0; c < 4; c++) {
            for (int r = 0; r < 4; r++) {
                int v = lower[current][c][r];
                if (v >= 1 && v <= 4) {
                    n[v]++;
                }
            }
        }
        int dominant = 1;
        for (int k = 2; k <= 4; k++) {
            if (n[k] > n[dominant]) {
                dominant = k;
            }
        }
        int hits = 0;
        int[] dropped = col.clone();
        for (int r = 0; r < 4; r++) {
            int lo = g[r], up = col[r];
            if (lo == 0 || up == 0) {
                g[r] = lo + up;
            } else if (!(isColour(lo) && isColour(up)) && !(isSpecial(lo) && isSpecial(up))) {
                if (lo == BOMB || up == BOMB) {
                    g[r] = EMPTY;
                } else if (lo == CYCLE || up == CYCLE) {
                    int v = lo == CYCLE ? up : lo;
                    g[r] = v == 4 ? 1 : v + 1;
                } else if (lo == PALETTE || up == PALETTE) {
                    g[r] = dominant;
                }
            } else {
                if (isColour(lo) && isColour(up)) {
                    hits++;
                    collisions[current]++;
                    if (hits == 1) {
                        bonus--;
                    }
                }
                g[r] = EMPTY;
            }
        }
        int before = count;
        for (int i = hl; i < count - 1; i++) {
            System.arraycopy(upper[i + 1], 0, upper[i], 0, 4);
        }
        for (int r = 0; r < 4; r++) {
            upper[count - 1][r] = EMPTY;
        }
        count--;
        if (balls > 0) {
            int points = level * difficulty * Math.max(1, 10 - before) * balls;
            score += points;
            square[current] += points;
        }
        if (listener != null) {
            listener.dropped(dropped, lowerCol);
        }
        if (hits > 0) {
            sound(SND_LOST);
            if (bonus < 0) {
                bonus = 0;
                endGame();
                return true;
            }
        }
        if (count <= hl && count > 0) {
            // Dropped the left-most column: the upper grid moves left by one.
            base -= 20;
            hl--;
        }
        if (count == 0) {
            penaltyColumn();
        }
        checkComplete();
        return true;
    }

    /** FUN_0040b0d4: add a column right away (only while fewer than 25). */
    private void penaltyColumn() {
        if (count < ALARM_COLUMNS) {
            sound(SND_TICK);
            addColumn();
        }
    }

    /** FUN_004080ae: a grid of 16 balls of one colour scores its SQUARE points and is cleared. */
    private void checkComplete() {
        int[] n = new int[5];
        for (int c = 0; c < 4; c++) {
            for (int r = 0; r < 4; r++) {
                int v = lower[current][c][r];
                if (v >= 1 && v <= 4) {
                    n[v]++;
                }
            }
        }
        boolean full = false;
        for (int k = 1; k <= 4; k++) {
            full |= n[k] == 16;
        }
        if (!full) {
            return;
        }
        sound(SND_HOME);
        score += square[current];
        square[current] = 0;
        boolean levelUp = toGo <= 1;
        if (listener != null) {
            int[][] copy = new int[4][];
            for (int c = 0; c < 4; c++) {
                copy[c] = lower[current][c].clone();
            }
            listener.gridCompleted(current, copy, levelUp);
        }
        for (int c = 0; c < 4; c++) {
            for (int r = 0; r < 4; r++) {
                lower[current][c][r] = EMPTY;
            }
        }
        collisions[current] = 0;
        current = previous;
        previous = previous == 0 ? 3 : previous - 1;
        if (levelUp) {
            bonus++;
            level++;
            startLevel();
        } else {
            toGo--;
        }
    }

    // ---- helpers -------------------------------------------------------------------------------

    static boolean isColour(int v) {
        return v >= 1 && v <= 4;
    }

    static boolean isSpecial(int v) {
        return v >= 5 && v <= 7;
    }

    /** FUN_0040229f: rand() % n, 0 for n < 1. */
    private int rand(int n) {
        return n < 1 ? 0 : rnd.nextInt(n);
    }

    private void sound(String name) {
        if (listener != null) {
            listener.sound(name);
        }
    }

    private void tip(int kind) {
        if (listener != null) {
            listener.tip(kind);
        }
    }
}
