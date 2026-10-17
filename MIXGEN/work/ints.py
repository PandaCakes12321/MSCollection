import sys, struct, pefile
pe = pefile.PE(sys.argv[1]); base=pe.OPTIONAL_HEADER.ImageBase
va=int(sys.argv[2],16); n=int(sys.argv[3],0); w=int(sys.argv[4]) if len(sys.argv)>4 else 8
d=pe.get_data(va-base, n*4)
v=struct.unpack('<%di'%n, d)
for i in range(0,n,w): print(hex(va+i*4), ' '.join('%6d'%x for x in v[i:i+w]))
