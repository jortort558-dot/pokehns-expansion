import re

# Read translate_phase1.py to get MOVE_NAMES keys in order
with open('/mnt/y/heartandsoul_esp/pokehns-expansion/translate_phase1.py', 'r', encoding='utf-8') as f:
    t1 = f.read()

m = re.search(r'MOVE_NAMES = \{([\s\S]*?)\}\n\n#', t1)
move_keys = []
if m:
    move_keys = [k.replace('"', '').strip() for k in re.findall(r'"([^"]+)":', m.group(1))]

# Read translate_phase1_desc.py to get MOVE_DESCRIPTIONS values in order
with open('/mnt/y/heartandsoul_esp/pokehns-expansion/translate_phase1_desc.py', 'r', encoding='utf-8') as f:
    t2 = f.read()

m2 = re.search(r'MOVE_DESCRIPTIONS = \{([\s\S]*?)\}\n\n#', t2)
desc_values = []
if m2:
    # Match value part after colon
    desc_values = re.findall(r':\s*\n?\s*"([^"]+)"', m2.group(1))

print(f"Total move keys in order: {len(move_keys)}")
print(f"Total desc values in order: {len(desc_values)}")
for i in range(min(20, len(desc_values))):
    k = move_keys[i].replace(' ', '_').replace('-', '_')
    v = desc_values[i].replace('\\n', ' ')
    print(f"MOVE_{k}: {v[:40]}")
