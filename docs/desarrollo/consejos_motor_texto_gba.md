# GUÍA DE DESARROLLO Y MOTOR DE TEXTO (GBA)

Este documento recopila buenas prácticas, restricciones del motor de Game Boy Advance y soluciones a problemas comunes de renderizado, desbordamiento y corte de textos.

---

## 1. Funcionamiento de la Caja de Diálogo en GBA

La caja de diálogo estándar en Pokémon de GBA tiene una resolución de 240x160 y admite **exactamente 2 líneas visibles al mismo tiempo**.

### Los 3 tipos de saltos de texto:
| Código | Función en el motor | Cuándo usarlo |
| :---: | :--- | :--- |
| **`\n`** | **Salto a la segunda línea**: Mueve el cursor de la línea superior a la inferior de la misma caja. | **Solo una vez** por párrafo (de línea 1 a línea 2). |
| **`\l`** | **Scroll hacia arriba (desplazamiento vertical)**: Desplaza la línea 2 a la posición 1 para escribir una nueva línea sin borrar la caja. | En la línea 3, línea 4, etc. de un mismo bloque continuo de conversación. |
| **`\p`** | **Nuevo párrafo con espera de botón 'A'**: Muestra la flecha roja parpadeante, espera que el jugador pulse 'A', limpia toda la caja y reinicia el cursor en la línea 1. | Para separar ideas o cuando la caja ya ha hecho varios scrolls y conviene limpiar. |
| **`$`** | **Terminador de cadena de ensamblador**: Marca el final exacto del texto en memoria binaria. | Obligatorio al final de todo `.string "..."` antes de la comilla de cierre. |

---

## 2. Errores Comunes que Rompen o Cortan Textos

### A. Uso incorrecto de `\n` en lugar de `\l` (Texto cortado o invisible)
* **El problema**: Si en un mismo bloque de texto se coloca un segundo `\n` mientras la caja ya está en la línea 2, el motor intenta renderizar en una **tercera línea inexistente** en lugar de desplazar la ventana. En emuladores o consola real, todo el texto posterior se vuelve invisible o desaparece.
* **Ejemplo erróneo (Bug de la chica de Growlithe en Ruta 36)**:
  ```assembly
  // INCORRECTO:
  .string "Vi a un POKéMON parecido a\n"
  .string "GROWLITHE, pero con un aura que\ndaba\l"  <-- ¡Se coló un \n antes de daba!
  .string "auténtico pavor.$"
  ```
* **Forma correcta**:
  ```assembly
  // CORRECTO:
  .string "Vi a un POKéMON parecido a\n"
  .string "GROWLITHE, pero con un aura que\l"
  .string "daba auténtico pavor.$"
  ```

### B. Desbordamiento horizontal (Más de 34-35 caracteres por línea)
* **El problema**: El motor de GBA **no tiene ajuste automático de línea** (*word wrap*).
* **Consecuencia**: Si una línea supera los **34 o 35 caracteres visuales**, los caracteres sobrantes se dibujan fuera del borde negro de la pantalla, dejando palabras mutiladas.
* **Regla de oro**: Mantener siempre un límite estricto de **32 a 34 caracteres** por línea.

### C. Variables y macros dinámicas (`{PLAYER}`, `{STR_VAR_1}`, etc.)
* Macros como `{PLAYER}` ocupan varios caracteres en tiempo de ejecución (ej. un nombre de 7 letras).
* Al redactar, reservar siempre mentalmente entre **5 y 7 caracteres visuales** para esas macros.

---

## 3. Plantilla Estándar para Redactar Diálogos

Para no fallar jamás en un script `.inc`, seguir siempre este patrón:

```assembly
NombreMapa_Text_Ejemplo:
    .string "1. Primera línea hasta 34 carac.\n"
    .string "2. Segunda línea del primer cuadro\l"
    .string "3. Tercera línea con scroll limpio.\p"
    .string "1. Nuevo párrafo esperando botón A\n"
    .string "2. Segunda línea del nuevo párrafo.$"
```

---

## 4. Checklist para Auditoría Rápida de Scripts
1. ¿Tiene como máximo un `\n` antes de cada `\p` o `$`?
2. ¿Todas las líneas siguientes dentro del mismo párrafo usan `\l`?
3. ¿Ninguna línea supera los 35 caracteres?
4. ¿Termina siempre con `$` antes de cerrar la comilla `"`?
5. ¿No hay saltos de línea físicos sin escapar dentro de las comillas?
