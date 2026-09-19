import json
import re

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_abilities.json', 'r', encoding='utf-8') as f:
    abilities = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_moves.json', 'r', encoding='utf-8') as f:
    moves = json.load(f)

with open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_items.json', 'r', encoding='utf-8') as f:
    items = json.load(f)

# English detection words
EN_WORDS = {'the', 'a', 'an', 'is', 'it', 'its', 'to', 'of', 'in', 'on', 'with', 'for', 'by', 'that', 'this', 'and', 'or', 'foe', 'target', 'user', 'boosts', 'raises', 'lowers', 'inflicts', 'damages', 'restores', 'cures', 'prevents', 'causes', 'attacks', 'absorbs', 'reduces', 'doubles', 'increases', 'turns', 'strikes'}

def is_english(text):
    if not text:
        return False
    words = set(re.findall(r'[a-zA-Z]+', text.lower()))
    common = words.intersection(EN_WORDS)
    return len(common) >= 1

en_abilities = [a for a in abilities if is_english(a.get('desc', ''))]
en_moves = [m for m in moves if is_english(m.get('desc', ''))]
en_items = [i for i in items if is_english(i.get('desc', ''))]

print(f"Total abilities in English: {len(en_abilities)} / {len(abilities)}")
print(f"Total moves in English: {len(en_moves)} / {len(moves)}")
print(f"Total items in English: {len(en_items)} / {len(items)}")

# Sample of first 5 English abilities
print("\nSample English Abilities:")
for a in en_abilities[:5]:
    print(f"  {a['id']}: {a['desc']}")

print("\nSample English Moves:")
for m in en_moves[:5]:
    print(f"  {m['id']}: {m['desc']}")

print("\nSample English Items:")
for it in en_items[:5]:
    print(f"  {it['id']}: {it['desc']}")
