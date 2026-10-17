import sys, struct, pefile
pe = pefile.PE(sys.argv[1])
va = int(sys.argv[2], 16); n = int(sys.argv[3]); w = int(sys.argv[4]) if len(sys.argv) > 4 else 8
d = pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, n * 4)
v = struct.unpack('<%di' % n, d)
for i in range(0, n, w):
    print('%08x: ' % (va + i * 4) + ' '.join('%6d' % x for x in v[i:i + w]))
