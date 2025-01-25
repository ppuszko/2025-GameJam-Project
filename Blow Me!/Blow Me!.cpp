#include <iostream>
#include <raylib.h>
#include "ScreenManager.hpp"

int main()
{
    ScreenManager screenManager;
    //Background background;

    //Vector2 bubblePos{ 100.f, 100.f };
    //Vector2 birdPos{ 500.f, 200.f };


    //Texture2D duck = LoadTexture("../Assets/bird.png");
    //Image img = LoadImage("../Assets/bird.png");
    //ImageResize(&img, img.width * 2.5f, img.height * 2.5f);
    //Texture2D duck2 = LoadTextureFromImage(img);
    //Texture2D bubble = LoadTexture("../Assets/bubble.png");
    //Entity bird(duck2, birdPos, 10, 7, 3, true);
    //Rectangle frameRec = { 0.f, 0.f, bubble.width / 4, bubble.height };

    while (!WindowShouldClose())
    {
        screenManager.drawModel();
        //background.updateScrolling();
        //background.drawBackground();

        //DrawTextureRec(bubble, frameRec, bubblePos, WHITE);
        //bird.shiftSpriteFrame();
        //bird.display();
        //bird.move();
    }
    CloseWindow();


}
