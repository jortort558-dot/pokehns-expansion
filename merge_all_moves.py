import json
import re

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_moves.json', 'r', encoding='utf-8') as f:
    raw_moves = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/moves_es.json', 'r', encoding='utf-8') as f:
    moves_es = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/shared_moves_es.json', 'r', encoding='utf-8') as f:
    shared_moves_es = json.load(f)

import sys
sys.path.insert(0, '/mnt/y/heartandsoul_esp/pokehns-expansion')
from remaining_moves_dict import REMAINING_MOVES_ES

# Update moves_es with REMAINING_MOVES_ES
moves_es.update(REMAINING_MOVES_ES)

with open('/home/falan/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
    header = f.read()

missing = []
for m in raw_moves:
    mid = m['id']
    if mid in moves_es:
        continue
    m_match = re.search(r'\[' + mid + r'\]\s*=\s*\{[\s\S]*?\.description\s*=\s*([A-Za-z0-9_]+)', header)
    if m_match and m_match.group(1) in shared_moves_es:
        continue
    missing.append(mid)

print(f"Total raw moves: {len(raw_moves)}")
print(f"Total moves in moves_es: {len(moves_es)}")
print(f"Missing moves: {len(missing)}")
if missing:
    print(f"Still missing: {missing}")
else:
    # Save back to moves_es.json
    with open('/mnt/y/heartandsoul_esp/pokehns-expansion/moves_es.json', 'w', encoding='utf-8') as f:
        json.dump(moves_es, f, ensure_ascii=False, indent=2)
    print("Successfully updated moves_es.json! 100% COVERAGE ACHIEVED!")
