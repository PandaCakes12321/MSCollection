package com.teff.puzzles.lineup;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;

public class LineupActivity extends BaseGameActivity {
    private GameView view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        view = new GameView(this);
        setContentView(view);
    }

    GameView gameView() {
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
