import json

with open('unmapped_moves.json', 'r', encoding='utf-8') as f:
    unmapped = json.load(f)

print(f"Total unmapped moves: {len(unmapped)}")
for idx, item in enumerate(unmapped[:100]):
    print(f"{idx}: {item['id']} | {item['name']} | {item['desc'][:30] if item['desc'] else 'SHARED'}")
