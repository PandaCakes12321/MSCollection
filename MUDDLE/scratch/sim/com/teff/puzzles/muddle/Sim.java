package com.teff.puzzles.muddle;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

/** Headless checks for Game: all 18 GLEVELs, solvability by BFS, random generator, random play. */
public final class Sim {
    static Path dir;
    static int sounds;

    public static void main(String[] args) throws Exception {
        dir = Paths.get(args[0]);
        Game.LevelSource src = name -> {
            try {
                return Files.readAllBytes(dir.resolve(name + ".bin"));
            } catch (Exception e) {
                return null;
            }
        };
        // 1. every level file loads, is consistent and is solvable with SPACE only
        String[] names = new String[18];
        for (int i = 1; i <= 8; i++) names[i - 1] = String.format("LEVELT%03d", i);
        for (int i = 1; i <= 10; i++) names[7 + i] = String.format("LEVEL%03d", i);
        for (String n : names) {
            Game g = new Game(new Random(1));
            g.levels = src;
            g.mode = Game.TRAINING;
            if (!g.loadLevel(n)) throw new AssertionError("load " + n);
            check(g);
            int depth = solve(g, 3_000_000);
            System.out.printf("%-10s cards=%d  order=%s  BFS solution: %s%n", n, g.cardsLeft(),
                    Arrays.toString(g.order), depth < 0 ? "none found (" + (-depth) + " states)" : depth + " moves");
        }
        // 2. random generator per difficulty
        for (int mode = Game.EASY; mode <= Game.HARD; mode++) {
            int solved = 0, total = 40, unknown = 0;
            long t = System.currentTimeMillis();
            for (int i = 0; i < total; i++) {
                Game g = new Game(new Random(1000L * mode + i));
                g.levels = src;
                g.mode = mode;
                g.generateLevel();
                check(g);
                if (g.cardsLeft() != 8) throw new AssertionError("random level cards " + g.cardsLeft());
                int d = solve(g, 400_000);
                if (d >= 0) solved++; else unknown++;
            }
            System.out.printf("random mode %d: %d/%d solved by BFS (%d over search limit), %d ms%n",
                    mode, solved, total, unknown, System.currentTimeMillis() - t);
        }
        // 3. random play, all difficulties, invariants every step
        Random r = new Random(42);
        int games = 0, levelsDone = 0, overs = 0;
        for (int i = 0; i < 400; i++) {
            Game g = new Game(new Random(i));
            g.levels = src;
            final int[] over = {0};
            g.listener = new Game.Listener() {
                public void sound(String name) { sounds++; }
                public void tip(int kind) { }
                public void gameOver(int score) { over[0]++; }
            };
            g.difficulty = 1 + (i % 5);
            g.startLevel = 1 + r.nextInt(10);
            g.newGame();
            games++;
            for (int step = 0; step < 4000 && g.state != Game.State.OVER; step++) {
                int a = r.nextInt(20);
                int lvl = g.level;
                if (a < 6) g.arrow(r.nextInt(4));
                else if (a < 8) g.selectGroup(1 + r.nextInt(8));
                else if (a < 9) g.chooseBet(1 + r.nextInt(4));
                else if (a < 10) g.move(true);
                else if (a < 11 && r.nextInt(20) == 0) g.restartLevel();
                else g.move(false);
                for (int k = 0; k < 25 && g.state == Game.State.LEVEL_DONE; k++) g.tick();
                g.tick();
                if (g.level != lvl || g.state == Game.State.OVER) levelsDone++;
                check(g);
            }
            overs += over[0];
        }
        System.out.printf("random play: %d games, %d level changes, %d game overs, %d sounds, no exceptions%n",
                games, levelsDone, overs, sounds);
        // 4. scripted check of the exit, scoring and coins on LEVELT001 solution
        Game g = new Game(new Random(5));
        g.levels = src;
        g.difficulty = Game.EASY;
        g.startLevel = 1;
        g.newGame();
        System.out.println("Easy new game: score=" + g.score + " bet=" + g.bet + " coins " + g.playerCoins + "/" + g.casinoCoins);
        int before = g.score;
        int[] path = solvePath(g, 400_000);
        if (path != null) {
            for (int d : path) {
                g.selectGroup(d);
                if (!g.move(false)) throw new AssertionError("solution move refused");
            }
            System.out.println("solved random Easy level in " + path.length + " moves: score " + before + " -> "
                    + g.score + " (expect +40 = -40 bet +80 won), playerCoins=" + g.playerCoins + " state=" + g.state);
            if (g.score != before + 40 || g.playerCoins != 16) throw new AssertionError("scoring");
        }
        System.out.println("ALL CHECKS PASSED");
    }

    static void check(Game g) {
        Set<Integer> onBoard = new HashSet<>();
        for (int[] row : g.board) {
            for (int v : row) {
                if (v < 0 || v > 12) throw new AssertionError("bad cell " + v);
                if (Game.isCard(v) && !onBoard.add(v)) throw new AssertionError("duplicate card " + v);
            }
        }
        Set<Integer> inOrder = new HashSet<>();
        boolean zero = false;
        for (int v : g.order) {
            if (v == 0) { zero = true; continue; }
            if (zero) throw new AssertionError("gap in order " + Arrays.toString(g.order));
            if (!inOrder.add(v)) throw new AssertionError("dup in order");
        }
        if (g.state != Game.State.OVER && g.state != Game.State.TITLE && g.state != Game.State.LEVEL_DONE
                && !onBoard.equals(inOrder)) {
            throw new AssertionError("board cards " + onBoard + " != order " + inOrder);
        }
        if (g.playerCoins < 0 || g.casinoCoins < 0 || g.playerCoins + g.casinoCoins > 16)
            throw new AssertionError("coins " + g.playerCoins + "/" + g.casinoCoins);
        if (g.bet < 1 || g.bet > 4) throw new AssertionError("bet");
        if (g.mode == Game.TRAINING && g.score != 0) throw new AssertionError("training score");
        if (g.score < 0) throw new AssertionError("negative score " + g.score);
    }

    // ---- BFS over SPACE moves -------------------------------------------------------------------

    static String key(Game g) {
        StringBuilder sb = new StringBuilder(150);
        for (int[] row : g.board) for (int v : row) sb.append((char) ('a' + v));
        for (int v : g.order) sb.append((char) ('0' + v));
        return sb.toString();
    }

    static void restore(Game g, String k) {
        int p = 0;
        for (int[] row : g.board) for (int c = 0; c < row.length; c++) row[c] = k.charAt(p++) - 'a';
        for (int i = 0; i < g.order.length; i++) g.order[i] = k.charAt(p++) - '0';
        g.state = Game.State.PLAYING;
    }

    static int solve(Game g, int limit) {
        int[] p = solvePath(g, limit);
        return p == null ? -limit : p.length;
    }

    static int[] solvePath(Game g, int limit) {
        Game.Listener saved = g.listener;
        g.listener = null;
        String start = key(g);
        int savedScore = g.score, savedBet = g.bet, pc = g.playerCoins, cc = g.casinoCoins, dir = g.dir;
        boolean betting = g.betting;
        Game.State st = g.state;
        java.util.HashMap<String, String> parent = new java.util.HashMap<>();
        java.util.HashMap<String, Integer> how = new java.util.HashMap<>();
        ArrayDeque<String> q = new ArrayDeque<>();
        parent.put(start, null);
        q.add(start);
        String goal = null;
        while (!q.isEmpty() && parent.size() < limit && goal == null) {
            String s = q.poll();
            for (int d = 1; d <= 8; d++) {
                restore(g, s);
                g.dir = d;
                if (!g.move(false)) continue;
                String n = key(g);
                if (parent.containsKey(n)) continue;
                parent.put(n, s);
                how.put(n, d);
                if (g.order[0] == 0) { goal = n; break; }
                q.add(n);
            }
        }
        restore(g, start);
        g.score = savedScore; g.bet = savedBet; g.playerCoins = pc; g.casinoCoins = cc; g.dir = dir;
        g.betting = betting; g.state = st; g.listener = saved;
        if (goal == null) return null;
        java.util.ArrayList<Integer> moves = new java.util.ArrayList<>();
        for (String s = goal; parent.get(s) != null; s = parent.get(s)) moves.add(0, how.get(s));
        int[] out = new int[moves.size()];
        for (int i = 0; i < out.length; i++) out[i] = moves.get(i);
        return out;
    }
}
