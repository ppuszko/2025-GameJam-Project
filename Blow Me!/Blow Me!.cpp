#include <iostream>
#include <raylib.h>
#include "ScreenManager.hpp"

int main()
{
    ScreenManager screenManager;
    InitAudioDevice();
    Music music = LoadMusicStream("../Assets/music/muzyka5.mp3");
    music.looping = true;
    PlayMusicStream(music);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        screenManager.drawModel();
        if (screenManager._getExitFlag())
        {
            CloseWindow();
            return 0;
        }
    }
    CloseWindow();
}
