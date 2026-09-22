# GUÍA: CÓMO GENERAR Y SACAR UNA ROM (.GBA)

Esta guía explica paso a paso cómo compilar, empaquetar, sincronizar y obtener una nueva versión funcional de la ROM (`.gba`) desde Windows y WSL.

---

## 1. Requisitos Previos

1. **Entorno WSL (Ubuntu)** con la toolchain de compilación ARM (`arm-none-eabi-gcc`, `make`, etc.) ya instalada en `/home/falan/pokehns-expansion`.
2. **Terminal de Windows** (PowerShell) abierta en `Y:\heartandsoul_esp`.
3. Tu emulador favorito (mGBA, VBA, etc.) para probar la ROM resultante.

---

## 2. Flujo Completo en 4 Pasos Sencillos

### Paso 1: Compilar la ROM en WSL
La compilación se realiza dentro de WSL porque Windows nativo no tiene las herramientas de compilación de Game Boy Advance.

Abre PowerShell en `Y:\heartandsoul_esp` y ejecuta:

```powershell
wsl -e bash -c "cd /home/falan/pokehns-expansion && make -j8"
```

> **¿Qué hace este comando?**
> Entra a Linux, compila en paralelo usando 8 hilos (`-j8`) todos los cambios que se hayan hecho en código C, ensamblador, scripts o gráficos, y genera el archivo binario final en `/home/falan/pokehns-expansion/pokehns.gba`.
> 
> *Si el comando termina sin errores (o con avisos menores de compilación), el archivo `.gba` está listo.*

---

### Paso 2: Registrar archivos nuevos en `sync_latest.ps1` (Solo si creaste/tocaste mapas nuevos)
Si has añadido mapas nuevos (`data/maps/.../scripts.inc`) o archivos nuevos de C/cabeceras (`.c`, `.h`):

1. Abre el archivo [sync_latest.ps1](file:///y:/heartandsoul_esp/sync_latest.ps1).
2. Asegúrate de que las rutas relativas de esos archivos nuevos estén incluidas dentro de la lista `$files = @(...)`.

*(Si solo has modificado archivos que ya estaban en el proyecto, puedes saltar directamente al Paso 3).*

---

### Paso 3: Sincronizar hacia Windows (y crear la release)
Ya no necesitas editar ningún archivo por dentro. Simplemente ejecuta el script pasándole el nombre de la versión con el parámetro `-Version`:

```powershell
powershell -ExecutionPolicy Bypass -File .\sync_latest.ps1 -Version "0.7.1-bloque6"
```

> **¿Qué hace este script?**
> 1. Copia todos los scripts y códigos modificados desde WSL hacia `Y:\heartandsoul_esp\pokehns-expansion\`.
> 2. Copia la ROM recién compilada a la raíz: `Y:\heartandsoul_esp\pokehns_fase1.gba` (para jugar al momento en tu emulador).
> 3. Si le pasas `-Version "0.7.1-bloque6"`, te crea automáticamente la release numerada:  
>    `releases/pokehns-0.7.1-bloque6-es.gba`.
> *(Si ejecutas `.\sync_latest.ps1` a secas sin `-Version`, actualizará `pokehns_fase1.gba` sin sobreescribir tus releases antiguas).*

---

### Paso 4: Probar la ROM
Abre en tu emulador de GBA cualquiera de las dos rutas:
- **Prueba directa**: `Y:\heartandsoul_esp\pokehns_fase1.gba`
- **Release versionada**: `Y:\heartandsoul_esp\releases\pokehns-<versión>-es.gba`

---

## 3. (Opcional pero Recomendado) Guardar Cambios en Git

Para que no queden diferencias entre lo que tienes en Linux y Windows, guarda el commit en ambos lados:

1. **Commit y subida en WSL (GitHub)**:
```powershell
wsl -e bash -c "cd /home/falan/pokehns-expansion && git add -A && git commit -m 'Release: nueva version de la ROM' && git push origin traduccion-es"
```

2. **Commit en el repositorio local de Windows**:
```powershell
git -C Y:\heartandsoul_esp\pokehns-expansion add -A
git -C Y:\heartandsoul_esp\pokehns-expansion commit -m "Sincronizar cambios y nueva ROM compilada"
```

---

## 4. Resumen Rápido (Cheat Sheet)

Cuando ya tengas experiencia, sacar una ROM se reduce a ejecutar solo **dos comandos** en PowerShell:

```powershell
# 1. Compilar en WSL
wsl -e bash -c "cd /home/falan/pokehns-expansion && make -j8"

# 2. Traer la ROM y archivos a Windows
powershell -ExecutionPolicy Bypass -File .\sync_latest.ps1
```
¡Y listo! Tu ROM actualizada ya estará en `pokehns_fase1.gba` y en `releases/`.
