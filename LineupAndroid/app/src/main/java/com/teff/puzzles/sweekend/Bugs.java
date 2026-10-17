package com.teff.puzzles.sweekend;

import java.util.Random;

/**
 * The bee and the butterfly that fly across the screen now and then (FUN_00406823, with
 * FUN_004065de for the bee and FUN_0040644d for the butterfly). Only one flies at a time.
 * Positions are original sprite coordinates: x from the left, y from the BOTTOM (screen y = 400 - y).
 * Plain Java, ticked every 50 ms.
 */
final class Bugs {
    private final Random rnd;

    /** 1-in-N chance per tick of a bee (butterfly: 1-in-N/2); 400 normally, 100 after a lost game. */
    int chance = 400;

    boolean bee, butterfly;
    int x, y, frame;
    private int dir;      // 0 = flying right, 1 = flying left
    private int vdir;     // +1 up, -1 down (DAT_00414714)
    private int steps;    // DAT_00414718
    private int hover;    // DAT_0041471c, bee only

    Bugs(Random rnd) {
        this.rnd = rnd;
    }

    private int rand(int n) {
        return n < 1 ? 0 : rnd.nextInt(n);
    }

    /** Returns the sound to play this tick (Game.SND_*), or 0. */
    int tick() {
        if (bee) {
            fly(20, 10, true);
            return 0;
        }
        if (butterfly) {
            fly(15, 7, false);
            return 0;
        }
        if (rand(chance) == 0) {
            bee = true;
            start();
            return Game.SND_BEE;
        }
        if (rand(chance / 2) == 0) {
            butterfly = true;
            start();
            return Game.SND_TIME1 + rand(3);
        }
        return 0;
    }

    private void start() {
        dir = rand(2);
        vdir = rand(2) == 0 ? 1 : -1;
        steps = 0;
        hover = 0;
        y = rand(300) + 50;
        if (dir == 0) {
            x = bee ? -80 : -100;
            frame = 4;
        } else {
            x = 700;
            frame = 0;
        }
    }

    private void fly(int dx, int dy, boolean canHover) {
        if (!canHover || hover == 0) {
            x += dir == 0 ? dx : -dx;
            y += vdir * dy;
        }
        int f = frame + 1;
        if (dir == 0) {
            if (vdir < 1) {
                if (f > 7) f = 6;
            } else if (f > 5) {
                f = 4;
            }
        } else {
            if (vdir < 1) {
                if (f > 1) f = 0;
            } else if (f > 3) {
                f = 2;
            }
        }
        frame = f;
        if ((dir == 0 && x > 700) || (dir != 0 && x < -100)) {
            bee = false;
            butterfly = false;
        }
        steps++;
        if (canHover) {
            if (hover != 0) {
                hover++;
            }
            if (hover > 30) {
                hover = 0;
            }
        }
        if (steps > 9) {
            if (rand(20) == 0) {
                vdir = -vdir;
            }
            if (canHover && hover == 0 && rand(20) == 0) {
                hover = 1;
            }
        }
    }
}
