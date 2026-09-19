import re

def check_moves():
    with open('/home/falan/pokehns-expansion/src/data/moves_info.h', 'r', encoding='utf-8') as f:
        text = f.read()

    # Match each [MOVE_NAME] = { ... }
    pattern = r'\[(MOVE_[A-Z0-9_]+)\]\s*=\s*\{'
    matches = list(re.finditer(pattern, text))
    print(f"Total move entries in moves_info.h: {len(matches)}")

    # Check how many have .description = COMPOUND_STRING(...)
    desc_pat = re.compile(r'\.description\s*=\s*COMPOUND_STRING\s*\(\s*("[\s\S]*?")\s*\)', re.MULTILINE)
    count = len(desc_pat.findall(text))
    print(f"Total move descriptions in moves_info.h: {count}")

def check_abilities():
    with open('/home/falan/pokehns-expansion/src/data/abilities.h', 'r', encoding='utf-8') as f:
        text = f.read()
    pattern = r'\[(ABILITY_[A-Z0-9_]+)\]\s*=\s*\{'
    matches = list(re.finditer(pattern, text))
    print(f"Total ability entries in abilities.h: {len(matches)}")
    desc_pat = re.compile(r'\.description\s*=\s*COMPOUND_STRING\s*\(\s*("[\s\S]*?")\s*\)', re.MULTILINE)
    count = len(desc_pat.findall(text))
    print(f"Total ability descriptions in abilities.h: {count}")

def check_items():
    with open('/home/falan/pokehns-expansion/src/data/items.h', 'r', encoding='utf-8') as f:
        text = f.read()
    pattern = r'\[(ITEM_[A-Z0-9_]+)\]\s*=\s*\{'
    matches = list(re.finditer(pattern, text))
    print(f"Total item entries in items.h: {len(matches)}")
    desc_pat = re.compile(r'\.description\s*=\s*(?:COMPOUND_STRING|_)\s*\(\s*("[\s\S]*?")\s*\)', re.MULTILINE)
    count = len(desc_pat.findall(text))
    print(f"Total item descriptions inline in items.h: {count}")
    static_desc = re.findall(r'static const u8 s[A-Za-z0-9_]+Desc\[\]\s*=\s*_\(', text)
    print(f"Total item static descriptions in items.h: {len(static_desc)}")

if __name__ == '__main__':
    check_moves()
    check_abilities()
    check_items()
