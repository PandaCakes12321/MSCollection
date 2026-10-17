package com.teff.puzzles.fringer;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;
import com.teff.puzzles.common.ComingSoon;

/** Fringer - not converted yet. */
public class FringerActivity extends BaseGameActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ComingSoon.show(this, "Fringer");
    }
}