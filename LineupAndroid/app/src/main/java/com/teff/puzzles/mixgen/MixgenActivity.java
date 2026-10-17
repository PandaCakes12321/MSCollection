package com.teff.puzzles.mixgen;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;
import com.teff.puzzles.common.ComingSoon;

/** Mixed Genetics - not converted yet. */
public class MixgenActivity extends BaseGameActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ComingSoon.show(this, "Mixed Genetics");
    }
}