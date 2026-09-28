# Guía para trabajar con IA usando menos tokens

Esta guía busca reducir contexto, tiempo y coste sin sacrificar calidad. La idea central es sencilla: cada tarea debe cargar únicamente la información que necesita.

## 1. Qué se ha configurado

El archivo `AGENTS.md` de la raíz contiene las instrucciones mínimas que una IA debe aplicar automáticamente. Se mantiene corto a propósito. Los detalles viven en `docs/` y se consultan solo cuando son relevantes.

No conviene copiar todo el estado del proyecto en `AGENTS.md`: ese contenido se enviaría una y otra vez en cada iteración. Tampoco conviene crear un agente por subsistema de forma permanente; coordinar agentes consume tokens y solo acelera trabajos independientes de suficiente tamaño.

## 2. Cómo formular una petición eficiente

Una petición ideal incluye cinco datos breves:

1. Objetivo observable.
2. Alcance o rutas permitidas.
3. Criterio de aceptación.
4. Validación deseada.
5. Límites explícitos, si los hay.

Ejemplo:

> Traduce los diálogos de `data/maps/Route45_hns/scripts.inc`. Conserva el tono existente, ninguna línea visible debe superar 35 caracteres y no cambies otros mapas. Ejecuta la validación de strings pertinente, pero no compiles la ROM completa.

Esto suele ser más eficiente que pedir “continúa con la traducción”, porque evita que la IA tenga que leer el roadmap, decidir el alcance y averiguar qué significa terminado.

## 3. Contexto progresivo

Usar este orden:

1. Buscar nombres, símbolos o frases con `rg`.
2. Abrir solo los fragmentos coincidentes y su contexto inmediato.
3. Leer el archivo completo únicamente si la estructura lo exige.
4. Consultar una guía temática concreta.
5. Compilar o analizar artefactos grandes al final.

Ejemplos de búsquedas focalizadas:

```powershell
rg -n "Route45|Ruta 45" docs pokehns-expansion/data/maps
rg -n "NuzlockeDeleteFaintedPartyPokemon" pokehns-expansion/src pokehns-expansion/include
rg -n --glob "*.inc" '\.string' pokehns-expansion/data/maps/Route45_hns
```

Para lotes de diálogos puede ejecutarse el auditor reutilizable sin cargar los
archivos completos en el contexto:

```powershell
powershell -ExecutionPolicy Bypass -File docs/utilidades/auditar_textos_gba.ps1 `
  pokehns-expansion/data/maps/Route45_hns
```

Comprueba segmentos de más de 35 caracteres, más de un `\n` por párrafo y
palabras inglesas frecuentes que requieren revisión manual.

Evitar como primer paso búsquedas globales sin filtro, abrir informes enteros o enumerar miles de archivos.

## 4. Documentación por capas

| Necesidad | Documento |
|---|---|
| Orientación mínima de la IA | `AGENTS.md` |
| Rendimiento y forma de trabajo | Este documento |
| Estado de traducción | `docs/traduccion/TRADUCCION_HNS.md` |
| Incidencias y releases | `docs/desarrollo/bugs.md` |
| Restricciones del motor de texto | `docs/desarrollo/consejos_motor_texto_gba.md` |
| Ideas no implementadas | `docs/mejoras_futuras/` |
| Contexto histórico amplio | `docs/desarrollo/INFORME_PROYECTO_IA.md` |

Los documentos de seguimiento deben enlazar al detalle en vez de duplicarlo. Una decisión estable pertenece a una guía; un estado cambiante pertenece al roadmap o al registro de bugs.

## 5. Validación escalonada

Aplicar la prueba más barata que pueda detectar el error esperado:

1. Revisar el diff del archivo tocado.
2. Ejecutar una búsqueda o comprobador específico.
3. Compilar solo el componente afectado si existe una vía fiable.
4. Hacer una compilación incremental completa para cambios integrados.
5. Hacer una compilación limpia o prueba en emulador solo para releases, cambios de build o fallos difíciles de aislar.

Pedir siempre una compilación completa para cambios de documentación o búsquedas exploratorias desperdicia tiempo y contexto de salida. En cambio, cambios de C, ensamblador, scripts o recursos que llegarán a una ROM sí deberían terminar con una build incremental antes de darse por concluidos.

La salida de compilación debe resumirse: éxito o fallo y primeras líneas útiles del error. No es necesario devolver cientos de líneas correctas al contexto conversacional.

## 6. Uso razonable de agentes paralelos

Usarlos cuando haya dos o más bloques independientes, por ejemplo:

- auditar mapas diferentes sin editar los mismos archivos;
- investigar por separado lógica, textos y pruebas de una funcionalidad amplia;
- comparar dos implementaciones sin dependencia mutua.

No usarlos para:

- editar uno o dos archivos;
- una investigación que depende del resultado del paso anterior;
- compilar mientras aún se está decidiendo qué cambiar;
- tareas donde varios agentes puedan tocar el mismo archivo.

Cada encargo a un agente debe indicar rutas, resultado esperado y prohibiciones. El agente principal debe integrar conclusiones, no pegar informes completos.

## 7. Higiene del repositorio

- Mantener fuera del contexto normal `build/`, ROM, ELF, mapas de enlazado, capturas y grandes ficheros de datos.
- No generar nuevos informes de sesión si la información cabe como actualización breve en un documento existente.
- No guardar transcripciones o cadenas de razonamiento.
- Actualizar la documentación solo cuando cambie una decisión, el flujo de trabajo o el estado de una tarea.
- Tratar `INFORME_PROYECTO_IA.md` como material histórico hasta actualizar sus rutas del antiguo NAS.

## 8. Plantillas de petición

### Corrección concreta

> Corrige [problema] en [ruta/s]. Terminado significa [resultado]. No cambies [límites]. Valida con [prueba] y resume solo archivos y resultado.

### Investigación sin cambios

> Diagnostica [problema]. Busca primero en [rutas]. No edites archivos. Devuelve causa probable, evidencia con rutas/líneas y la corrección mínima recomendada.

### Lote de traducción

> Traduce [mapas/rango]. Sigue `consejos_motor_texto_gba.md` y el tono de los mapas vecinos. Conserva macros y terminadores. Audita inglés residual y líneas visibles; no compiles hasta completar el lote.

### Implementación amplia

> Implementa [función]. Antes de editar, identifica puntos de entrada y propón un plan breve. Divide en paralelo solo investigaciones independientes. Termina con pruebas focalizadas, build incremental y documentación únicamente si cambia el comportamiento o el flujo.

## 9. Señales para abrir una conversación nueva

Conviene empezar una conversación nueva cuando cambia por completo el objetivo, cuando la conversación anterior acumuló grandes logs o cuando comienza una fase distinta del proyecto. En la nueva petición basta enlazar las rutas relevantes y describir el estado actual; no hace falta pegar informes enteros.

Dentro de una misma tarea, continuar en el mismo hilo preserva decisiones útiles y evita repetir contexto.
