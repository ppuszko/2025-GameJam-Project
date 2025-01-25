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

    Bubble bubble(16.f, 5, screenHeight, "../Assets/bubble_pop.png", bubblePos, 8, 6, 0, 0, 2);
    Fan fan(100, 60, 5, 3, "../Assets/fan.png", 10, 6);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        globalFrames++;
        //screenManager.drawModel();
        BeginDrawing();
        ClearBackground(WHITE);

        bubble.display(globalFrames);
        bubble.update(fan);
        //fan.animComponent->draw(globalFrames, 100, 700, 4);
        fan.update(screenWidth, globalFrames);
        EndDrawing();
    }
    CloseWindow();
}