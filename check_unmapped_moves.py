import json

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_moves.json', 'r', encoding='utf-8') as f:
    raw_moves = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/moves_es.json', 'r', encoding='utf-8') as f:
    moves_es = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/shared_moves_es.json', 'r', encoding='utf-8') as f:
    shared_moves = json.load(f)

unmapped = []
for m in raw_moves:
    mv_id = m['id']
    if mv_id == 'MOVE_NONE':
        continue
    desc = m.get('desc', '')
    if desc.startswith('s') and desc.endswith('Description') and desc in shared_moves:
        continue
    if mv_id not in moves_es:
        unmapped.append(m)

print(f"Total raw moves: {len(raw_moves)}")
print(f"Unmapped moves: {len(unmapped)}")
print("\nSample unmapped (first 25):")
for u in unmapped[:25]:
    print(f"  {u['id']}: {repr(u['name'])} -> {repr(u['desc'][:40] if u['desc'] else '')}")

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/unmapped_moves.json', 'w', encoding='utf-8') as f:
    json.dump(unmapped, f, ensure_ascii=False, indent=2)
