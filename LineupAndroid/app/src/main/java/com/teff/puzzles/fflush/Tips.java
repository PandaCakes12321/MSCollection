package com.teff.puzzles.fflush;

/** Help text from the original Quick Help and Tip dialogs (FFLUSH1.DLL), reworded for touch. */
final class Tips {
    private Tips() {}

    static final String QUICK_HELP =
            "Fill each empty grid with balls of one color. Fill 3 grids to get a bonus point "
                    + "and move to the next level.\n\n"
                    + "Tap to the left or right of the upper or lower grid to move it. "
                    + "Then tap the highlighted column to drop it onto the lower grid.\n\n"
                    + "Tap one of the 4 small grids to switch to it. Tap the lower grid to turn it "
                    + "(hold your finger on it to turn it the other way).\n\n"
                    + "Dropping balls onto other balls costs one bonus point. "
                    + "Your game is over when the upper grid is full.";

    static String forKind(int kind) {
        switch (kind) {
            case Game.PALETTE:
                return "Drop the palette to change a ball to the color dominating the rest of the grid.";
            case Game.BOMB:
                return "Drop the blot onto a ball to remove it from the grid.";
            case Game.TIP_NO_BONUS:
                return "You have no bonus points, so balls can't be dropped onto other balls. "
                        + "A new column was added instead. Find empty spots, or turn the grid!";
            default:
                return "";
        }
    }
}
