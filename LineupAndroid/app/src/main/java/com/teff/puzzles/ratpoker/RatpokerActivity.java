package com.teff.puzzles.ratpoker;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;

/** Rat Poker (Microsoft Puzzle Collection, 1997). */
public class RatpokerActivity extends BaseGameActivity {
    private GameView view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        view = new GameView(this);
        setContentView(view);
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
