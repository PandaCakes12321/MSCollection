package com.teff.puzzles.ratpoker;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * Rat Poker rules, recovered from RATPOKER.EXE.
 * Plain Java (no Android imports) so it can be simulated headless.
 *
 * Rats travel left-to-right on a conveyor belt. Arms can trap rats; once
 * in a trap, rats are released onto the platform. When a valid hand of 3+
 * same-colour (or rainbow) rats is on the platform, they escape and score.
 */
final class Game {

    // ---- colours (letter = sprite filename suffix) ----------------------------
    static final int NONE  = 0, COL_B = 1, COL_C = 2, COL_D = 3, COL_G = 4,
                     COL_M = 5, COL_O = 6, COL_R = 7, COL_W = 8, COL_Y = 9;
    static final String[] COL_NAME = {"","B","C","D","G","M","O","R","W","Y"};
    static final int COLORS = 9; // B C D G M O R W Y

    // ---- level tables (from RATPOKER.EXE @0x414660) ---------------------------
    /** 24 ints per level (index 0 = copy of 1). */
    static final int[][] LEVELS = {
        {150, 4, 20, 8, 0, 5, 0, 1, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {150, 4, 20, 8, 0, 5, 0, 1, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {150, 4, 20, 8, 0, 5, 0, 1, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {150, 4, 20, 8, 0, 5, 0, 1, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {150, 4, 20, 8, 0, 4, 0, 1, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {150, 5, 20, 7, 0, 5, 1, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {150, 5, 20, 7, 1, 5, 1, 2, 3, 2, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {150, 5, 22, 7, 1, 4, 1, 2, 3, 2, 11, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {150, 5, 24, 7, 1, 5, 2, 1, 2, 1, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {150, 5, 26, 6, 1, 5, 2, 1, 2, 1, 11, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {110, 5, 28, 6, 1, 4, 2, 1, 2, 1, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {110, 6, 30, 2, 1, 5, 3, 3, 1, 2, 0, 5, 10, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1},
        {110, 6, 32, 2, 1, 5, 3, 3, 1, 2, 5, 5, 5, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1},
        {110, 6, 34, 2, 1, 4, 3, 3, 1, 2, 0, 0, 5, 10, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {110, 6, 36, 2, 1, 4, 4, 2, 4, 1, 10, 3, 3, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {110, 6, 38, 2, 1, 5, 4, 2, 4, 1, 10, 3, 3, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1},
        {110, 6, 40, 2, 1, 4, 4, 2, 4, 1, 3, 0, 12, 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {110, 7, 42, 0, 1, 3, 5, 3, 3, 2, 0, 0, 9, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {110, 7, 44, 0, 1, 5, 5, 3, 3, 2, 3, 3, 3, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {110, 7, 48, 0, 1, 4, 6, 1, 2, 1, 5, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {110, 7, 99, 0, 1, 3, 6, 1, 2, 1, 7, 2, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    /** Arms per level: {arm0..3 present(0/1/2), pinwheelType}. 2=can swing. */
    static final int[][] ARMS = {
        {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}, {0, 1, 1, 0, 0}, {0, 1, 1, 0, 0}, {0, 1, 1, 0, 0},
        {0, 1, 2, 0, 0}, {0, 1, 2, 0, 0}, {0, 1, 2, 0, 0}, {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0}, {0, 1, 1, 1, 0}, {0, 1, 1, 1, 4}, {0, 1, 1, 1, 4},
        {0, 1, 1, 1, 4}, {0, 1, 1, 1, 4}, {0, 1, 1, 1, 4}, {0, 1, 1, 1, 4},
        {0, 1, 1, 1, 4},
    };

    // Sounds
    static final String SND_TRAP    = "TRAPWAV",
                        SND_RELEASE = "RELEASEWAV",
                        SND_SCORE   = "SCOREWAV",
                        SND_LEVEL   = "LEVELWAV",
                        SND_OVER    = "GAMEOVER";

    static final int MAX_BELT   = 12;   // belt slots before overflow
    static final int MAX_PLAT   = 7;    // platform slots
    static final int ANIM_FRAMES = 18;

    enum State { TITLE, PLAYING, PAUSED, OVER, LEVEL_DONE }

    interface Listener {
        void sound(String name);
        void tip(int level);
        void gameOver(int score);
    }

    // ---- state ---------------------------------------------------------------
    State state = State.TITLE;
    Listener listener;

    int level = 1, score, rescued, infested;
    int startLevel = 1;
    int difficulty = 1; // 1..4

    // Belt: list of moving rats (index 0 = newest/rightmost; they advance left)
    final List<Rat> belt = new ArrayList<>();
    // Platform: where scored rats go (left side)
    final int[] platform = new int[MAX_PLAT]; // rat colours, 0=empty
    int platCount;

    // Arms (up to 3 active based on level)
    int numArms;
    final Arm[] arms = new Arm[]{new Arm(), new Arm(), new Arm()};
    int activeArm;  // 0-based index into active arms array
    int activeSlot; // 0 or 1 (for 2-slot arm at later levels)

    private final Random rnd;
    private int tickMs;
    private int spawnTimer;
    private int numColors;
    int rescueTarget;         // read by GameView for HUD
    private int maxInfestation;
    private boolean hasMinusPlus;
    private boolean whiteWild;

    // Animation
    int[] beltAnim;  // anim frame per belt position
    int globalAnim;  // overall frame counter
    boolean escaped; // flash flag when hand scored

    Game() { this(new Random()); }
    Game(Random rnd) { this.rnd = rnd; }

    static final class Rat {
        int color;      // COL_* constant
        int modifier;   // 0=none, 1=plus, -1=minus
        int beltPos;    // 0=left edge (overflow), MAX_BELT=just entered
        int frame;      // walk animation frame 0..17
    }

    static final class Arm {
        boolean present;
        boolean canSwing;
        int beltPos;     // which belt slot this arm covers (0..MAX_BELT-1)
        int numSlots;    // 1 or 2 trapped-rat slots
        final int[] trapped = new int[2]; // colour of trapped rat (0=empty)
        final int[] trapMod = new int[2]; // modifier of trapped rat
    }

    // ---- level setup ---------------------------------------------------------
    void startGame() {
        level = startLevel;
        score = 0;
        rescued = 0;
        initLevel();
    }

    void startLevel() {
        rescued = 0;
        infested = 0;
        belt.clear();
        platCount = 0;
        for (int i = 0; i < MAX_PLAT; i++) platform[i] = NONE;
        initLevel();
    }

    private void initLevel() {
        int lv = Math.min(level, LEVELS.length - 1);
        int[] ld = LEVELS[lv];
        int[] ad = ARMS[lv];

        tickMs        = ld[0];
        numColors     = Math.min(ld[1], COLORS);
        rescueTarget  = ld[2];
        maxInfestation= ld[3];
        hasMinusPlus  = ld[4] == 1;
        whiteWild     = level >= 8;

        // build arm array
        numArms = 0;
        for (int a = 0; a < 4; a++) {
            if (ad[a] > 0) {
                Arm arm = arms[numArms];
                arm.present   = true;
                arm.canSwing  = ad[a] == 2;
                arm.numSlots  = (level >= 3 && numArms == 0) ? 2 : 1;
                arm.trapped[0]= NONE; arm.trapped[1] = NONE;
                arm.trapMod[0]= 0;    arm.trapMod[1]  = 0;
                // belt positions: spread arms evenly
                arm.beltPos = (a + 1) * MAX_BELT / 5;
                numArms++;
            }
        }
        activeArm  = 0;
        activeSlot = 0;
        spawnTimer = tickMs;
        state = State.PLAYING;
    }

    // ---- tick ----------------------------------------------------------------
    void tick(int ms) {
        if (state != State.PLAYING) return;
        globalAnim = (globalAnim + 1) % ANIM_FRAMES;
        escaped = false;

        spawnTimer -= ms;
        if (spawnTimer <= 0) {
            spawnTimer += tickMs;
            spawnRat();
        }

        // advance belt
        for (int i = belt.size() - 1; i >= 0; i--) {
            Rat r = belt.get(i);
            r.beltPos--;
            r.frame = (r.frame + 1) % ANIM_FRAMES;
            if (r.beltPos < 0) {
                belt.remove(i);
                infested++;
                if (infested > maxInfestation) {
                    state = State.OVER;
                    sound(SND_OVER);
                    if (listener != null) listener.gameOver(score);
                    return;
                }
            }
        }
    }

    private void spawnRat() {
        if (belt.size() >= MAX_BELT) return;
        Rat r = new Rat();
        r.color = pickColor();
        r.beltPos = MAX_BELT - 1;
        r.frame = rnd.nextInt(ANIM_FRAMES);
        if (hasMinusPlus && rnd.nextInt(4) == 0) {
            r.modifier = rnd.nextBoolean() ? 1 : -1;
        }
        belt.add(r);
    }

    private int pickColor() {
        // Color indices 1..numColors (avoid white unless whiteWild)
        int pool = whiteWild ? numColors : Math.min(numColors, COL_W - 1);
        return rnd.nextInt(pool) + 1;
    }

    // ---- player actions ------------------------------------------------------
    /** SPACE: trap rat at active arm / release trapped rat to platform. */
    void pressSpace() {
        if (state != State.PLAYING) { if (state == State.TITLE) startGame(); return; }
        Arm arm = arms[activeArm];
        if (arm.trapped[activeSlot] == NONE) {
            // try to trap a rat on the belt at this arm position
            Rat rat = ratAt(arm.beltPos);
            if (rat != null) {
                arm.trapped[activeSlot] = rat.color;
                arm.trapMod[activeSlot] = rat.modifier;
                belt.remove(rat);
                sound(SND_TRAP);
            }
        } else {
            // release to platform
            int color = arm.trapped[activeSlot];
            int mod   = arm.trapMod[activeSlot];
            arm.trapped[activeSlot] = NONE;
            arm.trapMod[activeSlot] = 0;
            releaseToPlatform(color, mod);
            sound(SND_RELEASE);
        }
    }

    /** TAB: switch active slot (if arm has 2 slots) or next arm. */
    void pressTab() {
        if (state != State.PLAYING) return;
        Arm arm = arms[activeArm];
        if (arm.numSlots == 2) {
            activeSlot = 1 - activeSlot;
        } else if (numArms > 1) {
            activeArm = (activeArm + 1) % numArms;
            activeSlot = 0;
        }
    }

    /** LEFT/RIGHT: switch active arm (level 2+) or swing arm (level 4+). */
    void pressLeft() {
        if (state != State.PLAYING) return;
        if (numArms > 1) {
            activeArm = (activeArm - 1 + numArms) % numArms;
            activeSlot = 0;
        } else if (arms[activeArm].canSwing) {
            arms[activeArm].beltPos = Math.max(0, arms[activeArm].beltPos - 1);
        }
    }

    void pressRight() {
        if (state != State.PLAYING) return;
        if (numArms > 1) {
            activeArm = (activeArm + 1) % numArms;
            activeSlot = 0;
        } else if (arms[activeArm].canSwing) {
            arms[activeArm].beltPos = Math.min(MAX_BELT - 2, arms[activeArm].beltPos + 1);
        }
    }

    void pressPause() {
        if (state == State.PLAYING) state = State.PAUSED;
        else if (state == State.PAUSED) state = State.PLAYING;
    }

    // ---- platform & scoring --------------------------------------------------
    private void releaseToPlatform(int color, int mod) {
        if (platCount >= MAX_PLAT) {
            // shift left, losing oldest
            System.arraycopy(platform, 1, platform, 0, MAX_PLAT - 1);
            platCount = MAX_PLAT - 1;
        }
        platform[platCount++] = color;
        checkHand();
    }

    private void checkHand() {
        if (platCount < 3) return;
        // check best scoring hand in the current platform contents
        int[] present = new int[COLORS + 1]; // count by color
        for (int i = 0; i < platCount; i++) {
            int c = platform[i];
            if (c == COL_W && whiteWild) {
                // wild: count as whatever is most needed — handled below
            } else if (c > 0) {
                present[c]++;
            }
        }
        int wilds = whiteWild ? present[COL_W] : 0;

        // Find best same-color run (with wilds)
        int best = 0, bestColor = 0;
        for (int c = 1; c <= COLORS; c++) {
            if (c == COL_W) continue;
            int total = present[c] + wilds;
            if (total > best) { best = total; bestColor = c; }
        }

        // Check rainbow (all different)
        boolean rainbow = false;
        int rainbowLen = 0;
        if (platCount >= 3) {
            boolean[] seen = new boolean[COLORS + 1];
            rainbowLen = 0;
            for (int i = platCount - 1; i >= 0; i--) {
                int c = platform[i];
                if (c == COL_W) { rainbowLen++; continue; }
                if (seen[c]) break;
                seen[c] = true;
                rainbowLen++;
            }
            rainbow = (rainbowLen >= 3);
        }

        int handLen = 0, handScore = 0;
        if (rainbow && rainbowLen >= best) {
            handLen = rainbowLen;
            handScore = rainbowScore(rainbowLen);
        } else if (best >= 3) {
            handLen = best;
            handScore = sameColorScore(best);
        }

        if (handLen >= 3) {
            score += handScore;
            rescued += handLen;
            // clear the platform entries used
            platCount = 0;
            for (int i = 0; i < MAX_PLAT; i++) platform[i] = NONE;
            escaped = true;
            sound(SND_SCORE);
            if (rescued >= rescueTarget) {
                state = State.LEVEL_DONE;
                sound(SND_LEVEL);
            }
        }
    }

    private int sameColorScore(int n) {
        switch (n) {
            case 3: return 5;
            case 4: return 25;
            case 5: return 125;
            case 6: return 400;
            default: return 1500;
        }
    }

    private int rainbowScore(int n) {
        switch (n) {
            case 3: return 15;
            case 4: return 60;
            case 5: return 150;
            case 6: return 600;
            default: return 2500;
        }
    }

    // ---- helpers -------------------------------------------------------------
    Rat ratAt(int beltPos) {
        for (Rat r : belt) {
            if (r.beltPos == beltPos) return r;
        }
        return null;
    }

    private void sound(String name) {
        if (listener != null) listener.sound(name);
    }

    int levelCount() { return LEVELS.length - 1; } // 20 levels
}
