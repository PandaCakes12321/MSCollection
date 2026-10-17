package com.teff.puzzles.colc;

import android.os.Bundle;
import com.teff.puzzles.common.BaseGameActivity;

public class ColcActivity extends BaseGameActivity {
    private ColcGameView view;

    @Override protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        view = new ColcGameView(this);
        setContentView(view);
    }

    ColcGameView gameView() { return view; }

    @Override protected void onResume()  { super.onResume();  view.onHostResume(); }
    @Override protected void onPause()   { view.onHostPause(); super.onPause(); }
    @Override protected void onDestroy() { view.release();    super.onDestroy(); }
}
