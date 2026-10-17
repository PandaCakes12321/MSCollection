package com.teff.puzzles.muddle;

import android.os.Bundle;

import com.teff.puzzles.common.BaseGameActivity;
import com.teff.puzzles.common.ComingSoon;

/** Muddled Casino - not converted yet. */
public class MuddleActivity extends BaseGameActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ComingSoon.show(this, "Muddled Casino");
    }
}