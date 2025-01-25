#include <iostream>
#include <raylib.h>
#include "ScreenManager.hpp"

int main()
{
    ScreenManager screenManager;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        screenManager.drawModel();
    }
    CloseWindow();
}