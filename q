#include "game_lib.h"
#include "sdl_component.h" 

#define UNIX_FONT_PATH "/home/panha/build/PONG_MINI/class/SDL-Pong/fonts_ttf/8bitOperatorPlus-Bold.ttf" 
#define WINDOW_FONT_PATH "%USERPROFILE%\Desktop\SDL-Pong/fonts_ttf"

int main() {

	if (SDL_Initializer() < 0) {
		print_debug("sdl init faliure\n"); 
		exit(0); 
	}
	SDL_Window* window = SDL_Create_Window("Pong", 900, 600); 
	if (window != NULL) {
		printf("Loading window passed \n"); 
	}
	SDL_Renderer* renderer = SDL_Create_Renderer(window);
	if (window != NULL) {
		printf("Loading renderer passed \n"); 
	}	
	if (TTF_Init() == -1) {
		exit(0); 
	}
	TTF_Font* openFont = TTF_OpenFont(UNIX_FONT_PATH, 32);
	if (openFont == NULL) {
	        printf("Font can't load");
	}

	/* Main loop flag */
	int running = 1; 

	/* Main loop event */ 
	SDL_Event event;

	/* Game objcet */ 
	Game_Objcet player_1 = SDL_Create_Objcet(50, 200, 10, 200); 
	Game_Objcet player_2 = SDL_Create_Objcet(850, 200, 10, 200);
	Game_Objcet Ball = SDL_Create_Objcet(100, 100, 30, 30);  
	float angle = 45.f; 
	int p1_point = 0; 
	int p2_point = 0;

	while (running) {
		
		running = SDL_Handle_Input(event, &player_1, &player_2); 

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);	
		SDL_RenderClear(renderer);	

		/* Update function */	
		if (Collision(&player_1, &Ball) || Collision(&player_2, &Ball)) {
			angle = 180.f - angle; 
		}
			
		update_position(&Ball, 20.f, &angle); 	

		update_score(&Ball, &p1_point, &p2_point);		

		/* Draw ttf funciton */	
		SDL_Display_TTF(300, 10, 300, 100, openFont, renderer, &p1_point, &p2_point); 

		/* Draw funciton */
		SDL_Draw_Rect(player_1.sdl_rect.x, player_1.sdl_rect.y, player_1.sdl_rect.w, player_1.sdl_rect.h, renderer); 	
		SDL_Draw_Rect(player_2.sdl_rect.x, player_2.sdl_rect.y, player_2.sdl_rect.w, player_2.sdl_rect.h, renderer); 	
		SDL_Draw_Rect(Ball.sdl_rect.x, Ball.sdl_rect.y, Ball.sdl_rect.w, Ball.sdl_rect.h, renderer); 	


		SDL_RenderPresent(renderer);	
		SDL_Delay(16);
	}
	SDL_DestroyWindow(window); 
	SDL_DestroyRenderer(renderer); 
	TTF_Quit();
	TTF_CloseFont(openFont);
}
