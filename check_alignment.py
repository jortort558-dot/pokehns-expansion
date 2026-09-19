import re

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/translate_phase1.py', 'r', encoding='utf-8') as f:
    t1 = f.read()

m = re.search(r'MOVE_NAMES = \{([\s\S]*?)\}\n\n#', t1)
move_keys = []
if m:
    move_keys = [k.replace('"', '').strip() for k in re.findall(r'"([^"]+)":', m.group(1))]

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/translate_phase1_desc.py', 'r', encoding='utf-8') as f:
    t2 = f.read()

m2 = re.search(r'MOVE_DESCRIPTIONS = \{([\s\S]*?)\}\n\n#', t2)
desc_pairs = []
if m2:
    desc_pairs = re.findall(r'"([^"]+)"\s*:\s*\n?\s*"([^"]+)"', m2.group(1))

print(f"Total move keys: {len(move_keys)}")
print(f"Total desc pairs: {len(desc_pairs)}")

for i in range(50, 75):
    k = move_keys[i]
    en_desc, es_desc = desc_pairs[i]
    print(f"{i}: MOVE_{k} | EN: {en_desc[:30]} | ES: {es_desc[:30]}")
