#ifndef SDL_COMPONENT_H 
#define SDL_COMPONENT_H 
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>	
#include "rect.h"


void print_debug(char* stringErrorMessages); 
int SDL_Initializer();
SDL_Window* SDL_Create_Window(char* Title, int width, int height);  
SDL_Renderer* SDL_Create_Renderer(SDL_Window* window); 
int SDL_Handle_Input(SDL_Event e, Game_Objcet* objcet); 
void SDL_Draw(SDL_Rect* rect, SDL_Renderer* renderer, int r, int g, int b);  
void SDL_Draw_Rect(int x, int y, int w, int h, SDL_Renderer* renderer);  
Game_Objcet SDL_Create_Objcet(int x, int y, int w, int h);  

#endif 
