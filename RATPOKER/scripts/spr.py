import sys, os, struct
from PIL import Image
src, out = sys.argv[1], sys.argv[2]
os.makedirs(out, exist_ok=True)
idx = []
for fn in sorted(os.listdir(src)):
    if not fn.endswith('.bin'): continue
    name = fn[:-4]
    d = open(os.path.join(src, fn), 'rb').read()
    ver, cnt = struct.unpack_from('<HH', d, 0)
    assert ver == 1, fn
    dims = [struct.unpack_from('<HH', d, 4 + 4*i) for i in range(cnt)]
    hots = [struct.unpack_from("<hh", d, 0x84 + 4*i) for i in range(cnt)]
    trans = [d[0x104 + i] for i in range(cnt)]
    npal = struct.unpack_from('<H', d, 0x124)[0]
    p = 0x126
    pal = d[p:p+768]; p += 768*npal
    frames = []
    for i,(w,h) in enumerate(dims):
        px = d[p:p+w*h]; p += w*h
        im = Image.new('RGBA', (w, h))
        im.putdata([(0,0,0,0) if b == trans[i] else (min(255,pal[b*3]*255//63), min(255,pal[b*3+1]*255//63), min(255,pal[b*3+2]*255//63), 255) for b in px])
        frames.append(im)
    W = sum(w for w,h in dims); H = max(h for w,h in dims)
    sheet = Image.new('RGBA', (W, H)); x = 0
    for i, im in enumerate(frames):
        sheet.paste(im, (x, 0))
        idx.append(f"{name} {i} {x} {dims[i][0]} {dims[i][1]} {hots[i][0]} {hots[i][1]}")
        x += dims[i][0]
    sheet.save(os.path.join(out, name + '.png'))
    print(name, cnt, dims[:3], hots[:3], trans[:3], 'left', len(d)-p)
open(os.path.join(out, 'sprites.txt'), 'w').write("\n".join(idx) + "\n")
