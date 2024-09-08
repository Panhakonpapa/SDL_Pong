#include "rect.h" 
#include "physic.h"
#include "sdl_component.h" 
#include "SDL2/SDL_ttf.h" 

extern void print_debug(char* stringErrorMessages); 
extern int SDL_Initializer();
extern SDL_Window* SDL_Create_Window(char* Title, int width, int height);  
extern SDL_Renderer* SDL_Create_Renderer(SDL_Window* window); 
extern int SDL_Handle_Input(SDL_Event e, Game_Objcet* objcet); 
extern void SDL_Draw(SDL_Rect* rect, SDL_Renderer* renderer, int r, int g, int b);  
extern void SDL_Draw_Rect(int x, int y, int w, int h, SDL_Renderer* renderer);  
extern Game_Objcet SDL_Create_Objcet(int x, int y, int w, int h);  

int main() {
	if (SDL_Initializer() < 0) 
	{
		print_debug("sdl init faliure\n"); 
		exit(0); 
	}
	SDL_Window* window = SDL_Create_Window("Pong", 900, 600); 
	if (window != NULL)
	{
		printf("Loading window passed \n"); 
	}
	SDL_Renderer* renderer = SDL_Create_Renderer(window);

	if (window != NULL)
	{
		printf("Loading renderer passed \n"); 
	}
			
	if (TTF_Init() == -1) 	
	{
		exit(0); 
	}
	TTF_Font* openFont = TTF_OpenFont("/home/panha/build/PONG_MINI/class/fonts_ttf/8bitOperatorPlus-Bold.ttf", 32);
	if (openFont == NULL)
	{
		printf("Font can't load");
	}
  	SDL_Color textColor = {255, 255, 255, 255}; 
     	SDL_Surface* surfaceText = TTF_RenderText_Solid(openFont,"1        0", textColor);
	SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer,surfaceText);
  	SDL_FreeSurface(surfaceText); 
	SDL_Rect rectangle;
	    rectangle.x = 300;
	    rectangle.y = 10;
	    rectangle.w = 300;
	    rectangle.h = 100;
	/* Main loop flag */
	int running = 1; 

	/* Main loop event */ 
	SDL_Event event;

	/* Game objcet */ 
	Game_Objcet player_1 = SDL_Create_Objcet(50, 200, 10, 200);
	Game_Objcet player_2 = SDL_Create_Objcet(850, 200, 10, 200);
	Game_Objcet Ball = SDL_Create_Objcet(100, 100, 30, 30);  
	float angle = 45.f; 

	while (running) {
		
		running = SDL_Handle_Input(event, &player_1); 

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);	
		SDL_RenderClear(renderer);	
			
		/* Update function */	
		update_position(&Ball, 20.f, &angle); 
		
		/* Draw ttf funciton */
 		SDL_RenderCopy(renderer ,textureText, NULL, &rectangle);

		/* Draw funciton */
		SDL_Draw_Rect(player_1.sdl_rect.x, player_1.sdl_rect.y, player_1.sdl_rect.w, player_1.sdl_rect.h, renderer); 	
		SDL_Draw_Rect(player_2.sdl_rect.x, player_2.sdl_rect.y, player_2.sdl_rect.w, player_2.sdl_rect.h, renderer); 	
		SDL_Draw_Rect(Ball.sdl_rect.x, Ball.sdl_rect.y, Ball.sdl_rect.w, Ball.sdl_rect.h, renderer); 	

		SDL_RenderPresent(renderer);	
		SDL_Delay(100);
	}
	SDL_DestroyWindow(window); 
	SDL_DestroyRenderer(renderer); 
}
