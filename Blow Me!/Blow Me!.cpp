#include <iostream>
#include <raylib.h>
#include "ScreenManager.hpp"

int main()
{
    ScreenManager screenManager;

    while (!WindowShouldClose())
    {
        globalFrame++;

        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        bird.display(globalFrame);
        bird.move();
        bubble.display(globalFrame);

       
        EndDrawing();

        screenManager.drawModel();
    }
    CloseWindow();
}
