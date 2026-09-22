# Instrucciones de trabajo para IA

## Contexto mínimo

- El código está en `pokehns-expansion/` y la documentación del proyecto en `docs/`.
- La copia de trabajo principal es local: `D:\PROYECTOS\heartandsoul_esp`.
- En WSL, la ruta local equivalente es `/mnt/d/PROYECTOS/heartandsoul_esp`; compilar directamente desde ella y no sincronizar con `Y:\`.
- No asumir que las rutas históricas `Y:\` o el flujo NAS/WSL descrito en documentos antiguos siguen vigentes.
- Leer primero solo este archivo y los ficheros directamente relacionados con la petición.
- Consultar `docs/desarrollo/GUIA_IA_EFICIENTE.md` únicamente cuando haga falta orientación de flujo, contexto o validación.

## Forma de trabajar

- Buscar con `rg` antes de abrir archivos completos; limitar resultados por ruta, extensión y patrón.
- No cargar ROM, binarios, imágenes, artefactos de compilación ni JSON grandes salvo que la tarea lo requiera.
- No releer documentos completos si basta una sección o coincidencias concretas.
- Antes de editar, comprobar el estado del archivo y preservar cambios ajenos.
- Hacer cambios pequeños y focalizados. Evitar refactorizaciones no solicitadas.
- Validar primero con la comprobación más estrecha aplicable; compilar la ROM completa solo cuando aporte evidencia necesaria.
- Para lotes de diálogos, usar `docs/utilidades/auditar_textos_gba.ps1` antes de compilar.
- No crear subagentes para tareas pequeñas o secuenciales. Usarlos solo si el trabajo puede dividirse en bloques independientes con un resultado claro.
- En la entrega, resumir resultado, archivos modificados y validación; no narrar cada comando ejecutado.
- Al terminar un lote de código o traducción: crear commit, subirlo a `origin/traduccion-es`, ejecutar `wsl.exe -e bash -lc 'cd /mnt/d/PROYECTOS/heartandsoul_esp/pokehns-expansion && make hns -j8'` y publicar la ROM resultante tanto en `pokehns_fase1.gba` como en `releases/pokehns-<versión>-<fecha>-<hito>-es.gba`.
- No inspeccionar pasos adicionales después de la build salvo que falle. Los cambios exclusivamente documentales no requieren recompilar.

## Fuentes de verdad bajo demanda

- Estado y alcance de traducción: `docs/traduccion/TRADUCCION_HNS.md`.
- Bugs y versiones: `docs/desarrollo/bugs.md`.
- Reglas de texto GBA: `docs/desarrollo/consejos_motor_texto_gba.md`.
- Mejoras futuras: `docs/mejoras_futuras/`.
- Guía histórica de relevo: `docs/desarrollo/INFORME_PROYECTO_IA.md` (puede contener rutas o estados obsoletos; contrastar con el árbol actual).

## Reglas críticas de textos

- Al editar diálogos, respetar el formato de strings y el límite visual descrito en `docs/desarrollo/consejos_motor_texto_gba.md`.
- Conservar terminología y tono ya establecidos; revisar textos vecinos antes de traducir.
- No modificar archivos generados o artefactos (`build/`, `*.gba`, `*.elf`, `*.map`) salvo petición expresa.
