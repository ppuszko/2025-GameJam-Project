#include <iostream>

#include <raylib.h>

#include "Entity.hpp"
#include "Bubble.hpp"

#define FPS 60

int main()
{
    static int64_t globalFrame = 0;
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Blow Me!");
    SetTargetFPS(FPS);

    Entity bird ("../Assets/bird.png", {800, 500}, 8,7,1,1,2.0f);
    Bubble bubble(100.f, 200.f, 16, 2.f, screenHeight,
        "../Assets/bubble_idle.png", { 100, 300 }, 8, 5, 0, 0, 1);




    while (!WindowShouldClose())
    {
        globalFrame++;

        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        bird.display(globalFrame);
        bird.move();
        bubble.display(globalFrame);

       
        EndDrawing();

    }


}
