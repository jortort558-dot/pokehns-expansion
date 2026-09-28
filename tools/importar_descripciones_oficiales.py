#!/usr/bin/env python3
"""Importa el texto oficial español más reciente disponible para cada objeto."""

import argparse
import csv
import json
import re
import subprocess
from pathlib import Path

from auditar_descripciones_objetos import parse_descriptions

REPO = Path(__file__).resolve().parents[1]

ALIASES = {
    "ITEM_PARLYZ_HEAL": "paralyze-heal",
    "ITEM_UPGRADE": "up-grade",
    "ITEM_HEALTH_FEATHER": "health-wing",
    "ITEM_MUSCLE_FEATHER": "muscle-wing",
    "ITEM_RESIST_FEATHER": "resist-wing",
    "ITEM_GENIUS_FEATHER": "genius-wing",
    "ITEM_CLEVER_FEATHER": "clever-wing",
    "ITEM_SWIFT_FEATHER": "swift-wing",
    "ITEM_PRETTY_FEATHER": "pretty-wing",
    "ITEM_GB_PLAYER": "gb-sounds",
    "ITEM_POKE_VIAL": None,
}


def item_slug(item: str) -> str | None:
    if item in ALIASES:
        return ALIASES[item]
    return item.removeprefix("ITEM_").lower().replace("_", "-")


def normalize(text: str) -> str:
    return " ".join(text.replace("\f", " ").replace("\n", " ").split())


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--items-csv", required=True)
    parser.add_argument("--flavor-csv", required=True)
    parser.add_argument("--moves-csv")
    parser.add_argument("--move-flavor-csv")
    parser.add_argument("--anil-json")
    parser.add_argument("--fallback-json")
    parser.add_argument("--output", default="tools/item_descriptions_official_es.json")
    args = parser.parse_args()

    with open(args.items_csv, encoding="utf-8-sig", newline="") as file:
        ids = {row["identifier"]: row["id"] for row in csv.DictReader(file)}

    flavors: dict[str, dict[int, dict[str, str]]] = {}
    with open(args.flavor_csv, encoding="utf-8-sig", newline="") as file:
        for row in csv.DictReader(file):
            if row["language_id"] not in {"7", "9"}:
                continue
            item_id = row["item_id"]
            version = int(row["version_group_id"])
            language = "es" if row["language_id"] == "7" else "en"
            flavors.setdefault(item_id, {}).setdefault(version, {})[language] = normalize(row["flavor_text"])

    current = parse_descriptions((REPO / "src/data/items.h").read_text(encoding="utf-8"))
    upstream = subprocess.run(
        ["git", "show", "upstream/master:src/data/items.h"], cwd=REPO, check=True, capture_output=True
    ).stdout.decode("utf-8")
    english = parse_descriptions(upstream)
    official = {}
    provenance = {}
    missing = []
    for item in current:
        slug = item_slug(item)
        source_id = ids.get(slug) if slug else None
        if source_id is None and slug and slug.endswith("ium-z"):
            source_id = ids.get(slug + "--held")
        candidates = [
            (version, texts)
            for version, texts in flavors.get(source_id, {}).items()
            if "es" in texts
        ]
        if not candidates:
            missing.append({
                "item": item,
                "slug": slug,
                "english": " ".join(english.get(item, current[item]).lines),
            })
            continue
        version, texts = max(candidates, key=lambda pair: pair[0])
        official[item] = texts["es"]
        provenance[item] = {"slug": slug, "version_group_id": version}

    if args.moves_csv and args.move_flavor_csv:
        with open(args.moves_csv, encoding="utf-8-sig", newline="") as file:
            move_ids = {row["identifier"]: row["id"] for row in csv.DictReader(file)}
        move_flavors: dict[str, tuple[int, str]] = {}
        with open(args.move_flavor_csv, encoding="utf-8-sig", newline="") as file:
            for row in csv.DictReader(file):
                if row["language_id"] != "7":
                    continue
                move_id = row["move_id"]
                version = int(row["version_group_id"])
                if move_id not in move_flavors or version > move_flavors[move_id][0]:
                    move_flavors[move_id] = (version, normalize(row["flavor_text"]))
        still_missing = []
        for entry in missing:
            item = entry["item"]
            if item.startswith(("ITEM_TM_", "ITEM_HM_")):
                move_slug = item.split("_", 2)[2].lower().replace("_", "-")
                move_id = move_ids.get(move_slug)
                if move_id in move_flavors:
                    version, text = move_flavors[move_id]
                    official[item] = text
                    provenance[item] = {"slug": move_slug, "version_group_id": version, "source": "move"}
                    continue
            still_missing.append(entry)
        missing = still_missing

    if args.fallback_json:
        fallback = json.loads((REPO / args.fallback_json).read_text(encoding="utf-8"))
        still_missing = []
        for entry in missing:
            item = entry["item"]
            if item in fallback:
                official[item] = fallback[item]
                provenance[item] = {"source": "adaptacion-funcional-completa"}
            else:
                still_missing.append(entry)
        missing = still_missing

    if args.anil_json:
        anil = json.loads(Path(args.anil_json).read_text(encoding="utf-8"))["items"]
        anil_items = {
            re.sub(r"[^a-z0-9]", "", name.lower()): normalize(data["description"])
            for name, data in anil.items()
            if data.get("description")
        }
        still_missing = []
        for entry in missing:
            item = entry["item"]
            key = re.sub(r"[^a-z0-9]", "", item.removeprefix("ITEM_").lower())
            if key in anil_items:
                official[item] = anil_items[key]
                provenance[item] = {"slug": key, "source": "pokemon-anil"}
            else:
                still_missing.append(entry)
        missing = still_missing

    output = REPO / args.output
    output.write_text(json.dumps(official, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    output.with_name(output.stem + "_source.json").write_text(
        json.dumps(provenance, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )
    (output.with_name(output.stem + "_missing.json")).write_text(
        json.dumps(missing, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )
    print(f"Objetos del juego: {len(current)}")
    print(f"Con descripción oficial española: {len(official)}")
    print(f"Sin correspondencia oficial: {len(missing)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
