with open('/home/falan/pokehns-expansion/src/data/items.h', 'r', encoding='utf-8') as f:
    lines = f.readlines()

print(f"Total lines in items.h: {len(lines)}")
for idx, line in enumerate(lines[:100]):
    if 'static const u8' in line:
        print(f"Line {idx+1}: {line.strip()}")
