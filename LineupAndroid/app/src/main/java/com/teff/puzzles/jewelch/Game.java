package com.teff.puzzles.jewelch;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * Jewel Chase rules, recovered from JEWELCH.EXE (see PuzzlePort/JEWELCH/NOTES.md).
 * Plain Java (no Android imports) so it can be simulated headless.
 *
 * Board: 10 rows x 15 columns of 36 px tiles drawn 40 px below the top (540 x 400 screen).
 * One logic tick = one pass of the original idle loop (SendMessage 0x42B + Sleep(10)).
 */
public final class Game {
    public static final int ROWS = 10, COLS = 15, CELL = 36, TOP = 40;
    public static final int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
    private static final int[] DR = {-1, 0, 1, 0}, DC = {0, 1, 0, -1};

    // item (DAT_004285f2 + cell*10)
    public static final int EXIT = 1, EMERALD = 2, RUBY = 3, DIAMOND = 4, CASH = 5, GOLD = 6,
            SILVER = 7, WATCH = 8, SWITCH = 9, KEY = 10, STOPWATCH = 11, BOMB = 12;
    // item2 (DAT_004285f4 + cell*10): things that block a jump target
    public static final int BALL = 13, BARS = 14, LOCKED = 15, GATE = 16;
    private static final int MOVED = 0x28;  // FUN_0040a596 marks a ball that already rolled this round

    public static final int RIVAL = 0, PLAYER = 1;

    // Sound ids = WAV resource numbers (FUN_0040f923)
    public static final int SND_GEM = 11, SND_CASH = 12, SND_WATCH = 13, SND_STOPWATCH = 14, SND_COIN = 15,
            SND_SWITCH = 16, SND_KEY = 17, SND_BOMB = 18, SND_BUMP = 19, SND_LEVEL = 20, SND_LOSE = 21,
            SND_EXIT_OPEN = 23;

    /** Points per item (FUN_0040718f), multiplied by max(1, difficulty - 1). */
    private static final int[] VALUE = {0, 0, 25, 20, 30, 10, 2, 1, 5, 0, 0, 3, 0};

    /** Animation frame counts of sprite types 1..28 (table at 0x4205D0, field +0xC). */
    public static final int[] FRAMES = {0, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    public static final int LAST_LEVEL = 99;
    /** Difficulty: 1 Training (no rival), 2 Easy, 3 Medium, 4 Hard. */
    public static final int TRAINING = 1;

    public enum State { TITLE, PLAYING, PAUSED, OVER, WON }

    public interface Listener {
        void sound(int id);

        void levelStarted(int level);

        /** Game ended: won = finished level 99. */
        void gameOver(boolean won, int score);
    }

    public interface LevelSource {
        byte[] load(int level);
    }

    // ---- board -----------------------------------------------------------------------------------
    public final int[][] tile = new int[ROWS][COLS];
    public final int[][] mask = new int[ROWS][COLS];
    public final int[][] item = new int[ROWS][COLS];
    public final int[][] item2 = new int[ROWS][COLS];
    public final int[][] itemFrame = new int[ROWS][COLS];
    public final int[][] item2Frame = new int[ROWS][COLS];
    public final int[][] occupant = new int[ROWS][COLS];

    // ---- thieves (DAT_00420AD8, 24-byte records) ---------------------------------------------------
    public final int[] row = new int[3], col = new int[3], dir = new int[3], frame = new int[3];
    public final boolean[] present = new boolean[3];

    public State state = State.TITLE;
    public int level, score, rivalScore;
    public int difficulty = 2, startLevel = 1;
    public Listener listener;
    public LevelSource source;
    public final Random rnd;

    private int rivalTimer, ballTimer, item2AnimTimer, itemAnimTimer, thiefAnimTimer;
    private boolean exitSoundPending;
    /** Planned rival route (cells as row*16+col), next step first. Empty = needs planning. */
    private final ArrayDeque<Integer> rivalPath = new ArrayDeque<>();

    public Game(Random rnd) {
        this.rnd = rnd;
    }

    public Game() {
        this(new Random());
    }

    public boolean hasRival() {
        return difficulty > TRAINING;
    }

    /** Ticks between two rival moves: 100 / (difficulty - 1) (message 0x65 handler). */
    public int rivalPeriod() {
        return 100 / Math.max(1, difficulty - 1);
    }

    // ---- game flow -------------------------------------------------------------------------------

    public void newGame() {
        score = 0;
        rivalScore = 0;
        for (int i = 0; i < 3; i++) {
            dir[i] = UP;
            frame[i] = 0;
        }
        level = Math.max(1, Math.min(LAST_LEVEL, startLevel)) - 1;
        nextLevel();
    }

    /** Message 0x22B: advance to the next level, or the game is won after level 99. */
    private void nextLevel() {
        level++;
        if (level > LAST_LEVEL) {
            level = LAST_LEVEL;
            state = State.WON;
            if (listener != null) listener.gameOver(true, score);
            return;
        }
        if (!hasRival()) {
            score = 0;  // Training: score starts over every level
        }
        loadLevel(Level.parse(source.load(level)));
        state = State.PLAYING;
        if (listener != null) listener.levelStarted(level);
    }

    /** FUN_0040a07f. */
    public void loadLevel(Level lv) {
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                tile[r][c] = lv.tiles[r * COLS + c];
                mask[r][c] = Level.colourMask(tile[r][c]);
                item[r][c] = 0;
                item2[r][c] = 0;
                itemFrame[r][c] = 0;
                item2Frame[r][c] = 0;
                occupant[r][c] = -1;
            }
        }
        for (int[] e : lv.items) {
            if (inside(e[0], e[1])) item[e[0]][e[1]] = e[2];
        }
        for (int[] e : lv.items2) {
            if (inside(e[0], e[1])) item2[e[0]][e[1]] = e[2];
        }
        for (int i = 0; i < 3; i++) {
            row[i] = lv.startRow[i];
            col[i] = lv.startCol[i];
            present[i] = false;
        }
        place(PLAYER);
        if (hasRival()) {
            place(RIVAL);
        }
        rivalPath.clear();
        rivalTimer = rivalPeriod();
        ballTimer = 100;
        itemAnimTimer = 10;
        thiefAnimTimer = 14;
        item2AnimTimer = 13;
        exitSoundPending = true;
    }

    private void place(int who) {
        if (inside(row[who], col[who])) {
            present[who] = true;
            occupant[row[who]][col[who]] = who;
        }
    }

    public void pause() {
        if (state == State.PLAYING) state = State.PAUSED;
    }

    public void resume() {
        if (state == State.PAUSED) state = State.PLAYING;
    }

    // ---- per tick (message 0x42B) ------------------------------------------------------------------

    public void tick() {
        if (state != State.PLAYING) {
            return;
        }
        balls();               // FUN_0040a90d
        animateThieves();      // FUN_0040a80e
        animateItems();        // FUN_0040a88a
        if (!valuablesLeft() && exitSoundPending) {   // FUN_004093e4
            exitSoundPending = false;
            sound(SND_EXIT_OPEN);
        }
        if (hasRival() && state == State.PLAYING) {
            rival();           // FUN_0040c99b
        }
    }

    private void animateThieves() {
        if (--thiefAnimTimer < 1) {
            thiefAnimTimer = 14;
            for (int i = 0; i < 3; i++) {
                if (present[i]) frame[i] = (frame[i] + 1) % 4;
            }
        }
    }

    private void animateItems() {
        if (--itemAnimTimer < 1) {
            itemAnimTimer = 10;
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    int it = item[r][c];
                    if (it > 0 && it <= FRAMES.length && FRAMES[it - 1] > 0 && item2[r][c] == 0 && occupant[r][c] == -1) {
                        itemFrame[r][c] = (itemFrame[r][c] + 1) % FRAMES[it - 1];
                    }
                }
            }
        }
    }

    /** Every 100 ticks every rolling ball rolls one jump in one shared random direction. */
    private void balls() {
        item2AnimTimer--;
        if (--ballTimer < 1) {
            ballTimer = 100;
            boolean[] tried = new boolean[4];
            int d = rnd.nextInt(4);
            int moved = 0;
            while (moved == 0 && !(tried[0] && tried[1] && tried[2] && tried[3])) {
                int pick = -1;
                for (int k = d; k < 4; k++) {
                    if (!tried[k]) { pick = k; break; }
                }
                if (pick < 0) {
                    for (int k = 0; k < 4; k++) {
                        if (!tried[k]) { pick = k; break; }
                    }
                }
                d = pick;
                tried[d] = true;
                for (int r = 0; r < ROWS; r++) {
                    for (int c = 0; c < COLS; c++) {
                        int v = item2[r][c];
                        if (v != 0 && v < MOVED && rollBall(r, c, d)) {
                            moved++;
                        }
                    }
                }
            }
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (item2[r][c] >= MOVED) {
                        item2[r][c] -= MOVED;
                        item2Frame[r][c] = rnd.nextInt(14);
                    }
                }
            }
        } else if (item2AnimTimer < 1) {
            item2AnimTimer = 13;
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    int v = item2[r][c];
                    if (v > 0 && v <= 16 && FRAMES[v - 1] > 0 && occupant[r][c] == -1) {
                        item2Frame[r][c] = (item2Frame[r][c] + 1) % FRAMES[v - 1];
                    }
                }
            }
        }
    }

    /** FUN_0040a596: doors count as "done", a ball jumps like a thief if it can. */
    private boolean rollBall(int r, int c, int d) {
        if (item2[r][c] >= BARS) {
            return true;
        }
        int t = jumpTarget(r, c, d);
        if (t < 0) {
            return false;
        }
        int tr = t >> 4, tc = t & 15;
        if (occupant[tr][tc] != -1) {
            return false;
        }
        int v = item2[r][c];
        item2[r][c] = 0;
        item2[tr][tc] = v + MOVED;
        return true;
    }

    // ---- movement -------------------------------------------------------------------------------------

    /**
     * FUN_00408fab with "real" = 1: look along the direction for the first tile that shares a colour with
     * the tile we stand on (tiles of other colours are jumped over). A ball or door there blocks.
     * Returns row*16+col or -1.
     */
    public int jumpTarget(int r, int c, int d) {
        int m = mask[r][c];
        int nr = r + DR[d], nc = c + DC[d];
        while (inside(nr, nc)) {
            if ((m & mask[nr][nc]) != 0) {
                return item2[nr][nc] != 0 ? -1 : (nr << 4) | nc;
            }
            nr += DR[d];
            nc += DC[d];
        }
        return -1;
    }

    /** Player pressed an arrow key (FUN_004095c5 with thief 1). */
    public void movePlayer(int d) {
        if (state == State.PLAYING && present[PLAYER]) {
            move(PLAYER, d);
        }
    }

    /** FUN_004095c5. */
    private void move(int who, int d) {
        dir[who] = d;
        int t = jumpTarget(row[who], col[who], d);
        if (t < 0) {
            sound(SND_BUMP);
            return;
        }
        int tr = t >> 4, tc = t & 15;
        if (occupant[tr][tc] != -1) {
            return;
        }
        occupant[row[who]][col[who]] = -1;
        boolean ended = false;
        if (item[tr][tc] != 0) {
            ended = collect(who, tr, tc, true);
        }
        row[who] = tr;
        col[who] = tc;
        occupant[tr][tc] = who;
        if (ended) {
            endLevel(who);
        }
    }

    /**
     * Picks up the item at (r, c) if allowed. The exit (item 1) can only be taken when it is the
     * highest item left, i.e. every valuable is gone. Returns true if that emptied the level.
     * filtered: the player's move ignores keys/switches/bombs when computing that maximum
     * (FUN_004095c5); the rival's path step does not (FUN_0040c459).
     */
    private boolean collect(int who, int r, int c, boolean filtered) {
        int it = item[r][c];
        if (it <= EXIT && it != maxItem(filtered)) {
            return false;
        }
        if (it > 0 && it < VALUE.length) {
            if (who == PLAYER) {
                score += VALUE[it] * Math.max(1, difficulty - 1);
                switch (it) {
                    case EMERALD: case RUBY: case DIAMOND: sound(SND_GEM); break;
                    case CASH: sound(SND_CASH); break;
                    case GOLD: case SILVER: sound(SND_COIN); break;
                    case WATCH: sound(SND_WATCH); break;
                    case STOPWATCH: sound(SND_STOPWATCH); break;
                    default: break;
                }
            } else {
                rivalScore += VALUE[it];
            }
        }
        // switch / key / bomb open the first matching door (and always play their sound)
        if (it == SWITCH) {
            sound(SND_SWITCH);
            openFirst(GATE);
        } else if (it == KEY) {
            sound(SND_KEY);
            openFirst(LOCKED);
        } else if (it == BOMB) {
            sound(SND_BOMB);
            openFirst(BARS);
        }
        item[r][c] = 0;
        itemFrame[r][c] = 0;
        return !valuablesLeft();
    }

    private void openFirst(int door) {
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (item2[r][c] == door) {
                    item2[r][c] = 0;
                    return;
                }
            }
        }
    }

    /** Highest item value on the board; filtered = keys/switches/bombs count as 0 (STOPWATCH stays). */
    private int maxItem(boolean filtered) {
        int max = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                int v = item[r][c];
                if (filtered && v > WATCH && v != STOPWATCH) v = 0;
                max = Math.max(max, v);
            }
        }
        return max;
    }

    /** FUN_004094da: exit or any valuable still on the board. */
    public boolean levelItemsLeft() {
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                int v = item[r][c];
                if ((v > 0 && v <= WATCH) || v == STOPWATCH) return true;
            }
        }
        return false;
    }

    /** FUN_004093e4: valuables (not the exit) still on the board. */
    public boolean valuablesLeft() {
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                int v = item[r][c];
                if ((v > EXIT && v <= WATCH) || v == STOPWATCH) return true;
            }
        }
        return false;
    }

    /** Someone took the exit as the last item: 0x22B (player) or 0x22C (rival escaped first). */
    private void endLevel(int who) {
        if (who == PLAYER) {
            sound(SND_LEVEL);
            nextLevel();
        } else {
            sound(SND_LOSE);
            state = State.OVER;
            if (listener != null) listener.gameOver(false, score);
        }
    }

    // ---- the rival thief (FUN_0040c99b) -----------------------------------------------------------

    private void rival() {
        if (--rivalTimer >= 1) {
            return;
        }
        rivalTimer = rivalPeriod();
        if (!levelItemsLeft()) {
            endLevel(RIVAL);
            return;
        }
        if (rivalPath.isEmpty()) {
            int target = searchTarget();
            if (target >= 0) {
                List<Integer> path = shortestPath(row[RIVAL], col[RIVAL], target);
                if (path != null) rivalPath.addAll(path);
                if (!stepRival()) rivalPath.clear();
            } else {
                // No reachable item: one random legal jump.
                int[] order = {0, 1, 2, 3};
                for (int i = 3; i > 0; i--) {
                    int j = rnd.nextInt(i + 1);
                    int t = order[i]; order[i] = order[j]; order[j] = t;
                }
                for (int d : order) {
                    if (jumpTarget(row[RIVAL], col[RIVAL], d) >= 0) {
                        move(RIVAL, d);
                        break;
                    }
                }
            }
        } else if (!stepRival()) {
            rivalPath.clear();
        }
    }

    /** True if (r, c) holds something the rival wants (FUN_0040bbfa / FUN_0040c071). */
    private boolean wanted(int r, int c) {
        int v = item[r][c];
        return v != 0 && (v > EXIT || v == maxItem(false));
    }

    /** FUN_0040c459: one jump along the planned route. */
    private boolean stepRival() {
        Integer next = rivalPath.peekFirst();
        if (next == null) {
            return false;
        }
        int tr = next >> 4, tc = next & 15;
        if (occupant[tr][tc] != -1 || (item2[tr][tc] != 0 && item2[tr][tc] < MOVED)) {
            return false;
        }
        rivalPath.removeFirst();
        int r = row[RIVAL], c = col[RIVAL];
        if (tr > r) dir[RIVAL] = DOWN;
        if (tc > c) dir[RIVAL] = RIGHT;
        if (tr < r) dir[RIVAL] = UP;
        if (tc < c) dir[RIVAL] = LEFT;
        occupant[r][c] = -1;
        row[RIVAL] = tr;
        col[RIVAL] = tc;
        occupant[tr][tc] = RIVAL;
        boolean ended = false;
        if (item[tr][tc] != 0) {
            ended = collect(RIVAL, tr, tc, false);
        }
        if (ended) {
            endLevel(RIVAL);
        }
        return true;
    }

    /** FUN_0040bbfa: jumps needed going straight in one direction to reach a wanted item, 0 = none. */
    private int straightCount(int r, int c, int d) {
        int n = 0;
        while (true) {
            int t = jumpTarget(r, c, d);
            if (t < 0) return 0;
            r = t >> 4;
            c = t & 15;
            n++;
            if (occupant[r][c] != -1) return 0;
            if (wanted(r, c)) return n;
        }
    }

    /**
     * FUN_0040c071: depth-first search from the rival. At each tile it prefers the direction with the
     * fewest straight jumps to an item (FUN_0040bec3), otherwise tries the untried directions starting
     * at a random one (FUN_00409d13), backtracking when stuck. Returns the item tile found, or -1.
     */
    private int searchTarget() {
        int sr = row[RIVAL], sc = col[RIVAL];
        int[][] tried = new int[ROWS][COLS];       // bit d = direction d tried
        boolean[][] visited = new boolean[ROWS][COLS];
        int[][] parent = new int[ROWS][COLS];
        visited[sr][sc] = true;
        parent[sr][sc] = -1;
        int r = sr, c = sc;
        int guard = 0;
        while (guard++ < 10000) {
            if ((r != sr || c != sc) && wanted(r, c)) {
                return (r << 4) | c;
            }
            int best = -1, bestN = Integer.MAX_VALUE;
            for (int d = 0; d < 4; d++) {
                int n = straightCount(r, c, d);
                if (n > 0 && n < bestN) {
                    bestN = n;
                    best = d;
                }
            }
            int go = -1;
            if (best >= 0 && (tried[r][c] & 1 << best) == 0 && open(r, c, best, visited)) {
                go = best;
            } else {
                int s = rnd.nextInt(4);
                for (int k = 0; k < 4 && go < 0; k++) {
                    int d = (s + k) & 3;
                    if ((tried[r][c] & 1 << d) == 0) {
                        tried[r][c] |= 1 << d;
                        if (open(r, c, d, visited)) go = d;
                    }
                }
            }
            if (go >= 0) {
                tried[r][c] |= 1 << go;
                int t = jumpTarget(r, c, go);
                int nr = t >> 4, nc = t & 15;
                visited[nr][nc] = true;
                parent[nr][nc] = (r << 4) | c;
                r = nr;
                c = nc;
            } else {
                int p = parent[r][c];
                if (p < 0) return -1;
                r = p >> 4;
                c = p & 15;
            }
        }
        return -1;
    }

    private boolean open(int r, int c, int d, boolean[][] visited) {
        int t = jumpTarget(r, c, d);
        return t >= 0 && !visited[t >> 4][t & 15];
    }

    /**
     * Route to the target in the fewest jumps (stands in for the original's path-shortening pass
     * FUN_0040b758 over the depth-first route). Returns the cells after the start, or null.
     */
    private List<Integer> shortestPath(int sr, int sc, int target) {
        int[] prev = new int[256];
        java.util.Arrays.fill(prev, -2);
        ArrayDeque<Integer> q = new ArrayDeque<>();
        int start = (sr << 4) | sc;
        prev[start] = -1;
        q.add(start);
        while (!q.isEmpty()) {
            int cur = q.poll();
            if (cur == target) break;
            for (int d = 0; d < 4; d++) {
                int t = jumpTarget(cur >> 4, cur & 15, d);
                if (t >= 0 && prev[t] == -2) {
                    prev[t] = cur;
                    q.add(t);
                }
            }
        }
        if (prev[target] == -2) return null;
        List<Integer> path = new ArrayList<>();
        for (int at = target; at != start; at = prev[at]) path.add(0, at);
        return path;
    }

    // ---- helpers ----------------------------------------------------------------------------------------

    public static boolean inside(int r, int c) {
        return r >= 0 && r < ROWS && c >= 0 && c < COLS;
    }

    private void sound(int id) {
        if (listener != null) listener.sound(id);
    }

    /** Count of items of any kind still on the board (for the simulation / display). */
    public int itemsLeft() {
        int n = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (item[r][c] != 0) n++;
            }
        }
        return n;
    }

    /** Sprite type for drawing a thief: 17 + dir*3 + index (FUN_00408bad). */
    public int thiefSprite(int who) {
        return 17 + dir[who] * 3 + who;
    }
}
