import json

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/unmapped_moves.json', 'r', encoding='utf-8') as f:
    unmapped = json.load(f)

for idx, m in enumerate(unmapped):
    print(f"{idx}: {m['id']} -> desc: {repr(m['desc'])}")
