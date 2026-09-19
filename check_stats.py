import json

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_abilities.json', 'r', encoding='utf-8') as f:
    abilities = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_moves.json', 'r', encoding='utf-8') as f:
    moves = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_items.json', 'r', encoding='utf-8') as f:
    items = json.load(f)

print(f"Abilities count: {len(abilities)}")
print(f"Moves count: {len(moves)}")
print(f"Items count: {len(items)}")
