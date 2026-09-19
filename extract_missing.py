import re
import json

def get_missing():
    # 1. Habilidades pendientes
    with open('/home/falan/pokehns-expansion/src/data/abilities.h', 'r', encoding='utf-8') as f:
        ab_text = f.read()
    
    ab_blocks = re.split(r'(?=\n\s*\[ABILITY_[A-Z0-9_]+\]\s*=)', ab_text)
    missing_abilities = []
    for b in ab_blocks:
        m_id = re.search(r'\[(ABILITY_[A-Z0-9_]+)\]', b)
        if not m_id: continue
        ab_id = m_id.group(1)
        if ab_id == 'ABILITY_NONE': continue
        m_desc = re.search(r'\.description\s*=\s*COMPOUND_STRING\s*\(\s*"([^"]+)"\s*\)', b)
        if m_desc:
            # Si el texto sigue en inglés (detectado por palabras comunes o si no tiene tildes/español)
            desc = m_desc.group(1)
            missing_abilities.append((ab_id, desc))

    # 2. Movimientos pendientes
    with open('/home/falan/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
        mv_text = f.read()
    
    mv_blocks = re.split(r'(?=\n\s*\[MOVE_[A-Z0-9_]+\]\s*=)', mv_text)
    missing_moves = []
    for b in mv_blocks:
        m_id = re.search(r'\[(MOVE_[A-Z0-9_]+)\]', b)
        if not m_id: continue
        mv_id = m_id.group(1)
        if mv_id == 'MOVE_NONE': continue
        # Ver si tiene descripción en inglés
        m_desc = re.search(r'\.description\s*=\s*COMPOUND_STRING\s*\(\s*("[\s\S]*?")\s*\)', b)
        if m_desc:
            desc_raw = m_desc.group(1)
            # extraemos partes limpias
            parts = re.findall(r'"([^"]*)"', desc_raw)
            full_desc = "".join(parts)
            # si parece inglés (ej. the, user, foe, attack, boosts, raises)
            if any(w in full_desc.lower() for w in ['the ', 'user', 'foe', 'target', 'attack', 'boosts', 'raises', 'hits', 'deals']):
                missing_moves.append((mv_id, full_desc))

    print(f"Habilidades pendientes de traducir: {len(missing_abilities)}")
    print(f"Movimientos pendientes de traducir: {len(missing_moves)}")

    with open('/mnt/y/heartandsoul_esp/pokehns-expansion/missing_abilities.json', 'w', encoding='utf-8') as f:
        json.dump(missing_abilities, f, ensure_ascii=False, indent=2)

    with open('/mnt/y/heartandsoul_esp/pokehns-expansion/missing_moves.json', 'w', encoding='utf-8') as f:
        json.dump(missing_moves, f, ensure_ascii=False, indent=2)

if __name__ == '__main__':
    get_missing()
