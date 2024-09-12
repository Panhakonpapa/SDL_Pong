#ifndef SDL_COMPONENT_H 
#define SDL_COMPONENT_H 
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>	

typedef struct {
	SDL_Rect sdl_rect; 
} Game_Objcet; 


void print_debug(char* stringErrorMessages); 
int SDL_Initializer();
SDL_Window* SDL_Create_Window(char* Title, int width, int height);  
SDL_Renderer* SDL_Create_Renderer(SDL_Window* window); 
int SDL_Handle_Input(SDL_Event e, Game_Objcet* objcet1, Game_Objcet* objcet2); 
void SDL_Draw(SDL_Rect* rect, SDL_Renderer* renderer, int r, int g, int b);  
void SDL_Draw_Rect(int x, int y, int w, int h, SDL_Renderer* renderer);  
void SDL_Display_TTF(int x, int y, int w, int h, TTF_Font* openFont, SDL_Renderer* renderer, int* p1, int* p2);  
Game_Objcet SDL_Create_Objcet(int x, int y, int w, int h);  

#endif 
