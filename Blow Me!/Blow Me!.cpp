#include <iostream>
#include <raylib.h>
#include "ScreenManager.hpp"
#include "Bubble.hpp"

int main()
{
    //ScreenManager screenManager;
   
    int screenHeight = 800;
    int screenWidth = 1200;

    InitWindow(screenWidth, screenHeight, "dupa");
    Vector2 bubblePos{ 100, screenHeight / 2 };
    int64_t globalFrames = 0;

    Bubble bubble(16.f, 0, screenHeight, "../Assets/bubble_pop.png", bubblePos, 8, 6, 0, 0);

    Animation anim1("../Assets/bubble_pop.png", 6, 8);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        globalFrames++;
       // screenManager.drawModel();
        BeginDrawing();
        bubble.display(globalFrames);
        anim1.draw(globalFrames, 500, 100, 1.f);
        EndDrawing();
    }
    CloseWindow();
}