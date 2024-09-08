#include "sdl_component.h"


void print_debug(char* stringErrorMessages)
{	
	printf("Error ->%s -> results output %s", stringErrorMessages, SDL_GetError()); 	
}

int SDL_Initializer() {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		print_debug("SDL INIT "); 
		return -1; 
	}
	return 0; 
}
SDL_Window* SDL_Create_Window(char* Title, int width, int height) {

	SDL_Window* window = SDL_CreateWindow(Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if (window == NULL) {
		print_debug("Is window ?"); 
	}
	return window; 
}
SDL_Renderer* SDL_Create_Renderer(SDL_Window* window) {	
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); 
	if (renderer == NULL) {
		print_debug("Renderer load ?"); 
		exit(0);
	}
	return renderer; 
}

#include "physic.h" 
int SDL_Handle_Input(SDL_Event e, Game_Objcet* objcet) {

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_KEYDOWN) {	
			   switch (e.key.keysym.sym) { 
				    case SDLK_q:
					    return 0; 
					    break;
				     case SDLK_d:
					    movement(objcet, DOWN , 10);  
					    break; 
		  	}
		}
		else if (e.type == SDL_QUIT) {
			return 0; 
		}
	} 
	    return 1; 
} 
void SDL_Draw_Rect(int x, int y, int w, int h, SDL_Renderer* renderer) {
	Game_Objcet obj = SDL_Create_Objcet(x, y, w, h);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);		
	SDL_RenderFillRect(renderer, &obj.sdl_rect);
}

Game_Objcet SDL_Create_Objcet(int x, int y, int w, int h) {
	Game_Objcet class_objcet; 
	class_objcet.sdl_rect.x = x; 
	class_objcet.sdl_rect.y = y; 
	class_objcet.sdl_rect.w = w; 
	class_objcet.sdl_rect.h = h; 	
	return class_objcet; 
}  




