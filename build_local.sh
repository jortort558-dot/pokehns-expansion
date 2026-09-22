#!/usr/bin/env bash
# build_local.sh - Sincroniza NAS -> local WSL y compila
# Uso: wsl bash /mnt/y/heartandsoul_esp/build_local.sh
set -e

NAS_DIR="/mnt/y/heartandsoul_esp/pokehns-expansion"
LOCAL_DIR="$HOME/pokehns-expansion"

echo "========================================================"
echo "  BUILD LOCAL HNS (NAS -> WSL local -> ROM)"
echo "========================================================"

# 1. Sync NAS -> local (solo archivos nuevos/modificados, excluye build/)
echo ""
echo "[1/3] Sincronizando cambios NAS -> local..."
rsync -a --update \
  --exclude='build/' \
  --exclude='.git/' \
  --exclude='*.gba' \
  "$NAS_DIR/" "$LOCAL_DIR/"
echo "      OK"

# 2. Compilar en local (filesystem nativo, sin overhead SMB)
echo ""
echo "[2/3] Compilando..."
cd "$LOCAL_DIR"
time make modern -j$(nproc)

# 3. Copiar ROM al NAS
echo ""
echo "[3/3] Copiando ROM al NAS..."
GBA_FILE=$(find "$LOCAL_DIR" -maxdepth 3 -name "*.gba" 2>/dev/null | head -1)
if [ -n "$GBA_FILE" ]; then
  cp "$GBA_FILE" "$NAS_DIR/"
  echo "      ROM -> $NAS_DIR/$(basename $GBA_FILE)"
else
  echo "      AVISO: No se encontro .gba"
fi

echo ""
echo "========================================================"
echo "  LISTO"
echo "========================================================"
