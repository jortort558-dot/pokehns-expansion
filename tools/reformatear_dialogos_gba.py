#!/usr/bin/env python3
"""Reajusta bloques `.string` a cajas de texto GBA sin alterar el contenido."""

from __future__ import annotations

import argparse
import re
import textwrap
from pathlib import Path


STRING_BLOCK_RE = re.compile(
    r'(?m)^(?P<indent>[ \t]*)\.string ".*"(?:\n(?P=indent)\.string ".*")*\n?'
)
STRING_RE = re.compile(r'\.string "(.*)"')


def render_block(match: re.Match[str], width: int) -> str:
    indent = match.group("indent")
    encoded = "".join(STRING_RE.findall(match.group(0)))
    terminated = encoded.endswith("$")
    if terminated:
        encoded = encoded[:-1]
    paragraphs = encoded.split(r"\p")
    output: list[str] = []

    for paragraph_index, paragraph in enumerate(paragraphs):
        plain = re.sub(r"\\[nl]", " ", paragraph)
        plain = re.sub(r"[ \t]+", " ", plain).strip()
        lines = textwrap.wrap(
            plain,
            width=width,
            break_long_words=False,
            break_on_hyphens=False,
        ) or [""]
        for line_index, line in enumerate(lines):
            last_line = line_index == len(lines) - 1
            last_paragraph = paragraph_index == len(paragraphs) - 1
            if last_line:
                suffix = "$" if terminated and last_paragraph else (r"\p" if not last_paragraph else "")
            elif line_index == 0:
                suffix = r"\n"
            else:
                suffix = r"\l"
            output.append(f'{indent}.string "{line}{suffix}"')
    return "\n".join(output) + ("\n" if match.group(0).endswith("\n") else "")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("paths", nargs="+", type=Path)
    parser.add_argument("--width", type=int, default=32)
    args = parser.parse_args()

    files: list[Path] = []
    for path in args.paths:
        files.extend(path.rglob("scripts.inc") if path.is_dir() else [path])

    for path in sorted(set(files)):
        contents = path.read_text(encoding="utf-8")
        formatted = STRING_BLOCK_RE.sub(lambda match: render_block(match, args.width), contents)
        if formatted != contents:
            path.write_text(formatted, encoding="utf-8", newline="\n")
            print(path)


if __name__ == "__main__":
    main()
