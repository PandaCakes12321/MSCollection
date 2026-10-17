# Decompile every game exe in original\ with Ghidra headless; one .c file per game.
$p = "D:\Downloads\AIWORKSPACE\PuzzlePort"
$ghidra = "C:\Users\Teff\Desktop\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat"
$games = "CHARMER", "COLC", "FFLUSH", "Fringer", "JEWELCH", "MIXGEN", "MUDDLE", "RATPOKER", "SWEEKEND", "Play"
foreach ($g in $games) {
    $out = "$p\$g\decompiled"
    New-Item -ItemType Directory -Force $out | Out-Null
    & $ghidra "$p\ghidra_proj" $g -import "$p\original\$g.EXE" -overwrite -scriptPath "$p\tools" -postScript ExportDecompiled.java "$out\${g}_exe.c" 2>&1 |
        Select-String -Pattern 'Exported|ERROR' | ForEach-Object { "${g}: $_" }
}
