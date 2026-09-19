import re

with open('/home/falan/pokehns-expansion/src/data/moves_info.h.bak_desc_20260918_205635', 'r', encoding='utf-8') as f:
    text = f.read()

blocks = re.split(r'(?=\n\s*\[MOVE_[A-Z0-9_]+\]\s*=)', text)
with_cpp = []
without_cpp = []

for block in blocks:
    m_id = re.search(r'\[(MOVE_[A-Z0-9_]+)\]', block)
    if not m_id:
        continue
    move_id = m_id.group(1)
    if '.description' in block:
        # Match from .description to the closing parenthesis of COMPOUND_STRING
        desc_area = re.search(r'\.description\s*=\s*COMPOUND_STRING[\s\S]*?\)', block)
        if desc_area and ('#if' in desc_area.group(0) or '#else' in desc_area.group(0)):
            with_cpp.append((move_id, desc_area.group(0)))
        else:
            without_cpp.append(move_id)

print(f"Moves without cpp in description: {len(without_cpp)}")
print(f"Moves with cpp in description: {len(with_cpp)}")
for m, d in with_cpp:
    print(f"{m}:")
    print(d)
    print("-" * 40)
