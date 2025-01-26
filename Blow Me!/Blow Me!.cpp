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
        if (screenManager._getExitFlag())
        {
            CloseWindow();
            return 0;
        }
    }
    CloseWindow();
}