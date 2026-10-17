package com.teff.puzzles.muddle;

import java.util.Arrays;
import java.util.Random;

/**
 * Muddled Casino rules, rebuilt from the decompiled MUDDLE.EXE (see PuzzlePort/MUDDLE/NOTES.md).
 * Plain Java (no Android) so it can be simulated headless.
 *
 * The table is board[row][col], 10 rows x 14 columns, row 0 at the BOTTOM (the original draws into a
 * bottom-up DIB). The exit is just right of row 0, column 13. {@link #tick()} runs every 50 ms like
 * the original's Win32 timer (SetTimer 0x32).
 */
final class Game {
    static final int ROWS = 10, COLS = 14, CARDS = 8;

    // Cell values (FUN_0040a9e7 / FUN_00406602).
    static final int EMPTY = 0;            // 1..8 = cards
    static final int JOKER = 9, HOLE = 10, BUMPER = 11, DICE = 12;

    // Difficulty (DAT_00412730).
    static final int TRAINING = 1, EASY = 2, MEDIUM = 3, HARD = 4, CHALLENGE = 5;

    /** Chip values (DAT_00412b88[1..4]); index 0 unused. */
    static final int[] DENOM = {1, 5, 10, 25, 50};

    /** Order list base for Training/Easy/Medium (DAT_00412710). */
    private static final int[] BASE_ORDER = {6, 3, 2, 7, 1, 8, 5, 4};

    // Sounds, by the original resource names (FUN_004026e6 order 1..7).
    static final String SND_WON = "CARDWONWAV", SND_COIN = "COINCHANGEWAV", SND_LOST = "CARDLOSTWAV",
            SND_MOVE = "MOVECARDWAV", SND_NOMOVE = "NOMOVECARDWAV", SND_START = "STARTGAMEWAV",
            SND_DIR = "CHANGEDIRWAV";

    // Tip kinds (FUN_00406602): the feature cell values, plus these two messages.
    static final int TIP_CHALLENGE_DONE = 13, TIP_TRAINING_DONE = 14;

    // Sides of the table: the arrow keys.
    static final int SIDE_UP = 0, SIDE_LEFT = 1, SIDE_RIGHT = 2, SIDE_DOWN = 3;

    enum State { TITLE, PLAYING, PAUSED, LEVEL_DONE, OVER }

    interface Listener {
        void sound(String name);

        void tip(int kind);

        void gameOver(int score);
    }

    /** Supplies the GLEVEL resources (2528-byte files). Returns null if missing. */
    interface LevelSource {
        byte[] load(String name);
    }

    final int[][] board = new int[ROWS][COLS];
    /** Cards still to remove; order[0] is next (the bottom of the right column). 0 = none. */
    final int[] order = new int[CARDS];

    // Saved copy for "Reset level" (DAT_00428660 / DAT_0042a250).
    private final int[][] savedBoard = new int[ROWS][COLS];
    private final int[] savedOrder = new int[CARDS];

    int dir = 3;                            // DAT_00412a60: selected group, 1..8
    final int[] sideMemory = {1, 7, 3, 5};  // DAT_00412a50..5c: last group per side
    int score;                              // DAT_00412020
    int bet = 1;                            // DAT_00412b84: chip index 1..4
    int playerCoins = 8, casinoCoins = 8;   // DAT_00412b7c / DAT_00412b80
    boolean betting;                        // DAT_00412b9c: true until the first move of a level
    int difficulty = TRAINING;              // option (DAT_0041202c)
    int startLevel = 1;                     // option (DAT_00412028)
    int mode = TRAINING;                    // difficulty of the running game (DAT_00412730)
    int level = 1;                          // DAT_00412024
    int blink;                              // DAT_00412ba4: 0..14
    State state = State.TITLE;
    Listener listener;
    LevelSource levels;
    /** Set when the game itself changed the difficulty (training done / challenge done). */
    boolean difficultyChanged;

    private int levelDoneTicks;
    final Random rnd;

    Game() {
        this(new Random());
    }

    Game(Random rnd) {
        this.rnd = rnd;
    }

    // ---- card attributes ----------------------------------------------------------------------

    static boolean isCard(int v) {
        return v >= 1 && v <= 8;
    }

    /** True if card v belongs to group d (FUN_0040a6aa); also gives the arrow-highlight frame. */
    static int groupFrame(int v, int d) {
        if (!isCard(v)) {
            return 0;
        }
        switch (d) {
            case 1: return v <= 4 ? 1 : 0;                                        // round, up
            case 2: return v >= 5 ? 1 : 0;                                        // square, up
            case 3: return (v == 1 || v == 2 || v == 5 || v == 6) ? 2 : 0;        // black, right
            case 4: return (v == 3 || v == 4 || v == 7 || v == 8) ? 2 : 0;        // red, right
            case 5: return (v == 1 || v == 3 || v == 5 || v == 7) ? 3 : 0;        // spade/diamond, down
            case 6: return (v == 2 || v == 4 || v == 6 || v == 8) ? 3 : 0;        // club/heart, down
            case 7: return (v == 2 || v == 3 || v == 5 || v == 8) ? 4 : 0;        // yellow, left
            case 8: return (v == 1 || v == 4 || v == 6 || v == 7) ? 4 : 0;        // white, left
            default: return 0;
        }
    }

    /** Row/column step of a group's direction (FUN_0040b2d9); row +1 = up. */
    static int dRow(int d) {
        return d == 1 || d == 2 ? 1 : d == 5 || d == 6 ? -1 : 0;
    }

    static int dCol(int d) {
        return d == 3 || d == 4 ? 1 : d == 7 || d == 8 ? -1 : 0;
    }

    static int sideOf(int d) {
        return d <= 2 ? SIDE_UP : d <= 4 ? SIDE_RIGHT : d <= 6 ? SIDE_DOWN : SIDE_LEFT;
    }

    /**
     * FUN_0040a0c1: true if a card or bumper lies anywhere further along the line in direction d.
     * Only the front card of each line moves.
     */
    boolean blockedAhead(int[][] b, int r, int c, int d) {
        int dr = dRow(d), dc = dCol(d);
        for (int rr = r + dr, cc = c + dc; rr >= 0 && rr < ROWS && cc >= 0 && cc < COLS; rr += dr, cc += dc) {
            int v = b[rr][cc];
            if (isCard(v) || v == BUMPER) {
                return true;
            }
        }
        return false;
    }

    /** FUN_0040a36a: highlight frame (1..4) if this card would move with the selected group, else 0. */
    int moveFrame(int r, int c) {
        int v = board[r][c];
        if (!isCard(v) || blockedAhead(board, r, c, dir)) {
            return 0;
        }
        return groupFrame(v, dir);
    }

    // ---- game flow ----------------------------------------------------------------------------

    /** FUN_0040c8f0. */
    void newGame() {
        mode = difficulty;
        level = startLevel;
        if (mode == TRAINING && level > 8) {
            level = 8;
        }
        playerCoins = 8;
        casinoCoins = 8;
        score = mode == TRAINING ? 0 : 100;
        clampBet();
        betting = true;
        generateLevel();
        save();
        blink = 0;
        state = State.PLAYING;
        sound(SND_START);
        featureTips();
    }

    private void save() {
        for (int r = 0; r < ROWS; r++) {
            System.arraycopy(board[r], 0, savedBoard[r], 0, COLS);
        }
        System.arraycopy(order, 0, savedOrder, 0, CARDS);
    }

    /** Lower the bet while it is not affordable (score must cover 8 chips). */
    private void clampBet() {
        while (bet > 1 && score < DENOM[bet] * 8) {
            bet--;
        }
    }

    private boolean mayContinue() {
        return mode < EASY || DENOM[1] * 8 <= score;
    }

    /** FUN_0040ca4b: called once the last card of a level is gone. */
    private void nextLevel() {
        level++;
        if (mode == TRAINING && level > 8) {
            difficulty = EASY;
            difficultyChanged = true;
            tip(TIP_TRAINING_DONE);
            startLevel = 1;
            newGame();
            return;
        }
        if (mode == CHALLENGE && level > 10) {
            mode = HARD;
            difficulty = HARD;
            difficultyChanged = true;
            tip(TIP_CHALLENGE_DONE);
        }
        clampBet();
        if (mayContinue()) {
            playerCoins = 8;
            casinoCoins = 8;
            betting = true;
            generateLevel();
            save();
            state = State.PLAYING;
            sound(SND_START);
            featureTips();
        } else {
            gameOver();
        }
    }

    /** FUN_0040cc37 ("Reset!"): start this level again from its saved layout. The bet is paid again. */
    void restartLevel() {
        if (state != State.PLAYING && state != State.PAUSED) {
            return;
        }
        clampBet();
        if (!mayContinue()) {
            gameOver();
            return;
        }
        for (int r = 0; r < ROWS; r++) {
            System.arraycopy(savedBoard[r], 0, board[r], 0, COLS);
        }
        System.arraycopy(savedOrder, 0, order, 0, CARDS);
        playerCoins = 8;
        casinoCoins = 8;
        betting = true;
        state = State.PLAYING;
    }

    /** FUN_004095e6. */
    private void gameOver() {
        state = State.OVER;
        sound(SND_LOST);
        if (listener != null) {
            listener.gameOver(score);
        }
    }

    /** FUN_0040c834: one-time tips for the features on a new table. */
    private void featureTips() {
        boolean[] seen = new boolean[13];
        for (int[] row : board) {
            for (int v : row) {
                if (v > 8 && v <= DICE && !seen[v]) {
                    seen[v] = true;
                    tip(v);
                }
            }
        }
    }

    /** 50 ms timer: blinks the next card and the exit arrow; finishes a level after a pause. */
    void tick() {
        if (state == State.PLAYING) {
            blink = (blink + 1) % 15;
        } else if (state == State.LEVEL_DONE) {
            if (--levelDoneTicks <= 0) {
                nextLevel();
            }
        }
    }

    /** The next card shows its bold picture for 5 of every 15 ticks (FUN_0040d05e). */
    boolean blinkBold() {
        return blink >= 10;
    }

    // ---- input --------------------------------------------------------------------------------

    /** An arrow key (FUN_0040d74d WM_KEYDOWN): first press picks the side, the second swaps groups. */
    void arrow(int side) {
        if (state != State.PLAYING) {
            return;
        }
        int a = 1 + 2 * new int[] {0, 3, 1, 2}[side];   // first group of the side: 1, 7, 3, 5
        if (dir == a) {
            dir = a + 1;
        } else if (dir == a + 1) {
            dir = a;
        } else {
            dir = sideMemory[side];
        }
        sideMemory[side] = dir;
        sound(SND_DIR);
    }

    /** Clicking a box beside the table picks that group directly (FUN_00409a42). */
    void selectGroup(int d) {
        if (state != State.PLAYING || d < 1 || d > 8) {
            return;
        }
        dir = d;
        sideMemory[sideOf(d)] = d;
        sound(SND_DIR);
    }

    /** Clicking a chip before the first move changes the bet (FUN_00409a42). */
    void chooseBet(int chip) {
        if (state != State.PLAYING || !betting || mode == TRAINING) {
            return;
        }
        bet = Math.max(1, Math.min(4, chip));
        clampBet();
        sound(SND_COIN);
    }

    /**
     * FUN_0040b42d: SPACE (knock = false) or TAB (knock = true).
     * Every front card of the selected group steps one cell. With SPACE the whole move is refused if
     * any of them would leave the table, fall into a hole or hit a joker it can't use. With TAB those
     * cards are knocked off instead (lost). The next card in the order may leave through the exit
     * (right of the bottom-right cell) or a joker.
     */
    boolean move(boolean knock) {
        if (state != State.PLAYING) {
            return false;
        }
        int[][] next = new int[ROWS][COLS];
        for (int r = 0; r < ROWS; r++) {
            System.arraycopy(board[r], 0, next[r], 0, COLS);
        }
        int[] nextOrder = order.clone();
        int teleR1 = -1, teleC1 = -1, teleR2 = -1, teleC2 = -1;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == DICE) {
                    if (teleR1 < 0) {
                        teleR1 = r;
                        teleC1 = c;
                    } else {
                        teleR2 = r;
                        teleC2 = c;
                    }
                }
            }
        }
        int into1 = 0, into2 = 0, won = 0, lost = 0;
        int dr = dRow(dir), dc = dCol(dir);
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                int v = board[r][c];
                if (!isCard(v) || blockedAhead(board, r, c, dir) || groupFrame(v, dir) == 0) {
                    continue;
                }
                int nr = r + dr, nc = c + dc;
                boolean off = nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS;
                int target = off ? EMPTY : board[nr][nc];
                if (off || target == JOKER || target == HOLE) {
                    boolean exit = nc == COLS && nr == 0;
                    if ((exit || target == JOKER) && v == order[0]) {
                        // Card won: drop the first entry of the order list.
                        System.arraycopy(nextOrder, 1, nextOrder, 0, CARDS - 1);
                        nextOrder[CARDS - 1] = 0;
                        next[r][c] = EMPTY;
                        if (target == JOKER) {
                            next[nr][nc] = EMPTY;   // a joker works once
                        }
                        won++;
                    } else {
                        if (!knock) {
                            sound(SND_NOMOVE);
                            return false;
                        }
                        for (int k = 0; k < CARDS; k++) {
                            if (nextOrder[k] == v) {
                                lost++;
                                System.arraycopy(nextOrder, k + 1, nextOrder, k, CARDS - 1 - k);
                                nextOrder[CARDS - 1] = 0;
                                break;
                            }
                        }
                        next[r][c] = EMPTY;
                    }
                } else {
                    if (nr == teleR1 && nc == teleC1) {
                        into1 = v;
                    }
                    if (nr == teleR2 && nc == teleC2) {
                        into2 = v;
                    }
                    next[nr][nc] = v;
                    next[r][c] = EMPTY;
                }
            }
        }
        // Dice: a card that ran into one die comes out at the other; both dice are then used up.
        if (teleR1 >= 0 && teleR2 >= 0 && (into1 > 0 || into2 > 0)) {
            next[teleR1][teleC1] = into2;
            next[teleR2][teleC2] = into1;
        }
        for (int r = 0; r < ROWS; r++) {
            System.arraycopy(next[r], 0, board[r], 0, COLS);
        }
        System.arraycopy(nextOrder, 0, order, 0, CARDS);

        if (betting) {
            // First move of the level: both stakes go into the pot, the player pays 8 chips.
            betting = false;
            playerCoins = 0;
            casinoCoins = 0;
            if (mode != TRAINING) {
                score -= DENOM[bet] * 8;
            }
        }
        if (won < 1 && lost < 1) {
            sound(SND_MOVE);
        } else {
            if (won > 0) {
                int before = playerCoins;
                if (playerCoins < 4) {
                    playerCoins += 1;
                } else if (playerCoins < 8) {
                    playerCoins += 2;
                } else if (playerCoins < 11) {
                    playerCoins += 3;
                } else {
                    playerCoins += 5;
                }
                if (mode != TRAINING) {
                    score += DENOM[bet] * (playerCoins - before);
                }
                sound(SND_WON);
            }
            if (lost > 0) {
                sound(SND_LOST);
                for (int i = 0; i < lost; i++) {
                    if (casinoCoins == 0) {
                        casinoCoins = 5;
                    } else if (casinoCoins == 5) {
                        casinoCoins = 8;
                    } else if (casinoCoins == 8) {
                        casinoCoins = 10;
                    } else if (casinoCoins == 10) {
                        casinoCoins = 12;
                    } else {
                        casinoCoins++;
                    }
                }
            }
            playerCoins = Math.min(playerCoins, 16);
            casinoCoins = Math.min(casinoCoins, 16);
            if (playerCoins + casinoCoins > 16) {
                casinoCoins = 16 - playerCoins;
            }
        }
        if (order[0] == 0) {
            state = State.LEVEL_DONE;
            levelDoneTicks = 20;   // the original sleeps 1 s before the next table
        }
        return true;
    }

    // ---- levels -------------------------------------------------------------------------------

    /** FUN_0040bfd5: Training 1-8 and Alexey's Challenge 1-10 load GLEVEL files, the rest is random. */
    void generateLevel() {
        if (mode == TRAINING && level >= 1 && level <= 8 && loadLevel(String.format("LEVELT%03d", level))) {
            return;
        }
        if (mode == CHALLENGE && level >= 1 && level <= 10 && loadLevel(String.format("LEVEL%03d", level))) {
            return;
        }
        for (int attempt = 0; ; attempt++) {
            if (randomLevel()) {
                return;
            }
            if (attempt >= 100 && loadLevel(String.format("LEVEL%03d", rnd.nextInt(10) + 1))) {
                return;
            }
            if (attempt > 10000) {
                throw new IllegalStateException("could not build a table");
            }
        }
    }

    /** Parses a GLEVEL file: order list at 0x80 (16-byte entries), table at 0x120 (row 0 first). */
    boolean loadLevel(String name) {
        byte[] d = levels == null ? null : levels.load(name);
        if (d == null) {
            return false;
        }
        int[][] b = parseBoard(d);
        int[] o = parseOrder(d);
        if (b == null || o == null) {
            return false;
        }
        for (int r = 0; r < ROWS; r++) {
            System.arraycopy(b[r], 0, board[r], 0, COLS);
        }
        System.arraycopy(o, 0, order, 0, CARDS);
        return true;
    }

    static int[][] parseBoard(byte[] d) {
        if (d.length < 0x120 + 0x8c0) {
            return null;
        }
        int[][] b = new int[ROWS][COLS];
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                int v = le32(d, 0x120 + r * 0xe0 + c * 0x10);
                b[r][c] = v >= 0 && v <= DICE ? v : EMPTY;
            }
        }
        return b;
    }

    static int[] parseOrder(byte[] d) {
        if (d.length < 0x80 + 0xa0) {
            return null;
        }
        int[] o = new int[CARDS];
        for (int i = 0; i < CARDS; i++) {
            int v = le32(d, 0x80 + i * 0x10);
            o[i] = isCard(v) ? v : 0;
        }
        return o;
    }

    private static int le32(byte[] d, int p) {
        return (d[p] & 0xff) | (d[p + 1] & 0xff) << 8 | (d[p + 2] & 0xff) << 16 | (d[p + 3] & 0xff) << 24;
    }

    /**
     * One try of the random table builder: pick the order, scatter features, then play backwards
     * from an empty table, feeding cards in through the exit (FUN_0040bc74 with param 0).
     */
    private boolean randomLevel() {
        for (int[] row : board) {
            Arrays.fill(row, EMPTY);
        }
        Arrays.fill(order, 0);
        if (mode == TRAINING || mode == EASY) {
            int start = rnd.nextInt(8);
            for (int i = 0; i < CARDS; i++) {
                order[i] = BASE_ORDER[(start + i) & 7];
            }
        } else if (mode == MEDIUM) {
            int[] base = BASE_ORDER.clone();
            for (int i = 0; i < 4; i++) {
                if (rnd.nextInt(2) == 1) {
                    int t = base[2 * i];
                    base[2 * i] = base[2 * i + 1];
                    base[2 * i + 1] = t;
                }
            }
            int start = rnd.nextInt(8);
            for (int i = 0; i < CARDS; i++) {
                order[i] = base[(start + i) & 7];
            }
        } else {
            boolean[] used = new boolean[9];
            for (int i = 0; i < CARDS; i++) {
                int v;
                do {
                    v = rnd.nextInt(8) + 1;
                } while (used[v]);
                used[v] = true;
                order[i] = v;
            }
        }
        if (rnd.nextInt(10) > 8 - mode) placeFeature(HOLE);
        if (rnd.nextInt(10) > 10 - mode) placeFeature(HOLE);
        if (rnd.nextInt(10) > 5) placeFeature(BUMPER);
        if (rnd.nextInt(10) > 5) placeFeature(BUMPER);
        if (rnd.nextInt(10) > mode + 2) placeFeature(JOKER);
        if (rnd.nextInt(10) > mode * 2 + 2) placeFeature(JOKER);
        if (rnd.nextInt(10) > 5) {
            board[rnd.nextInt(5) + 2][rnd.nextInt(2) + 2] = DICE;
            int r = rnd.nextInt(5) + 2, c = rnd.nextInt(2) + 9;
            board[r][c] = board[r][c] == DICE ? EMPTY : DICE;
        }

        int saveDir = dir;
        int nextIn = CARDS - 1;   // DAT_00412ba0: next card to feed in, from the end of the order
        int fails = 0;
        for (int i = 0; i < 2000; i++) {
            dir = rnd.nextInt(8) + 1;
            int before = nextIn;
            nextIn = scrambleStep(nextIn);
            boolean ok = nextIn != Integer.MIN_VALUE;
            if (!ok) {
                nextIn = before;
                fails++;
            } else {
                fails = 0;
            }
            if (fails > 99) {
                break;
            }
        }
        dir = saveDir;
        if (nextIn >= 0) {
            return false;
        }
        int first = order[0];
        if (mode < HARD) {
            return board[0][13] != first;
        }
        return board[0][13] != first && board[0][12] != first && board[1][12] != first && board[1][13] != first;
    }

    private void placeFeature(int v) {
        board[rnd.nextInt(5) + 2][rnd.nextInt(9) + 2] = v;
    }

    /**
     * Backwards move of the current group; returns the new feed index, or MIN_VALUE if refused.
     */
    private int scrambleStep(int nextIn) {
        int[][] next = new int[ROWS][COLS];
        for (int r = 0; r < ROWS; r++) {
            System.arraycopy(board[r], 0, next[r], 0, COLS);
        }
        int dr = -dRow(dir), dc = -dCol(dir);
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                int v = board[r][c];
                if (!isCard(v) || blockedAhead(board, r, c, dir) || groupFrame(v, dir) == 0) {
                    continue;
                }
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || board[nr][nc] != EMPTY) {
                    return Integer.MIN_VALUE;
                }
                next[nr][nc] = v;
                next[r][c] = EMPTY;
            }
        }
        if (nextIn >= 0 && order[nextIn] > 0 && (dir == 3 || dir == 4) && rowEmpty(0)
                && groupFrame(order[nextIn], dir) > 0) {
            next[0][13] = order[nextIn];
            nextIn--;
        }
        for (int r = 0; r < ROWS; r++) {
            System.arraycopy(next[r], 0, board[r], 0, COLS);
        }
        return nextIn;
    }

    private boolean rowEmpty(int r) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] != EMPTY) {
                return false;
            }
        }
        return true;
    }

    // ---- helpers ------------------------------------------------------------------------------

    int cardsLeft() {
        int n = 0;
        for (int v : order) {
            if (v != 0) n++;
        }
        return n;
    }

    private void sound(String s) {
        if (listener != null) {
            listener.sound(s);
        }
    }

    private void tip(int kind) {
        if (listener != null) {
            listener.tip(kind);
        }
    }
}
