#include "Lib/Include/game_lib.h"
#include "Lib/Include/sdl_component.h" 
#include <SDL2/SDL_mixer.h>

void play_sound(char *file) {
    Mix_Chunk *soundEffect = Mix_LoadWAV(file);
    
    if (soundEffect == NULL) {
        printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    Mix_PlayChannel(-1, soundEffect, 0);

    //Mix_FreeChunk(soundEffect);
}
int main() {
	/* Initialize the game */	
	if (SDL_Initializer() < 0) {
		print_debug("sdl init faliure\n"); 
		exit(EXIT_FAILURE); 
	}

	if (TTF_Init()) {
		printf("TTF Creation Faliure\n"); 
		exit(EXIT_FAILURE); 
	}
	 if (SDL_Init(SDL_INIT_AUDIO) < 0) {	
		exit(EXIT_FAILURE); 
	 }
	    
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		exit(EXIT_FAILURE); 
	}

	/* Create Window */
	SDL_Window* window = SDL_Create_Window("Pong", 900, 600); 
	if (!window) {
		printf("Window Creation Faliure\n"); 
		exit(EXIT_FAILURE); 
	}
	/* Create Renderer */
	SDL_Renderer* renderer = SDL_Create_Renderer(window);
	if (!renderer) {
		printf("Renderer Creation Faliure\n"); 
		exit(EXIT_FAILURE); 
	}
	/* Open ttf fonts */
	TTF_Font* openFont = TTF_OpenFont("~/SDL-Pong/fonts_ttf/8bitOperatorPlus-Bold.ttf", 32);
	if (!openFont) {
	        printf("Font can't load\n");	
		exit(EXIT_FAILURE); 
	}

	/* Main loop flag */
	int running = 1; 

	/* Main loop event */ 
	SDL_Event event;

	/* Game objcet */ 
	Game_Objcet player_1 = SDL_Create_Objcet(50, 200, 10, 200); 
	Game_Objcet player_2 = SDL_Create_Objcet(850, 200, 10, 200);
	Game_Objcet Ball     = SDL_Create_Objcet(100, 100, 30, 30);  

	float angle = 45.f; 
	int p1_point = 0; 
	int p2_point = 0;

	while (running) {
		
		/* get event input */
		running = SDL_Handle_Input(event, &player_1, &player_2); 

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);	
		SDL_RenderClear(renderer);	

		/* Collsion detection */	
		if (Collision(&player_1, &Ball) || Collision(&player_2, &Ball)) {
			play_sound("~/SDL-Pong/sound/8-bit-game-2-186976.wav"); 
			angle = 180.f - angle; 
		}
		/* Update function */	
		update_position(&Ball, 20.f, &angle); 	
		update_score(&Ball, &p1_point, &p2_point);		

		/* Render ttf on the screen */	
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
	Mix_CloseAudio();
}
