"""List the resources inside a Windows PE file (exe/dll): type, name, language, size."""
import sys
from collections import Counter

import pefile

RT_NAMES = {v: k for k, v in pefile.RESOURCE_TYPE.items()}


def label(entry):
    if entry.name is not None:
        return str(entry.name)
    return RT_NAMES.get(entry.id, str(entry.id)) if entry.id in RT_NAMES else str(entry.id)


def main(path, verbose=False):
    pe = pefile.PE(path, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_RESOURCE"]])
    if not hasattr(pe, "DIRECTORY_ENTRY_RESOURCE"):
        print(f"{path}: no resources")
        return
    counts, sizes = Counter(), Counter()
    for rtype in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        tname = label(rtype)
        for rname in rtype.directory.entries:
            for rlang in rname.directory.entries:
                size = rlang.data.struct.Size
                counts[tname] += 1
                sizes[tname] += size
                if verbose:
                    nm = str(rname.name) if rname.name is not None else rname.id
                    print(f"  {tname:<16} {nm!s:<24} lang={rlang.id:<5} {size:>9}")
    print(f"{path}")
    for t in counts:
        print(f"  {t:<16} x{counts[t]:<4} {sizes[t]:>10} bytes")


if __name__ == "__main__":
    args = [a for a in sys.argv[1:] if a != "-v"]
    for p in args:
        main(p, verbose="-v" in sys.argv)
