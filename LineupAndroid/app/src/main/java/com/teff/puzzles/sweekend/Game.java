package com.teff.puzzles.sweekend;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Random;

/**
 * Spring Weekend rules, recovered from SWEEKEND.EXE (see PuzzlePort/SWEEKEND/NOTES.md).
 * Plain Java (no Android imports) so it can be simulated headless.
 *
 * The pond holds 19 figures on a hexagon (rows of 3-4-5-4-3). The 7 inner figures are the
 * ring centres: clicking one turns the 6 figures around it one step. The model (target) is the
 * level read from a GLEVEL resource; the pond starts as the model scrambled by ring turns.
 * Coordinates are original screen pixels (628x400 window).
 */
final class Game {

    interface Listener {
        void sound(int id);

        /** Tournament game lost (out of moves). */
        void gameOver(int score);
    }

    enum State { TITLE, PLAYING, PAUSED, LEVEL_DONE, OVER }

    static final int N = 19;
    static final int FLOWER_KINDS = 11;
    static final int TRAINING = 1, TOURNAMENT = 2;

    // Sound ids of FUN_00407c42 (table at 0x416c40, filled in FUN_00407f6b).
    static final int SND_ROTATE = 1, SND_NOROTATE = 2, SND_NEXTLEVEL = 3, SND_GAMEOVER1 = 4,
            SND_GAMEOVER2 = 5, SND_BEE = 6, SND_TIME1 = 7, SND_TIME2 = 8, SND_TIME3 = 9;

    /** Cell offsets from the pond centre, y pointing UP (table at 0x414070, 12-byte stride). */
    static final int[] CX = {-54, 0, 54, -81, -27, 27, 81, -108, -54, 0, 54, 108, -81, -27, 27, 81, -54, 0, 54};
    static final int[] CY = {94, 94, 94, 47, 47, 47, 47, 0, 0, 0, 0, 0, -47, -47, -47, -47, -94, -94, -94};
    /** Pond centre on screen: sprites at (x + 200, 190 - y); clicks map back the same way. */
    static final int POND_X = 200, POND_Y = 190;
    /** Model: half-size copy at (x * 0.5 + 474, 98 - y * 0.5) (FUN_00402aa1, FUN_00403bd6). */
    static final int MODEL_X = 474, MODEL_Y = 98;
    /** Original hit test: squared distance to a clickable cell below 0x2d9 (FUN_00405c6a). */
    static final int HIT_RADIUS = 27;

    /** GLEVEL files store the cells centre-first in a spiral; cell i = file[FILE_ORDER[i]] (0x414020). */
    static final int[] FILE_ORDER = {7, 18, 17, 8, 1, 6, 16, 9, 2, 0, 5, 15, 10, 3, 4, 14, 11, 12, 13};

    /**
     * The 7 rings (table at 0x414158, 13 ints each): centre cell, then 6 (from, to) pairs.
     * Right button (FUN_004051ab) moves each figure from -> to (clockwise on screen);
     * left button (FUN_00405656) moves to -> from (counter-clockwise).
     */
    static final int[] RING_CENTRE = {4, 5, 8, 9, 10, 13, 14};
    static final int[][][] RING_PAIRS = {
            {{0, 1}, {1, 5}, {5, 9}, {9, 8}, {8, 3}, {3, 0}},
            {{1, 2}, {2, 6}, {6, 10}, {10, 9}, {9, 4}, {4, 1}},
            {{3, 4}, {4, 9}, {9, 13}, {13, 12}, {12, 7}, {7, 3}},
            {{4, 5}, {5, 10}, {10, 14}, {14, 13}, {13, 8}, {8, 4}},
            {{5, 6}, {6, 11}, {11, 15}, {15, 14}, {14, 9}, {9, 5}},
            {{8, 9}, {9, 14}, {14, 17}, {17, 16}, {16, 12}, {12, 8}},
            {{9, 10}, {10, 15}, {15, 18}, {18, 17}, {17, 13}, {13, 9}},
    };

    static final int ANIM_TICKS = 4;        // 4 animation steps (FUN_004051ab), one per 50 ms tick
    static final int DONE_TICKS = 12;       // score count-up + pause before the next level (~600 ms)
    static final int DONE_HIDE_TICK = 8;    // pond flowers are cleared shortly before the next level

    // ---- state ---------------------------------------------------------------------------------

    final short[][] levels;   // raw GLEVEL data, 50 x 19
    final Random rnd;
    Listener listener;

    State state = State.TITLE;
    int mode = TOURNAMENT;    // DAT_004145f8
    int startLevel = 1;       // DAT_00414f70, 1..50
    int level;                // DAT_004145dc
    int moves;                // DAT_004145d8, moves left
    int score;                // DAT_00414f68
    final int[] board = new int[N];   // DAT_004164b0 (pond)
    final int[] model = new int[N];   // DAT_004163e0 (target)
    final int[] start = new int[N];   // DAT_00416440 (scramble, for Reset in training)

    // undo (not in the original): board + moves before each turn of this level
    private final ArrayDeque<int[]> undo = new ArrayDeque<>();

    // turn animation
    int animRing = -1;
    boolean animCw;
    int animTick;
    int animSerial;

    int doneTick;
    int[][] lastScramble = new int[0][];   // ring turns used by the scramble (for tests)

    Game(short[][] levels, Random rnd) {
        this.levels = levels;
        this.rnd = rnd;
    }

    private int rand(int n) {     // FUN_00403aef
        return n < 1 ? 0 : rnd.nextInt(n);
    }

    // ---- level setup ---------------------------------------------------------------------------

    /** Moves allowed (FUN_00404d57), computed from the given level number. */
    static int movesFor(int lvl) {
        int m = lvl + 10;
        if (lvl > 50) {
            m = 50 - (lvl - 50);
        }
        if (m < 10 && lvl > 50) {
            m = 10;
        }
        if (m < 20 && lvl < 50) {
            m = 20;
        }
        if (m > 99) {
            m = 99;
        }
        return m;
    }

    /** Level file loader FUN_0040445d: reorder cells, then give each colour a random flower. */
    void loadLevel(int number, int[] out) {
        int idx = number - 1;
        if (idx < 0 || idx > 49) {
            idx = rand(30) + 20;
        }
        short[] raw = levels[idx];
        int[] cells = new int[N];
        for (int i = 0; i < N; i++) {
            cells[i] = raw[FILE_ORDER[i]];
        }
        int[] map = new int[256];
        Arrays.fill(map, -1);
        boolean[] used = new boolean[FLOWER_KINDS];
        for (int i = 0; i < N; i++) {
            int key = cells[i] & 0xff;
            if (map[key] < 0) {
                int pick = 0;
                for (int tries = 0; tries < 0x2000; tries++) {
                    int f = rand(FLOWER_KINDS);
                    if (!used[f]) {
                        used[f] = true;
                        pick = f;
                        break;
                    }
                }
                map[key] = pick;
            }
            cells[i] = map[key];
        }
        System.arraycopy(cells, 0, out, 0, N);
    }

    /**
     * Scramble FUN_00404984: each ring in order turns once clockwise with probability 6/7
     * (twice over the rings above level 32), repeated until the pond differs from the model.
     * Faithful quirk: the result is the state before the last ring's turn of the final pass.
     */
    void scramble(int[] p) {
        boolean allSame = true;
        for (int i = 1; i < N; i++) {
            allSame &= p[i] == p[0];
        }
        if (allSame) {
            lastScramble = new int[0][];
            return;
        }
        int[] before;
        java.util.List<int[]> ops = new java.util.ArrayList<>();
        do {
            ops.clear();
            int[] cur = p.clone();
            before = cur.clone();
            int passes = level > 32 ? 2 : 1;
            for (int pass = 0; pass < passes; pass++) {
                for (int r = 0; r < 7; r++) {
                    before = cur.clone();
                    if (rand(7) != 0) {
                        turn(cur, r, true);
                        ops.add(new int[] {r, 1});
                    } else {
                        ops.add(new int[] {r, 0});
                    }
                }
            }
            // the last op recorded never reaches the pond (see quirk above)
            ops.remove(ops.size() - 1);
        } while (Arrays.equals(p, before));
        System.arraycopy(before, 0, p, 0, N);
        java.util.List<int[]> applied = new java.util.ArrayList<>();
        for (int[] op : ops) {
            if (op[1] == 1) {
                applied.add(new int[] {op[0]});
            }
        }
        lastScramble = applied.toArray(new int[0][]);
    }

    static void turn(int[] cells, int ring, boolean clockwise) {
        int[] old = cells.clone();
        for (int[] pr : RING_PAIRS[ring]) {
            if (clockwise) {
                cells[pr[1]] = old[pr[0]];
            } else {
                cells[pr[0]] = old[pr[1]];
            }
        }
    }

    private void setUpLevel(int fileLevel) {
        loadLevel(fileLevel, board);
        System.arraycopy(board, 0, model, 0, N);
        scramble(board);
        System.arraycopy(board, 0, start, 0, N);
        undo.clear();
        animRing = -1;
    }

    /** New game, FUN_00404f6d. */
    void newGame() {
        state = State.PLAYING;
        score = 0;
        level = startLevel;
        moves = movesFor(level);
        setUpLevel(level);
    }

    /** Next level, FUN_00404df5 (moves are computed before the level number goes up). */
    void nextLevel() {
        moves = movesFor(level);
        level++;
        setUpLevel(level < 50 ? level : level % 18 + 32);
        state = State.PLAYING;
    }

    /** Training-mode "Reset!" (menu 0xc9, FUN_0040512c): back to this level's scramble. */
    boolean canRetry() {
        return mode == TRAINING && state == State.PLAYING && animRing < 0;
    }

    void retry() {
        if (!canRetry()) {
            return;
        }
        moves = movesFor(level);
        System.arraycopy(start, 0, board, 0, N);
        undo.clear();
    }

    // ---- input ---------------------------------------------------------------------------------

    boolean busy() {
        return animRing >= 0;
    }

    /** Clickable cell nearest to the screen point within radius, or -1. */
    static int cellAt(float sx, float sy, float radius) {
        float tx = sx - POND_X, ty = POND_Y - sy;
        int best = -1;
        float bestD = radius * radius;
        for (int r = 0; r < RING_CENTRE.length; r++) {
            int c = RING_CENTRE[r];
            float dx = CX[c] - tx, dy = CY[c] - ty;
            float d = dx * dx + dy * dy;
            if (d < bestD) {
                bestD = d;
                best = c;
            }
        }
        return best;
    }

    static int ringOf(int cell) {
        for (int r = 0; r < RING_CENTRE.length; r++) {
            if (RING_CENTRE[r] == cell) {
                return r;
            }
        }
        return -1;
    }

    /** A click in the pond that missed every ring centre (FUN_00405c6a: NOROTATE, no move used). */
    void miss() {
        if (state == State.PLAYING && !busy()) {
            sound(SND_NOROTATE);
        }
    }

    /** Click on a ring centre: right button = clockwise, left button = counter-clockwise. */
    boolean turnAt(int cell, boolean clockwise) {
        int ring = ringOf(cell);
        if (state != State.PLAYING || busy() || ring < 0) {
            return false;
        }
        sound(SND_ROTATE);
        undo.push(snapshot());
        if (moves > 0) {
            moves--;
        }
        turn(board, ring, clockwise);
        animRing = ring;
        animCw = clockwise;
        animTick = 0;
        animSerial++;
        return true;
    }

    boolean canUndo() {
        return state == State.PLAYING && !busy() && !undo.isEmpty();
    }

    void undo() {
        if (!canUndo()) {
            return;
        }
        int[] s = undo.pop();
        System.arraycopy(s, 0, board, 0, N);
        moves = s[N];
    }

    private int[] snapshot() {
        int[] s = Arrays.copyOf(board, N + 1);
        s[N] = moves;
        return s;
    }

    boolean solved() {   // FUN_0040492f
        return Arrays.equals(board, model);
    }

    /** After the turn animation: win check, then the tournament move limit (WM_LBUTTONDOWN). */
    private void resolveTurn() {
        if (solved()) {
            score += (moves * 5 + 10) * (level / 7 + 1);
            sound(SND_NEXTLEVEL);
            state = State.LEVEL_DONE;
            doneTick = 0;
            undo.clear();
        } else if (mode == TOURNAMENT && moves == 0) {
            state = State.OVER;
            undo.clear();
            if (listener != null) {
                listener.gameOver(score);
            }
        }
    }

    /** 50 ms timer (SetTimer period 0x32). */
    void tick() {
        if (state == State.PAUSED) {
            return;
        }
        if (animRing >= 0) {
            animTick++;
            if (animTick >= ANIM_TICKS) {
                animRing = -1;
                if (state == State.PLAYING) {
                    resolveTurn();
                }
            }
        } else if (state == State.LEVEL_DONE) {
            doneTick++;
            if (doneTick >= DONE_TICKS) {
                nextLevel();
            }
        }
    }

    /** Pond flowers are hidden on the title, after a game is lost, and just before a new level. */
    boolean pondVisible() {
        return state == State.PLAYING || state == State.PAUSED
                || (state == State.LEVEL_DONE && doneTick < DONE_HIDE_TICK);
    }

    private void sound(int id) {
        if (listener != null) {
            listener.sound(id);
        }
    }
}
