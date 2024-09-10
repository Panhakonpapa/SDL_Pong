#include "sdl_component.h" 
#include <SDL2/SDL.h>
#define UP -1
#define DOWN 1 

void movement(Game_Objcet* move, int direction, int speed);  
void update_position(Game_Objcet* move,  float speed, float* angle);  
void update_score(Game_Objcet* move, int* p1, int* p2); 
bool Collision(Game_Objcet* rect1, Game_Objcet* rect2);  
