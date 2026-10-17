import sys, pefile, capstone
pe=pefile.PE(sys.argv[1]); va=int(sys.argv[2],16); n=int(sys.argv[3])
rva=va-pe.OPTIONAL_HEADER.ImageBase
d=pe.get_data(rva,n)
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
for i in md.disasm(d,va): print(f"{i.address:08x} {i.mnemonic} {i.op_str}")
