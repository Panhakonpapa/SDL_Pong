#!/bin/bash 

CC="gcc"
EXTERN="sdl_component.c game_lib.c"
COMPILER_FLAGS="-lm"
LIB_SDL="-lSDL2 -lSDL2_ttf"
FILE="game.c"
OUTPUT="Linux.bin"
$CC -v $FILE -o $OUTPUT $EXTERN $COMPILER_FLAGS $LIB_SDL
