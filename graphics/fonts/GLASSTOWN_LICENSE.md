# Glasstown NBP

La fuente `latin_glasstown.png` es una adaptación raster para Pokémon Heart & Soul de **Glasstown NBP**, creada por Nate Halley (Total FontGeek DTF, Ltd.) con FontStruct.

- Fuente original: `GlasstownNbpRegular-RyMM.ttf`
- Página de distribución: <https://www.fontspace.com/glasstown-nbp-font-f15300>
- Licencia: Creative Commons Attribution Share Alike 3.0 Unported (CC BY-SA 3.0)
- Licencia completa: <https://creativecommons.org/licenses/by-sa/3.0/>

Glasstown NBP está inspirada en la tipografía de *The Urbz: Sims in the City* para GBA/DS. La hoja raster adaptada conserva los símbolos internos del motor procedentes de la fuente normal del proyecto y se distribuye bajo la misma licencia CC BY-SA 3.0.

## Regeneración

Desde la raíz del proyecto:

```bash
python3 docs/utilidades/generar_fuente_ttf_gba.py \
  glasstown-nbp-font/GlasstownNbpRegular-RyMM.ttf \
  pokehns-expansion/graphics/fonts/latin_normal.png \
  pokehns-expansion/charmap.txt \
  pokehns-expansion/graphics/fonts/latin_glasstown.png \
  pokehns-expansion/graphics/fonts/glasstown.widths \
  --size 16 --baseline 14
```

En un script de evento, `special EnableGlasstownMessageBox` hace que el siguiente `msgbox` use esta fuente. El efecto se consume al mostrar ese cuadro y no altera los diálogos posteriores.
