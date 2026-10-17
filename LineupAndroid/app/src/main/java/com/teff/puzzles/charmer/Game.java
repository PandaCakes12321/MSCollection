package com.teff.puzzles.charmer;

import java.util.Random;

/**
 * Charmer rules engine, recovered from CHARMER.EXE (see PuzzlePort/CHARMER/NOTES.md).
 * Plain Java (no Android imports) so it can be simulated headless.
 *
 * Coordinates are the original 600x400 playfield pixels. One {@link #tick()} is one pass of the
 * original idle-loop game step (WM 0x42B, posted with Sleep(10) between, ~15 ms on Windows).
 */
final class Game {

    interface Listener {
        void sound(String name);

        void tip(String key);

        void gameOver(int score, boolean won);
    }

    enum State { TITLE, PLAYING, PAUSED, LIFE_LOST, LEVEL_DONE, ENDING, OVER }

    static final int TICK_MS = 15;
    static final int COLS = 7;
    static final int BASE_Y = 366;          // bottom of the pot stacks
    static final int POT_H = 25;
    static final int MAX_LEVEL = 10;

    // Speed table DAT_00429220: [flute][snake type][field], all in ticks except STEP (pixels).
    static final int WAIT = 0, RISE = 1, LINGER = 2, DESCEND = 3, FALL = 4, ANIM = 5, STEP = 6;
    static final int[][][] SPEED = {
            {{120, 5, 50, 3, 1, 31, 1}, {40, 3, 80, 2, 1, 20, 1}, {120, 5, 50, 3, 1, 31, 1}, {20, 2, 100, 4, 1, 20, 1}},
            {{20, 2, 100, 5, 1, 21, 1}, {50, 3, 70, 2, 1, 22, 1}, {120, 5, 50, 3, 1, 31, 1}, {120, 5, 50, 3, 1, 23, 1}},
            {{120, 5, 50, 3, 1, 26, 1}, {60, 4, 60, 3, 1, 24, 1}, {20, 3, 120, 6, 1, 26, 1}, {120, 5, 50, 3, 1, 28, 1}},
    };
    /** FUN_0040f161: per level {hidden-column code f78, extra height f7c}. */
    static final int[][] LEVELS = {{4, 1}, {4, 5}, {3, 2}, {3, 6}, {2, 3}, {2, 7}, {1, 4}, {1, 8}, {0, 5}, {0, 9}};
    /** FUN_0040f161: 1-in-N chance per tick that a lid starts to fall, [difficulty-1][flute]. */
    static final int[][] LID_CHANCE = {{1500, 1400, 1600}, {1000, 1200, 600}, {700, 650, 750}};
    static final int LID_STEP = 1, LID_PERIOD = 4;  // DAT_00431f70 / DAT_00431f74
    /** Snake head segment height per type (DAT_004288d0). */
    static final int[] SEG_H = {35, 41, 58, 47};

    // Snake states (column +0x20)
    static final int S_WAIT = 0, S_RISE = 1, S_LINGER = 2, S_DESCEND = 3, S_DROP = 4, S_IDLE = 5;
    // Lid states (column +0x18C)
    static final int L_HELD = 0, L_UP = 1, L_FALL = 2, L_RAISE = 3, L_LANDED = 4;

    // Animation tables
    static final int[] PARROT_FRAMES = {3, 1, 2, 1, 2, 0, 3, 4, 5, 0, 0, 3, 4, 5, 4, 5, 3, 0, 3, 0, 3, 4, 5, 4,
            5, 4, 5, 3, 0, 3, 0, 1, 2, 1, 2, 1, 2, 3, 0};
    static final int[] OLDMAN_FRAMES = {0, 0, 1, 2, 3, 1, 2, 3, 4, 5, 6, 5, 6, 5, 6, 4, 1, 3, 1, 0, 0};
    static final int[] ZAS_FRAMES = {0, 1, 2, 3, 4, 3, 2, 1, 2, 3, 2, 5, 5, 1, 2, 1, 5, 5, 5, 2, 1, 5, 5, 3,
            2, 1, 0, 1, 5, 3, 4, 3, 2, 1};
    static final int PARROT_TICKS = 270 * 55 / TICK_MS;   // 270 GetTickCount/55 units

    static final class Column {
        boolean active;
        int x;
        int n;                                  // pots in the stack, 1 = only the white base
        final int[] potType = new int[16];      // index 1..n
        final int[] potColor = new int[16];
        int type, color;                        // snake / top pot
        int state = S_IDLE;
        int timer, animTimer, frame;
        boolean animFrozen;
        int y;                                  // snake head top
        int lidY, lidState = L_UP, lidTimer;

        int bottom() {
            return BASE_Y - POT_H * n;
        }
    }

    static final class Heart {
        boolean anim, closing;
        int frame;
        int shown = Integer.MIN_VALUE;          // frame drawn by the last animation step
    }

    Listener listener;
    final Random rnd;
    final Column[] cols = new Column[COLS];
    final Heart[] hearts = {new Heart(), new Heart(), new Heart()};

    State state = State.TITLE;
    int difficulty = 1, startLevel = 1;
    int level, score, livesLost;
    int narrow, maxPots, vineY;
    int flute, fluteCol = 3;
    int lostCol, lostY;
    boolean won;

    boolean oldMan;
    int oldManIdx = -1, oldManTimer;
    boolean parrot;
    int parrotIdx, parrotTimer, parrotLeft;
    int heartTimer, lamp, lampTimer;
    int zasIdx, zasTimer;
    long ticks;

    Game() {
        this(new Random());
    }

    Game(Random rnd) {
        this.rnd = rnd;
        for (int i = 0; i < COLS; i++) {
            cols[i] = new Column();
        }
    }

    // ---- setup ---------------------------------------------------------------------------------

    void newGame() {
        level = Math.max(1, Math.min(MAX_LEVEL, startLevel));
        difficulty = Math.max(1, Math.min(3, difficulty));
        score = 0;
        livesLost = 0;
        flute = 0;
        fluteCol = 3;
        won = false;
        oldMan = false;
        parrot = false;
        for (Heart h : hearts) {
            h.anim = false;
            h.shown = Integer.MIN_VALUE;
        }
        setupLevel();
    }

    /** Level start: FUN_0040f161 + FUN_0040ae15. */
    private void setupLevel() {
        narrow = LEVELS[level - 1][0];
        maxPots = LEVELS[level - 1][1] + 4;
        vineY = BASE_Y - POT_H * maxPots;
        int lo = (narrow + 1) / 2;
        boolean extra = narrow == 1 || narrow == 3;
        for (int c = 0; c < COLS; c++) {
            Column col = cols[c];
            col.x = c * 56 + 96 - (extra ? 28 : 0);
            col.active = false;
            col.n = 0;
            col.lidState = L_UP;
            if ((c >= lo && c < COLS - lo) || (extra && c == COLS - lo)) {
                col.state = S_IDLE;
                col.frame = 0;
                col.lidState = L_UP;
                col.active = true;
            }
        }
        for (int i = 0; i < maxPots - 3; i++) {
            for (int c = 0; c < COLS; c++) {
                if (cols[c].active) {
                    addPot(cols[c]);
                }
            }
        }
        Column f = cols[fluteCol];
        f.timer = spd(f.type, WAIT);
        f.state = S_WAIT;
        state = State.PLAYING;
    }

    /** FUN_0040cd06: a new random pot on top of the stack. */
    private void addPot(Column col) {
        if (col.n >= maxPots) {
            return;
        }
        col.n++;
        col.type = rnd.nextInt(4);
        col.color = rnd.nextInt(4);
        col.y = col.bottom() + 1;
        col.potType[col.n] = col.type;
        col.potColor[col.n] = col.color;
        col.lidY = vineY - 9;
        col.lidState = L_UP;
        col.active = true;
    }

    /** FUN_0040ce75: the charmed snake's pot disappears. */
    private void removePot(Column col) {
        if (col.n == 1) {
            return;
        }
        col.n--;
        col.lidY = vineY - 9;
        col.type = col.potType[col.n];
        col.color = col.potColor[col.n];
        col.y = col.bottom() + 1;
    }

    private int spd(int type, int field) {
        return SPEED[flute][type][field];
    }

    // ---- input ---------------------------------------------------------------------------------

    boolean controlsLive() {
        return state == State.PLAYING || state == State.LIFE_LOST;
    }

    /** LEFT / RIGHT arrow (FUN_0040d835 with 0xCC / 0xC9). */
    void moveFlute(int dir) {
        moveFluteTo(fluteCol + dir);
    }

    void moveFluteTo(int target) {
        if (!controlsLive() || target < 0 || target >= COLS || target == fluteCol || !cols[target].active) {
            return;
        }
        leave(cols[fluteCol]);
        fluteCol = target;
        arrive(cols[target]);
    }

    /** FUN_0040da14. */
    private void leave(Column col) {
        if (col.state == S_RISE) {
            col.state = S_LINGER;
            col.timer = spd(col.type, LINGER);
        } else if (col.state == S_WAIT) {
            col.state = S_IDLE;
        }
    }

    /** FUN_0040dae5. */
    private void arrive(Column col) {
        if (col.state == S_LINGER || col.state == S_DESCEND) {
            col.state = S_RISE;
            col.timer = spd(col.type, RISE);
        } else if (col.state == S_IDLE) {
            col.state = S_WAIT;
            col.timer = spd(col.type, WAIT);
        }
    }

    /** SPACEBAR / DOWN: next flute (FUN_0040d749). */
    void nextFlute() {
        if (!controlsLive()) {
            return;
        }
        flute = (flute + 1) % 3;
        sound("FLUTE" + flute);
    }

    // ---- main step (FUN_0040f6f0, message 0x42B) -------------------------------------------------

    void tick() {
        ticks++;
        if (state == State.TITLE) {
            if (--zasTimer < 1) {
                zasTimer = 30;
                zasIdx = (zasIdx + 1) % ZAS_FRAMES.length;
            }
            return;
        }
        if (state == State.PAUSED || state == State.OVER) {
            return;
        }
        oldManTick();
        parrotTick();
        if (anyHeartAnim() && --heartTimer < 1) {
            heartTimer = 25;
            heartStep();
        }
        if (--lampTimer < 1) {
            lampTimer = 10;
            lamp = rnd.nextInt(2) == 0 ? 0 : anyHeartAnim() ? 2 : 1;
        }
        switch (state) {
            case LIFE_LOST:
                lifeLostTick();
                return;
            case LEVEL_DONE:
                sound("NEWLEVEL");
                nextLevel();
                return;
            case ENDING:
                if (!anyHeartAnim()) {
                    finish(false);
                }
                return;
            default:
                break;
        }
        if (rnd.nextInt(6000) == 0x309 && !oldMan) {
            sound("DOOROPEN");
            oldMan = true;
            oldManIdx = -1;
            oldManTimer = 1;
            tip("partner");
        }
        if (livesLost > 0 && rnd.nextInt((9 - livesLost) * 200 + 4000) == 0x4d && !parrot) {
            sound("PARHELLO");
            parrot = true;
            parrotIdx = PARROT_FRAMES.length - 1;
            parrotLeft = PARROT_TICKS;
            parrotTimer = 1;
            tip("parrot");
        }
        for (int c = 0; c < COLS && state == State.PLAYING; c++) {
            columnTick(c);
        }
        if (state == State.PLAYING) {
            lidDrop();
        }
    }

    /** FUN_0040c827: one column's lid and snake. */
    private void columnTick(int c) {
        Column col = cols[c];
        if (!col.active) {
            return;
        }
        if (--col.lidTimer == 0) {
            col.lidTimer = LID_PERIOD;
            if (col.lidState == L_RAISE || col.lidState == L_FALL || col.lidState == L_HELD) {
                lidMove(c);
                snakeShape(col);
            }
        }
        if (col.state == S_IDLE) {
            return;
        }
        if (!col.animFrozen && --col.animTimer == 0) {
            col.frame = col.frame < 7 ? col.frame + 1 : 0;
            col.animTimer = spd(col.type, ANIM);
            if (col.state == S_LINGER) {
                snakeShape(col);
            }
        }
        col.timer--;
        boolean charmed = !oldMan || fluteCol == c;
        if (col.state == S_LINGER && !charmed) {
            col.state = S_DESCEND;
            col.timer = spd(col.type, DESCEND) / 2;
        } else if (col.timer == 0) {
            if (col.state == S_WAIT) {
                if (charmed) {
                    col.state = S_RISE;
                    col.timer = spd(col.type, RISE);
                    col.animTimer = spd(col.type, ANIM);
                } else {
                    col.state = S_IDLE;
                }
                return;
            }
            switch (col.state) {
                case S_RISE:
                    if (charmed) {
                        col.timer = spd(col.type, RISE);
                    } else {
                        col.state = S_DESCEND;
                        col.timer = spd(col.type, DESCEND) / 2;
                    }
                    break;
                case S_DESCEND:
                    col.timer = charmed ? spd(col.type, DESCEND) : spd(col.type, DESCEND) / 2;
                    break;
                case S_LINGER:
                    col.state = S_DESCEND;
                    col.timer = spd(col.type, DESCEND);
                    break;
                case S_DROP:
                    col.timer = spd(col.type, FALL);
                    break;
                default:
                    break;
            }
            snakeMove(col);
            snakeShape(col);
            snakeArrive(c);
        }
    }

    /** FUN_0040c2fc. */
    private void snakeMove(Column col) {
        int step = spd(col.type, STEP);
        if (col.state == S_RISE) {
            int d = col.y - vineY;
            col.y -= (d >= 0 && d < step) ? d : step;
            if (col.y <= col.lidY + 9) {
                col.lidY = col.y - 9;
            }
        } else if (col.state == S_DESCEND || col.state == S_DROP) {
            int s = col.state == S_DROP ? step * 10 : step;
            int d = col.bottom() - col.y;
            col.y += (d >= 0 && d < s) ? d : s;
        }
    }

    /** FUN_0040b6b8 side effect: a snake shorter than its head segment stops animating. */
    private void snakeShape(Column col) {
        int h = col.bottom() - col.y;
        if (h > 0) {
            if (h < SEG_H[col.type]) {
                col.frame = 1;
                col.animFrozen = true;
            } else {
                col.animFrozen = false;
            }
        }
    }

    /** FUN_0040beae: snake reached the vine, or got back into its pot. */
    private void snakeArrive(int c) {
        Column col = cols[c];
        if (col.state == S_RISE && col.y <= vineY) {
            score += (5 - narrow) * difficulty * 10;
            if (parrot && livesLost > 0) {
                livesLost--;
                sound("NEWHEART");
                if (!anyHeartAnim()) {
                    int left = 3 - livesLost % 3;
                    if (left == 1) {
                        Heart h = hearts[livesLost / 3];
                        h.anim = true;
                        h.closing = false;
                        h.frame = 2;
                    }
                } else {
                    for (Heart h : hearts) {
                        if (h.anim) {
                            h.closing = false;
                            break;
                        }
                    }
                }
            }
            sound("SNAKEUP");
            col.state = S_DROP;
            col.timer = spd(col.type, FALL);
        } else if ((col.state == S_DROP || col.state == S_DESCEND) && col.bottom() <= col.y) {
            if (col.state == S_DROP) {
                removePot(col);
                if (col.n == maxPots || allCleared()) {
                    state = State.LEVEL_DONE;
                }
            }
            col.y = col.bottom() + 1;
            if (fluteCol == c) {
                col.state = S_WAIT;
                col.timer = spd(col.type, WAIT);
            } else {
                col.state = S_IDLE;
            }
        }
    }

    /** FUN_0040bdb2: every stack is down to its white base. */
    private boolean allCleared() {
        for (Column col : cols) {
            if (col.active && col.n != 1) {
                return false;
            }
        }
        return true;
    }

    /** FUN_0040c463. */
    private void lidMove(int c) {
        Column col = cols[c];
        int top = vineY - 9;
        switch (col.lidState) {
            case L_HELD:
                if (col.lidY == top) {
                    col.lidState = L_UP;
                } else if (col.state != S_RISE) {
                    col.lidState = L_RAISE;
                }
                break;
            case L_FALL: {
                int target = BASE_Y - 9 - POT_H * col.n;
                if (col.lidY == target) {
                    col.lidState = L_LANDED;
                    sound((livesLost + 1) % 3 == 0 ? "WINDOW" : "COVER");
                    lostCol = c;
                    lostY = BASE_Y - POT_H * col.n - POT_H;
                    state = State.LIFE_LOST;
                    return;
                }
                int d = target - col.lidY;
                col.lidY += d < LID_STEP ? d : LID_STEP;
                if (col.y - 9 <= col.lidY) {
                    col.lidY = col.y - 9;
                    double snake = spd(col.type, STEP) / (double) spd(col.type, RISE);
                    if (snake < LID_STEP / (double) LID_PERIOD) {
                        col.lidState = L_RAISE;
                    } else {
                        col.lidState = col.state == S_RISE ? L_HELD : L_RAISE;
                    }
                }
                break;
            }
            case L_RAISE: {
                int d = col.lidY - top;
                col.lidY -= d < LID_STEP ? d : LID_STEP;
                if (col.y - 9 <= col.lidY) {
                    col.lidY = col.y - 9;
                }
                if (col.lidY == top) {
                    col.lidState = L_UP;
                }
                break;
            }
            default:
                break;
        }
    }

    /** FUN_0040dc76: maybe drop one lid from the vine. */
    private void lidDrop() {
        int chance = LID_CHANCE[difficulty - 1][flute];
        for (Column col : cols) {
            if (col.active && col.state != S_DROP && col.lidState == L_UP && rnd.nextInt(chance) == 7) {
                col.lidTimer = LID_PERIOD;
                col.lidState = L_FALL;
                sound("COVER");
                return;
            }
        }
    }

    /** FUN_00409226: the daggers fly up to the vine, then a life is lost and a pot is added. */
    private void lifeLostTick() {
        if (lostY > vineY - 25) {
            lostY -= 2;
            return;
        }
        Column col = cols[lostCol];
        addPot(col);
        col.lidY = vineY - 9;
        col.lidState = L_UP;
        livesLost++;
        sound("HEART");
        if (livesLost % 3 == 0) {
            Heart h = hearts[(livesLost - 1) / 3];
            if (!h.anim) {
                h.frame = 0;
            }
            h.closing = true;
            h.anim = true;
        }
        if (livesLost >= 9 || col.n == maxPots) {
            for (int s = (livesLost - 1) / 3; s < 3; s++) {
                hearts[s].anim = true;
                hearts[s].frame = 0;
                hearts[s].closing = true;
            }
            state = State.ENDING;
            oldMan = false;
            parrot = false;
        } else {
            state = State.PLAYING;
        }
    }

    /** Command 0x77: next level, or the game is won after level 10. */
    private void nextLevel() {
        if (level >= MAX_LEVEL) {
            tip("congratulate");
            finish(true);
            return;
        }
        level++;
        setupLevel();
    }

    private void finish(boolean victory) {
        won = victory;
        state = State.OVER;
        oldMan = false;
        parrot = false;
        if (listener != null) {
            listener.gameOver(score, victory);
        }
    }

    // ---- side animations -------------------------------------------------------------------------

    /** FUN_0040e729: the mysterious man in the doorway, one frame per 20 ticks. */
    private void oldManTick() {
        if (!oldMan) {
            return;
        }
        if (--oldManTimer >= 1) {
            return;
        }
        oldManTimer = 20;
        if (oldManIdx == -1) {
            oldManIdx = 0;
        } else if (oldManIdx == OLDMAN_FRAMES.length - 1) {
            oldMan = false;
            sound("DOORCLOS");
        } else {
            oldManIdx++;
        }
    }

    /** Parrot (DAT_00431b10): squawks for ~15 s; a snake reaching the vine meanwhile restores a life. */
    private void parrotTick() {
        if (!parrot) {
            return;
        }
        parrotLeft--;
        if (--parrotTimer >= 1) {
            return;
        }
        parrotTimer = 30;
        if (parrotLeft <= 0) {
            parrot = false;
            return;
        }
        if (parrotIdx == PARROT_FRAMES.length - 1) {
            parrotIdx = 0;
        } else {
            parrotIdx++;
            if ((parrotIdx + 1) % 9 == 0) {
                sound("PARROT");
            }
        }
    }

    boolean anyHeartAnim() {
        return hearts[0].anim || hearts[1].anim || hearts[2].anim;
    }

    /** FUN_00408bfa: one curtain step on the first animating heart niche. */
    private void heartStep() {
        for (Heart h : hearts) {
            if (!h.anim) {
                continue;
            }
            h.shown = h.frame;
            if (!h.closing) {
                h.frame--;
                if (h.frame == -2) {
                    h.anim = false;
                }
            } else {
                if (h.frame == 0) {
                    sound("WINDOW");
                }
                h.frame++;
                if (h.frame == 3) {
                    h.anim = false;
                }
            }
            return;
        }
    }

    /** Hearts left in niche s (0..3), FUN_00408add. */
    int heartsIn(int s) {
        return Math.max(0, Math.min(3, 3 - (livesLost - 3 * s)));
    }

    int parrotSprite() {
        return parrot ? PARROT_FRAMES[parrotIdx] : 0;
    }

    int oldManSprite() {
        return OLDMAN_FRAMES[Math.max(0, oldManIdx)];
    }

    private void sound(String name) {
        if (listener != null) {
            listener.sound(name);
        }
    }

    private void tip(String key) {
        if (listener != null) {
            listener.tip(key);
        }
    }
}
