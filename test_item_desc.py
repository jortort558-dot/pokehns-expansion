import re

with open('/home/falan/pokehns-expansion/src/data/items.h', 'r', encoding='utf-8') as f:
    text = f.read()

blocks = re.split(r'(?=\n\s*\[ITEM_[A-Z0-9_]+\]\s*=)', text)
inline_desc = 0
sym_desc = 0
no_desc = 0

for b in blocks:
    m = re.search(r'\[(ITEM_[A-Z0-9_]+)\]', b)
    if not m or m.group(1) == 'ITEM_NONE':
        continue
    item_id = m.group(1)
    if re.search(r'\.description\s*=\s*(?:COMPOUND_STRING|_)\s*\(\s*\n?\s*"[\s\S]*?"\s*\)', b):
        inline_desc += 1
    elif re.search(r'\.description\s*=\s*(s[A-Za-z0-9_]+Desc)', b):
        sym_desc += 1
    else:
        no_desc += 1

print(f"Total items parsed: {len(blocks) - 1}")
print(f"Items with inline description: {inline_desc}")
print(f"Items with shared symbol description: {sym_desc}")
print(f"Items without description: {no_desc}")

static_symbols = re.findall(r'static const u8 (s[A-Za-z0-9_]+Desc)\[\]\s*=\s*_\(\s*\n?\s*"([\s\S]*?)"\s*\);', text)
print(f"Total static symbol definitions: {len(static_symbols)}")
