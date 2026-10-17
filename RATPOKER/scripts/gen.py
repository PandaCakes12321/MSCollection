import struct, pefile
pe = pefile.PE('../../original/RATPOKER.EXE'); base = pe.OPTIONAL_HEADER.ImageBase
rd = lambda va,n: pe.get_data(va-base,n)
ints = lambda va,n: list(struct.unpack('<%di'%n, rd(va,4*n)))
o=[]
o.append("    /** Level table @0x414660, 24 ints per level (index 0 unused, copy of 1). */")
o.append("    static final int[][] LEVELS = {")
for L in range(21): o.append("            {" + ", ".join(map(str,ints(0x414660+L*0x60,24))) + "},")
o.append("    };")
o.append("    /** Hands @0x416380: length, score, pattern[length]. */")
o.append("    static final int[][] HANDS = {")
for h in range(10):
    v=ints(0x416380+h*0x30,12); o.append("            {" + ", ".join(map(str,v[:2+v[0]])) + "},")
o.append("    };")
o.append("    /** Arms @0x414e40: present[4], rotation limit (0 none, 1-3 swing, 4 = pinwheel). */")
o.append("    static final int[][] ARMS = {")
for L in range(21): o.append("            {" + ", ".join(map(str,ints(0x414e40+L*0x28,5))) + "},")
o.append("    };")
o.append("    /** Level maps @0x415318, 10 rows of 10 cells (row 0 = top). */")
o.append("    static final String[][] MAPS = {")
for L in range(21):
    rows=[rd(0x415318+L*200+r*20,10).decode('latin1') for r in range(10)]
    o.append("            {" + ", ".join('"%s"'%r for r in rows) + "},")
o.append("    };")
open('../conv/tables.java.txt','w').write("\n".join(o)+"\n")
