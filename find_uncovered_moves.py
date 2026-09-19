import json

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_moves.json', 'r', encoding='utf-8') as f:
    raw_moves = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/moves_es.json', 'r', encoding='utf-8') as f:
    moves_es = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/shared_moves_es.json', 'r', encoding='utf-8') as f:
    shared_moves_es = json.load(f)

with open('/home/falan/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
    header = f.read()

import re

uncovered = []
for m in raw_moves:
    mid = m['id']
    if mid in moves_es:
        continue
    # check if it uses shared symbol
    m_match = re.search(r'\[' + mid + r'\]\s*=\s*\{[\s\S]*?\.description\s*=\s*([A-Za-z0-9_]+)', header)
    if m_match and m_match.group(1) in shared_moves_es:
        continue
    uncovered.append(m)

print(f"Truly uncovered moves (not in moves_es and not in shared_moves_es): {len(uncovered)}")
for u in uncovered:
    print(f"{u['id']}: {repr(u['desc'])}")
