package com.teff.puzzles.colc;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;
import com.teff.puzzles.common.ComingSoon;

/** Color Collision - not converted yet. */
public class ColcActivity extends BaseGameActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ComingSoon.show(this, "Color Collision");
    }
}