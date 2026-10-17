package com.teff.puzzles.jewelch;

/**
 * One GLEVEL resource ("LEVELnnn", loader FUN_0040a07f / FUN_00408a27):
 * <pre>
 *   "PL"                       2-byte tag
 *   uint16 tile[10][15]        row-major; bits 0-1 kind (0 = one colour, 1-3 = four-part tile),
 *                              bits 2-4 / 5-7 / 8-10 / 11-13 = colour of quarter 0..3 (1..6)
 *   byte start[3]              (row &lt;&lt; 4 | col) of thief 0 (computer), 1 (player), 2 (unused 2nd player)
 *   byte n, n x { byte pos, uint16 item, byte pad }      valuables / exit / key / switch / bomb
 *   byte m, m x { byte pos, byte item2 }                  rolling ball / doors
 *   (any trailing bytes are editor leftovers and ignored)
 * </pre>
 * Plain Java so it can be loaded in the headless simulation.
 */
public final class Level {
    public final int[] tiles = new int[Game.ROWS * Game.COLS];
    public final int[] startRow = new int[3], startCol = new int[3];
    public final int[][] items;   // {row, col, item}
    public final int[][] items2;  // {row, col, item2}

    private Level(int[][] items, int[][] items2) {
        this.items = items;
        this.items2 = items2;
    }

    public static Level parse(byte[] d) {
        if (d == null || d.length < 2 + 300 + 4 || d[0] != 'P' || d[1] != 'L') {
            throw new IllegalArgumentException("not a GLEVEL resource");
        }
        int p = 2;
        int[] tiles = new int[Game.ROWS * Game.COLS];
        for (int i = 0; i < tiles.length; i++) {
            tiles[i] = (d[p] & 0xFF) | (d[p + 1] & 0xFF) << 8;
            p += 2;
        }
        int[] start = {d[p] & 0xFF, d[p + 1] & 0xFF, d[p + 2] & 0xFF};
        int n = d[p + 3] & 0xFF;
        p += 4;
        int[][] items = new int[n][];
        for (int i = 0; i < n; i++) {
            int pos = d[p] & 0xFF;
            int v = (d[p + 1] & 0xFF) | (d[p + 2] & 0xFF) << 8;
            items[i] = new int[] {pos >> 4, pos & 15, v};
            p += 4;
        }
        int m = d[p] & 0xFF;
        p++;
        int[][] items2 = new int[m][];
        for (int i = 0; i < m; i++) {
            int pos = d[p] & 0xFF;
            items2[i] = new int[] {pos >> 4, pos & 15, d[p + 1] & 0xFF};
            p += 2;
        }
        if (p > d.length) {
            throw new IllegalArgumentException("truncated GLEVEL resource");
        }
        Level level = new Level(items, items2);
        System.arraycopy(tiles, 0, level.tiles, 0, tiles.length);
        for (int i = 0; i < 3; i++) {
            level.startRow[i] = start[i] >> 4;
            level.startCol[i] = start[i] & 15;
        }
        return level;
    }

    /** Colour (1..6) of quarter q (0..3) of a tile word; one-colour tiles use quarter 0's colour everywhere. */
    public static int quarterColour(int tile, int q) {
        if ((tile & 3) == 0) {
            q = 0;
        }
        return (tile >> (2 + 3 * q)) & 7;
    }

    /** Colour bit mask of a tile word (FUN_00407347). */
    public static int colourMask(int tile) {
        int m = 0;
        int quarters = (tile & 3) == 0 ? 1 : 4;
        for (int q = 0; q < quarters; q++) {
            int c = quarterColour(tile, q);
            if (c > 0) {
                m |= 1 << (c - 1);
            }
        }
        return m & 0xFF;
    }
}
