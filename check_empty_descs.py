import json
import re

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/unmapped_moves.json', 'r', encoding='utf-8') as f:
    unmapped = json.load(f)

# Load moves_info.h to check which symbol is used for empty descs
with open('/home/falan/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
    content = f.read()

print("Checking empty desc moves:")
for m in unmapped:
    if not m['desc']:
        mid = m['id']
        match = re.search(r'\[' + mid + r'\]\s*=\s*\{[\s\S]*?\.description\s*=\s*([A-Za-z0-9_]+)', content)
        sym = match.group(1) if match else "NOT FOUND"
        print(f"{mid} -> {sym}")
