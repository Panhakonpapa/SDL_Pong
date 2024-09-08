#include "physic.h"
#include <math.h>
void movement(Game_Objcet* move, int direction, int speed) {
	move->sdl_rect.y += speed * direction; 
}

#define WINDOW_W 600 
#define WINDOW_H 900 

void update_position(Game_Objcet* move,  float speed, float* angle) {


	float new_x = speed * cos(*(angle) * (M_PI / 180.f));  
	float new_y = speed * sin(*(angle) * (M_PI / 180.f));  

	move->sdl_rect.x += (int)new_x;  
	move->sdl_rect.y += (int)new_y;   

	if (move->sdl_rect.y <= 0 || move->sdl_rect.y + move->sdl_rect.h >= WINDOW_W) {
		printf("pong hit window");
		*angle = -(*angle); 
	}
	

	if (move->sdl_rect.x <= 0 || move->sdl_rect.x + move->sdl_rect.w >= WINDOW_H) {
		printf("pong hit window");
		*angle = 180.f - (*angle); 
	}
	
}

bool SDL_Collision(SDL_Rect* rect1, SDL_Rect* rect2) {
	return (rect1->x < rect2->x + rect2->w &&
		rect1->x + rect1->w > rect2->x &&
		rect1->y < rect2->y + rect2->h &&
		rect1->y + rect1->h > rect2->y); 
}

/*	if (distances <= CONSTENDIS) {
		if (y2 > 0) {
			y1 += static_cast<int>(round((y2 - y1) * speeds / distances));		
		}	
		if (y2 < 0) {	
			y1 -= static_cast<int>(round((y2 - y1) * speeds / distances));		
		}
	}
*/
