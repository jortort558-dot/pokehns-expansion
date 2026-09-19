with open('/home/falan/pokehns-expansion/src/data/items.h', 'r', encoding='utf-8') as f:
    content = f.read()

import re
matches = re.findall(r'\[(ITEM_[A-Z0-9_]+)\]\s*=\s*\{[\s\S]*?\.description\s*=\s*([A-Za-z0-9_]+|COMPOUND_STRING[\s\S]*?\)),', content)
print(f"Total item assignments found: {len(matches)}")
for m in matches[:10]:
    print(m[0], "->", m[1][:40].replace('\n', ' '))
