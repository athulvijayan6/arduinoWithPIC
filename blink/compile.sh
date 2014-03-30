#!/bin/bash
filename="main"   # without extension eg. main
cpu="24F16KA102"
gldPath="/opt/microchip/xc16/v1.21/support/PIC24F/gld/p24F16KA102.gld"
xc16-gcc $filename.c $PWD/libraries/library.h $PWD/libraries/library.c -std=c99 -mcpu=$cpu -Wl,--script=$gldPath -o $filename.elf
xc16-bin2hex $filename.elf
