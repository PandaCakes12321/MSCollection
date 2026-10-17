package com.teff.puzzles.muddle;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;

/** Muddled Casino (Microsoft Puzzle Collection, 1997). */
public class MuddleActivity extends BaseGameActivity {
    private MuddleGameView view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        view = new MuddleGameView(this);
        setContentView(view);
    }

    MuddleGameView gameView() {
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
