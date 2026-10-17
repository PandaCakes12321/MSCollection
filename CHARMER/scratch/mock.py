import struct, sys
from PIL import Image
A = sys.argv[1] + '/img/'
G = {}
import pefile
pe = pefile.PE(sys.argv[2]); base = pe.OPTIONAL_HEADER.ImageBase
geom = struct.unpack('<544i', pe.get_data(0x428890 - base, 544 * 4))
def T(t, f, i): return geom[t * 136 + f * 17 + i]
shift = [(0, 0), (0, 0), (55, 5), (30, -1)]
bg = Image.open(A + 'PLAYBOX.png').convert('RGBA')
def im(n): return Image.open(A + n + '.png').convert('RGBA')
def blit(dst, src, sx, sy, w, h, dx, dy):
    if w <= 0 or h <= 0: return
    dst.alpha_composite(src.crop((sx, sy, sx + w, sy + h)), (dx, dy))
level_max = 9; vine = 366 - 25 * level_max
blit(bg, im('MARGIN'), 0, 0, 404, 51, 90, vine - 25)
box = im('BOXCOVER'); base1 = im('BOXCOVER1')
for col, (t, n, h, frame, st) in enumerate([(0, 3, 150, 0, 1), (1, 4, 120, 2, 1), (2, 3, 160, 3, 1), (3, 2, 40, 1, 2), (0, 5, 20, 4, 1)]):
    x = (col + 1) * 56 + 96
    for k in range(1, n + 1):
        y = 366 - 25 * k
        if k == 1: blit(bg, base1, 0, 0, 50, 25, x, y)
        else: blit(bg, box, t * 50, (k & 1) * 34 + 9, 50, 25, x, y)
    bottom = 366 - 25 * n
    sy = bottom - h
    o = 8 if st == 2 else 0
    seg = T(t, frame, 16)
    spr = im('SNAKE%d%d' % (t, 1))
    hh = h if h < seg else seg
    if h < seg: frame = 1
    xs = shift[t][1] if not (shift[t][0] < hh - 1) else 0
    blit(bg, spr, T(t, frame, o + 4), T(t, frame, o + 5), T(t, frame, o + 6), hh, x + T(t, frame, o + 7) + xs, sy)
    if h >= seg:
        blit(bg, spr, T(t, frame, o + 0), T(t, frame, o + 1), T(t, frame, o + 2), h - seg, x + T(t, frame, o + 3), sy + seg)
    blit(bg, box, t * 50, (1 & 1) * 34, 50, 9, x, sy - 9)
fl = im('FLUTES'); blit(bg, fl, 35, 0, 35, 29, 2 * 56 + 96 + 7, 370)
bg.save(sys.argv[3])
