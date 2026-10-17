"""Tile every PNG in a folder into one labelled overview image.

Usage: python -I contact_sheet.py <png-folder> <out.png> [max-cell-px]
"""
import os
import sys

from PIL import Image, ImageDraw


def main(folder, out, cell=160):
    files = sorted((f for f in os.listdir(folder) if f.lower().endswith(".png")),
                   key=lambda f: (len(f), f))
    cols = 10
    rows = (len(files) + cols - 1) // cols
    sheet = Image.new("RGB", (cols * cell, rows * (cell + 14)), (60, 60, 60))
    draw = ImageDraw.Draw(sheet)
    for i, name in enumerate(files):
        im = Image.open(os.path.join(folder, name)).convert("RGB")
        w, h = im.size
        im.thumbnail((cell - 4, cell - 4))
        x, y = (i % cols) * cell, (i // cols) * (cell + 14)
        sheet.paste(im, (x + 2, y + 2))
        draw.text((x + 2, y + cell), f"{name[:-4]} {w}x{h}", fill=(255, 255, 0))
    sheet.save(out)
    print(out, len(files))


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2], int(sys.argv[3]) if len(sys.argv) > 3 else 160)
