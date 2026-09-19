import urllib.request
import csv
import io
import json

def fetch():
    print("Downloading moves.csv...")
    moves_url = 'https://raw.githubusercontent.com/PokeAPI/pokeapi/master/data/v2/csv/moves.csv'
    req = urllib.request.Request(moves_url, headers={'User-Agent': 'Mozilla/5.0'})
    content = urllib.request.urlopen(req).read().decode('utf-8')
    moves = {int(r['id']): r['identifier'] for r in csv.DictReader(io.StringIO(content))}

    print("Downloading move_names.csv...")
    names_url = 'https://raw.githubusercontent.com/PokeAPI/pokeapi/master/data/v2/csv/move_names.csv'
    req = urllib.request.Request(names_url, headers={'User-Agent': 'Mozilla/5.0'})
    content = urllib.request.urlopen(req).read().decode('utf-8')
    names_es = {int(r['move_id']): r['name'] for r in csv.DictReader(io.StringIO(content)) if r['local_language_id'] == '7'}

    print("Total moves:", len(moves), "Total ES names:", len(names_es))

    print("Downloading move_flavor_text.csv...")
    flavor_url = 'https://raw.githubusercontent.com/PokeAPI/pokeapi/master/data/v2/csv/move_flavor_text.csv'
    req = urllib.request.Request(flavor_url, headers={'User-Agent': 'Mozilla/5.0'})
    content = urllib.request.urlopen(req).read().decode('utf-8')
    flavor_es = {}
    for r in csv.DictReader(io.StringIO(content)):
        if r['language_id'] == '7':
            mid = int(r['move_id'])
            vg = int(r['version_group_id'])
            # prefer Gen 4 (HGSS=10 or Platinum=9) or Gen 3 (Emerald=6, FRLG=5)
            # if not present, take latest
            curr = flavor_es.get(mid)
            if curr is None:
                flavor_es[mid] = {'vg': vg, 'text': r['flavor_text']}
            else:
                # Prefer HGSS (vg==10) if possible
                if curr['vg'] != 10 and vg == 10:
                    flavor_es[mid] = {'vg': vg, 'text': r['flavor_text']}
                elif curr['vg'] < 10 and vg > curr['vg']:
                    flavor_es[mid] = {'vg': vg, 'text': r['flavor_text']}
                elif curr['vg'] > 10 and vg > curr['vg']:
                    flavor_es[mid] = {'vg': vg, 'text': r['flavor_text']}

    print("Total moves with ES flavor:", len(flavor_es))
    with open('/home/falan/pokehns-expansion/pokeapi_moves_all.json', 'w', encoding='utf-8') as f:
        json.dump({'identifiers': moves, 'names_es': names_es, 'flavor_es': flavor_es}, f, ensure_ascii=False, indent=2)
    print("Saved /home/falan/pokehns-expansion/pokeapi_moves_all.json successfully!")

if __name__ == '__main__':
    fetch()
