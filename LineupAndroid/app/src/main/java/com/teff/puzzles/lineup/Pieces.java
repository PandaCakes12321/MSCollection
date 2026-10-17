package com.teff.puzzles.lineup;

/**
 * The 12 pentominoes from Lineup.EXE (7x7 grids at VA 0x4114B0, center cell = row 3, col 3),
 * expanded into 96 variants exactly like FUN_00402c90: id = base*8 + rotation*2 + mirrored + 1.
 */
final class Pieces {
    private Pieces() {}

    static final int COUNT = 96;

    // Base order as stored in the exe: T V F X W P Y U L N I Z
    private static final String[] BASE = {
            "......." + "......." + "......." + "..###.." + "...#..." + "...#..." + ".......",
            "......." + "...#..." + "...#..." + "...###." + "......." + "......." + ".......",
            "......." + "......." + "...##.." + "..##..." + "...#..." + "......." + ".......",
            "......." + "......." + "...#..." + "..###.." + "...#..." + "......." + ".......",
            "......." + "......." + "..#...." + "..##..." + "...##.." + "......." + ".......",
            "......." + "......." + "...##.." + "...##.." + "...#..." + "......." + ".......",
            "......." + "......." + "...#..." + ".####.." + "......." + "......." + ".......",
            "......." + "......." + "..#.#.." + "..###.." + "......." + "......." + ".......",
            "...#..." + "...#..." + "...#..." + "...##.." + "......." + "......." + ".......",
            "......." + "...#..." + "...#..." + "..##..." + "..#...." + "......." + ".......",
            "......." + "...#..." + "...#..." + "...#..." + "...#..." + "...#..." + ".......",
            "......." + "......." + "..##..." + "...#..." + "...##.." + "......." + ".......",
    };

    /** Picker weights per tier (table at VA 0x411C20), one per base shape. Tier 0 is unused. */
    static final int[][] WEIGHTS = {
            {8, 8, 1, 8, 1, 2, 1, 2, 8, 1, 8, 2},
            {8, 8, 1, 8, 1, 2, 1, 2, 8, 1, 8, 2},
            {8, 8, 2, 8, 2, 4, 2, 4, 8, 2, 8, 4},
            {2, 2, 1, 2, 1, 2, 1, 2, 2, 1, 2, 2},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {2, 2, 3, 2, 3, 4, 3, 4, 2, 3, 2, 4},
    };

    /** SHAPE[id] = the five {rowOffset, colOffset} cells relative to the center, ids 1..96. */
    static final int[][][] SHAPE = new int[COUNT + 1][][];

    static {
        for (int base = 0; base < BASE.length; base++) {
            boolean[][] grid = new boolean[7][7];
            for (int i = 0; i < 49; i++) {
                grid[i / 7][i % 7] = BASE[base].charAt(i) == '#';
            }
            for (int rot = 0; rot < 4; rot++) {
                for (int mirror = 0; mirror < 2; mirror++) {
                    boolean[][] g = mirror == 1 ? mirrored(grid) : grid;
                    for (int k = 0; k < rot; k++) {
                        g = rotated(g);
                    }
                    SHAPE[base * 8 + rot * 2 + mirror + 1] = cells(g);
                }
            }
        }
    }

    /** Which SQUARE_n ball image a piece uses (FUN_004068f3). */
    static int look(int id) {
        return (((id - 1) & 1) + ((id - 1) >> 3) * 2) % 6;
    }

    /** The piece after one quarter turn (orientation + 6 mod 8, same as the original click handler). */
    static int rotate(int id) {
        int orientation = (id - 1) & 7;
        int base = (id - 1) >> 3;
        return base * 8 + ((orientation + 6) & 7) + 1;
    }

    private static boolean[][] mirrored(boolean[][] g) {
        boolean[][] out = new boolean[7][7];
        for (int r = 0; r < 7; r++) {
            for (int c = 0; c < 7; c++) {
                out[r][c] = g[r][6 - c];
            }
        }
        return out;
    }

    private static boolean[][] rotated(boolean[][] g) {
        boolean[][] out = new boolean[7][7];
        for (int r = 0; r < 7; r++) {
            for (int c = 0; c < 7; c++) {
                out[r][c] = g[6 - c][r];
            }
        }
        return out;
    }

    private static int[][] cells(boolean[][] g) {
        int[][] out = new int[5][];
        int n = 0;
        for (int r = 0; r < 7; r++) {
            for (int c = 0; c < 7; c++) {
                if (g[r][c]) {
                    out[n++] = new int[] {r - 3, c - 3};
                }
            }
        }
        return out;
    }
}
