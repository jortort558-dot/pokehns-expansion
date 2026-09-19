from pathlib import Path

maps_dir = Path("data/maps")
map_jsons = []
for p in sorted(maps_dir.iterdir()):
    if p.is_dir() and (p / "map.json").is_file():
        map_jsons.append(f"data/maps/{p.name}/map.json")

content = "MAP_JSONS := \\\n  " + " \\\n  ".join(map_jsons) + "\n"
with open("data/maps/map_list.mk", "w") as f:
    f.write(content)

print(f"Generated data/maps/map_list.mk with {len(map_jsons)} maps.")
