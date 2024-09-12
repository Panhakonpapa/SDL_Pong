#!/bin/bash

# Define package and paths
package="your_package_name"
package_manager="your_package_manager"
install_dependency="sudo $package_manager $package"

# Install dependencies
echo "Installing dependencies..."
$install_dependency

# Compiler and paths
CC="gcc"
LIB="Lib"
INCLUDE="Lib/Include"
EXTERNAL_LIB="-lSDL2 -lSDL2_ttf -lSDL2_mixer -lm"
OUTPUT="pong"
# Compile to object files
echo "Compiling source files..."
$CC -v -c -I$INCLUDE $LIB/game_lib.c -o game_lib.o 
$CC -v -c -I$INCLUDE $LIB/sdl_component.c -o sdl_component.o 
$CC -v -c -I$INCLUDE game.c -o game.o   

# Link object files
echo "Linking object files..."
$CC -v sdl_component.o game_lib.o game.o -o $OUTPUT $EXTERNAL_LIB 

echo "Build complete."

