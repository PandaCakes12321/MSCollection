package com.teff.puzzles.fringer;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;

/** Fringer (Microsoft Puzzle Collection, 1997). */
public class FringerActivity extends BaseGameActivity {
    private FringerGameView view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        view = new FringerGameView(this);
        setContentView(view);
    }

    FringerGameView gameView() {
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
