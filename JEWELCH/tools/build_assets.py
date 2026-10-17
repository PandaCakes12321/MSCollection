"""Build assets/jewelch from JEWELCH/extracted. Usage: python -I build_assets.py <JEWELCH dir> <assets/jewelch dir>"""
import os, shutil, struct, sys
from PIL import Image
src, dst = sys.argv[1], sys.argv[2]
ex = os.path.join(src, 'extracted', 'shared')
for sub in ('img', 'snd', 'mus', 'data'):
    os.makedirs(os.path.join(dst, sub), exist_ok=True)

def bmp(path):
    d = open(path, 'rb').read()
    off, = struct.unpack_from('<I', d, 10)
    w, h = struct.unpack_from('<ii', d, 18)
    pal = [tuple(d[54 + i*4:57 + i*4][::-1]) for i in range(256)]
    stride = (w + 3) & ~3
    rows = [d[off + y*stride: off + y*stride + w] for y in range(h)]
    rows.reverse()  # top first
    return w, h, pal, b''.join(rows)

w, h, pal, _ = bmp(os.path.join(ex, 'bitmaps', 'PATTERN000.bmp'))
open(os.path.join(dst, 'data', 'palette.bin'), 'wb').write(bytes(c for p in pal for c in p))
for i in (0, 1):
    w, h, _, px = bmp(os.path.join(ex, 'bitmaps', 'PATTERN%03d.bmp' % i))
    open(os.path.join(dst, 'data', 'pattern%d.bin' % i), 'wb').write(px)
shutil.copy(os.path.join(ex, 'sprite', '1000.bin'), os.path.join(dst, 'data', 'tiles.bin'))
# object/thief sheet: index 0 transparent
d = open(os.path.join(ex, 'sprite', '1001.bin'), 'rb').read()
sw, sh = struct.unpack_from('<HH', d, 0)
img = Image.new('RGBA', (sw, sh))
img.putdata([(*pal[i], 0 if i == 0 else 255) for i in d[4:4 + sw*sh]])
img.save(os.path.join(dst, 'img', 'sheet.png'))
for n in ['LEVSCORE', 'TITLEBMP', 'PAUSEBMP', 'GAMEOVERBMP', 'CUPBMP'] + ['DIGIT%d' % i for i in range(10)]:
    shutil.copy(os.path.join(ex, 'bitmaps', n + '.png'), os.path.join(dst, 'img', n + '.png'))
for f in os.listdir(os.path.join(ex, 'glevel')):
    shutil.copy(os.path.join(ex, 'glevel', f), os.path.join(dst, 'data', f))
for f in os.listdir(os.path.join(ex, 'sounds')):
    shutil.copy(os.path.join(ex, 'sounds', f), os.path.join(dst, 'snd', 'S' + f))
for f in os.listdir(os.path.join(ex, 'music')):
    shutil.copy(os.path.join(ex, 'music', f), os.path.join(dst, 'mus', f))
print('ok')
