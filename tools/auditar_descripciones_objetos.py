#!/usr/bin/env python3
"""Comprueba que las descripciones de objetos caben en el original inglés.

Por defecto compara ``src/data/items.h`` con el mismo archivo de
``upstream/master``. También admite un archivo inglés explícito para poder
trabajar sin esa referencia de Git.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path


ITEM_START_RE = re.compile(r"(?m)^\s*\[(ITEM_[A-Z0-9_]+)\]\s*=\s*\{")
SHARED_DESC_RE = re.compile(
    r"static\s+const\s+u8\s+(\w+Desc)\[\]\s*=\s*_\((.*?)\);", re.DOTALL
)
STRING_RE = re.compile(r'"((?:\\.|[^"\\])*)"')


@dataclass(frozen=True)
class Description:
    item: str
    lines: tuple[str, ...]
    source_line: int


def decode_c_strings(expression: str) -> str:
    parts: list[str] = []
    for match in STRING_RE.finditer(expression):
        value = match.group(1)
        value = value.replace(r"\n", "\n")
        value = value.replace(r"\l", "\n")
        value = value.replace(r"\p", "\n")
        value = value.replace(r'\"', '"').replace(r"\\", "\\")
        parts.append(value)
    return "".join(parts)


def extract_parenthesized(text: str, open_pos: int) -> str | None:
    depth = 0
    in_string = False
    escaped = False
    for pos in range(open_pos, len(text)):
        char = text[pos]
        if in_string:
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == '"':
                in_string = False
            continue
        if char == '"':
            in_string = True
        elif char == "(":
            depth += 1
        elif char == ")":
            depth -= 1
            if depth == 0:
                return text[open_pos + 1 : pos]
    return None


def parse_descriptions(text: str) -> dict[str, Description]:
    shared = {
        match.group(1): decode_c_strings(match.group(2))
        for match in SHARED_DESC_RE.finditer(text)
    }
    starts = list(ITEM_START_RE.finditer(text))
    descriptions: dict[str, Description] = {}

    for index, match in enumerate(starts):
        item = match.group(1)
        end = starts[index + 1].start() if index + 1 < len(starts) else len(text)
        block = text[match.end() : end]
        desc_match = re.search(r"\.description\s*=\s*", block)
        if desc_match is None:
            continue

        value_start = desc_match.end()
        remainder = block[value_start:]
        compound = re.match(r"COMPOUND_STRING\s*\(", remainder)
        if compound:
            open_pos = value_start + compound.end() - 1
            expression = extract_parenthesized(block, open_pos)
            if expression is None:
                continue
            value = decode_c_strings(expression)
        else:
            reference = re.match(r"(\w+)", remainder)
            if reference is None or reference.group(1) not in shared:
                continue
            value = shared[reference.group(1)]

        source_line = text.count("\n", 0, match.start()) + 1
        descriptions[item] = Description(item, tuple(value.split("\n")), source_line)

    return descriptions


def read_git_reference(repo: Path, git_ref: str, relative_path: str) -> str:
    result = subprocess.run(
        ["git", "show", f"{git_ref}:{relative_path}"],
        cwd=repo,
        check=False,
        capture_output=True,
    )
    if result.returncode != 0:
        message = result.stderr.decode("utf-8", errors="replace").strip()
        raise RuntimeError(f"No se pudo leer {git_ref}:{relative_path}: {message}")
    return result.stdout.decode("utf-8")


def audit(current: dict[str, Description], reference: dict[str, Description]) -> list[str]:
    issues: list[str] = []
    for item, description in current.items():
        original = reference.get(item)
        if original is None:
            issues.append(f"{item} (línea {description.source_line}): sin referencia inglesa")
            continue
        if len(description.lines) > len(original.lines):
            issues.append(
                f"{item} (línea {description.source_line}): usa {len(description.lines)} líneas; "
                f"el inglés usa {len(original.lines)}"
            )
        for index, line in enumerate(description.lines[: len(original.lines)]):
            allowed = len(original.lines[index])
            if len(line) > allowed:
                issues.append(
                    f"{item} (línea {description.source_line}, texto {index + 1}): "
                    f"{len(line)} caracteres; máximo inglés {allowed} — {line!r}"
                )
    return issues


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--items", default="src/data/items.h", help="archivo traducido")
    parser.add_argument("--reference-ref", default="upstream/master", help="referencia Git inglesa")
    parser.add_argument("--reference-file", help="archivo inglés; sustituye a --reference-ref")
    args = parser.parse_args()

    repo = Path(__file__).resolve().parents[1]
    items_path = (repo / args.items).resolve()
    current_text = items_path.read_text(encoding="utf-8")
    relative_path = items_path.relative_to(repo).as_posix()

    try:
        if args.reference_file:
            reference_text = Path(args.reference_file).resolve().read_text(encoding="utf-8")
        else:
            reference_text = read_git_reference(repo, args.reference_ref, relative_path)
    except (OSError, RuntimeError, ValueError) as error:
        print(f"ERROR: {error}", file=sys.stderr)
        return 2

    current = parse_descriptions(current_text)
    reference = parse_descriptions(reference_text)
    issues = audit(current, reference)

    print(f"Descripciones analizadas: {len(current)}; referencia inglesa: {len(reference)}")
    if issues:
        print(f"Incidencias: {len(issues)}")
        for issue in issues:
            print(f"- {issue}")
        return 1

    print("OK: todas respetan las líneas y caracteres del original inglés.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
