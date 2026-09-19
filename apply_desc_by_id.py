import re
import os
import sys
import shutil
from datetime import datetime

# Import existing dictionaries
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import translate_phase1 as p1
import translate_phase1_desc as p1_desc

def backup_file(filepath):
    bak = filepath + ".bak_id_" + datetime.now().strftime("%Y%m%d_%H%M%S")
    shutil.copy2(filepath, bak)
    return bak

def build_move_id_map():
    """Maps MOVE_ID -> Spanish description based on the sequential alignment of Gen 1-4 moves."""
    # List of keys from MOVE_NAMES
    move_names_keys = list(p1.MOVE_NAMES.keys())
    desc_values = list(p1_desc.MOVE_DESCRIPTIONS.values())

    move_id_to_desc = {}
    for i in range(min(len(move_names_keys), len(desc_values))):
        key = move_names_keys[i].replace(" ", "_").replace("-", "_")
        move_id = f"MOVE_{key}"
        move_id_to_desc[move_id] = desc_values[i]
    return move_id_to_desc

def build_ability_id_map():
    """Maps ABILITY_ID -> Spanish description based on sequential alignment."""
    ab_names_keys = list(p1.ABILITY_NAMES.keys())
    desc_values = list(p1_desc.ABILITY_DESCRIPTIONS.values())

    ability_id_to_desc = {}
    # Notice ABILITY_NONE is index 0 in abilities.h, and "No special ability." is index 0 in ABILITY_DESCRIPTIONS
    ability_id_to_desc["ABILITY_NONE"] = desc_values[0]
    for i in range(min(len(ab_names_keys), len(desc_values) - 1)):
        key = ab_names_keys[i].replace(" ", "_").replace("-", "_")
        ab_id = f"ABILITY_{key}"
        ability_id_to_desc[ab_id] = desc_values[i + 1]
    return ability_id_to_desc

def format_compound_string(text):
    """Formats a text with \\n into COMPOUND_STRING multiline C string."""
    parts = text.split("\\n")
    if len(parts) == 1:
        return f'"{parts[0]}"'
    lines = [f'"{parts[0]}\\n"']
    for p in parts[1:-1]:
        lines.append(f'        "{p}\\n"')
    lines.append(f'        "{parts[-1]}"')
    return "\n".join(lines)

def apply_move_descriptions(filepath, move_id_map, dry_run=False):
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    blocks = re.split(r'(?=\n\s*\[MOVE_[A-Z0-9_]+\]\s*=)', content)
    new_blocks = []
    count = 0

    for block in blocks:
        m_id = re.search(r'\[(MOVE_[A-Z0-9_]+)\]', block)
        if not m_id or m_id.group(1) not in move_id_map:
            new_blocks.append(block)
            continue

        move_id = m_id.group(1)
        spanish_desc = move_id_map[move_id]
        # Si el bloque contiene directivas de preprocesador en su descripción (#if / #else / #endif),
        # lo preservamos intacto para no romper los bloques condicionales de la compilación
        desc_match = re.search(r'\.description\s*=\s*COMPOUND_STRING[\s\S]*?\)', block)
        if desc_match and ('#if' in desc_match.group(0) or '#else' in desc_match.group(0) or '#endif' in desc_match.group(0)):
            new_blocks.append(block)
            continue

        new_desc_str = format_compound_string(spanish_desc)
        safe_repl = new_desc_str.replace('\\', '\\\\')
        pattern = r'(\.description\s*=\s*COMPOUND_STRING\s*\(\s*\n?\s*)"[\s\S]*?"(\s*\))'
        new_block, n = re.subn(pattern, r'\g<1>' + safe_repl + r'\g<2>', block)
        if n > 0:
            count += n
            new_blocks.append(new_block)
        else:
            new_blocks.append(block)

    if not dry_run and count > 0:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write("".join(new_blocks))


    return count

def apply_ability_descriptions(filepath, ability_id_map, dry_run=False):
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    blocks = re.split(r'(?=\n\s*\[ABILITY_[A-Z0-9_]+\]\s*=)', content)
    new_blocks = []
    count = 0

    for block in blocks:
        m_id = re.search(r'\[(ABILITY_[A-Z0-9_]+)\]', block)
        if not m_id or m_id.group(1) not in ability_id_map:
            new_blocks.append(block)
            continue

        ab_id = m_id.group(1)
        spanish_desc = ability_id_map[ab_id]
        new_desc_str = format_compound_string(spanish_desc)

        safe_repl = new_desc_str.replace('\\', '\\\\')
        pattern = r'(\.description\s*=\s*COMPOUND_STRING\s*\(\s*\n?\s*)"[\s\S]*?"(\s*\))'
        new_block, n = re.subn(pattern, r'\g<1>' + safe_repl + r'\g<2>', block)
        if n > 0:
            count += n
            new_blocks.append(new_block)
        else:
            new_blocks.append(block)

    if not dry_run and count > 0:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write("".join(new_blocks))

    return count

def apply_item_descriptions(filepath, item_desc_map, dry_run=False):
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    count = 0
    for en, es in item_desc_map.items():
        en_parts = en.split("\\n")
        inner_pat = r'\\n"\s*\n?\s*"'.join(re.escape(p) for p in en_parts)
        pattern = r'((?:COMPOUND_STRING|_)\s*\(\s*\n?\s*)"' + inner_pat + r'"(\s*\))'

        es_desc_str = format_compound_string(es)
        safe_repl = es_desc_str.replace('\\', '\\\\')
        new_content, n = re.subn(pattern, r'\g<1>' + safe_repl + r'\g<2>', content)
        if n > 0:
            count += n
            content = new_content


    if not dry_run and count > 0:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)

    return count

def main():
    project_dir = sys.argv[1] if len(sys.argv) > 1 else "."
    dry_run = "--dry-run" in sys.argv

    if dry_run:
        print("[MODO SIMULACIÓN - No se escriben cambios]")

    moves_file = os.path.join(project_dir, "src", "data", "moves_info.h")
    abilities_file = os.path.join(project_dir, "src", "data", "abilities.h")
    items_file = os.path.join(project_dir, "src", "data", "items.h")

    move_id_map = build_move_id_map()
    ability_id_map = build_ability_id_map()

    print("=" * 60)
    print("  TRADUCCIONES POR ID - Descripciones de Movimientos y Habilidades")
    print("=" * 60)
    print(f"  Mapeados {len(move_id_map)} movimientos por ID")
    print(f"  Mapeadas {len(ability_id_map)} habilidades por ID")

    # Movimientos
    if os.path.exists(moves_file):
        if not dry_run:
            bak = backup_file(moves_file)
            print(f"\n  [BAK] {os.path.basename(bak)}")
        n_mov = apply_move_descriptions(moves_file, move_id_map, dry_run=dry_run)
        print(f"  [OK] Descripciones de Movimientos: {n_mov} sustituciones aplicadas")

    # Habilidades
    if os.path.exists(abilities_file):
        if not dry_run:
            bak = backup_file(abilities_file)
            print(f"\n  [BAK] {os.path.basename(bak)}")
        n_ab = apply_ability_descriptions(abilities_file, ability_id_map, dry_run=dry_run)
        print(f"  [OK] Descripciones de Habilidades: {n_ab} sustituciones aplicadas")

    # Objetos
    if os.path.exists(items_file):
        if not dry_run:
            bak = backup_file(items_file)
            print(f"\n  [BAK] {os.path.basename(bak)}")
        n_it = apply_item_descriptions(items_file, p1_desc.ITEM_DESCRIPTIONS, dry_run=dry_run)
        print(f"  [OK] Descripciones de Objetos: {n_it} sustituciones aplicadas")

    print("\n" + "=" * 60)
    print("  LISTO")
    print("=" * 60)

if __name__ == '__main__':
    main()
