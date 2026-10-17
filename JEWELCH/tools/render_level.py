"""Render a level like the game does. python -I render_level.py <assets/jewelch> <level#> <out.png>"""
import struct, sys, os
from PIL import Image
a, lv, out = sys.argv[1], int(sys.argv[2]), sys.argv[3]
pal = open(os.path.join(a, 'data', 'palette.bin'), 'rb').read()
pat = open(os.path.join(a, 'data', 'pattern%d.bin' % (lv & 1)), 'rb').read()
t = open(os.path.join(a, 'data', 'tiles.bin'), 'rb').read(); tw = 144
d = open(os.path.join(a, 'data', 'LEVEL%03d.bin' % lv), 'rb').read()
g = struct.unpack('<150H', d[2:302])
buf = bytearray(pat)
for r in range(10):
    for c in range(15):
        w = g[r*15 + c]
        cols = [(w >> 2) & 7] * 4 if (w & 3) == 0 else [(w >> 2) & 7, (w >> 5) & 7, (w >> 8) & 7, (w >> 11) & 7]
        for q, col in enumerate(cols):
            row = 5 if col == 0 else col - 1
            for y in range(36):
                for x in range(36):
                    s = t[4 + (row*36 + y)*tw + q*36 + x]
                    if s:
                        i = (40 + r*36 + y)*540 + c*36 + x
                        buf[i] = (s + pat[i] - 23) & 255
img = Image.frombytes('P', (540, 400), bytes(buf)); img.putpalette(pal); img = img.convert('RGBA')
sheet = Image.open(os.path.join(a, 'img', 'sheet.png'))
TBL = [(155,268,18,26,9,5),(0,195,18,24,7,3),(0,220,22,23,5,5),(0,244,21,23,5,5),(174,268,25,20,5,8),(199,268,25,20,5,8),(224,268,25,20,5,8),(250,268,32,33,2,1),(111,268,21,36,7,0),(174,289,31,13,2,11),(283,268,22,27,4,4),(0,305,23,20,6,8),(24,305,19,19,8,8),(0,268,36,36,0,0),(37,268,36,36,0,0),(74,268,36,36,0,0),
 (101,32,26,32,5,2),(101,97,26,32,5,2),(101,162,26,32,5,2),(0,0,33,27,1,5),(0,65,33,27,1,5),(0,130,33,27,1,5),(0,28,25,36,5,0),(0,93,25,36,5,0),(0,159,25,36,5,0),(133,0,33,28,1,6),(133,65,33,28,1,6),(133,130,33,28,1,6)]
def put(typ, r, c):
    sx, sy, w, h, dx, dy = TBL[typ-1]
    img.alpha_composite(sheet.crop((sx, sy, sx+w, sy+h)), (c*36+dx, 40+r*36+dy))
t2 = d[302:]
n = t2[3]; p = 4
for i in range(n):
    pos = t2[p]; v = struct.unpack('<H', t2[p+1:p+3])[0]; put(v, pos >> 4, pos & 15); p += 4
n2 = t2[p]; p += 1
for i in range(n2):
    put(t2[p+1], t2[p] >> 4, t2[p] & 15); p += 2
put(17+1*3+1, t2[1] >> 4, t2[1] & 15)
put(17+3*3+0, t2[0] >> 4, t2[0] & 15)
img.save(out)
