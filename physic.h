#include "sdl_component.h" 
#include "rect.h"

#define UP -1
#define DOWN 1 

void movement(Game_Objcet* move, int direction, int speed);  
void update_position(Game_Objcet* move,  float speed, float* angle);  
bool SDL_Collision(SDL_Rect* rect1, SDL_Rect* rect2);  
