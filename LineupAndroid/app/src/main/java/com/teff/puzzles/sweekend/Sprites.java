package com.teff.puzzles.sweekend;

/**
 * Hotspots of the original SPRITE frames (header offset 0x84, one (x, y) pair per frame, measured
 * from the frame's top-left). A sprite placed at (px, py) on screen is drawn at (px - x, py - y).
 * Frames are in assets/sweekend/img/&lt;name&gt;_&lt;frame&gt;.png (converted by SWEEKEND/scratch/convert.py).
 */
final class Sprites {
    private Sprites() {}

    static final int[][] BEE = {{36, 23}, {38, 28}, {39, 30}, {40, 30}, {30, 30}, {32, 30}, {30, 23}, {31, 28}};
    static final int[][] BUTTERFLY = {{45, 43}, {37, 31}, {43, 50}, {37, 36}, {39, 50}, {35, 36}, {41, 43}, {36, 31}};
    static final int[][] DIGITS_LEV = {{9, 12}, {5, 12}, {8, 12}, {8, 12}, {9, 12}, {8, 12}, {8, 12}, {9, 11}, {8, 12}, {9, 12}};
    static final int[][] DIGITS_MOV = {{10, 10}, {7, 10}, {9, 10}, {9, 10}, {10, 10}, {9, 10}, {9, 10}, {10, 9}, {9, 10}, {10, 10}};
    static final int[][] DIGITS_SCO = {{9, 12}, {5, 12}, {7, 12}, {7, 12}, {9, 12}, {8, 12}, {8, 12}, {9, 11}, {8, 12}, {9, 12}};
    static final int[][] FLOWERS = {{24, 20}, {21, 23}, {19, 20}, {23, 17}, {22, 17}, {19, 23}, {23, 25}, {22, 24}, {28, 26}, {23, 24}, {26, 19}};
    static final int[][] FLOWERS1 = {{13, 12}, {11, 12}, {10, 11}, {12, 11}, {12, 10}, {10, 11}, {13, 13}, {13, 12}, {15, 12}, {13, 12}, {13, 10}};
}
