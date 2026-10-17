package com.teff.puzzles.charmer;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;

/** Charmer (Microsoft Puzzle Collection, 1997). */
public class CharmerActivity extends BaseGameActivity {
    private CharmerGameView view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        view = new CharmerGameView(this);
        setContentView(view);
    }

    CharmerGameView gameView() {
        return view;
    }

    @Override
    protected void onResume() {
        super.onResume();
        view.onHostResume();
    }

    @Override
    protected void onPause() {
        view.onHostPause();
        super.onPause();
    }

    @Override
    protected void onDestroy() {
        view.release();
        super.onDestroy();
    }
}
