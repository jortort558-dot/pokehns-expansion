import json
import re

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_moves.json', 'r', encoding='utf-8') as f:
    moves = json.load(f)

# Collect all non-empty descriptions
sample = []
for m in moves:
    if m.get('desc'):
        sample.append((m['id'], m['name'], m['desc']))

print(f"Moves with English descriptions in raw: {len(sample)}")
with open('/mnt/y/heartandsoul_esp/pokehns-expansion/moves_to_translate.json', 'w', encoding='utf-8') as f:
    json.dump(sample, f, ensure_ascii=False, indent=2)

print("Saved moves_to_translate.json")
