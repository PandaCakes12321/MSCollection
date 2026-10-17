"""Convert Puzzle Collection plain SPRITE resources to PNG.

Plain sprite layout (CHARMER, COLC, Fringer, JEWELCH, MIXGEN):
    uint16 width, uint16 height, then width*height palette indices, top row first.
Sprites carry no palette: colours come from an 8-bit BMP of the same game (usually the
full-screen background that is on screen when the sprite is drawn).

MUDDLE, RATPOKER and SWEEKEND use a different, multi-frame compressed layout
(starts with uint16 1, uint16 frameCount) that this tool does not handle.

Usage:
    python -I sprite_to_png.py <sprite.bin | folder> <palette.bmp> <out-folder> [--transparent N] [--flip]
--transparent N  palette index drawn as fully transparent (repeatable)
--flip           rows are stored bottom-up (use if output comes out upside down)
"""
import os
import struct
import sys

from PIL import Image


def read_palette(bmp_path):
    d = open(bmp_path, "rb").read()
    header_size, = struct.unpack_from("<I", d, 14)
    bpp, = struct.unpack_from("<H", d, 28)
    if header_size != 40 or bpp != 8:
        raise ValueError(f"{bmp_path}: need an 8-bit BMP with a 40-byte header")
    used, = struct.unpack_from("<I", d, 46)
    used = used or 256
    pal = []
    for i in range(256):
        if i < used:
            b, g, r, _ = d[54 + i * 4:58 + i * 4]
            pal.append((r, g, b))
        else:
            pal.append((255, 0, 255))
    return pal


def is_plain_sprite(data):
    if len(data) < 4:
        return False
    w, h = struct.unpack_from("<HH", data, 0)
    return w > 0 and h > 0 and len(data) == 4 + w * h


def convert(path, palette, out_dir, transparent, flip):
    data = open(path, "rb").read()
    if not is_plain_sprite(data):
        return False
    w, h = struct.unpack_from("<HH", data, 0)
    img = Image.new("RGBA", (w, h))
    px = img.load()
    for y in range(h):
        row = data[4 + y * w:4 + (y + 1) * w]
        ty = h - 1 - y if flip else y
        for x, idx in enumerate(row):
            r, g, b = palette[idx]
            px[x, ty] = (r, g, b, 0 if idx in transparent else 255)
    name = os.path.splitext(os.path.basename(path))[0]
    img.save(os.path.join(out_dir, name + ".png"))
    return True


def main(argv):
    args = [a for a in argv if not a.startswith("--")]
    transparent = {int(argv[i + 1]) for i, a in enumerate(argv) if a == "--transparent"}
    args = [a for a in args if not (a.isdigit() and str(a) in {str(t) for t in transparent})]
    flip = "--flip" in argv
    src, pal_path, out_dir = args[0], args[1], args[2]
    palette = read_palette(pal_path)
    os.makedirs(out_dir, exist_ok=True)
    files = [os.path.join(src, f) for f in sorted(os.listdir(src))] if os.path.isdir(src) else [src]
    done = skipped = 0
    for f in files:
        if f.lower().endswith(".bin"):
            if convert(f, palette, out_dir, transparent, flip):
                done += 1
            else:
                skipped += 1
    print(f"{done} converted, {skipped} skipped (not plain sprites) -> {out_dir}")


if __name__ == "__main__":
    main(sys.argv[1:])
