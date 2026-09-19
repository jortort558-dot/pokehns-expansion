import re
import json

def dump_all():
    # 1. abilities
    with open('/home/falan/pokehns-expansion/src/data/abilities.h', 'r', encoding='utf-8') as f:
        ab_text = f.read()
    ab_blocks = re.split(r'(?=\n\s*\[ABILITY_[A-Z0-9_]+\]\s*=)', ab_text)
    abilities = []
    for b in ab_blocks:
        m_id = re.search(r'\[(ABILITY_[A-Z0-9_]+)\]', b)
        if not m_id or m_id.group(1) == 'ABILITY_NONE':
            continue
        m_name = re.search(r'\.name\s*=\s*_\("([^"]+)"\)', b)
        m_desc = re.search(r'\.description\s*=\s*COMPOUND_STRING\("([^"]+)"\)', b)
        name = m_name.group(1) if m_name else ''
        desc = m_desc.group(1) if m_desc else ''
        abilities.append({'id': m_id.group(1), 'name': name, 'desc': desc})

    # 2. moves
    with open('/home/falan/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
        mv_text = f.read()
    mv_blocks = re.split(r'(?=\n\s*\[MOVE_[A-Z0-9_]+\]\s*=)', mv_text)
    moves = []
    for b in mv_blocks:
        m_id = re.search(r'\[(MOVE_[A-Z0-9_]+)\]', b)
        if not m_id or m_id.group(1) == 'MOVE_NONE':
            continue
        m_name = re.search(r'\.name\s*=\s*COMPOUND_STRING\("([^"]+)"\)', b)
        m_desc = re.search(r'\.description\s*=\s*COMPOUND_STRING\(\s*("[\s\S]*?")\s*\)', b)
        name = m_name.group(1) if m_name else ''
        raw_desc = m_desc.group(1) if m_desc else ''
        parts = re.findall(r'"([^"]*)"', raw_desc)
        desc = "".join(parts)
        moves.append({'id': m_id.group(1), 'name': name, 'desc': desc})

    # 3. items
    with open('/home/falan/pokehns-expansion/src/data/items.h', 'r', encoding='utf-8') as f:
        it_text = f.read()
    it_blocks = re.split(r'(?=\n\s*\[ITEM_[A-Z0-9_]+\]\s*=)', it_text)
    items = []
    for b in it_blocks:
        m_id = re.search(r'\[(ITEM_[A-Z0-9_]+)\]', b)
        if not m_id or m_id.group(1) == 'ITEM_NONE':
            continue
        m_name = re.search(r'\.name\s*=\s*(?:ITEM_NAME|COMPOUND_STRING)\("([^"]+)"\)', b)
        m_desc_inline = re.search(r'\.description\s*=\s*(?:COMPOUND_STRING|_)\(\s*("[\s\S]*?")\s*\)', b)
        m_desc_sym = re.search(r'\.description\s*=\s*(s[A-Za-z0-9_]+Desc)', b)
        name = m_name.group(1) if m_name else ''
        desc = ''
        sym = ''
        if m_desc_inline:
            parts = re.findall(r'"([^"]*)"', m_desc_inline.group(1))
            desc = "".join(parts)
        elif m_desc_sym:
            sym = m_desc_sym.group(1)
        items.append({'id': m_id.group(1), 'name': name, 'desc': desc, 'sym': sym})

    with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_abilities.json', 'w', encoding='utf-8') as f:
        json.dump(abilities, f, ensure_ascii=False, indent=2)
    with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_moves.json', 'w', encoding='utf-8') as f:
        json.dump(moves, f, ensure_ascii=False, indent=2)
    with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_items.json', 'w', encoding='utf-8') as f:
        json.dump(items, f, ensure_ascii=False, indent=2)

    print(f"Exported {len(abilities)} abilities, {len(moves)} moves, {len(items)} items.")

if __name__ == '__main__':
    dump_all()
