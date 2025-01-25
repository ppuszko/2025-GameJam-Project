#include <iostream>
#include <raylib.h>
#include "ScreenManager.hpp"

int main()
{
    ScreenManager screenManager;

    while (!WindowShouldClose())
    {
        screenManager.drawModel();
    }
    CloseWindow();
}
