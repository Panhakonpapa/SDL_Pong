#!/bin/bash 
EXTERN_TEST="sdl_component.c physic.c "
LIB="-lSDL2 -lm;"
CLEAN="rm test"
gcc -v test.c -o test $EXTERN_TEST $LIB
echo "running test"
./test
echo "<< Test Good >>"
$CLEAN


