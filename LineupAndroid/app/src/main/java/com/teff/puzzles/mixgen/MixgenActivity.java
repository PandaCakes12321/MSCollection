package com.teff.puzzles.mixgen;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;

/** Mixed Genetics (Microsoft Puzzle Collection, 1997). */
public class MixgenActivity extends BaseGameActivity {
    private MixgenGameView view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        view = new MixgenGameView(this);
        setContentView(view);
    }

    MixgenGameView gameView() {
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
