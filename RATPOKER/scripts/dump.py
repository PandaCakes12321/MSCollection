import sys, struct, pefile
pe = pefile.PE(sys.argv[1]); base = pe.OPTIONAL_HEADER.ImageBase
def rd(va, n): return pe.get_data(va - base, n)
def ints(va, n): return list(struct.unpack('<%di' % n, rd(va, 4*n)))
print("LEVELS (24 ints)")
for L in range(21):
    print(L, ints(0x414660 + L*0x60, 24))
print("HANDS 0x416380 (12 ints)")
for h in range(10):
    print(h, ints(0x416380 + h*0x30, 12))
print("ARMS 0x414e40")
for L in range(21):
    print(L, ints(0x414e40 + L*0x28, 10))
print("MAPS")
for L in range(21):
    s = rd(0x415318 + L*200, 200)
    print("L", L, s[:200])
