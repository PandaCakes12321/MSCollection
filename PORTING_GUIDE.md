# Puzzle Collection — porting guide (one game per worker)

Goal: rebuild one 1997 *Microsoft Puzzle Collection* game as a native Android screen inside the
existing app at `PuzzlePort/LineupAndroid` (one app, a game menu, each game its own Activity).
It is for the owner's kids' tablet only — personal use, never distributed.
Play it like the original: same rules, levels, scoring and art, controlled by touch.

## Your boundaries (several workers run at the same time)
- Write ONLY inside:
  - `LineupAndroid/app/src/main/java/com/teff/puzzles/<id>/` (your package; the Activity stub is already there)
  - `LineupAndroid/app/src/main/assets/<id>/` (your art/sound/data)
  - `PuzzlePort/<GAME>/` (your notes, scratch conversions)
- Read-only for you: `common/`, `lineup/`, `MenuActivity`, `AndroidManifest.xml`, Gradle files, other games.
  If you need a shared helper changed, copy what you need into your own package instead.
- Keep your Activity's class name and package (the menu and manifest already point at it).
- Java only, no extra libraries/dependencies, minSdk 24, compileSdk 37.
- Do NOT run Gradle / Android Studio builds, adb, or the emulator. The owner builds by hand.
- Python: always `python -I`. Never put scripts inside an `extracted/` or `original/` folder.

## What exists
- Decompiled game logic (Ghidra 12.1.2 pseudo-C): `PuzzlePort/<GAME>/decompiled/<GAME>_exe.c`
- Extracted resources: `PuzzlePort/<GAME>/extracted/shared/` (bitmaps as .bmp+.png, sounds .wav,
  music .mid, `sprite/`, `glevel/`, `sprfont/`, `anim/` as raw .bin) and `extracted/en/` (menus, dialogs).
  `extracted/dialog_text.txt` has every dialog's text — Quick Help = the rules.
  `extracted/overview.png` = contact sheet of the bitmaps.
- Original binaries (copies): `PuzzlePort/original/` (`<GAME>.EXE`, `Shared/<GAME>.DLL`, `EN/<GAME>1.DLL`, `.HLP`).
- Tools in `PuzzlePort/tools/`:
  - `fn.py <file.c> <regex | =FUN_name> [maxLines]` — print whole decompiled functions
  - `peek.py <pe> <hexVA> <len> [width]` — read bytes at a virtual address (tells you if it is runtime-built)
  - `list_resources.py [-v] <pe>`, `extract_resources.py <pe> <outdir>`, `contact_sheet.py <pngdir> <out.png>`
  - `sprite_to_png.py <sprite.bin|folder> <palette.bmp> <outdir> [--transparent N] [--flip]`
    Plain sprites (CHARMER, COLC, Fringer, JEWELCH, MIXGEN) = uint16 w, uint16 h, w*h 8-bit
    palette indices, top row first, no palette of their own — take the palette from the 8-bit BMP
    that is on screen with them (usually the 600x400 background; check the code that loads the
    sprite/palette). MUDDLE / RATPOKER / SWEEKEND sprites are a multi-frame compressed layout
    (start `01 00 <frameCount u16> ...`) — decode it from that game's sprite loader in the decompile.
  - Ghidra project: `PuzzlePort/ghidra_proj` (headless: `C:\Users\Teff\Desktop\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat`).
    Its launcher breaks on paths containing `(x86)`; use the copies in `original/`.
- Reference port: package `com.teff.puzzles.lineup` (fully working Lineup). Copy its patterns:
  - fixed logical layout (original-art pixels) scaled to fit the screen, letterboxed
    (`onSizeChanged` → scale/offset; touch → logical coords)
  - 100 ms (or the original's timer period) `Handler` loop calling `game.tick()`
  - rules engine in its own plain-Java class (no Android imports) so it can be unit-simulated
  - title / playing / paused / game-over states, Play/Pause, New (with confirm), Options, Scores
  - `Dialogs` for options + top-10 high scores in SharedPreferences named after your id
  - one-time tips from the original Tip dialogs
- Shared helpers in `com.teff.puzzles.common` (read-only, just use them):
  - `BaseGameActivity` — fullscreen, screen kept on; call `exitToMenu()` from your Exit button
  - `ControlPad` — on-screen arrow keys / SPACE / TAB with hold + multi-touch; draw it inside your
    scaled canvas, feed it touches; `isDown(code)` for held keys, or `Listener` callbacks
  - `GameAudio(context, "<id>")` — plays `assets/<id>/snd/NAME.wav` by name, loops `assets/<id>/mus/NAME.mid`

## Requirements for your game screen
1. A visible **Exit** button (returns to the menu via `exitToMenu()`), plus Play/Pause and New.
   The Android back gesture already returns to the menu; pause the game in `onPause`.
2. Keyboard games get on-screen controls via `ControlPad` (arrows / SPACE / TAB as the original used),
   big enough for a child's finger, placed so they don't cover the play area. Mouse games use direct taps
   (right-click → long-press or a toggle button, if the game needs it).
3. Use the original art, sounds and music, copied/converted into `assets/<id>/`
   (`img/*.png`, `snd/*.wav`, `mus/*.mid`, `data/` for level files). Asset names must stay ASCII.
4. Recover the real rules from the decompile (board sizes, timings, scoring, level data). Where
   something can't be recovered, choose something faithful to the help text and note it.
5. Write `PuzzlePort/<GAME>/NOTES.md`: rules recovered (with FUN_ addresses), file formats decoded,
   anything approximated.

## Verify before you finish (no Gradle)
Type-check the whole app against the Android SDK into your own scratch folder:
```
& "C:\Program Files\Android\Android Studio\jbr\bin\javac.exe" --release 17 -Xlint:all `
  -classpath "$env:LOCALAPPDATA\Android\Sdk\platforms\android-37.0\android.jar" `
  -d <your-scratch-dir> (all .java files under LineupAndroid/app/src/main/java)
```
It must compile with no errors (other workers' in-progress files may break it — if an error is
clearly in someone else's package, compile your package + `common` + `MenuActivity` only and say so).
Then compile your rules class with plain `javac` and run a headless simulation (many random games,
check invariants, no exceptions), like Lineup's was tested.

## Report back
Short summary: what is playable, controls, what was recovered vs approximated, anything that needs
the owner's eyes on a real device.
