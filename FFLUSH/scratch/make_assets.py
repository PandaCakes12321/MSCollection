import os, shutil, sys
from PIL import Image
root = sys.argv[1]           # PuzzlePort/FFLUSH
out = sys.argv[2]            # assets/fflush
bm = os.path.join(root, 'extracted', 'shared', 'bitmaps')
os.makedirs(os.path.join(out, 'img'), exist_ok=True)
os.makedirs(os.path.join(out, 'snd'), exist_ok=True)
os.makedirs(os.path.join(out, 'mus'), exist_ok=True)

def conv(src, dst, key=None):
    im = Image.open(os.path.join(bm, src + '.bmp')).convert('RGBA')
    if key is not None:
        px = im.load()
        for y in range(im.height):
            for x in range(im.width):
                r, g, b, a = px[x, y]
                if (r, g, b) == key:
                    px[x, y] = (0, 0, 0, 0)
    im.save(os.path.join(out, 'img', dst + '.png'))

conv('200', 'BACK')
for i in (101, 102, 103, 104):
    conv(str(i), 'LEVEL%d' % (i - 100))
conv('203', 'SHEET', key=(255, 2, 255))
for n in ('LIGHTED', 'DIGITS', 'BREAKBMP', 'BREAKBMP1', 'BREAKBMP2', 'GAMEOVERBMP', 'BOMBBMP', 'PBRUSHBMP'):
    conv(n, n)
for f in os.listdir(os.path.join(root, 'extracted', 'shared', 'sounds')):
    shutil.copy(os.path.join(root, 'extracted', 'shared', 'sounds', f), os.path.join(out, 'snd', f))
for f in os.listdir(os.path.join(root, 'extracted', 'shared', 'music')):
    shutil.copy(os.path.join(root, 'extracted', 'shared', 'music', f), os.path.join(out, 'mus', f))
print(sorted(os.listdir(os.path.join(out, 'img'))))
