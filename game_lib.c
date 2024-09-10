#include "game_lib.h"
#include <math.h>

#define WINDOW_W 600 
#define WINDOW_H 900 

void movement(Game_Objcet* move, int direction, int speed) {
	move->sdl_rect.y += speed * direction; 

	if (move->sdl_rect.y <= 0) {
		move->sdl_rect.y = 0; 	
	}	

	if (move->sdl_rect.y + move->sdl_rect.h >= WINDOW_W) {
		move->sdl_rect.y = WINDOW_W - move->sdl_rect.h;  	
	}	
}

bool Collision(Game_Objcet* rect1, Game_Objcet* rect2) {
	return (rect1->sdl_rect.x < rect2->sdl_rect.x + rect2->sdl_rect.w &&
		rect1->sdl_rect.x + rect1->sdl_rect.w > rect2->sdl_rect.x &&
		rect1->sdl_rect.y < rect2->sdl_rect.y + rect2->sdl_rect.h &&
		rect1->sdl_rect.y + rect1->sdl_rect.h > rect2->sdl_rect.y); 
}
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
		*angle = 180.f - *(angle); 
	}
	
	
}
void update_score(Game_Objcet* move, int* p1, int* p2)
{
			
	if (move->sdl_rect.x <= 0) {
		*p2 += 1;
	}
	if (move->sdl_rect.x + move->sdl_rect.w >= WINDOW_H)
	{
		*p1 += 1; 
	}
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
