import sys, struct, pefile
pe = pefile.PE(sys.argv[1]); base=pe.OPTIONAL_HEADER.ImageBase
def ints(va,n): return struct.unpack('<%di'%n, pe.get_data(va-base,n*4))
print("extra table 4282b0:")
for e in range(5):
    v=ints(0x4282b0+e*0x144,0x51); c=v[0]
    print(e, c, [v[1+k*4:4+k*4] for k in range(min(c,20))], 'ptrs', [v[4+k*4] for k in range(min(c,20))])
for s in range(7):
  for p in range(6):
    v=ints(0x428680+s*0x798+p*0x144,0x51); c=v[0]
    print('sp',s,'part',p,c, [v[1+k*4:4+k*4] for k in range(min(c,20))], [v[4+k*4] for k in range(min(c,20))] if any(v[4+k*4] for k in range(min(c,20))) else '')
