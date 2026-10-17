"""Copy Mixed Genetics art/sound/music into the Android assets folder.
Bitmaps -> PNG (palette index 0 transparent, except full-screen backgrounds),
sprites -> raw .bin (kept as-is, decoded on device with palette.bin = GAMEBOX palette)."""
import os, shutil, struct, sys
from PIL import Image
src = sys.argv[1]; dst = sys.argv[2]
for d in ('img', 'spr', 'snd', 'mus', 'data'):
    os.makedirs(os.path.join(dst, d), exist_ok=True)
bm = os.path.join(src, 'bitmaps')
OPAQUE = {'GAMEBOX', 'TITLEBMP', 'ABOUTBMP', 'OPTIONSBMP', 'CUPBMP', 'QUICKHELPBMP'}
for f in os.listdir(bm):
    if not f.endswith('.bmp'):
        continue
    name = f[:-4]
    im = Image.open(os.path.join(bm, f))
    pal = im.getpalette()
    rgba = im.convert('RGBA')
    if name not in OPAQUE and im.mode == 'P':
        px = im.load(); out = rgba.load()
        for y in range(im.height):
            for x in range(im.width):
                if px[x, y] == 0:
                    out[x, y] = (0, 0, 0, 0)
    rgba.save(os.path.join(dst, 'img', name + '.png'), optimize=True)
# palette of GAMEBOX for the sprites
d = open(os.path.join(bm, 'GAMEBOX.bmp'), 'rb').read()
used = struct.unpack_from('<I', d, 46)[0] or 256
pal = bytearray()
for i in range(256):
    if i < used:
        b, g, r, _ = d[54 + i * 4:58 + i * 4]
    else:
        r = g = b = 0
    pal += bytes((r, g, b))
open(os.path.join(dst, 'data', 'palette.bin'), 'wb').write(pal)
for f in os.listdir(os.path.join(src, 'sprite')):
    shutil.copy(os.path.join(src, 'sprite', f), os.path.join(dst, 'spr', f))
for f in os.listdir(os.path.join(src, 'sounds')):
    shutil.copy(os.path.join(src, 'sounds', f), os.path.join(dst, 'snd', 'S' + f))
for f in os.listdir(os.path.join(src, 'music')):
    shutil.copy(os.path.join(src, 'music', f), os.path.join(dst, 'mus', f))
print('done')
