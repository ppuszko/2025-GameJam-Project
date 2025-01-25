#include <iostream>

#include <raylib.h>

#include "Entity.hpp";



int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 800;


    //sprite sheet clipping logic part1. 
    int currentFrame{ 0 };
    int frameCounter{ 0 };
    int frameSpeed{ 4 };
    //
   

    Vector2 bubblePos{ 100.f, 100.f };
    Vector2 birdPos{ 500.f, 200.f };

    InitWindow(screenWidth, screenHeight, "Blow Me!");

    Texture2D duck = LoadTexture("../Assets/bird.png");

    Image img = LoadImage("../Assets/bird.png");
    ImageResize(&img, img.width * 2.5f, img.height * 2.5f);
    Texture2D duck2 = LoadTextureFromImage(img);

    Texture2D bubble = LoadTexture("../Assets/bubble.png");


    Entity bird(duck2, birdPos, 10, 7, 3, true);


    //source rectangle defining frame position on sprite sheet
    Rectangle frameRec = { 0.f, 0.f, bubble.width / 4, bubble.height };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {


        frameCounter++;

        if (frameCounter >= (60 / frameSpeed))
        {
            frameCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;
            frameRec.x = currentFrame * bubble.width / 4;
           
        }
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        DrawTextureRec(bubble, frameRec, bubblePos, WHITE);

        bird.shiftSpriteFrame();
        bird.display();
        bird.move();

        EndDrawing();

    }


}
