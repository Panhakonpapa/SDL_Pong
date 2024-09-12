#include "Include/sdl_component.h"
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

void SDL_Display_TTF(int x, int y, int w, int h, TTF_Font* openFont, SDL_Renderer* renderer, int* p1, int* p2) {
	SDL_Rect rectangle; 
	    rectangle.x = x;
	    rectangle.y = y;  
	    rectangle.w = w;
	    rectangle.h = h;

	char score[20];
	sprintf(score, "%d      %d", *p1, *p2); 
	SDL_Color textColor = {255, 255, 255, 255}; 
	SDL_Surface* surfaceText = TTF_RenderText_Solid(openFont, score , textColor);
	SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer,surfaceText);
	SDL_FreeSurface(surfaceText);  
	SDL_RenderCopy(renderer ,textureText, NULL, &rectangle);
	
}
#include "game_lib.h" 
int SDL_Handle_Input(SDL_Event e, Game_Objcet* objcet1, Game_Objcet* objcet2) {

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_KEYDOWN) {	
			   switch (e.key.keysym.sym) { 
				    case SDLK_q:
					    return 0; 
					    break;
				     case SDLK_w:
					    movement(objcet1, -1 , 100);  
					    break; 

				     case SDLK_s:
					    movement(objcet1, 1 ,100);  
					    break; 
				
				     case SDLK_i:
					    movement(objcet2, -1 , 100);  
					    break; 

				     case SDLK_k:
					    movement(objcet2, 1 ,100);  
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




