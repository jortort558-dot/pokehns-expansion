import json
import sys
sys.path.insert(0, '/mnt/y/heartandsoul_esp/pokehns-expansion')
import translate_phase1_desc as p1_desc

raw = json.load(open('/mnt/y/heartandsoul_esp/pokehns-expansion/raw_moves.json'))
descs = p1_desc.MOVE_DESCRIPTIONS

matches = 0
not_found = []
for m in raw:
    d = m['desc']
    if not d:
        continue
    if d in descs:
        matches += 1
    else:
        not_found.append(m)

print("Total raw moves with non-empty desc:", len([m for m in raw if m['desc']]))
print("Direct matches in MOVE_DESCRIPTIONS:", matches)
print("Unmatched:", len(not_found))

# Check RAZOR LEAF and LEAF BLADE specifically
for m in raw:
    if m['id'] in ('MOVE_RAZOR_LEAF', 'MOVE_LEAF_BLADE'):
        print(m['id'], "EN desc:", repr(m['desc']))
        print("In MOVE_DESCRIPTIONS?", m['desc'] in descs)
        if m['desc'] in descs:
            print("ES desc:", repr(descs[m['desc']]))
