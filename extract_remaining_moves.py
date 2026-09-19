import json
import re

with open('/home/falan/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
    text = f.read()

# Load already translated Gen 1-4
import sys, os
sys.path.insert(0, '/mnt/y/heartandsoul_esp/pokehns-expansion')
import translate_phase1 as p1
import translate_phase1_desc as p1_desc

move_names_keys = list(p1.MOVE_NAMES.keys())
desc_values = list(p1_desc.MOVE_DESCRIPTIONS.values())

existing_map = {}
for i in range(min(len(move_names_keys), len(desc_values))):
    key = move_names_keys[i].replace(" ", "_").replace("-", "_")
    move_id = f"MOVE_{key}"
    existing_map[move_id] = desc_values[i]

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_moves.json', 'r', encoding='utf-8') as f:
    moves = json.load(f)

print(f"Total moves in raw: {len(moves)}")
print(f"Existing mapped moves: {len(existing_map)}")

missing_moves = []
for m in moves:
    mv_id = m['id']
    if mv_id not in existing_map:
        missing_moves.append(m)

print(f"Moves to translate: {len(missing_moves)}")

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/remaining_moves.json', 'w', encoding='utf-8') as f:
    json.dump(missing_moves, f, ensure_ascii=False, indent=2)

print("Saved remaining_moves.json successfully.")
