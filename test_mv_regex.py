import re

with open('/home/falan/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
    text = f.read()

blocks = re.split(r'(?=\n\s*\[MOVE_[A-Z0-9_]+\]\s*=)', text)
found_inline = 0
found_sym = 0
found_cpp = 0
missing = []

for b in blocks:
    m = re.search(r'\[(MOVE_[A-Z0-9_]+)\]', b)
    if not m:
        continue
    mv_id = m.group(1)
    if mv_id == 'MOVE_NONE':
        continue
    
    desc_area = re.search(r'\.description\s*=\s*COMPOUND_STRING[\s\S]*?\)', b)
    if desc_area and ('#if' in desc_area.group(0) or '#else' in desc_area.group(0) or '#endif' in desc_area.group(0)):
        found_cpp += 1
    elif re.search(r'(\.description\s*=\s*COMPOUND_STRING\s*\(\s*\n?\s*)"[\s\S]*?"(\s*\))', b):
        found_inline += 1
    elif re.search(r'\.description\s*=\s*(s[A-Za-z0-9_]+Description)', b):
        found_sym += 1
    else:
        missing.append((mv_id, b[:100]))

print(f"Total move blocks analyzed: {len(blocks) - 1}")
print(f"Inline COMPOUND_STRING: {found_inline}")
print(f"Shared symbol descriptions: {found_sym}")
print(f"Preprocessor CPP descriptions: {found_cpp}")
print(f"Missing / unhandled: {len(missing)}")
if missing:
    for m, snip in missing[:10]:
        print(f"  {m}: {repr(snip)}")
