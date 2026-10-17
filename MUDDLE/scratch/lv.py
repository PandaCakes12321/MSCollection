import sys, os, struct
d0=sys.argv[1]
ch={0:'.',9:'J',10:'O',11:'B',12:'D'}
for fn in sorted(os.listdir(d0)):
    d=open(os.path.join(d0,fn),'rb').read()
    order=[struct.unpack_from('<4i',d,0x80+16*i) for i in range(10)]
    hdr=d[:0x80].rstrip(b'\0')
    other=[i for i in range(0x10,0x80) if d[i]]
    print(fn, hdr, 'nonzero hdr bytes', other, 'order', [o[0] for o in order], [o[1:] for o in order if any(o[1:])][:3])
    for r in range(9,-1,-1):
        row=[struct.unpack_from('<4i',d,0x120+r*0xe0+c*16) for c in range(14)]
        print('  ', ''.join(ch.get(x[0],str(x[0])) for x in row), [x[1:] for x in row if any(x[2:])])
    print('  tail', [i for i in range(0x120+0x8c0,len(d)) if d[i]])
