package com.teff.puzzles.mixgen;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;

/**
 * The original plain SPRITE resources: uint16 width, uint16 height, then width*height 8-bit
 * palette indices, top row first. Index 0 is transparent (the blitter FUN_00416a90 skips it).
 * The colours come from the GAMEBOX palette (assets/mixgen/data/palette.bin).
 * Plain Java (no Android imports) so the rules can be simulated headless.
 */
final class Sprites {
    static final class Sprite {
        final int id, w, h;
        final byte[] px;

        Sprite(int id, int w, int h, byte[] px) {
            this.id = id;
            this.w = w;
            this.h = h;
            this.px = px;
        }

        boolean opaqueAt(int x, int y) {
            return x >= 0 && y >= 0 && x < w && y < h && px[y * w + x] != 0;
        }
    }

    interface Source {
        /** Opens SPRITE resource {@code id}, or returns null if it does not exist. */
        InputStream open(int id) throws IOException;
    }

    private final Map<Integer, Sprite> map = new HashMap<>();

    /** Every sprite id the game uses (body parts, breed hearts, pipe bubbles, rescue valve). */
    static int[] allIds() {
        int[] ids = new int[200];
        int n = 0;
        for (int s = 0; s < Game.SPECIES; s++) {
            for (int p = 0; p < 5; p++) {
                ids[n++] = 2100 + s * 100 + p;
            }
            for (int f = 0; f < Game.HEAD[s].length; f++) {
                ids[n++] = 2105 + s * 100 + f;
            }
        }
        for (int i = 3000; i <= 3012; i++) ids[n++] = i;
        for (int i = 3100; i <= 3112; i++) ids[n++] = i;
        for (int i = 3300; i <= 3303; i++) ids[n++] = i;
        int[] out = new int[n];
        System.arraycopy(ids, 0, out, 0, n);
        return out;
    }

    static Sprites load(Source source) throws IOException {
        Sprites s = new Sprites();
        for (int id : allIds()) {
            try (InputStream in = source.open(id)) {
                if (in == null) {
                    continue;
                }
                byte[] all = readAll(in);
                if (all.length < 4) {
                    continue;
                }
                int w = (all[0] & 0xFF) | (all[1] & 0xFF) << 8;
                int h = (all[2] & 0xFF) | (all[3] & 0xFF) << 8;
                byte[] px = new byte[w * h];
                System.arraycopy(all, 4, px, 0, Math.min(px.length, all.length - 4));
                s.map.put(id, new Sprite(id, w, h, px));
            }
        }
        return s;
    }

    Sprite get(int id) {
        return map.get(id);
    }

    Iterable<Sprite> all() {
        return map.values();
    }

    private static byte[] readAll(InputStream in) throws IOException {
        byte[] buf = new byte[8192];
        java.io.ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
        int r;
        while ((r = in.read(buf)) > 0) {
            out.write(buf, 0, r);
        }
        return out.toByteArray();
    }
}
