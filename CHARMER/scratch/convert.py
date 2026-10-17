"""Convert Charmer resources into the Android assets folder."""
import os, struct, shutil, sys
from PIL import Image

SRC = sys.argv[1]   # PuzzlePort/CHARMER/extracted/shared
DST = sys.argv[2]   # LineupAndroid/app/src/main/assets/charmer

def pal(bmp):
    d = open(bmp, 'rb').read()
    n = struct.unpack_from('<I', d, 46)[0] or 256
    p = [(255, 0, 255)] * 256
    for i in range(n):
        b, g, r = d[54 + i * 4:57 + i * 4]
        p[i] = (r, g, b)
    return p

play = pal(os.path.join(SRC, 'bitmaps', 'PLAYBOX.bmp'))
start = pal(os.path.join(SRC, 'bitmaps', 'STARTBMP.bmp'))
img = os.path.join(DST, 'img'); os.makedirs(img, exist_ok=True)

def save_indexed(w, h, px, p, out):
    im = Image.new('RGBA', (w, h))
    im.putdata([(0, 0, 0, 0) if c == 0 else p[c] + (255,) for c in px])
    im.save(out)

for f in sorted(os.listdir(os.path.join(SRC, 'sprite'))):
    d = open(os.path.join(SRC, 'sprite', f), 'rb').read()
    w, h = struct.unpack_from('<HH', d, 0)
    name = f[:-4].upper()
    p = start if name.startswith('ZAS') or name == 'SNAKEBAS' else play
    save_indexed(w, h, d[4:4 + w * h], p, os.path.join(img, name + '.png'))

# 8-bit BMPs: full-screen ones opaque, LEVELnn drawn with colour key 0
for f in sorted(os.listdir(os.path.join(SRC, 'bitmaps'))):
    if not f.endswith('.bmp'):
        continue
    name = f[:-4].upper()
    if name.startswith('LEVEL'):
        im = Image.open(os.path.join(SRC, 'bitmaps', f))
        p = pal(os.path.join(SRC, 'bitmaps', f))
        save_indexed(im.width, im.height, list(im.getdata()), p, os.path.join(img, name + '.png'))
    elif name in ('PLAYBOX', 'STARTBMP', 'PAUSEBMP', 'GAMEOVERBMP'):
        Image.open(os.path.join(SRC, 'bitmaps', f)).convert('RGB').save(os.path.join(img, name + '.png'))

# SPRFONT 1000: 256 glyphs, each uint16 w,h + w*h indices; keep the digits
d = open(os.path.join(SRC, 'sprfont', '1000.bin'), 'rb').read()
o = 0
for code in range(256):
    w, h = struct.unpack_from('<HH', d, o)
    if 48 <= code <= 57:
        save_indexed(w, h, d[o + 4:o + 4 + w * h], play, os.path.join(img, 'DIGIT_%c.png' % code))
    o += 4 + w * h

for sub, ext in (('sounds', '.wav'), ('music', '.mid')):
    out = os.path.join(DST, 'snd' if sub == 'sounds' else 'mus'); os.makedirs(out, exist_ok=True)
    for f in os.listdir(os.path.join(SRC, sub)):
        if f.endswith(ext):
            n = f[:-4].upper()
            if n.endswith('WAV'):
                n = n[:-3]
            shutil.copy(os.path.join(SRC, sub, f), os.path.join(out, n + ext))
print('done')
