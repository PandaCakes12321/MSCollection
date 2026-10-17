# Lineup port notes

Source: Microsoft Entertainment Pack: The Puzzle Collection (1997), game by Mir-Dialogue / Beachware.
Personal use only (kids' tablet) — do not distribute.

## Files
- `original\Lineup.EXE` (89 KB) — game logic, plain Win32 + GDI, MSVC runtime, 198 functions
- `original\Shared\Lineup.DLL` — art + audio → `extracted\shared\` (120 bitmaps as BMP+PNG, 8 WAV, 5 MIDI)
- `original\EN\Lineup1.DLL` — menus + dialogs → `extracted\en\`
- `decompiled\Lineup_exe.c` — Ghidra 12.1.2 pseudo-C of the whole exe
- `extracted\overview.png` — contact sheet of every bitmap

## Rules (from the game's own Quick Help / tip dialogs)
- Objective: connect opposite sides of the field with a vertical or horizontal line of balls.
  Ball types can be mixed. A completed line disappears.
- A "piece line" (queue) on the right; the bottom box is the piece you must place next.
- Place a piece by clicking where its white "center" ball should go.
- A timer keeps adding pieces to the queue; game over when the queue fills to the top.
- Special items on the field — "surround" them to trigger:
  - Golf ball → +1 bonus ball (no more until it is surrounded again)
  - Medal → clears the whole field
  - Garbage can → adds a dirt patch every time you clear a line; surround its figure to remove it (also removes one dirt patch)
  - Clock → pauses the timer temporarily
  - Scorecard → bonus points
- Bonus balls can be spent (1 each) to: rotate the bottom piece, move any queued piece to the bottom, or delete a piece from the field by clicking it.
- Options: difficulty Easy / Medium / Hard / Crazy, start level 1–10, music, sound effects, player name.
- High score table: top 10.

## Art cues
- Tiles are 27x27 (SQUARE_0..5 = ball types: basketball, tennis, football, volleyball, baseball?, soccer; SQUARE_E = empty grass).
- SMALLSQUARE_* 14x14 = queue previews. GARBAGE00-08, BONUSADD00-08, TIMEBONUS00-11, CLEARBONUS00-08, SCOREBONUS00-11 = animation frames for the specials.
- BREAK_E0-E3 = line-clear animation. DIGIT_0-9/E = score digits.
- Field frame: BORDER_H/V, ARROW_D/L; buttons PLAY/PAUSE/STEP/NEW (3 states each); banners TITLE, BREAK (Time Out), GAMEOVER.

## Exact rules recovered from the decompile (window class `PentomaniaWnd`)

### Board
- 14x14 playable cells (indices 1..14, ring 0/15 is unused border), 27 px each → 378x378 px.
- Cell `type`: 0 empty, 1 ball (part of a placed piece), 2 dirt patch (art BREAK_E0..3, random 0-3),
  3 clock, 4 medal, 5 scorecard, 6 garbage can, 7 golf ball (art loaded in that order: TimeBonus,
  ClearBonus, ScoreBonus, GARBAGE, BonusAdd).
- Each ball cell remembers its piece id (1..96) and the board position of that piece's center,
  so "remove piece" removes all 5 of its cells.

### Pieces (FUN_00402c90, base table at VA 0x4114B0)
- 12 base pentominoes, each a 7x7 grid, center (3,3) = the white "center" ball:
  T, V, F, X(+), W, P, Y, U, L, N, I, Z (base order 0..11, see `pieces.txt`).
- Expanded to 96 variants: id = base*8 + rotation*2 + mirrored + 1 (4 rotations x mirror).
- Ball look of a variant: `((id-1)&1) + ((id-1)>>3)*2) % 6` → SQUARE_0..5.
- Picker (FUN_00406770): weighted by base shape, then random rotation/mirror.
  Tier = difficulty, bumped to >=2 at level 3+, >=3 at level 6+, 4 at level 8+, 5 at level 10.
  Weights per base [T,V,F,X,W,P,Y,U,L,N,I,Z]:
  - tier 1: 8 8 1 8 1 2 1 2 8 1 8 2
  - tier 2: 8 8 2 8 2 4 2 4 8 2 8 4
  - tier 3: 2 2 1 2 1 2 1 2 2 1 2 2
  - tier 4: all 1
  - tier 5: 2 2 3 2 3 4 3 4 2 3 2 4

### Difficulty (1 Easy, 2 Medium, 3 Hard, 4 Crazy)
- Start with (difficulty - 1) bonus balls.
- Hard/Crazy (>2): each new board starts with one of 8 dirt layouts (FUN_00407179..FUN_00407955):
  corner triangles (manhattan <4 / <3 +center 2x2 / <2 + center), center blob, two blobs left/right,
  two blobs top/bottom, horizontal bar through middle rows 7-8 (cols 1-4 & 11-14), vertical equivalent.
- Medium/Crazy: one extra dirt patch per level number when a board is (re)built, and one more on
  each level-up.

### Timer / queue
- Win32 timer: 100 ms tick. A new piece is due every (108 - 10*level) ticks (level 1 = 9.8 s,
  level 10 = 0.8 s).
- Queue has 5 slots. If a new piece is due and all 5 are full: spend 1 bonus ball; with 0 bonus
  balls → GAME OVER.
- Clock pause counter: while > 0, each due piece decrements it instead of adding a piece.

### Placing (FUN_00408984)
- Tap = center cell. All 5 cells must be inside 1..14 and empty, else rejected.
- Tapping a dirt patch with >2 bonus balls: spend 3 bonus balls, dirt removed.
- Placement score: +level.

### Surround specials (checked after every placement)
- A special at (r,c) whose 8 neighbours are all balls triggers, then disappears:
  - clock: +10 to the pause counter
  - medal: board wiped and rebuilt (layout/dirt rules above), stop processing
  - scorecard: +100*level
  - garbage: removes one random dirt patch
  - golf ball: +1 bonus ball (max 12)
- Spawning (FUN_00409942, once per due-piece tick, level >= 2): chance 1/(level+1) when no specials,
  else 1/(10*specialCount). Type random 3..7; needs specialCount < 5-difficulty (medal ignores this).
  Unlock levels: golf 3+, scorecard 4+, clock 5+, garbage 6+, medal any.
  Needs an empty 3x3 area with center in 2..13.
- Lifetimes per tick: clock & scorecard count down from 12 then vanish; medal lasts 13 ticks.

### Line clears
- A full row (all 14 cells type 1) or full column counts as a line.
- Every whole piece with any cell in a completed line is removed (dirt stays).
  Each removed piece scores (difficulty+2)*level.
- A line made entirely of one ball look → +1 bonus ball.
- Lines = rows + cols, +1 extra if both rows and cols were cleared. If lines > 1, that many bonus balls.
- For each garbage can on the board, add a dirt patch per clear.
- Clear counter +1 per clearing move; level up when counter > 10*level (new speed, +dirt on Medium/Crazy).
- If the board has no pieces left after a clear (and no golf ball present): +1 bonus ball and
  +(difficulty+2)*level*10 points.

### Bonus balls (max 12)
- Spend 1: delete a placed piece (tap it), rotate the bottom queue piece, or move a queued piece to
  the bottom. Spend 3: remove a dirt patch.
