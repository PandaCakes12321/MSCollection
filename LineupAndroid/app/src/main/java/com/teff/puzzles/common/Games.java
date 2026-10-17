package com.teff.puzzles.common;

import android.app.Activity;

/** The ten games in menu order. Icons are assets/icons/&lt;id&gt;.png (each game's original About picture). */
public final class Games {
    private Games() {}

    public static final class Entry {
        public final String id;
        public final String title;
        public final Class<? extends Activity> activity;

        Entry(String id, String title, Class<? extends Activity> activity) {
            this.id = id;
            this.title = title;
            this.activity = activity;
        }
    }

    public static final Entry[] ALL = {
            new Entry("charmer", "Charmer", com.teff.puzzles.charmer.CharmerActivity.class),
            new Entry("colc", "Color Collision", com.teff.puzzles.colc.ColcActivity.class),
            new Entry("fflush", "Finty Flush", com.teff.puzzles.fflush.FflushActivity.class),
            new Entry("fringer", "Fringer", com.teff.puzzles.fringer.FringerActivity.class),
            new Entry("jewelch", "Jewel Chase", com.teff.puzzles.jewelch.JewelchActivity.class),
            new Entry("lineup", "Lineup", com.teff.puzzles.lineup.LineupActivity.class),
            new Entry("mixgen", "Mixed Genetics", com.teff.puzzles.mixgen.MixgenActivity.class),
            new Entry("muddle", "Muddled Casino", com.teff.puzzles.muddle.MuddleActivity.class),
            new Entry("ratpoker", "Rat Poker", com.teff.puzzles.ratpoker.RatpokerActivity.class),
            new Entry("sweekend", "Spring Weekend", com.teff.puzzles.sweekend.SweekendActivity.class),
    };
}
