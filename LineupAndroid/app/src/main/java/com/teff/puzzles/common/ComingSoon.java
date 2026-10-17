package com.teff.puzzles.common;

import android.app.Activity;
import android.graphics.Color;
import android.view.Gravity;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

/** Placeholder screen for a game that has not been converted yet. */
public final class ComingSoon {
    private ComingSoon() {}

    public static void show(BaseGameActivity activity, String title) {
        LinearLayout box = new LinearLayout(activity);
        box.setOrientation(LinearLayout.VERTICAL);
        box.setGravity(Gravity.CENTER);
        box.setBackgroundColor(0xFF163016);

        TextView label = new TextView(activity);
        label.setText(title + "\n\nComing soon!");
        label.setTextColor(Color.WHITE);
        label.setTextSize(28);
        label.setGravity(Gravity.CENTER);
        box.addView(label);

        Button exit = new Button(activity);
        exit.setText("Exit");
        exit.setOnClickListener(v -> activity.exitToMenu());
        box.addView(exit);

        ((Activity) activity).setContentView(box);
    }
}
