package com.teff.puzzles.charmer;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;
import com.teff.puzzles.common.ComingSoon;

/** Charmer - not converted yet. */
public class CharmerActivity extends BaseGameActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ComingSoon.show(this, "Charmer");
    }
}