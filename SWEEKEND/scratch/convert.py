"""Convert Spring Weekend resources into assets/sweekend and print Java hotspot tables."""
import os, shutil, struct, sys
from PIL import Image
root = sys.argv[1]            # PuzzlePort/SWEEKEND
assets = sys.argv[2]          # .../assets/sweekend
ex = os.path.join(root, 'extracted', 'shared')
for sub in ('img', 'snd', 'mus', 'data'):
    os.makedirs(os.path.join(assets, sub), exist_ok=True)
for src, dst in (('BACKGROUND', 'background'), ('TITLEBMP', 'title'), ('GAMEOVERBMP', 'gameover')):
    Image.open(os.path.join(ex, 'bitmaps', src + '.bmp')).convert('RGB').save(os.path.join(assets, 'img', dst + '.png'))
for f in os.listdir(os.path.join(ex, 'sounds')):
    shutil.copy(os.path.join(ex, 'sounds', f), os.path.join(assets, 'snd', f))
for f in os.listdir(os.path.join(ex, 'music')):
    shutil.copy(os.path.join(ex, 'music', f), os.path.join(assets, 'mus', f))
for f in os.listdir(os.path.join(ex, 'glevel')):
    shutil.copy(os.path.join(ex, 'glevel', f), os.path.join(assets, 'data', f.lower()))
java = []
for fn in sorted(os.listdir(os.path.join(ex, 'sprite'))):
    d = open(os.path.join(ex, 'sprite', fn), 'rb').read()
    magic, n = struct.unpack_from('<HH', d, 0)
    assert magic == 1
    wh = [struct.unpack_from('<HH', d, 4 + i * 4) for i in range(n)]
    hs = [struct.unpack_from('<hh', d, 0x84 + i * 4) for i in range(n)]
    tr = d[0x104:0x104 + n]
    npal = struct.unpack_from('<H', d, 0x124)[0]
    off = 0x126
    pal = None
    for _ in range(npal):
        pal = [min(255, v * 255 // 63) for v in d[off:off + 0x300]]   # 6-bit VGA palette
        off += 0x300
    name = fn[:-4].lower()
    for i, (w, h) in enumerate(wh):
        px = d[off:off + w * h]
        off += w * h
        im = Image.frombytes('P', (w, h), px)
        im.putpalette(pal)
        rgba = im.convert('RGBA')
        rgba.putalpha(Image.frombytes('L', (w, h), bytes(0 if p == tr[i] else 255 for p in px)))
        rgba.save(os.path.join(assets, 'img', f'{name}_{i}.png'))
    assert off == len(d), fn
    java.append(f'    static final int[][] {name.upper()} = {{' + ', '.join(f'{{{x}, {y}}}' for x, y in hs) + '};')
print('\n'.join(java))
