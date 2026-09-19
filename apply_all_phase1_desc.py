#!/usr/bin/env python3
"""
apply_all_phase1_desc.py - Aplica al 100% todas las descripciones de la Fase 1:
- Movimientos (moves_info.h): inline e identificadores compartidos.
- Habilidades (abilities.h): inline por ID.
- Objetos (items.h): inline por ID y símbolos compartidos static const u8.
- Mensajes de Combate (battle_message.c): sustitución de cadenas de batalla.
"""

import os
import sys
import re
import json
import shutil
from datetime import datetime

def backup_file(filepath):
    bak = filepath + ".bak_fase1_" + datetime.now().strftime("%Y%m%d_%H%M%S")
    shutil.copy2(filepath, bak)
    return bak

def format_compound_string(text):
    """Convierte texto con saltos de línea \\n en formato COMPOUND_STRING multilínea."""
    parts = text.split("\\n")
    if len(parts) == 1:
        return f'"{parts[0]}"'
    lines = [f'"{parts[0]}\\n"']
    for p in parts[1:-1]:
        lines.append(f'        "{p}\\n"')
    lines.append(f'        "{parts[-1]}"')
    return "\n".join(lines)

def apply_abilities(abilities_file, abilities_es, dry_run=False):
    with open(abilities_file, "r", encoding="utf-8") as f:
        content = f.read()

    blocks = re.split(r'(?=\n\s*\[ABILITY_[A-Z0-9_]+\]\s*=)', content)
    new_blocks = []
    count = 0

    for block in blocks:
        m_id = re.search(r'\[(ABILITY_[A-Z0-9_]+)\]', block)
        if not m_id or m_id.group(1) not in abilities_es:
            new_blocks.append(block)
            continue

        ab_id = m_id.group(1)
        spanish_desc = abilities_es[ab_id]
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
        with open(abilities_file, "w", encoding="utf-8") as f:
            f.write("".join(new_blocks))

    return count

def apply_moves(moves_file, moves_es, shared_moves_es, dry_run=False):
    with open(moves_file, "r", encoding="utf-8") as f:
        content = f.read()

    shared_count = 0
    # 1. Reemplazar símbolos compartidos static const u8 s...Description[] = _("...");
    for sym, es_desc in shared_moves_es.items():
        es_parts = es_desc.split("\\n")
        repl_lines = []
        for i, p in enumerate(es_parts):
            if i < len(es_parts) - 1:
                repl_lines.append(f'"{p}\\n"')
            else:
                repl_lines.append(f'"{p}"')
        formatted_c_str = "\n".join("    " + l if i > 0 else l for i, l in enumerate(repl_lines))
        safe_repl = formatted_c_str.replace('\\', '\\\\')

        # Buscar static const u8 sym[] = _(...)
        pattern = r'(static\s+const\s+u8\s+' + re.escape(sym) + r'\[\]\s*=\s*_\(\s*\n?\s*)"[\s\S]*?"(\s*\);)'
        new_content, n = re.subn(pattern, r'\g<1>' + safe_repl + r'\g<2>', content)
        if n > 0:
            shared_count += n
            content = new_content

    # 2. Reemplazar descripciones inline de movimientos
    blocks = re.split(r'(?=\n\s*\[MOVE_[A-Z0-9_]+\]\s*=)', content)
    new_blocks = []
    inline_count = 0

    for block in blocks:
        m_id = re.search(r'\[(MOVE_[A-Z0-9_]+)\]', block)
        if not m_id or m_id.group(1) not in moves_es:
            new_blocks.append(block)
            continue

        move_id = m_id.group(1)
        spanish_desc = moves_es[move_id]

        # Evitar sobreescribir bloques que tengan directivas de preprocesador embebidas (#if/#else/#endif)
        desc_match = re.search(r'\.description\s*=\s*COMPOUND_STRING[\s\S]*?\)', block)
        if desc_match and ('#if' in desc_match.group(0) or '#else' in desc_match.group(0) or '#endif' in desc_match.group(0)):
            new_blocks.append(block)
            continue

        new_desc_str = format_compound_string(spanish_desc)
        safe_repl = new_desc_str.replace('\\', '\\\\')
        pattern = r'(\.description\s*=\s*COMPOUND_STRING\s*\(\s*\n?\s*)"[\s\S]*?"(\s*\))'
        new_block, n = re.subn(pattern, r'\g<1>' + safe_repl + r'\g<2>', block)
        if n > 0:
            inline_count += n
            new_blocks.append(new_block)
        else:
            new_blocks.append(block)

    final_content = "".join(new_blocks)
    if not dry_run and (shared_count > 0 or inline_count > 0):
        with open(moves_file, "w", encoding="utf-8") as f:
            f.write(final_content)

    return inline_count, shared_count

def apply_items(items_file, items_es, shared_items_es, dry_run=False):
    with open(items_file, "r", encoding="utf-8") as f:
        content = f.read()

    shared_count = 0
    # 1. Reemplazar símbolos compartidos static const u8 s...Desc[] = _("...");
    for sym, es_desc in shared_items_es.items():
        es_parts = es_desc.split("\\n")
        repl_lines = []
        for i, p in enumerate(es_parts):
            if i < len(es_parts) - 1:
                repl_lines.append(f'"{p}\\n"')
            else:
                repl_lines.append(f'"{p}"')
        formatted_c_str = "\n".join("    " + l if i > 0 else l for i, l in enumerate(repl_lines))
        safe_repl = formatted_c_str.replace('\\', '\\\\')

        pattern = r'(static\s+const\s+u8\s+' + re.escape(sym) + r'\[\]\s*=\s*_\(\s*\n?\s*)"[\s\S]*?"(\s*\);)'
        new_content, n = re.subn(pattern, r'\g<1>' + safe_repl + r'\g<2>', content)
        if n > 0:
            shared_count += n
            content = new_content

    # 2. Reemplazar descripciones inline de objetos
    blocks = re.split(r'(?=\n\s*\[ITEM_[A-Z0-9_]+\]\s*=)', content)
    new_blocks = []
    inline_count = 0

    for block in blocks:
        m_id = re.search(r'\[(ITEM_[A-Z0-9_]+)\]', block)
        if not m_id or m_id.group(1) not in items_es:
            new_blocks.append(block)
            continue

        item_id = m_id.group(1)
        spanish_desc = items_es[item_id]

        # Evitar sobreescribir bloques que tengan directivas de preprocesador embebidas (#if/#else/#endif)
        desc_match = re.search(r'\.description\s*=\s*COMPOUND_STRING[\s\S]*?\)', block)
        if desc_match and ('#if' in desc_match.group(0) or '#else' in desc_match.group(0) or '#endif' in desc_match.group(0)):
            new_blocks.append(block)
            continue

        new_desc_str = format_compound_string(spanish_desc)
        safe_repl = new_desc_str.replace('\\', '\\\\')
        pattern = r'(\.description\s*=\s*COMPOUND_STRING\s*\(\s*\n?\s*)"[\s\S]*?"(\s*\))'
        new_block, n = re.subn(pattern, r'\g<1>' + safe_repl + r'\g<2>', block)
        if n > 0:
            inline_count += n
            new_blocks.append(new_block)
        else:
            new_blocks.append(block)

    final_content = "".join(new_blocks)
    if not dry_run and (shared_count > 0 or inline_count > 0):
        with open(items_file, "w", encoding="utf-8") as f:
            f.write(final_content)

    return inline_count, shared_count

def apply_battle_messages(battle_msg_file, battle_messages, dry_run=False):
    with open(battle_msg_file, "r", encoding="utf-8") as f:
        content = f.read()

    count = 0
    for en, es in battle_messages.items():
        if en in content:
            content = content.replace(en, es)
            count += 1

    if not dry_run and count > 0:
        with open(battle_msg_file, "w", encoding="utf-8") as f:
            f.write(content)

    return count

def main():
    project_dir = sys.argv[1] if len(sys.argv) > 1 else "."
    dry_run = "--dry-run" in sys.argv

    dict_dir = "/mnt/y/heartandsoul_esp/pokehns-expansion"
    if not os.path.exists(os.path.join(dict_dir, "abilities_es.json")):
        dict_dir = os.path.dirname(os.path.abspath(__file__))

    # Cargar diccionarios JSON
    with open(os.path.join(dict_dir, "abilities_es.json"), "r", encoding="utf-8") as f:
        abilities_es = json.load(f)

    with open(os.path.join(dict_dir, "moves_es.json"), "r", encoding="utf-8") as f:
        moves_es = json.load(f)

    with open(os.path.join(dict_dir, "shared_moves_es.json"), "r", encoding="utf-8") as f:
        shared_moves_es = json.load(f)

    with open(os.path.join(dict_dir, "items_es.json"), "r", encoding="utf-8") as f:
        items_es = json.load(f)

    with open(os.path.join(dict_dir, "shared_items_es.json"), "r", encoding="utf-8") as f:
        shared_items_es = json.load(f)

    sys.path.insert(0, dict_dir)
    import translate_phase1_desc as p1_desc
    from battle_messages_expansion import BATTLE_MESSAGES_EXPANSION
    battle_messages = dict(p1_desc.BATTLE_MESSAGES)
    battle_messages.update(BATTLE_MESSAGES_EXPANSION)

    moves_file = os.path.join(project_dir, "src", "data", "moves_info.h")
    abilities_file = os.path.join(project_dir, "src", "data", "abilities.h")
    items_file = os.path.join(project_dir, "src", "data", "items.h")
    battle_msg_file = os.path.join(project_dir, "src", "battle_message.c")

    print("=" * 65)
    print("  TRADUCCIÓN INTEGRAL FASE 1: DESCRIPCIONES Y MENSAJES (100%)")
    print("=" * 65)
    print(f"  • Habilidades en diccionario: {len(abilities_es)}")
    print(f"  • Movimientos en diccionario: {len(moves_es)} (+ {len(shared_moves_es)} compartidos)")
    print(f"  • Objetos en diccionario:     {len(items_es)} (+ {len(shared_items_es)} compartidos)")
    print(f"  • Mensajes de combate:       {len(battle_messages)}")
    print("=" * 65)

    if dry_run:
        print("  [MODO DRY-RUN ACTIVADO: No se modifican archivos]")

    # 1. Habilidades
    if os.path.exists(abilities_file):
        if not dry_run:
            bak = backup_file(abilities_file)
            print(f"  [BAK] {os.path.basename(bak)}")
        n_ab = apply_abilities(abilities_file, abilities_es, dry_run=dry_run)
        print(f"  [OK] Habilidades: {n_ab} descripciones traducidas.")

    # 2. Movimientos
    if os.path.exists(moves_file):
        if not dry_run:
            bak = backup_file(moves_file)
            print(f"  [BAK] {os.path.basename(bak)}")
        n_mov_in, n_mov_sh = apply_moves(moves_file, moves_es, shared_moves_es, dry_run=dry_run)
        print(f"  [OK] Movimientos: {n_mov_in} inline + {n_mov_sh} compartidos traducidos.")

    # 3. Objetos
    if os.path.exists(items_file):
        if not dry_run:
            bak = backup_file(items_file)
            print(f"  [BAK] {os.path.basename(bak)}")
        n_it_in, n_it_sh = apply_items(items_file, items_es, shared_items_es, dry_run=dry_run)
        print(f"  [OK] Objetos: {n_it_in} inline + {n_it_sh} compartidos traducidos.")

    # 4. Mensajes de Combate
    if os.path.exists(battle_msg_file):
        if not dry_run:
            bak = backup_file(battle_msg_file)
            print(f"  [BAK] {os.path.basename(bak)}")
        n_msg = apply_battle_messages(battle_msg_file, battle_messages, dry_run=dry_run)
        print(f"  [OK] Mensajes de combate: {n_msg} textos traducidos.")

    print("=" * 65)
    print("  ¡PROCESO COMPLETADO CON ÉXITO!")
    print("=" * 65)

if __name__ == "__main__":
    main()
