#!/usr/bin/env bash
set -e

cd /mnt/y/heartandsoul_esp/pokehns-expansion

CC1=$(arm-none-eabi-gcc --print-prog-name=cc1)
LIBGCC=$(dirname $(arm-none-eabi-gcc -mthumb -print-file-name=libgcc.a))
LIBC=$(dirname $(arm-none-eabi-gcc -mthumb -print-file-name=libc.a))

FILES="${@:-src/pokemon.c}"

echo "========================================================"
echo "  COMPILACIÓN RÁPIDA HNS (Direct Toolchain)"
echo "========================================================"

for SRC in $FILES; do
    OBJ="build/hns/${SRC%.c}.o"
    echo "  [Compilando C] $SRC -> $OBJ"
    mkdir -p "$(dirname "$OBJ")"
    arm-none-eabi-cpp -iquote include -Wno-trigraphs -DMODERN=1 -DTESTING=0 -DPOKEMON_HNS -std=gnu17 "$SRC" | \
    tools/preproc/preproc -i "$SRC" charmap.txt | \
    "$CC1" -quiet -mthumb -mthumb-interwork -O2 -mabi=apcs-gnu -mtune=arm7tdmi -march=armv4t \
        -Wno-pointer-to-int-cast -std=gnu17 -Werror -Wall -Wno-strict-aliasing -Wno-attribute-alias -Woverride-init \
        -Wnonnull -Wenum-conversion -Wno-error=unused-variable -Wno-error=unused-const-variable \
        -Wno-error=unused-parameter -Wno-error=unused-function -Wno-error=unused-but-set-parameter \
        -Wno-error=unused-but-set-variable -Wno-error=unused-value -Wno-error=unused-local-typedefs \
        -Wno-error=override-init -o - - | \
    cat - <(printf ".text\n\t.align\t2, 0\n") | \
    arm-none-eabi-as -mcpu=arm7tdmi -march=armv4t -meabi=5 --defsym MODERN=1 --defsym POKEMON_HNS=1 -o "$OBJ" -
done

echo "  [Enlazando ELF] pokehns.elf..."
cd build/hns
LIB="-L $LIBGCC -L $LIBC -lc -lnosys -lgcc -L../../libagbsyscall -lagbsyscall"
OBJS=$(find . -name "*.o" ! -path "./test/*" | sort)

arm-none-eabi-ld -Map ../../pokehns.map --print-memory-usage --gc-sections -T ../../ld_script_modern.ld -o ../../pokehns.elf $OBJS $LIB
cd ../..
tools/gbafix/gbafix pokehns.elf -t"POKEMON HNS" -cBPEE -m01 -r0 --silent

echo "  [Creando ROM] pokehns.gba..."
arm-none-eabi-objcopy -O binary pokehns.elf pokehns.gba
tools/gbafix/gbafix pokehns.gba -p --silent

echo "========================================================"
echo "  [EXITO] ROM GENERADA: pokehns.gba"
echo "========================================================"
