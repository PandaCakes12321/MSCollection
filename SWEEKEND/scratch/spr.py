import struct,sys,os
from PIL import Image
src=sys.argv[1]; out=sys.argv[2]; bg=sys.argv[3]
os.makedirs(out,exist_ok=True)
bgpal=Image.open(bg).getpalette()[:768]
for fn in sorted(os.listdir(src)):
    d=open(os.path.join(src,fn),'rb').read()
    magic,n=struct.unpack_from('<HH',d,0)
    wh=[struct.unpack_from('<HH',d,4+i*4) for i in range(n)]
    hs=[struct.unpack_from('<hh',d,0x84+i*4) for i in range(n)]
    tr=list(d[0x104:0x104+n])
    npal=struct.unpack_from('<H',d,0x124)[0]
    off=0x126; pal=None
    for i in range(npal):
        pal=[min(255,v*255//63) for v in d[off:off+0x300]]; off+=0x300
    used=pal if pal else bgpal
    tot=off+sum(w*h for w,h in wh)
    print(fn,n,'npal',npal,'size',len(d),'expect',tot,wh[:3],hs[:3],tr[:3])
    name=fn[:-4]
    for i,(w,h) in enumerate(wh):
        px=d[off:off+w*h]; off+=w*h
        im=Image.frombytes('P',(w,h),px); im.putpalette(used)
        rgba=im.convert('RGBA')
        a=[(0 if p==tr[i] else 255) for p in px]
        al=Image.frombytes('L',(w,h),bytes(a)); rgba.putalpha(al)
        if '--flip' in sys.argv: rgba=rgba.transpose(Image.FLIP_TOP_BOTTOM)
        rgba.save(os.path.join(out,f'{name.lower()}_{i}.png'))
    print('  hot',hs)
