import struct,sys,glob,os,collections
d0=sys.argv[1]
items=collections.Counter(); it2=collections.Counter(); tiles=collections.Counter()
for f in sorted(glob.glob(os.path.join(d0,'*.bin'))):
    d=open(f,'rb').read()
    assert d[:2]==b'PL'
    g=struct.unpack('<150H',d[2:302])
    t=d[302:]
    for w in g: tiles[(w&3, (w>>2)&7,(w>>5)&7,(w>>8)&7,(w>>11)&7) if w&3 else (0,(w>>2)&7)]+=1
    n=t[3]; p=4
    ent=[]
    for i in range(n):
        pos=t[p]; v=struct.unpack('<H',t[p+1:p+3])[0]; ent.append((pos>>4,pos&15,v)); items[v]+=1; p+=4
    n2=t[p]; p+=1; e2=[]
    for i in range(n2):
        e2.append((t[p]>>4,t[p]&15,t[p+1])); it2[t[p+1]]+=1; p+=2
    rest=len(t)-p
    if f.endswith('001.bin') or f.endswith('002.bin') or rest: print(os.path.basename(f),'thieves',hex(t[0]),hex(t[1]),hex(t[2]),'items',ent,'it2',e2,'rest',rest)
print('items',sorted(items.items()));print('it2',sorted(it2.items()));print('tiles',sorted(tiles.items()))
