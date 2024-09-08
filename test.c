#include <assert.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "sdl_component.h"
#include "physic.h"
// Test Initializer
void test_Initializer() {
    int result = Initializer();
    assert(result == 0 && "SDL initialization failed");
}

// Test Window Creation
void test_Create_Window() {
    SDL_Window* window = Create_Window("Test Window", 640, 480);
    assert(window != NULL && "Window creation failed");
    SDL_DestroyWindow(window);
}

// Test Renderer Creation
void test_Create_Renderer() {
    SDL_Window* window = Create_Window("Test Window", 640, 480);
    SDL_Renderer* renderer = Create_Renderer(window);
    assert(renderer != NULL && "Renderer creation failed");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

// Test Collision Detection
void test_SDL_Collision() {
    SDL_Rect rect1 = {0, 0, 50, 50};
    SDL_Rect rect2 = {25, 25, 50, 50};
    SDL_Rect rect3 = {100, 100, 50, 50};
    
    bool result1 = SDL_Collision(&rect1, &rect2);
    bool result2 = SDL_Collision(&rect1, &rect3);
    
    assert(result1 == true && "Collision detection failed (should collide)");
    assert(result2 == false && "Collision detection failed (should not collide)");
}
#include "physic.h"
/* It have pointer mod */
void test_movement() {
    Game_Objcet obj = create_objcet(10, 20, 30, 40); // Initial y = 20

    // Test moving up (negative direction)
    movement(&obj, -1, 5);
    assert(obj.sdl_rect.y == 15 && "Movement up failed");

    // Test moving down (positive direction)
    movement(&obj, 1, 10);
    assert(obj.sdl_rect.y == 25 && "Movement down failed");

    // Test no movement (direction = 0)
    movement(&obj, 0, 10);
    assert(obj.sdl_rect.y == 25 && "Movement with zero direction failed");
}

// Test Object Creation
void test_create_objcet() {
    Game_Objcet obj = create_objcet(10, 20, 30, 40);
    assert(obj.sdl_rect.x == 10 && obj.sdl_rect.y == 20);
    assert(obj.sdl_rect.w == 30 && obj.sdl_rect.h == 40);
}
#define WINDOW_H 900 
void test_update_position() {
    Game_Objcet obj = create_objcet(100, 100, 30, 40); // Initial position

    // Test moving the object with a positive angle
    float speed = 10.0f;
    update_position(&obj, speed);
    
    // Calculate expected values
    float angle = 45.0f * (M_PI / 180.f); // Convert angle to radians
    float expected_x_change = speed * cos(angle);
    float expected_y_change = speed * sin(angle);
    
    // Calculate expected new position
    int expected_x = 100 + (int)expected_x_change;
    int expected_y = 100 + (int)expected_y_change;
    
    assert(obj.sdl_rect.x == expected_x && "X position update failed");
    assert(obj.sdl_rect.y == expected_y && "Y position update failed");

    // Test boundary condition
    obj.sdl_rect.y = WINDOW_H - obj.sdl_rect.h; // Set near boundary
    update_position(&obj, speed);
    
    // Since angle is unchanged and speed is positive, angle should not change
    assert(obj.sdl_rect.y >= 0 && obj.sdl_rect.y + obj.sdl_rect.h <= WINDOW_H && "Boundary condition test failed");
    
    printf("All update_position tests passed!\n");
}
int main(int argc, char* argv[]) {
    // Initialize SDL before running any tests
    test_Initializer();
    
    // Run other tests
    test_Create_Window();
    printf("Test Passed \n"); 
    test_Create_Renderer();
    printf("Test Passed \n"); 
    test_SDL_Collision();
    printf("Test Passed \n"); 
    test_create_objcet(); 
    printf("Test Passed \n"); 
    test_movement();  
    printf("Test Passed \n"); 
    test_update_position(); 
    printf("All tests passed!\n");
    
    // Cleanup SDL after tests
    SDL_Quit();
    
    return 0;
}

