package com.teff.puzzles.lineup;

import java.util.Arrays;
import java.util.Random;

/**
 * Lineup rules, rebuilt from the decompiled Lineup.EXE (see PuzzlePort/Lineup/NOTES.md).
 * The board is [row][col] with playable cells 1..14; row/col 0 and 15 stay empty as a border.
 * {@link #tick()} is called every 100 ms, like the original's Win32 timer.
 */
final class Game {
    static final int N = 14;
    static final int EMPTY = 0, BALL = 1, DIRT = 2, CLOCK = 3, MEDAL = 4, SCORECARD = 5, GARBAGE = 6, GOLF = 7;
    static final int MAX_BONUS = 12, QUEUE = 5;

    // Sound ids, in the order the original loads them (FUN_0040ce27).
    static final int SND_APPLAUSE = 1, SND_PLACE = 2, SND_BONUS = 3, SND_STEP = 4, SND_SPEND = 5,
            SND_LINE = 6, SND_WHISTLE = 7, SND_NEW_PIECE = 8;

    /** Tip kinds: the special types CLOCK..GOLF, plus this one for the first bonus ball. */
    static final int TIP_FIRST_BONUS = 8;

    enum State { TITLE, PLAYING, PAUSED, OVER }

    interface Listener {
        void sound(int id);

        void tip(int kind);

        void gameOver(int score);
    }

    final int[][] type = new int[N + 2][N + 2];
    final int[][] look = new int[N + 2][N + 2];     // ball: its piece id; dirt: which of 4 pictures
    final int[][] timer = new int[N + 2][N + 2];    // specials: lifetime counter
    final int[][] centerR = new int[N + 2][N + 2];  // ball: the center cell of the piece it belongs to
    final int[][] centerC = new int[N + 2][N + 2];
    final int[] queue = new int[QUEUE + 1];        // queue[1] is the piece to place, queue[5] the top

    int difficulty = 1;  // 1 Easy, 2 Medium, 3 Hard, 4 Crazy
    int startLevel = 1;
    int score, level, bonus, pause, clears, ticks, interval, lastRotated;
    boolean garbageMode;
    State state = State.TITLE;
    Listener listener;

    private final Random rnd = new Random();

    // ---- game flow ---------------------------------------------------------------------------

    void newGame() {
        score = 0;
        clears = 0;
        level = startLevel;
        interval = intervalFor(level);
        garbageMode = difficulty == 2 || difficulty == 4;
        rebuildBoard();
        Arrays.fill(queue, 0);
        queue[1] = pickPiece();
        bonus = difficulty - 1;
        pause = 0;
        ticks = 0;
        lastRotated = 0;
        state = State.PLAYING;
    }

    void tick() {
        if (state != State.PLAYING) {
            return;
        }
        if (queue[1] == 0) {
            pieceDue();
        }
        if (state == State.PLAYING && ++ticks > interval) {
            ticks = 0;
            if (pause < 1) {
                pieceDue();
            } else if (pause < 2) {
                pause = 0;
            } else {
                pause--;
            }
        }
    }

    private static int intervalFor(int level) {
        return Math.max(3, 108 - 10 * level);
    }

    /** Timer fired: maybe spawn a special, age specials, then push a new piece onto the queue. */
    private void pieceDue() {
        spawnSpecial();
        ageSpecials();
        for (int k = 1; k <= QUEUE; k++) {
            if (queue[k] == 0) {
                ticks = 0;
                queue[k] = pickPiece();
                sound(SND_NEW_PIECE);
                return;
            }
        }
        if (bonus < 1) {
            gameOver();
        } else {
            spendBonus(1);
        }
    }

    private void gameOver() {
        state = State.OVER;
        clearBoard();
        sound(SND_WHISTLE);
        if (listener != null) {
            listener.gameOver(score);
        }
    }

    // ---- player actions ----------------------------------------------------------------------

    /** A tap on board cell (r, c). allowDelete: the tap may remove a placed piece for 1 bonus ball. */
    void tapBoard(int r, int c, boolean allowDelete) {
        if (state != State.PLAYING || r < 1 || r > N || c < 1 || c > N) {
            return;
        }
        if (place(r, c, queue[1])) {
            System.arraycopy(queue, 2, queue, 1, QUEUE - 1);
            queue[QUEUE] = 0;
            if (queue[1] == 0) {
                queue[1] = pickPiece();
            }
        } else if (allowDelete) {
            deletePiece(r, c);
        }
    }

    /** A tap on queue slot k: slot 1 rotates (first turn costs 1 bonus ball), others swap to the bottom. */
    void tapQueue(int k) {
        if (state != State.PLAYING || k < 1 || k > QUEUE) {
            return;
        }
        if (k == 1) {
            if (bonus > 0 || queue[1] == lastRotated) {
                if (queue[1] != lastRotated) {
                    spendBonus(1);
                }
                queue[1] = Pieces.rotate(queue[1]);
                lastRotated = queue[1];
            }
        } else if (bonus > 0 && queue[k] != 0) {
            int swap = queue[k];
            queue[k] = queue[1];
            queue[1] = swap;
            spendBonus(1);
        }
    }

    boolean canPlace(int r, int c, int id) {
        if (id < 1 || id > Pieces.COUNT) {
            return false;
        }
        for (int[] cell : Pieces.SHAPE[id]) {
            int rr = r + cell[0], cc = c + cell[1];
            if (rr < 1 || rr > N || cc < 1 || cc > N || type[rr][cc] != EMPTY) {
                return false;
            }
        }
        return true;
    }

    /** FUN_00408984: place a piece with its center on (r, c), then resolve specials and lines. */
    private boolean place(int r, int c, int id) {
        if (type[r][c] == DIRT && bonus > 2) {
            spendBonus(3);
            clearCell(r, c);
            return false;
        }
        if (!canPlace(r, c, id)) {
            return false;
        }
        sound(SND_PLACE);
        lastRotated = 0;
        for (int[] cell : Pieces.SHAPE[id]) {
            int rr = r + cell[0], cc = c + cell[1];
            type[rr][cc] = BALL;
            look[rr][cc] = id;
            centerR[rr][cc] = r;
            centerC[rr][cc] = c;
        }
        score += level;

        // Specials completely surrounded by balls trigger and disappear.
        for (int rr = 1; rr <= N; rr++) {
            for (int cc = 1; cc <= N; cc++) {
                if (type[rr][cc] > DIRT && surrounded(rr, cc)) {
                    switch (type[rr][cc]) {
                        case CLOCK:
                            pause += 10;
                            break;
                        case MEDAL:
                            rebuildBoard();
                            return true;
                        case SCORECARD:
                            score += level * 100;
                            break;
                        case GARBAGE:
                            removeRandomDirt();
                            break;
                        case GOLF:
                            gainBonus();
                            break;
                        default:
                            break;
                    }
                    clearCell(rr, cc);
                }
            }
        }
        resolveLines();
        return true;
    }

    private void resolveLines() {
        int[][] remove = new int[N + 2][N + 2];  // piece id, stored at that piece's center
        int rows = 0, cols = 0;
        boolean oneKindLine = false;
        for (int r = 1; r <= N; r++) {
            boolean full = true, same = true;
            int kind = Pieces.look(look[r][1]);
            for (int c = 1; c <= N; c++) {
                if (type[r][c] != BALL) {
                    full = false;
                    break;
                }
                same &= Pieces.look(look[r][c]) == kind;
            }
            if (full) {
                rows++;
                oneKindLine |= same;
                for (int c = 1; c <= N; c++) {
                    remove[centerR[r][c]][centerC[r][c]] = look[r][c];
                }
            }
        }
        for (int c = 1; c <= N; c++) {
            boolean full = true, same = true;
            int kind = Pieces.look(look[1][c]);
            for (int r = 1; r <= N; r++) {
                if (type[r][c] != BALL) {
                    full = false;
                    break;
                }
                same &= Pieces.look(look[r][c]) == kind;
            }
            if (full) {
                cols++;
                oneKindLine |= same;
                for (int r = 1; r <= N; r++) {
                    remove[centerR[r][c]][centerC[r][c]] = look[r][c];
                }
            }
        }
        if (rows + cols == 0) {
            return;
        }

        if (oneKindLine) {
            gainBonus();
        }
        if (rows > 0 && cols > 0) {
            rows++;
        }
        int lines = rows + cols;
        if (lines > 1) {
            for (int i = 0; i < lines; i++) {
                gainBonus();
            }
        }

        boolean golfOnBoard = false;
        int garbageCans = 0;
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                golfOnBoard |= type[r][c] == GOLF;
                if (type[r][c] == GARBAGE) {
                    garbageCans++;
                }
            }
        }
        for (int i = 0; i < garbageCans; i++) {
            addRandomDirt();
        }

        // Every whole piece touching a completed line goes.
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                int id = remove[r][c];
                if (id == 0) {
                    continue;
                }
                for (int[] cell : Pieces.SHAPE[id]) {
                    int rr = r + cell[0], cc = c + cell[1];
                    if (type[rr][cc] == BALL && centerR[rr][cc] == r && centerC[rr][cc] == c) {
                        clearCell(rr, cc);
                    }
                }
                score += (difficulty + 2) * level;
            }
        }

        clears++;
        if (clears > level * 10) {
            level++;
            interval = intervalFor(level);
            if (garbageMode && level % 2 == 0) {
                addRandomDirt();
            }
            sound(SND_WHISTLE);
        }

        if (golfOnBoard || hasPieces()) {
            sound(SND_LINE);
            return;
        }
        // Board cleared of every piece.
        if (bonus < MAX_BONUS) {
            gainBonus();
        } else {
            sound(SND_LINE);
        }
        score += (difficulty + 2) * level * 10;
    }

    /** FUN_004097d3: spend a bonus ball to remove the whole piece under (r, c). */
    private void deletePiece(int r, int c) {
        if (bonus < 1 || type[r][c] != BALL) {
            return;
        }
        spendBonus(1);
        int cr = centerR[r][c], cc = centerC[r][c];
        for (int rr = Math.max(1, cr - 3); rr <= Math.min(N, cr + 3); rr++) {
            for (int c2 = Math.max(1, cc - 3); c2 <= Math.min(N, cc + 3); c2++) {
                if (type[rr][c2] == BALL && centerR[rr][c2] == cr && centerC[rr][c2] == cc) {
                    clearCell(rr, c2);
                }
            }
        }
    }

    // ---- bonus balls -------------------------------------------------------------------------

    private void gainBonus() {
        if (bonus < MAX_BONUS) {
            sound(SND_BONUS);
            bonus++;
            if (bonus == 1 && listener != null) {
                listener.tip(TIP_FIRST_BONUS);
            }
        }
    }

    private void spendBonus(int n) {
        if (bonus >= n) {
            sound(SND_SPEND);
            bonus -= n;
        }
    }

    // ---- specials ----------------------------------------------------------------------------

    /** FUN_00409942. */
    private void spawnSpecial() {
        if (level < 2) {
            return;
        }
        int count = 0;
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if (type[r][c] > DIRT) {
                    count++;
                }
            }
        }
        int roll = count < 1 ? rnd.nextInt(level + 1) : rnd.nextInt(count * 10);
        if (roll != 0) {
            return;
        }
        int kind = 0;
        for (int i = 0; i < 100 && kind <= DIRT; i++) {
            kind = rnd.nextInt(7) + 1;
        }
        if (kind <= DIRT || (count >= 5 - difficulty && kind != MEDAL)) {
            return;
        }
        if ((kind == GOLF && level < 3) || (kind == SCORECARD && level < 4)
                || (kind == CLOCK && level < 5) || (kind == GARBAGE && level < 6)) {
            return;
        }
        for (int i = 0; i < 500; i++) {
            int r = rnd.nextInt(12) + 2, c = rnd.nextInt(12) + 2;
            if (areaEmpty(r, c)) {
                type[r][c] = kind;
                look[r][c] = 0;
                timer[r][c] = kind == MEDAL ? 1 : (kind == CLOCK || kind == SCORECARD) ? 12 : 0;
                if (listener != null) {
                    listener.tip(kind);
                }
                return;
            }
        }
    }

    /** FUN_00409c7c: clocks and scorecards count down, medals count up, then vanish. */
    private void ageSpecials() {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if (type[r][c] == CLOCK || type[r][c] == SCORECARD) {
                    if (timer[r][c] < 1) {
                        clearCell(r, c);
                    } else {
                        timer[r][c]--;
                    }
                } else if (type[r][c] == MEDAL) {
                    if (timer[r][c] <= 12) {
                        timer[r][c]++;
                    } else {
                        clearCell(r, c);
                    }
                }
            }
        }
    }

    private boolean surrounded(int r, int c) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if ((dr != 0 || dc != 0) && type[r + dr][c + dc] != BALL) {
                    return false;
                }
            }
        }
        return true;
    }

    // ---- board setup -------------------------------------------------------------------------

    /** FUN_00407a1d: empty board, Hard/Crazy dirt layout, Medium/Crazy extra dirt per even level. */
    private void rebuildBoard() {
        clearBoard();
        if (difficulty > 2) {
            int layout = rnd.nextInt(8);
            for (int r = 1; r <= N; r++) {
                for (int c = 1; c <= N; c++) {
                    if (inLayout(layout, r, c)) {
                        setDirt(r, c);
                    }
                }
            }
        }
        if (garbageMode) {
            for (int i = 2; i <= level; i += 2) {
                addRandomDirt();
            }
        }
    }

    /** The 8 starting dirt layouts (FUN_00407179 .. FUN_00407955). */
    private static boolean inLayout(int layout, int r, int c) {
        switch (layout) {
            case 0:
                return nearCorner(r, c, 4);
            case 1:
                return nearCorner(r, c, 3) || ((r == 7 || r == 8) && (c == 7 || c == 8));
            case 2:
                return nearCorner(r, c, 2) || nearCenter(r, c);
            case 3:
                return nearCenter(r, c);
            case 4:
                return near(r, c, 4, 7) || near(r, c, 4, 8) || near(r, c, 11, 7) || near(r, c, 11, 8);
            case 5:
                return near(r, c, 7, 4) || near(r, c, 8, 4) || near(r, c, 7, 11) || near(r, c, 8, 11);
            case 6:
                return (r == 7 || r == 8) && (c < 5 || c > 10);
            default:
                return (c == 7 || c == 8) && (r < 5 || r > 10);
        }
    }

    private static boolean nearCorner(int r, int c, int limit) {
        return dist(1, 1, r, c) < limit || dist(1, N, r, c) < limit
                || dist(N, 1, r, c) < limit || dist(N, N, r, c) < limit;
    }

    private static boolean nearCenter(int r, int c) {
        return near(r, c, 7, 7) || near(r, c, 8, 8) || near(r, c, 8, 7) || near(r, c, 7, 8);
    }

    private static boolean near(int r, int c, int r0, int c0) {
        return dist(r0, c0, r, c) < 2;
    }

    private static int dist(int r0, int c0, int r, int c) {
        return Math.abs(r0 - r) + Math.abs(c0 - c);
    }

    /** FUN_0040701b: a dirt patch on a random spot whose 3x3 area is empty. */
    private void addRandomDirt() {
        for (int i = 0; i < 500; i++) {
            int r = rnd.nextInt(N) + 1, c = rnd.nextInt(N) + 1;
            if (areaEmpty(r, c)) {
                setDirt(r, c);
                return;
            }
        }
    }

    /** FUN_00408281. */
    private void removeRandomDirt() {
        for (int i = 0; i < 500; i++) {
            int r = rnd.nextInt(N) + 1, c = rnd.nextInt(N) + 1;
            if (type[r][c] == DIRT) {
                clearCell(r, c);
                return;
            }
        }
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if (type[r][c] == DIRT) {
                    clearCell(r, c);
                    return;
                }
            }
        }
    }

    /** FUN_00406e77: not on the edge, and the cell plus its 8 neighbours are empty. */
    private boolean areaEmpty(int r, int c) {
        if (r == 1 || c == 1 || r == N || c == N) {
            return false;
        }
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (type[r + dr][c + dc] != EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }

    /** FUN_00406770: weighted base shape for the current tier, random rotation/mirror. */
    private int pickPiece() {
        int tier = difficulty;
        if (level > 2 && difficulty < 2) tier = 2;
        if (level > 5 && tier < 3) tier = 3;
        if (level > 7) tier = 4;
        if (level > 9) tier = 5;
        int[] weights = Pieces.WEIGHTS[tier];
        int total = 0;
        int[] cumulative = new int[weights.length];
        for (int i = 0; i < weights.length; i++) {
            total += weights[i];
            cumulative[i] = total;
        }
        int roll = rnd.nextInt(total) + 1;
        for (int i = 0; i < weights.length; i++) {
            if (roll < cumulative[i]) {
                return rnd.nextInt(8) + i * 8 + 1;
            }
        }
        return rnd.nextInt(Pieces.COUNT) + 1;
    }

    private void setDirt(int r, int c) {
        clearCell(r, c);
        type[r][c] = DIRT;
        look[r][c] = rnd.nextInt(4);
    }

    private void clearCell(int r, int c) {
        type[r][c] = EMPTY;
        look[r][c] = 0;
        timer[r][c] = 0;
        centerR[r][c] = 0;
        centerC[r][c] = 0;
    }

    private void clearBoard() {
        for (int r = 0; r < N + 2; r++) {
            for (int c = 0; c < N + 2; c++) {
                clearCell(r, c);
            }
        }
    }

    private boolean hasPieces() {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if (type[r][c] == BALL) {
                    return true;
                }
            }
        }
        return false;
    }

    private void sound(int id) {
        if (listener != null) {
            listener.sound(id);
        }
    }
}
