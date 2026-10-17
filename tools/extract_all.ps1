# Extract resources + dialog/menu text for every game into <Game>\extracted\.
$p = "D:\Downloads\AIWORKSPACE\PuzzlePort"
$o = "$p\original"
$games = @{ CHARMER = "CHARMER1"; COLC = "COLC1"; FFLUSH = "FFLUSH1"; Fringer = "FRINGER1"; JEWELCH = "JEWELCH1";
            Lineup = "Lineup1"; MIXGEN = "MIXGEN1"; MUDDLE = "MUDDLE1"; RATPOKER = "RATPOKE1"; SWEEKEND = "SWEEKEN1" }
foreach ($g in $games.Keys) {
    $x = "$p\$g\extracted"
    python -I "$p\tools\extract_resources.py" "$o\Shared\$g.DLL" "$x\shared"
    python -I "$p\tools\extract_resources.py" "$o\EN\$($games[$g]).DLL" "$x\en"
    python -I "$p\tools\contact_sheet.py" "$x\shared\bitmaps" "$x\overview.png" | Out-Null
    # Dialog + menu text in one readable file
    $lines = foreach ($sub in "rt_dialog", "rt_menu") {
        Get-ChildItem "$x\en\$sub" -Filter *.bin -ErrorAction SilentlyContinue | ForEach-Object {
            $t = [Text.Encoding]::Unicode.GetString([IO.File]::ReadAllBytes($_.FullName))
            "== $sub\$($_.BaseName)"
            ([regex]::Matches($t, '[\x20-\x7e]{3,}') | ForEach-Object Value) -join ' | '
            ""
        }
    }
    $lines | Set-Content "$x\dialog_text.txt" -Encoding utf8
}
