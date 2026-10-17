"""Extract bitmaps, sounds, music and strings from a Windows PE file into a folder.

Usage: python -I extract_resources.py <pe-file> <out-dir>
Bitmaps are saved as .bmp (and .png if Pillow is installed), WAVE as .wav,
MIDI as .mid, string tables as strings.txt, everything else as raw .bin.
"""
import os
import struct
import sys

import pefile

try:
    from PIL import Image
except ImportError:
    Image = None

RT_NAMES = {v: k for k, v in pefile.RESOURCE_TYPE.items()}
SKIP = {"RT_ICON", "RT_GROUP_ICON", "RT_VERSION"}


def type_label(entry):
    if entry.name is not None:
        return str(entry.name)
    return RT_NAMES.get(entry.id, str(entry.id))


def dib_to_bmp(dib):
    """RT_BITMAP data is a DIB without the 14-byte BITMAPFILEHEADER; add one."""
    hdr_size, = struct.unpack_from("<I", dib, 0)
    if hdr_size == 12:  # BITMAPCOREHEADER
        bpp, = struct.unpack_from("<H", dib, 10)
        colors = (1 << bpp) if bpp <= 8 else 0
        palette = colors * 3
    else:
        bpp, compression = struct.unpack_from("<HI", dib, 14)
        clr_used, = struct.unpack_from("<I", dib, 32)
        colors = clr_used or ((1 << bpp) if bpp <= 8 else 0)
        palette = colors * 4
        if compression == 3 and hdr_size == 40:  # BI_BITFIELDS masks
            palette += 12
    offset = 14 + hdr_size + palette
    return b"BM" + struct.pack("<IHHI", 14 + len(dib), 0, 0, offset) + dib


def string_table(block_id, data):
    out, pos = [], 0
    for i in range(16):
        n, = struct.unpack_from("<H", data, pos)
        pos += 2
        if n:
            out.append(((block_id - 1) * 16 + i, data[pos:pos + n * 2].decode("utf-16-le")))
        pos += n * 2
    return out


def main(path, out_dir):
    pe = pefile.PE(path, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_RESOURCE"]])
    os.makedirs(out_dir, exist_ok=True)
    strings, counts = [], {}
    for rtype in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        tname = type_label(rtype)
        if tname in SKIP:
            continue
        for rname in rtype.directory.entries:
            name = str(rname.name) if rname.name is not None else str(rname.id)
            for rlang in rname.directory.entries:
                d = rlang.data.struct
                data = pe.get_memory_mapped_image()[d.OffsetToData:d.OffsetToData + d.Size]
                counts[tname] = counts.get(tname, 0) + 1
                if tname == "RT_STRING":
                    strings += string_table(rname.id, data)
                    continue
                if tname == "RT_BITMAP":
                    sub, ext, data = "bitmaps", ".bmp", dib_to_bmp(data)
                elif tname == "WAVE":
                    sub, ext = "sounds", ".wav"
                elif tname == "MIDI":
                    sub, ext = "music", ".mid"
                else:
                    sub, ext = tname.lower(), ".bin"
                folder = os.path.join(out_dir, sub)
                os.makedirs(folder, exist_ok=True)
                target = os.path.join(folder, f"{name}{ext}")
                with open(target, "wb") as f:
                    f.write(data)
                if ext == ".bmp" and Image is not None:
                    try:
                        Image.open(target).save(target[:-4] + ".png")
                    except Exception as e:  # keep the .bmp even if PNG conversion fails
                        print(f"  png failed for {name}: {e}")
    if strings:
        with open(os.path.join(out_dir, "strings.txt"), "w", encoding="utf-8") as f:
            for sid, text in sorted(strings):
                f.write(f"{sid}\t{text}\n")
    print(out_dir, counts)


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
