package com.teff.puzzles.lineup;

/** Help text from the original Quick Help and Tip dialogs (Lineup1.DLL), reworded for touch. */
final class Tips {
    private Tips() {}

    static final String QUICK_HELP =
            "Fill a whole row or column with balls to clear it - any kinds of balls work.\n"
                    + "The bottom box of the piece line on the right is the piece you place. "
                    + "Tap where you want its white center ball to go.\n"
                    + "Don't let the piece line fill up to the top!";

    static String forKind(int kind) {
        switch (kind) {
            case Game.CLOCK:
                return "Surround the clock to stop the timer for a while, so no new pieces are added.";
            case Game.MEDAL:
                return "Surround the medal to completely clear the playing field.";
            case Game.SCORECARD:
                return "Surround the scorecard to earn points.";
            case Game.GARBAGE:
                return "The garbage can adds a dirt patch every time you clear a line. "
                        + "Surround it to remove it - one dirt patch disappears too.";
            case Game.GOLF:
                return "Surround the golf ball to get one bonus ball.";
            case Game.TIP_FIRST_BONUS:
                return "Bonus ball! Spend one to: turn the bottom piece (tap it), "
                        + "swap a piece to the bottom (tap it), or remove a piece from the field (tap it). "
                        + "3 bonus balls remove a dirt patch.";
            default:
                return "";
        }
    }
}
