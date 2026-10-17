"""Read bytes at a virtual address from a PE file and show which section holds it.

Usage: python -I peek.py <pe-file> <hex-va> <length> [grid-width]
With grid-width, the bytes are printed as rows of that width.
"""
import sys

import pefile


def main(path, va, length, width=0):
    pe = pefile.PE(path)
    rva = va - pe.OPTIONAL_HEADER.ImageBase
    for s in pe.sections:
        if s.VirtualAddress <= rva < s.VirtualAddress + s.Misc_VirtualSize:
            raw_end = s.VirtualAddress + s.SizeOfRawData
            name = s.Name.rstrip(b"\x00").decode()
            kind = "(initialised)" if rva < raw_end else "(zero-filled at load: built at runtime)"
            print(f"section {name} rva={rva:#x} {kind}")
    data = pe.get_data(rva, length)
    if width:
        for i in range(0, len(data), width):
            print(" ".join(f"{b:02x}" for b in data[i:i + width]))
    else:
        print(data.hex(" "))


if __name__ == "__main__":
    main(sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3]), int(sys.argv[4]) if len(sys.argv) > 4 else 0)
