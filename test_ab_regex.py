import re

with open('/home/falan/pokehns-expansion/src/data/abilities.h', 'r', encoding='utf-8') as f:
    text = f.read()

blocks = re.split(r'(?=\n\s*\[ABILITY_[A-Z0-9_]+\]\s*=)', text)
found = 0
missing = []
for b in blocks:
    m = re.search(r'\[(ABILITY_[A-Z0-9_]+)\]', b)
    if not m:
        continue
    ab_id = m.group(1)
    if re.search(r'(\.description\s*=\s*COMPOUND_STRING\s*\(\s*\n?\s*)"[\s\S]*?"(\s*\))', b):
        found += 1
    else:
        missing.append(ab_id)

print(f"Total matched abilities descriptions: {found}")
print(f"Missing or mismatched: {len(missing)}")
if missing:
    print("Mismatched IDs:", missing[:10])
