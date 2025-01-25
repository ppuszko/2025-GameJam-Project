#include <iostream>

#include <raylib.h>

#include "Entity.hpp";

#define FPS 60

int main()
{
    static int64_t globalFrame = 0;
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Blow Me!");
    SetTargetFPS(FPS);

    Entity bird ("../Assets/bubble_pop.png", {800, 500}, 8,6,1,0,2.0f);



    while (!WindowShouldClose())
    {
        globalFrame++;

        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        bird.display(globalFrame);
        bird.move();
  

       
        EndDrawing();

    }


}
