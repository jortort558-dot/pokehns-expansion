import json

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/unmapped_moves.json', 'r', encoding='utf-8') as f:
    unmapped = json.load(f)

print(f"Total: {len(unmapped)}")
print("First 10:")
for item in unmapped[:10]:
    print(item)
print("Last 10:")
for item in unmapped[-10:]:
    print(item)
