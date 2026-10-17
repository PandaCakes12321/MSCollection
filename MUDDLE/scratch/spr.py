import sys, os, struct, json
from PIL import Image
src, out = sys.argv[1], sys.argv[2]
os.makedirs(out, exist_ok=True)
meta = {}
for fn in sorted(os.listdir(src)):
    d = open(os.path.join(src, fn), 'rb').read()
    name = fn[:-4]
    ver, n = struct.unpack_from('<HH', d, 0)
    wh = [struct.unpack_from('<hh', d, 4 + 4*i) for i in range(n)]
    hs = [struct.unpack_from('<hh', d, 0x84 + 4*i) for i in range(n)]
    tr = list(d[0x104:0x104+n])
    npal = struct.unpack_from('<H', d, 0x124)[0]
    p = 0x126
    pal = None
    for i in range(npal):
        pal = d[p:p+768]; p += 768
    frames = []
    for i in range(n):
        w, h = wh[i]
        px = d[p:p+w*h]; p += w*h
        im = Image.new('RGBA', (w, h))
        im.putdata([(0,0,0,0) if c == tr[i] else (pal[c*3]*255//63, pal[c*3+1]*255//63, pal[c*3+2]*255//63, 255) for c in px])
        frames.append(im)
    # strip: all frames side by side in cells of max w/h
    mw = max(w for w, h in wh); mh = max(h for w, h in wh)
    strip = Image.new('RGBA', (mw*n, mh))
    for i, im in enumerate(frames):
        strip.paste(im, (i*mw, 0))
    strip.save(os.path.join(out, name.lower() + '.png'))
    meta[name] = dict(n=n, cell=[mw, mh], wh=wh, hot=hs, trans=tr, npal=npal, left=len(d)-p)
    print(name, n, wh[:3], hs[:3], tr[:3], 'npal', npal, 'leftover', len(d)-p)
json.dump(meta, open(os.path.join(out, 'sprites.json'), 'w'), indent=1)
