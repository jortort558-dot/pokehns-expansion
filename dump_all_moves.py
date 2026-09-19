import re
import json

with open('/home/falan/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
    text = f.read()

blocks = re.split(r'(?=\n\s*\[MOVE_[A-Z0-9_]+\]\s*=)', text)
moves = []

for b in blocks:
    m_id = re.search(r'\[(MOVE_[A-Z0-9_]+)\]', b)
    if not m_id:
        continue
    mv_id = m_id.group(1)
    if mv_id == 'MOVE_NONE':
        continue
    
    m_name = re.search(r'\.name\s*=\s*COMPOUND_STRING\("([^"]+)"\)', b)
    name = m_name.group(1) if m_name else ''
    
    desc = ''
    m_desc = re.search(r'\.description\s*=\s*COMPOUND_STRING\(\s*("[\s\S]*?")\s*\)', b)
    if m_desc:
        parts = re.findall(r'"([^"]*)"', m_desc.group(1))
        desc = "".join(parts)
    elif re.search(r'\.description\s*=\s*(s[A-Za-z0-9_]+Description)', b):
        desc = re.search(r'\.description\s*=\s*(s[A-Za-z0-9_]+Description)', b).group(1)

    moves.append({'id': mv_id, 'name': name, 'desc': desc})

print(f"Total moves dumped in exact code order: {len(moves)}")
with open('/mnt/y/heartandsoul_esp/pokehns-expansion/all_moves_order.json', 'w', encoding='utf-8') as f:
    json.dump(moves, f, ensure_ascii=False, indent=2)

print("Saved all_moves_order.json")
