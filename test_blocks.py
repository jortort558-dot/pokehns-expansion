import re
import sys

def test():
    with open('/mnt/y/heartandsoul_esp/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
        text = f.read()

    # Match each [MOVE_NAME] = { ... }
    # To avoid non-greedy bleeding into other moves, match [MOVE_NAME] up to the next [MOVE_ or end of array
    move_blocks = re.split(r'(?=\n\s*\[MOVE_[A-Z0-9_]+\]\s*=)', text)
    print(f"Total split sections in moves_info.h: {len(move_blocks)}")

    replaced = 0
    # Let's test finding .description in a block
    for block in move_blocks:
        m_id = re.search(r'\[(MOVE_[A-Z0-9_]+)\]', block)
        if not m_id:
            continue
        move_id = m_id.group(1)
        m_desc = re.search(r'(\.description\s*=\s*COMPOUND_STRING\s*\(\s*)("[\s\S]*?")(\s*\))', block)
        if m_desc:
            replaced += 1

    print(f"Blocks with .description matched cleanly: {replaced}")

if __name__ == '__main__':
    test()
