# build_es.ps1 - Compilar ROM y guardar snapshot versionado en Y:\
# Uso: .\build_es.ps1
# Opcion: .\build_es.ps1 -Version 0.3.0

param(
    [string]$Version = "0.2.0",
    [switch]$Clean   = $false
)

$ErrorActionPreference = "Stop"

$WSL_REPO  = "/home/falan/pokehns-expansion"
$WSL_GBA   = "\\wsl$\Ubuntu\home\falan\pokehns-expansion\pokehns.gba"
$DEST_DIR  = "Y:\heartandsoul_esp\releases"

Write-Host ""
Write-Host "================================================" -ForegroundColor Cyan
Write-Host "  Pokemon HnS - Build traduccion ES  v$Version" -ForegroundColor Cyan
Write-Host "================================================" -ForegroundColor Cyan
Write-Host ""

# 1. Sincronizar WSL con GitHub (por si se editó desde Windows)
Write-Host "[1/4] Sincronizando WSL con origin..." -ForegroundColor Yellow
wsl bash -c "cd $WSL_REPO && git pull origin traduccion-es --ff-only 2>&1 || echo 'Ya al dia o sin cambios remotos'"

# 2. Compilar
if ($Clean) {
    Write-Host "[2/4] make clean + make -j8 ..." -ForegroundColor Yellow
    wsl bash -c "cd $WSL_REPO && make clean && make -j8 2>&1"
} else {
    Write-Host "[2/4] make -j8 (incremental) ..." -ForegroundColor Yellow
    wsl bash -c "cd $WSL_REPO && make -j8 2>&1"
}

if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR: La compilacion fallo. Revisa los errores arriba." -ForegroundColor Red
    exit 1
}

# 3. Nombre versionado
$hash = (wsl bash -c "cd $WSL_REPO && git rev-parse --short HEAD 2>/dev/null").Trim()
$date = Get-Date -Format "yyyyMMdd"
$filename = "pokehns-$Version-$date-$hash-es.gba"

# 4. Copiar a Y:\
Write-Host "[3/4] Copiando a $DEST_DIR ..." -ForegroundColor Yellow
New-Item -ItemType Directory -Force -Path $DEST_DIR | Out-Null

if (-not (Test-Path $WSL_GBA)) {
    Write-Host "ERROR: No se encuentra el .gba en $WSL_GBA" -ForegroundColor Red
    exit 1
}

Copy-Item -Path $WSL_GBA -Destination "$DEST_DIR\$filename" -Force

Write-Host ""
Write-Host "================================================" -ForegroundColor Green
Write-Host "  ROM guardada:" -ForegroundColor Green
Write-Host "  $DEST_DIR\$filename" -ForegroundColor White
Write-Host "================================================" -ForegroundColor Green
Write-Host ""
