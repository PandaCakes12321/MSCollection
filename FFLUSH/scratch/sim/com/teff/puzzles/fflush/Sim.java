package com.teff.puzzles.fflush;

import java.util.Random;

/** Headless simulation of Game: random and greedy players, invariant checks. */
public final class Sim {
    static int maxLevel, totalGrids, sounds, overGames, penalties, palettes, bombs;

    public static void main(String[] args) {
        int games = args.length > 0 ? Integer.parseInt(args[0]) : 2000;
        Random seed = new Random(12345);
        for (int n = 0; n < games; n++) {
            Game g = new Game(new Random(seed.nextLong()));
            g.difficulty = 1 + n % 4;
            g.startLevel = 1 + (n / 4) % 10;
            final Game game = g;
            g.listener = new Game.Listener() {
                public void sound(String s) { sounds++; }
                public void tip(int kind) {
                    if (kind == Game.PALETTE) palettes++;
                    if (kind == Game.BOMB) bombs++;
                    if (kind == Game.TIP_NO_BONUS) penalties++;
                }
                public void dropped(int[] balls, int col) { }
                public void gridCompleted(int grid, int[][] b, boolean up) {
                    totalGrids++;
                    int v = b[0][0];
                    for (int[] c : b) for (int x : c) if (x != v || v < 1 || v > 4) throw new IllegalStateException("not full");
                }
                public void gameOver(int score) {
                    if (game.state != Game.State.OVER) throw new IllegalStateException("over state");
                }
            };
            g.newGame();
            check(g);
            boolean greedy = n % 3 != 0;
            Random r = new Random(n);
            int lastScore = 0;
            for (int step = 0; step < 200000 && g.state == Game.State.PLAYING; step++) {
                if (greedy) {
                    if (!greedyMove(g, r)) {
                        g.tick(1000);
                    }
                    if (r.nextInt(4) == 0) g.tick(700);
                } else {
                    randomMove(g, r);
                    g.tick(r.nextInt(400));
                }
                check(g);
                if (g.score < lastScore) throw new IllegalStateException("score went down");
                lastScore = g.score;
                maxLevel = Math.max(maxLevel, g.level);
            }
            if (g.state != Game.State.OVER) throw new IllegalStateException("game never ended");
            overGames++;
        }
        System.out.println("games=" + games + " over=" + overGames + " gridsCompleted=" + totalGrids
                + " maxLevel=" + maxLevel + " sounds=" + sounds + " noBonusPenalties=" + penalties
                + " paletteTips=" + palettes + " bombTips=" + bombs);
    }

    static void randomMove(Game g, Random r) {
        switch (r.nextInt(8)) {
            case 0: g.slideUpperLeft(); break;
            case 1: g.slideUpperRight(); break;
            case 2: g.slideLowerLeft(); break;
            case 3: g.slideLowerRight(); break;
            case 4: g.rotate(r.nextBoolean()); break;
            case 5: g.selectGrid(r.nextInt(4)); break;
            default: g.drop(); break;
        }
        if (r.nextInt(3) == 0) g.finishRotation();
    }

    /** Pick the drop that keeps a grid single-coloured without collisions. */
    static boolean greedyMove(Game g, Random r) {
        g.finishRotation();
        int best = Integer.MIN_VALUE, bg = -1, bc = -1, bh = -1, brot = 0;
        // Every column stays on screen, so only these columns can reach the drop point.
        int hMin = Math.max(0, g.count - 14), hMax = Math.min(g.count - 1, 13);
        for (int h = Math.min(hMin, g.hl); h <= Math.max(hMax, g.hl); h++) {
            int[] col = g.upper[h];
            for (int grid = 0; grid < 4; grid++) {
                for (int rot = 0; rot < 4; rot++) {
                    int[][] m = rotated(g.lower[grid], rot);
                    int dom = dominant(m);
                    for (int c = 0; c < 4; c++) {
                        int s = 0;
                        for (int row = 0; row < 4; row++) {
                            int lo = m[c][row], up = col[row];
                            if (up == 0) continue;
                            if (Game.isColour(lo) && Game.isColour(up)) s -= 50;
                            else if (lo == 0 && Game.isColour(up)) s += (dom == 0 || up == dom) ? 10 : -20;
                            else if (up == Game.BOMB && Game.isColour(lo) && lo != dom) s += 15;
                            else if (up == Game.PALETTE && lo != 0) s += 5;
                        }
                        s -= Math.abs(h - g.hl) + rot;
                        if (s > best) {
                            best = s; bg = grid; bc = c; bh = h; brot = rot;
                        }
                    }
                }
            }
        }
        if (bg < 0 || best < 0) {
            return false;
        }
        g.selectGrid(bg);
        for (int k = 0; k < brot; k++) {
            g.rotate(true);
            g.finishRotation();
        }
        for (int guard = 0; guard < 10 && g.lowerCol != bc; guard++) {
            if (g.lowerCol < bc) g.slideLowerLeft(); else g.slideLowerRight();
        }
        for (int guard = 0; guard < 40 && g.hl != bh; guard++) {
            if (g.hl < bh) g.slideUpperRight(); else g.slideUpperLeft();
        }
        if (g.lowerCol != bc || g.hl != bh || g.current != bg) throw new IllegalStateException("could not reach move");
        return g.drop();
    }

    static int[][] rotated(int[][] m, int times) {
        int[][] a = new int[4][4];
        for (int c = 0; c < 4; c++) a[c] = m[c].clone();
        for (int t = 0; t < times; t++) {
            int[][] b = new int[4][4];
            for (int c = 0; c < 4; c++) for (int row = 0; row < 4; row++) b[c][row] = a[row][3 - c];
            a = b;
        }
        return a;
    }

    static int dominant(int[][] m) {
        int[] n = new int[5];
        for (int[] c : m) for (int v : c) if (v >= 1 && v <= 4) n[v]++;
        int d = 0;
        for (int k = 1; k <= 4; k++) if (n[k] > (d == 0 ? 0 : n[d])) d = k;
        return d;
    }

    static void check(Game g) {
        if (g.count < 0 || g.count > Game.MAX_COLUMNS) throw new IllegalStateException("count " + g.count);
        if (g.count > 0) {
            if (g.hl < 0 || g.hl >= g.count) throw new IllegalStateException("hl " + g.hl + "/" + g.count);
            if (g.base != Game.DROP_X + 20 * g.hl) throw new IllegalStateException("base " + g.base + " hl " + g.hl);
            for (int i = 0; i < g.count; i++) {
                boolean any = false;
                for (int v : g.upper[i]) {
                    if (v < 0 || v > 6) throw new IllegalStateException("upper value " + v);
                    any |= v != 0;
                }
                if (!any) throw new IllegalStateException("empty column " + i);
            }
        } else if (g.state == Game.State.PLAYING) {
            throw new IllegalStateException("upper grid empty while playing");
        }
        for (int[][] grid : g.lower) for (int[] c : grid) for (int v : c)
            if (v < 0 || v > 6) throw new IllegalStateException("lower value " + v);
        if (g.lowerCol < 0 || g.lowerCol > 3) throw new IllegalStateException("lowerCol");
        if (g.current == g.previous || g.current < 0 || g.current > 3 || g.previous < 0 || g.previous > 3)
            throw new IllegalStateException("grid select " + g.current + " " + g.previous);
        if (g.bonus < 0) throw new IllegalStateException("bonus");
        if (g.state == Game.State.PLAYING && (g.toGo < 1 || g.toGo > Game.gridsForLevel(g.level)))
            throw new IllegalStateException("toGo " + g.toGo);
        // Columns past the drop point are on screen inside the strip (x 17..577).
        if (g.count > 0 && (g.base > 577 || g.base - 20 * (g.count - 1) < 17))
            throw new IllegalStateException("column off screen: base " + g.base + " count " + g.count);
    }
}
