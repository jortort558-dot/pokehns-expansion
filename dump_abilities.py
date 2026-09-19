import re
import json

def extract():
    with open('/home/falan/pokehns-expansion/src/data/abilities.h', 'r', encoding='utf-8') as f:
        text = f.read()

    blocks = re.split(r'(?=\n\s*\[ABILITY_[A-Z0-9_]+\]\s*=)', text)
    abilities = []

    for b in blocks:
        m_id = re.search(r'\[(ABILITY_[A-Z0-9_]+)\]', b)
        if not m_id:
            continue
        ab_id = m_id.group(1)
        m_desc = re.search(r'\.description\s*=\s*COMPOUND_STRING\s*\(\s*"([^"]+)"\s*\)', b)
        if m_desc:
            abilities.append((ab_id, m_desc.group(1)))

    print(f"Total abilities extracted cleanly: {len(abilities)}")
    with open('/mnt/y/heartandsoul_esp/pokehns-expansion/all_abilities.json', 'w', encoding='utf-8') as out:
        json.dump(abilities, out, ensure_ascii=False, indent=2)

if __name__ == '__main__':
    extract()
