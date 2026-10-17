"""Print whole decompiled functions (from ExportDecompiled output) that match a regex,
or the function with a given name if the pattern starts with '='.

Usage: python -I fn.py <file.c> <regex | =FUN_name> [max-lines-per-function]
"""
import re
import sys


def main(path, pattern, limit=200):
    funcs, cur = [], []
    for line in open(path, encoding="utf-8", errors="replace"):
        if line.startswith("// ==== ") and cur:
            funcs.append(cur)
            cur = []
        cur.append(line.rstrip("\n"))
    if cur:
        funcs.append(cur)
    for body in funcs:
        if pattern.startswith("="):
            hit = body[0].startswith(f"// ==== {pattern[1:]} ")
        else:
            hit = any(re.search(pattern, l) for l in body)
        if hit:
            print("\n".join(l for l in body[:limit] if l.strip()))
            if len(body) > limit:
                print(f"... ({len(body) - limit} more lines)")
            print()


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2], int(sys.argv[3]) if len(sys.argv) > 3 else 200)
