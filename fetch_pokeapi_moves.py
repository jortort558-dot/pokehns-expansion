import urllib.request
import csv
import io
import json

print("Descargando moves.csv...")
url_moves = "https://raw.githubusercontent.com/PokeAPI/pokeapi/master/data/v2/csv/moves.csv"
req = urllib.request.Request(url_moves, headers={'User-Agent': 'Mozilla/5.0'})
content_moves = urllib.request.urlopen(req).read().decode('utf-8')

id_to_identifier = {}
reader = csv.DictReader(io.StringIO(content_moves))
for row in reader:
    # id, identifier
    id_to_identifier[int(row['id'])] = row['identifier']

print("Total moves identifier:", len(id_to_identifier))

print("Descargando move_names.csv...")
url_names = "https://raw.githubusercontent.com/PokeAPI/pokeapi/master/data/v2/csv/move_names.csv"
req = urllib.request.Request(url_names, headers={'User-Agent': 'Mozilla/5.0'})
content_names = urllib.request.urlopen(req).read().decode('utf-8')

# local_language_id = 7 (Spanish)
id_to_es_name = {}
reader = csv.DictReader(io.StringIO(content_names))
for row in reader:
    if row['local_language_id'] == '7': # Spanish
        id_to_es_name[int(row['move_id'])] = row['name']

print("Total Spanish names:", len(id_to_es_name))

# Comprobar Razor Leaf (id 75) y Leaf Blade (id 348)
print("Move 75 (razor-leaf):", id_to_identifier.get(75), "->", id_to_es_name.get(75))
print("Move 348 (leaf-blade):", id_to_identifier.get(348), "->", id_to_es_name.get(348))

with open('pokeapi_moves_clean.json', 'w', encoding='utf-8') as f:
    json.dump({
        'identifiers': id_to_identifier,
        'names_es': id_to_es_name
    }, f, ensure_ascii=False, indent=2)

print("Guardado en pokeapi_moves_clean.json")
