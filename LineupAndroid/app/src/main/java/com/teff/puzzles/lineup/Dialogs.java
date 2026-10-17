package com.teff.puzzles.lineup;

import android.app.AlertDialog;
import android.content.Context;
import android.content.SharedPreferences;
import android.text.InputType;
import android.view.Gravity;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.NumberPicker;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.ScrollView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

/** Options and the top-10 high score table, saved in SharedPreferences. */
final class Dialogs {
    private Dialogs() {}

    private static final String[] DIFFICULTIES = {"Easy", "Medium", "Hard", "Crazy"};
    private static final int MAX_SCORES = 10;

    static void showOptions(LineupActivity activity) {
        SharedPreferences prefs = prefs(activity);
        int pad = dp(activity, 20);

        LinearLayout box = new LinearLayout(activity);
        box.setOrientation(LinearLayout.VERTICAL);
        box.setPadding(pad, pad / 2, pad, 0);

        box.addView(label(activity, "Difficulty (applies to the next new game)"));
        RadioGroup difficulty = new RadioGroup(activity);
        difficulty.setOrientation(RadioGroup.HORIZONTAL);
        for (int i = 0; i < DIFFICULTIES.length; i++) {
            RadioButton b = new RadioButton(activity);
            b.setText(DIFFICULTIES[i]);
            b.setId(i + 1);
            difficulty.addView(b);
        }
        difficulty.check(prefs.getInt("difficulty", 1));
        box.addView(difficulty);

        box.addView(label(activity, "Start level (1 - 10)"));
        NumberPicker level = new NumberPicker(activity);
        level.setMinValue(1);
        level.setMaxValue(10);
        level.setValue(prefs.getInt("startLevel", 1));
        box.addView(level);

        CheckBox music = new CheckBox(activity);
        music.setText("Background music");
        music.setChecked(prefs.getBoolean("music", true));
        box.addView(music);

        CheckBox sound = new CheckBox(activity);
        sound.setText("Sound effects");
        sound.setChecked(prefs.getBoolean("sound", true));
        box.addView(sound);

        ScrollView scroll = new ScrollView(activity);
        scroll.addView(box);

        new AlertDialog.Builder(activity)
                .setTitle("Lineup Options")
                .setView(scroll)
                .setPositiveButton("OK", (d, w) -> {
                    prefs.edit()
                            .putInt("difficulty", Math.max(1, difficulty.getCheckedRadioButtonId()))
                            .putInt("startLevel", level.getValue())
                            .putBoolean("music", music.isChecked())
                            .putBoolean("sound", sound.isChecked())
                            .apply();
                    activity.gameView().optionsChanged();
                })
                .setNegativeButton("Cancel", null)
                .show();
    }

    static void checkHighScore(LineupActivity activity, int score) {
        List<Entry> scores = load(prefs(activity));
        boolean qualifies = score > 0
                && (scores.size() < MAX_SCORES || score > scores.get(scores.size() - 1).score);
        if (!qualifies) {
            return;
        }
        SharedPreferences prefs = prefs(activity);
        EditText name = new EditText(activity);
        name.setInputType(InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_FLAG_CAP_WORDS);
        name.setSingleLine(true);
        name.setText(prefs.getString("lastName", ""));
        name.selectAll();
        LinearLayout box = new LinearLayout(activity);
        int pad = dp(activity, 20);
        box.setPadding(pad, 0, pad, 0);
        box.addView(name, new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT));

        new AlertDialog.Builder(activity)
                .setTitle("Congratulations!")
                .setMessage("You beat a top 10 score! Your score is " + score + ".\nPlease type your name:")
                .setView(box)
                .setCancelable(false)
                .setPositiveButton("OK", (d, w) -> {
                    String who = name.getText().toString().trim();
                    if (who.isEmpty()) {
                        who = "Player";
                    }
                    who = who.replace('\t', ' ').replace('\n', ' ');
                    scores.add(new Entry(score, who));
                    scores.sort((a, b) -> Integer.compare(b.score, a.score));
                    while (scores.size() > MAX_SCORES) {
                        scores.remove(scores.size() - 1);
                    }
                    save(prefs, scores);
                    prefs.edit().putString("lastName", who).apply();
                    showHighScores(activity);
                })
                .show();
    }

    static void showHighScores(LineupActivity activity) {
        SharedPreferences prefs = prefs(activity);
        List<Entry> scores = load(prefs);
        StringBuilder sb = new StringBuilder();
        if (scores.isEmpty()) {
            sb.append("No scores yet - go play!");
        }
        for (int i = 0; i < scores.size(); i++) {
            sb.append(String.format(Locale.US, "%2d.  %-15s %6d%n", i + 1, scores.get(i).name, scores.get(i).score));
        }
        TextView view = new TextView(activity);
        view.setTypeface(android.graphics.Typeface.MONOSPACE);
        view.setTextSize(16);
        int pad = dp(activity, 20);
        view.setPadding(pad, pad / 2, pad, 0);
        view.setGravity(Gravity.START);
        view.setText(sb.toString());

        new AlertDialog.Builder(activity)
                .setTitle("High Scores for Lineup")
                .setView(view)
                .setPositiveButton("OK", null)
                .setNeutralButton("Reset", (d, w) -> new AlertDialog.Builder(activity)
                        .setTitle("Lineup")
                        .setMessage("Are you sure you want to reset all the High Scores to zero?")
                        .setPositiveButton("Yes", (d2, w2) -> prefs.edit().remove("scores").apply())
                        .setNegativeButton("No", null)
                        .show())
                .show();
    }

    // ---- storage: one "score<TAB>name" per line --------------------------------------------

    private static final class Entry {
        final int score;
        final String name;

        Entry(int score, String name) {
            this.score = score;
            this.name = name;
        }
    }

    private static List<Entry> load(SharedPreferences prefs) {
        List<Entry> out = new ArrayList<>();
        for (String line : prefs.getString("scores", "").split("\n")) {
            int tab = line.indexOf('\t');
            if (tab > 0) {
                try {
                    out.add(new Entry(Integer.parseInt(line.substring(0, tab)), line.substring(tab + 1)));
                } catch (NumberFormatException ignored) {
                    // skip a damaged line
                }
            }
        }
        out.sort((a, b) -> Integer.compare(b.score, a.score));
        return out;
    }

    private static void save(SharedPreferences prefs, List<Entry> scores) {
        StringBuilder sb = new StringBuilder();
        for (Entry e : scores) {
            sb.append(e.score).append('\t').append(e.name).append('\n');
        }
        prefs.edit().putString("scores", sb.toString()).apply();
    }

    private static SharedPreferences prefs(Context context) {
        return context.getSharedPreferences("lineup", Context.MODE_PRIVATE);
    }

    private static TextView label(Context context, String s) {
        TextView t = new TextView(context);
        t.setText(s);
        t.setPadding(0, dp(context, 12), 0, dp(context, 4));
        return t;
    }

    private static int dp(Context context, int v) {
        return Math.round(v * context.getResources().getDisplayMetrics().density);
    }
}
