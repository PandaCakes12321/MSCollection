package com.teff.puzzles.mixgen;

import java.util.Random;

/**
 * Mixed Genetics rules, recovered from MIXGEN.EXE (see PuzzlePort/MIXGEN/NOTES.md).
 * Plain Java, no Android imports, so it can be simulated headless.
 *
 * One {@link #tick()} is one pass of the original idle loop (Sleep(5) + redraw, taken as 10 ms):
 * animals move 3 px per tick, the spawn counter counts ticks.
 */
final class Game {
    // ---- tables from the EXE ------------------------------------------------------------------

    static final int SPECIES = 6, PARTS = 6;
    static final int MAX_ANIMALS = 51;          // object slots 0..50 (FUN_0040293a)
    static final int WAIT_CELLS = 20, DOME_CELL = 50, CELLS = 51;
    static final int MAX_LEVEL = 16;

    /** Region rects (DAT_0042b418): 0 waiting area, 1..6 tubes (odd = left, even = right), 7 dome. */
    static final int[][] REGION = {
            {34, -7, 594, 117}, {6, 112, 291, 179}, {332, 112, 617, 179}, {6, 188, 291, 255},
            {332, 188, 617, 255}, {6, 265, 291, 332}, {332, 265, 617, 332}, {265, 322, 375, 419}};

    /** Animals to rescue per level (DAT_0042beac). */
    static final int[] TARGET = {0, 10, 15, 20, 25, 25, 25, 30, 30, 30, 20, 20, 15, 15, 10, 10, 27};
    /** Points per rescued animal per level (FUN_00411ce7, WM_LBUTTONDOWN on the dome). */
    static final int[] RESCUE_POINTS = {0, 5, 10, 15, 20, 25, 30, 40, 50, 60, 100, 120, 200, 250, 400, 450, 500};

    /** Body part offsets per species, parts 0..4 (DAT_00428680, 0x798 per species, 0x144 per part). */
    static final int[][][] PART_OFF = {
            {{11, 28}, {24, 29}, {10, 12}, {7, 16}, {32, 14}},
            {{10, 26}, {23, 28}, {13, 12}, {4, 18}, {18, 16}},
            {{5, 25}, {24, 26}, {10, 12}, {1, 15}, {20, 16}},
            {{9, 27}, {26, 24}, {9, 12}, {2, 16}, {34, 16}},
            {{8, 31}, {22, 30}, {12, 12}, {5, 16}, {31, 12}},
            {{9, 25}, {25, 31}, {10, 12}, {5, 15}, {30, 12}}};

    /** Head (part 5) animation frames per species: x, y, delay in ticks. Sprite 2105 + s*100 + frame. */
    static final int[][][] HEAD = {
            {{3, 5, 45}, {10, 5, 45}, {10, 5, 45}, {10, 5, 45}, {10, 5, 45}, {10, 5, 45}},
            {{14, 0, 50}, {14, 0, 50}, {14, 0, 50}, {11, 0, 50}, {11, 0, 50}, {11, 0, 50}, {11, 0, 50},
                    {11, 0, 50}, {14, 0, 50}, {14, 0, 50}},
            {{12, 4, 35}, {10, 4, 35}, {10, 4, 35}, {7, 4, 35}, {7, 4, 35}, {7, 4, 35}, {10, 4, 35}, {10, 4, 35}},
            {{9, 3, 40}, {9, 3, 40}, {15, 3, 40}, {15, 3, 40}, {14, 3, 40}, {15, 3, 40}, {15, 4, 40}, {9, 3, 40}},
            {{3, 1, 40}, {6, 1, 40}, {14, 2, 40}, {14, 1, 40}, {14, 1, 40}, {14, 1, 40}, {14, 2, 40}, {6, 1, 40}},
            {{0, 3, 40}, {4, 4, 40}, {12, 3, 40}, {16, 3, 40}, {15, 4, 40}, {15, 3, 40}, {15, 4, 40}, {16, 3, 40},
                    {12, 3, 40}, {4, 4, 40}}};

    /** Breed-count heart (DAT_004282b0, indexed by breeds): x, y, delay. Sprites 3012 / 3000+f / 3006+f. */
    static final int[][][] HEART = {
            {{19, 22, 30}},
            {{20, 23, 30}, {19, 22, 30}, {20, 23, 30}, {19, 22, 30}, {18, 22, 30}, {19, 22, 30}},
            {{20, 23, 30}, {19, 22, 30}, {20, 23, 30}, {19, 22, 30}, {18, 22, 30}, {19, 22, 30}}};

    /** Bubbles in the centre pipe (object 51 at 300,181; DAT_00428168), sprite 3100+f (3113 missing = blank). */
    static final int PIPE_X = 300, PIPE_Y = 181;
    static final int[][] PIPE = {{14, 39, 10}, {15, 34, 10}, {12, 34, 10}, {11, 34, 10}, {11, 34, 10},
            {11, 34, 10}, {9, 34, 10}, {8, 31, 10}, {11, 34, 10}, {11, 34, 10}, {10, 34, 10}, {11, 34, 10},
            {12, 34, 10}, {12, 34, 100}};
    /** Rescue valve steam (object 53 at 107,341; DAT_00428020), sprite 3300+f. */
    static final int VALVE_X = 107, VALVE_Y = 341;
    static final int[][] VALVE = {{80, 26, 25}, {14, 25, 25}, {0, 0, 25}, {80, 26, Integer.MAX_VALUE}};

    static final int SPAWN_X = 290, SPAWN_Y = 195;  // new animals come out of the centre pipe
    static final int DOME_X = 285, DOME_Y = 337;

    // Sounds: original WAV resource numbers (assets snd/S<n>.wav).
    static final int SND_BAD = 11, SND_RESCUE = 12, SND_LEVEL = 13, SND_BREED = 14, SND_GAMEOVER = 15,
            SND_NEWANIMAL = 21, SND_FULL = 22, SND_DOOR = 23, SND_NOTPURE = 24, SND_IDENTICAL = 25;

    static final int TIP_IDENTICAL = 2, TIP_BOOK = 3, TIP_WON = 4;

    // ---- state --------------------------------------------------------------------------------

    enum State { TITLE, PLAYING, PAUSED, OVER }

    interface Listener {
        void sound(int id);

        void tip(int kind);

        void gameOver(int score, boolean won);
    }

    static final class Animal {
        final int idx;
        boolean alive;
        final int[] genes = new int[PARTS];
        int breeds;                 // 0..2; the third breeding removes it
        int x, y;                   // top-left of the animal canvas
        int homeX, homeY;           // rest position (jitter stays within +1..+3 of it)
        int cell = -1;
        int z;                      // draw/hit order: rest idx+1, moving 201+idx, held 401+idx
        int headFrame, headWait, heartFrame, heartWait;
        int moveWait;
        int fx, fy, stepX, stepY, steps, toX, toY;   // 16.16 movement (FUN_0040db6d)

        Animal(int idx) {
            this.idx = idx;
        }

        boolean pure() {
            for (int p = 1; p < PARTS; p++) {
                if (genes[p] != genes[0]) {
                    return false;
                }
            }
            return true;
        }

        int code() {
            int c = 0;
            for (int p = 0; p < PARTS; p++) {
                c |= genes[p] << (p * 3);
            }
            return c;
        }

        boolean moving() {
            return z > 200 && z <= 400;
        }
    }

    final Animal[] animals = new Animal[MAX_ANIMALS];
    final int[] cells = new int[CELLS];
    final Sprites sprites;
    final Random rnd;
    Listener listener;

    State state = State.TITLE;
    int startLevel = 1;
    int level = 1, score, toRescue, spawnInterval, spawnTimer;
    int held = -1, grabX, grabY;
    boolean won;

    // scenery
    int doorFrame, doorTarget, doorWait;
    boolean bookOpen;
    int bookPage;
    int pipeFrame, pipeWait;
    int valveFrame = -1, valveWait;

    Game(Sprites sprites, Random rnd) {
        this.sprites = sprites;
        this.rnd = rnd;
        for (int i = 0; i < MAX_ANIMALS; i++) {
            animals[i] = new Animal(i);
        }
        clearBoard();
    }

    // ---- helpers ------------------------------------------------------------------------------

    /** Number of species in play on a level (FUN_0040ce1e / FUN_004040ad switch). */
    static int speciesFor(int level) {
        if (level <= 5) {
            return level + 1;
        }
        return level == 7 || level == 9 ? 5 : 6;
    }

    /** Spawn period in ticks (FUN_00411936): slower on the harder levels. */
    static int spawnPeriod(int level) {
        int d = MAX_LEVEL - level;
        return (d * d * -7 + 3000) / 2;
    }

    static int regionOfCell(int cell) {
        if (cell < 0) return -1;
        if (cell < WAIT_CELLS) return 0;
        if (cell < DOME_CELL) return (cell - 20) / 5 + 1;
        return 7;
    }

    /** Cell top-left (FUN_00401c91). */
    static int cellX(int cell) {
        if (cell < WAIT_CELLS) return REGION[0][0] + 5 + (cell % 10) * 55;
        if (cell < DOME_CELL) return REGION[regionOfCell(cell)][0] + 5 + ((cell - 20) % 5) * 55;
        return DOME_X;
    }

    static int cellY(int cell) {
        if (cell < WAIT_CELLS) return REGION[0][1] + 5 + (cell / 10) * 57;
        if (cell < DOME_CELL) return REGION[regionOfCell(cell)][1] + 5;
        return DOME_Y;
    }

    static int regionAt(int x, int y) {
        for (int r = 0; r < REGION.length; r++) {
            int[] q = REGION[r];
            if (x >= q[0] && x <= q[2] && y >= q[1] && y <= q[3]) {
                return r;
            }
        }
        return -1;
    }

    static int headSprite(int species, int frame) {
        return 2105 + species * 100 + frame;
    }

    static int heartSprite(int breeds, int frame) {
        return breeds == 0 ? 3012 : 3000 + (breeds - 1) * 6 + frame;
    }

    /** Sprite id, x offset, y offset of part {@code p} (0..5 body, 6 heart) of an animal. */
    int[] partOf(Animal a, int p) {
        if (p < 5) {
            int s = a.genes[p];
            return new int[] {2100 + s * 100 + p, PART_OFF[s][p][0], PART_OFF[s][p][1]};
        }
        if (p == 5) {
            int s = a.genes[5];
            int[] f = HEAD[s][a.headFrame % HEAD[s].length];
            return new int[] {headSprite(s, a.headFrame % HEAD[s].length), f[0], f[1]};
        }
        int[] f = HEART[a.breeds][a.heartFrame % HEART[a.breeds].length];
        return new int[] {heartSprite(a.breeds, a.heartFrame % HEART[a.breeds].length), f[0], f[1]};
    }

    /** Canvas size (FUN_00408cd0: union of the part sprites from the animal origin). */
    int width(Animal a) {
        int w = 0;
        for (int p = 0; p < 6; p++) {
            int[] q = partOf(a, p);
            Sprites.Sprite s = sprites.get(q[0]);
            if (s != null) w = Math.max(w, q[1] + s.w);
        }
        return w;
    }

    int height(Animal a) {
        int h = 0;
        for (int p = 0; p < 6; p++) {
            int[] q = partOf(a, p);
            Sprites.Sprite s = sprites.get(q[0]);
            if (s != null) h = Math.max(h, q[2] + s.h);
        }
        return h;
    }

    /** Pixel-exact hit test like FUN_00418f1f (non-transparent pixel of any body part). */
    boolean hits(Animal a, int x, int y) {
        for (int p = 0; p < 6; p++) {
            int[] q = partOf(a, p);
            Sprites.Sprite s = sprites.get(q[0]);
            if (s != null && s.opaqueAt(x - a.x - q[1], y - a.y - q[2])) {
                return true;
            }
        }
        return false;
    }

    private int freeSlot() {
        for (int i = 0; i < MAX_ANIMALS; i++) {
            if (!animals[i].alive) return i;
        }
        return -1;
    }

    int aliveCount() {
        int n = 0;
        for (Animal a : animals) if (a.alive) n++;
        return n;
    }

    private void sound(int id) {
        if (listener != null) listener.sound(id);
    }

    private void tip(int kind) {
        if (listener != null) listener.tip(kind);
    }

    private void initAnimal(Animal a) {
        a.alive = true;
        a.breeds = 0;
        a.cell = -1;
        a.headFrame = rnd.nextInt(HEAD[a.genes[5]].length);
        a.headWait = HEAD[a.genes[5]][a.headFrame][2];
        a.heartFrame = 0;
        a.heartWait = HEART[0][0][2];
        a.moveWait = 1;
        a.steps = 0;
    }

    /** Start moving towards (tx, ty) at 3 px per tick (FUN_0040db6d). */
    private void moveTo(Animal a, int tx, int ty) {
        a.z = 201 + a.idx;
        a.moveWait = 1;
        a.toX = tx;
        a.toY = ty;
        a.fx = a.x << 16;
        a.fy = a.y << 16;
        int sx = Math.abs((tx - a.x) / 3), sy = Math.abs((ty - a.y) / 3);
        a.steps = Math.max(sx, sy);
        if (a.steps == 0) {
            a.stepX = a.stepY = 0;
        } else {
            a.stepX = (int) (((long) (tx - a.x) << 16) / a.steps);
            a.stepY = (int) (((long) (ty - a.y) << 16) / a.steps);
        }
    }

    private void placeInCell(Animal a, int cell) {
        cells[cell] = a.idx;
        a.cell = cell;
        int tx = cellX(cell), ty = cellY(cell);
        if (a.x == tx && a.y == ty) {
            a.z = a.idx + 1;
            a.homeX = tx;
            a.homeY = ty;
        } else {
            moveTo(a, tx, ty);
        }
    }

    private void remove(Animal a) {
        if (a.cell >= 0 && cells[a.cell] == a.idx) {
            cells[a.cell] = -1;
        }
        a.cell = -1;
        a.alive = false;
        if (held == a.idx) held = -1;
    }

    private void clearBoard() {
        for (Animal a : animals) {
            a.alive = false;
            a.cell = -1;
        }
        for (int i = 0; i < CELLS; i++) cells[i] = -1;
        held = -1;
    }

    // ---- game flow ----------------------------------------------------------------------------

    void newGame() {
        score = 0;
        won = false;
        level = Math.max(1, Math.min(MAX_LEVEL, startLevel));
        state = State.PLAYING;
        valveFrame = -1;
        startLevel();
    }

    /** FUN_00411936: clear everything, 10 new animals, reset the beaker and the spawn timer. */
    private void startLevel() {
        clearBoard();
        toRescue = TARGET[level];
        doorFrame = doorTarget = 0;
        for (int i = 0; i < 10; i++) {
            spawn();
        }
        spawnInterval = spawnPeriod(level);
        spawnTimer = spawnInterval;
        if (bookOpen) {
            bookPage %= speciesFor(level);
        }
    }

    /** FUN_00411a76: next level (+100 x new level), or +50000 and the end after level 16. */
    private void levelComplete() {
        sound(SND_LEVEL);
        if (level >= MAX_LEVEL) {
            score += 50000;
            won = true;
            tip(TIP_WON);
            gameOver();
            return;
        }
        level++;
        score += level * 100;
        startLevel();
    }

    private void gameOver() {
        if (state == State.OVER) return;
        state = State.OVER;
        held = -1;
        sound(SND_GAMEOVER);
        if (listener != null) listener.gameOver(score, won);
    }

    /** First empty waiting cell, bottom row (10..19) first, left to right (FUN_004026a9). */
    private int freeWaitingCell() {
        for (int row = 1; row >= 0; row--) {
            for (int col = 0; col < 10; col++) {
                if (cells[row * 10 + col] == -1) return row * 10 + col;
            }
        }
        return -1;
    }

    /**
     * FUN_00402fd7 + FUN_0040ce1e: a new mutant comes out of the pipe into the waiting area.
     * All parts get species S0, part P0 gets S1 (so it is never pure); later levels mix in more.
     */
    boolean spawn() {
        int cell = freeWaitingCell();
        if (cell < 0) return false;
        int slot = freeSlot();
        if (slot < 0) return false;
        Animal a = animals[slot];
        int n = speciesFor(level);
        int[] parts = shuffled(PARTS);
        int[] sp = shuffled(n);
        java.util.Arrays.fill(a.genes, sp[0]);
        a.genes[parts[0]] = sp[1];
        if (level > 5) a.genes[parts[1]] = level < 14 ? rnd.nextInt(n) : sp[2];
        if (level > 8) a.genes[parts[2]] = level < 15 ? rnd.nextInt(n) : sp[3];
        if (level > 10) a.genes[parts[3]] = level < 16 ? rnd.nextInt(n) : sp[4];
        if (level > 12) a.genes[parts[4]] = rnd.nextInt(n);
        initAnimal(a);
        a.x = a.homeX = SPAWN_X;
        a.y = a.homeY = SPAWN_Y;
        placeInCell(a, cell);
        return true;
    }

    /** FUN_0040cd60: identity permutation shuffled by 1000 random swaps. */
    private int[] shuffled(int n) {
        int[] v = new int[Math.max(n, 6)];
        for (int i = 0; i < v.length; i++) v[i] = i;
        for (int i = 0; i < 1000 && n > 1; i++) {
            int a = rnd.nextInt(n), b = rnd.nextInt(n);
            int t = v[a];
            v[a] = v[b];
            v[b] = t;
        }
        return v;
    }

    /** Timer spawn (message 0x42c): no room in the waiting area = game over. */
    private void timedSpawn() {
        if (!spawn()) {
            gameOver();
            return;
        }
        sound(SND_NEWANIMAL);
        if (freeWaitingCell() < 0) sound(SND_FULL);
    }

    /** Clicking the centre pipe (or Insert) brings the next animal right away. */
    void spawnNow() {
        if (state != State.PLAYING || held != -1) return;
        if (spawn()) {
            sound(SND_NEWANIMAL);
            spawnTimer = spawnInterval;
            if (freeWaitingCell() < 0) sound(SND_FULL);
        }
    }

    static boolean inPipe(int x, int y) {
        return x > 0x12f && x < 0x14a && y > 0x91 && y < 300;
    }

    // ---- tick ---------------------------------------------------------------------------------

    void tick() {
        if (state != State.PLAYING) return;
        if (--spawnTimer < 1) {
            spawnTimer = spawnInterval;
            timedSpawn();
            if (state != State.PLAYING) return;
        }
        animateScenery();
        for (Animal a : animals) {
            if (a.alive) animate(a);
        }
    }

    private void animateScenery() {
        if (--pipeWait < 1) {
            pipeFrame = (pipeFrame + 1) % PIPE.length;
            pipeWait = PIPE[pipeFrame][2];
        }
        if (valveFrame >= 0 && valveFrame < VALVE.length - 1 && --valveWait < 1) {
            valveFrame++;
            valveWait = VALVE[valveFrame][2];
        }
        if (doorFrame != doorTarget && --doorWait < 1) {
            doorFrame += doorTarget > doorFrame ? 1 : -1;
            doorWait = 5;
        }
    }

    /** FUN_004064ad: head/heart animation, idle jitter, movement. */
    private void animate(Animal a) {
        int[][] head = HEAD[a.genes[5]];
        if (--a.headWait < 1) {
            a.headFrame = (a.headFrame + 1) % head.length;
            a.headWait = head[a.headFrame][2];
        }
        int[][] heart = HEART[a.breeds];
        if (heart.length > 1 && --a.heartWait < 1) {
            a.heartFrame = (a.heartFrame + 1) % heart.length;
            a.heartWait = heart[a.heartFrame][2];
        }
        if (a.z > 400 || --a.moveWait >= 1) return;
        if (a.z < 200) {
            a.moveWait = 10;
            int nx = a.x + rnd.nextInt(3) - 1, ny = a.y + rnd.nextInt(3) - 1;
            if (nx - a.homeX >= 1 && nx - a.homeX < 4) a.x = nx;
            if (ny - a.homeY >= 1 && ny - a.homeY < 4) a.y = ny;
        } else {
            a.moveWait = 1;
            if (a.steps < 1) {
                a.x = a.homeX = a.toX;
                a.y = a.homeY = a.toY;
                a.z = a.idx + 1;
                if (a.cell == DOME_CELL) {
                    remove(a);      // rescued: gone into the dome
                }
            } else {
                a.steps--;
                a.fx += a.stepX;
                a.fy += a.stepY;
                a.x = a.fx >> 16;
                a.y = a.fy >> 16;
            }
        }
    }

    // ---- player actions -----------------------------------------------------------------------

    /** Topmost (or bottom-most) live animal under the point, excluding the held one and the dome. */
    private int animalAt(int x, int y, boolean topmost) {
        int best = -1, bestZ = 0;
        for (Animal a : animals) {
            if (!a.alive || a.idx == held || a.cell == DOME_CELL || !hits(a, x, y)) continue;
            if (best < 0 || (topmost ? a.z > bestZ : a.z < bestZ)) {
                best = a.idx;
                bestZ = a.z;
            }
        }
        return best;
    }

    Animal heldAnimal() {
        return held >= 0 ? animals[held] : null;
    }

    /** Left click on an animal: lift it out of its cell (FUN_00403177 + FUN_004021f1). */
    boolean pickUp(int x, int y) {
        if (state != State.PLAYING || held != -1) return false;
        int i = animalAt(x, y, true);
        if (i < 0) return false;
        Animal a = animals[i];
        int region = a.cell >= 0 ? regionOfCell(a.cell) : -1;
        if (a.cell >= 0) cells[a.cell] = -1;
        a.cell = -1;
        held = i;
        a.z = 401 + i;
        grabX = x - a.x;
        grabY = y - a.y;
        if (region >= 0) compact(region);
        if (a.pure()) openDoor();
        return true;
    }

    boolean canPickUp(int x, int y) {
        return state == State.PLAYING && held == -1 && animalAt(x, y, true) >= 0;
    }

    /** The held animal follows the pointer, clamped to the 630x400 screen (WM_MOUSEMOVE). */
    void moveHeld(int px, int py) {
        Animal a = heldAnimal();
        if (a == null) return;
        int nx = Math.max(0, Math.min(0x275 - width(a), px - grabX));
        int ny = Math.max(0, Math.min(399 - height(a), py - grabY));
        a.x = a.homeX = nx;
        a.y = a.homeY = ny;
    }

    /** Puts the held animal's centre under the pointer (used for tap-to-place). */
    void centreHeldOn(int px, int py) {
        Animal a = heldAnimal();
        if (a == null) return;
        grabX = width(a) / 2;
        grabY = height(a) / 2;
        moveHeld(px, py);
    }

    /**
     * Second click: drop the held animal where its centre is (FUN_00401df5 + FUN_004020e0).
     * Returns false (and keeps holding) when it is not over a region with room.
     */
    boolean drop(int px, int py) {
        Animal a = heldAnimal();
        if (state != State.PLAYING || a == null) return false;
        int region = regionAt(a.x + width(a) / 2, a.y + height(a) / 2);
        if (region < 0) {
            sound(SND_BAD);
            return false;
        }
        int cell = freeCell(region, a, px - 0x1c, py);
        if (cell < 0) {
            sound(region == 7 ? SND_NOTPURE : SND_BAD);
            return false;
        }
        held = -1;
        if (region == 7) {
            rescue(a);
        } else {
            placeInCell(a, cell);
        }
        closeDoor();
        if (toRescue == 0) {
            levelComplete();
        }
        return true;
    }

    private void rescue(Animal a) {
        sound(SND_RESCUE);
        if (cells[DOME_CELL] != -1) {
            remove(animals[cells[DOME_CELL]]);
        }
        placeInCell(a, DOME_CELL);
        valveFrame = 0;
        valveWait = VALVE[0][2];
        toRescue--;
        score += RESCUE_POINTS[Math.min(level, MAX_LEVEL)];
    }

    /** FUN_004026a9 / FUN_004020e0: the free cell nearest the pointer, or -1. */
    int freeCell(int region, Animal a, int mx, int my) {
        if (region == 7) {
            return a.pure() ? DOME_CELL : -1;
        }
        int best = -1, bestD = Integer.MAX_VALUE;
        if (region == 0) {
            for (int row = 1; row >= 0; row--) {
                for (int col = 0; col < 10; col++) {
                    if (cells[row * 10 + col] != -1) continue;
                    // the original measures every column against the top row's position
                    int d = Math.abs(cellY(col) - my) + Math.abs(cellX(col) - mx);
                    if (d < bestD) {
                        bestD = d;
                        best = row * 10 + col;
                    }
                }
            }
            return best;
        }
        int base = region * 5 + 15;
        for (int k = 0; k < 5; k++) {
            if (cells[base + k] != -1) continue;
            int d = Math.abs(cellX(base + k) - mx);
            if (d < bestD) {
                bestD = d;
                best = base + k;
            }
        }
        return best;
    }

    /** FUN_004021f1: after a pickup, close the gap by one step (waiting area falls down). */
    private void compact(int region) {
        if (region == 0) {
            for (int col = 0; col < 10; col++) {
                if (cells[10 + col] == -1 && cells[col] != -1) shift(col, 10 + col);
            }
        } else if (region >= 1 && region <= 6) {
            int base = region * 5 + 15;
            if ((region & 1) == 0) {
                for (int k = 4; k > 0; k--) {
                    for (int twice = 0; twice < 2; twice++) {
                        if (cells[base + k] == -1 && cells[base + k - 1] != -1) shift(base + k - 1, base + k);
                    }
                }
            } else {
                for (int k = 0; k < 4; k++) {
                    if (cells[base + k] == -1 && cells[base + k + 1] != -1) shift(base + k + 1, base + k);
                }
            }
        }
    }

    private void shift(int from, int to) {
        Animal a = animals[cells[from]];
        cells[from] = -1;
        cells[to] = a.idx;
        a.cell = to;
        moveTo(a, cellX(to), cellY(to));
    }

    static final int BREED_OK = 1, BREED_FAIL = 0;

    /**
     * Right click on the middle of three animals in a tube (FUN_00404930 / FUN_00403ee1 / FUN_004029a5).
     * On success the offspring is created under the pointer and is held, ready to be placed.
     */
    int breedAt(int x, int y) {
        if (state != State.PLAYING || held != -1) return BREED_FAIL;
        int i = animalAt(x, y, false);
        int mid = i < 0 ? -1 : animals[i].cell;
        int region = regionOfCell(mid);
        if (region < 1 || region > 6 || mid == region * 5 + 15 || mid == region * 5 + 19
                || cells[mid - 1] == -1 || cells[mid + 1] == -1) {
            sound(SND_BAD);
            return BREED_FAIL;
        }
        Animal[] p = {animals[cells[mid - 1]], animals[cells[mid]], animals[cells[mid + 1]]};
        int c0 = p[0].code(), c1 = p[1].code(), c2 = p[2].code();
        if (c0 == c1 || c0 == c2 || c1 == c2) {
            sound(SND_BAD);
            sound(SND_IDENTICAL);
            tip(TIP_IDENTICAL);
            return BREED_FAIL;
        }
        int slot = freeSlot();
        if (slot < 0) {
            gameOver();        // too many animals (message 0x22b -> 0x465)
            return BREED_FAIL;
        }
        Animal kid = animals[slot];
        for (int part = 0; part < PARTS; part++) {
            int a = p[0].genes[part], b = p[1].genes[part], c = p[2].genes[part];
            int g;
            if (a == b || a == c) g = a;
            else if (b == c) g = b;
            else g = p[rnd.nextInt(3)].genes[part];   // no majority: any parent's part
            kid.genes[part] = g;
        }
        initAnimal(kid);
        kid.x = kid.homeX = x - width(kid) / 2;
        kid.y = kid.homeY = y - height(kid) / 2;
        kid.z = 401 + slot;
        held = slot;
        grabX = x - kid.x;
        grabY = y - kid.y;
        for (Animal parent : p) {
            if (parent.breeds == 2) {
                remove(parent);
            } else {
                parent.breeds++;
                parent.heartFrame = 0;
                parent.heartWait = HEART[parent.breeds][0][2];
            }
        }
        sound(SND_BREED);
        if (kid.pure()) openDoor();
        return BREED_OK;
    }

    private void openDoor() {
        if (doorTarget != 3) {
            doorTarget = 3;
            doorWait = 0;
            sound(SND_DOOR);
        }
    }

    private void closeDoor() {
        doorTarget = 0;
    }

    // ---- Unmixed Genetics Guide (the book, bottom left) ----------------------------------------

    /** Clicks on the book (FUN_00411ce7 WM_LBUTTONDOWN, FUN_004040ad). Returns true if handled. */
    boolean tapBook(int x, int y) {
        if (state != State.PLAYING || held != -1 || y <= 0x154 || y >= 0x18b) return false;
        int n = speciesFor(level);
        if (x > 0xc && x < 0x20) {
            bookOpen = false;
            return true;
        }
        if (x > 0x20 && x < 0x53) {
            if (!bookOpen) {
                bookOpen = true;
                bookPage = 0;
            }
            bookPage = (bookPage + 1) % n;
            tip(TIP_BOOK);
            return true;
        }
        if (x > 0x53 && x < 0x62) {
            int tab = Math.max(0, Math.min(5, (y - 0x154) / 9));
            bookOpen = true;
            bookPage = tab < n ? tab : 0;
            tip(TIP_BOOK);
            return true;
        }
        return false;
    }

    // ---- invariants (used by the headless simulation) ------------------------------------------

    String checkInvariants() {
        for (int c = 0; c < CELLS; c++) {
            int i = cells[c];
            if (i == -1) continue;
            if (i < 0 || i >= MAX_ANIMALS) return "bad index in cell " + c;
            Animal a = animals[i];
            if (!a.alive) return "dead animal in cell " + c;
            if (a.cell != c) return "cell mismatch at " + c;
            if (i == held) return "held animal is in a cell";
        }
        for (Animal a : animals) {
            if (!a.alive) continue;
            if (a.idx != held && (a.cell < 0 || cells[a.cell] != a.idx)) return "lost animal " + a.idx;
            if (a.breeds < 0 || a.breeds > 2) return "breeds out of range";
            for (int g : a.genes) if (g < 0 || g >= SPECIES) return "bad gene";
        }
        if (held >= 0 && !animals[held].alive) return "held dead animal";
        if (toRescue < 0) return "negative beaker";
        return null;
    }
}
