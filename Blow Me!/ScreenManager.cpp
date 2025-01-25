#include "ScreenManager.hpp"

ScreenManager::ScreenManager()
{
    _initWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
}

ScreenManager::~ScreenManager()
{
    delete _background;
}

void ScreenManager::_createObjects()
{
    _background = new Background();
    _bird = new Entity("../Assets/bird.png", { 800, 500 }, 8, 7, 1, 1, 2.0f);
}

void ScreenManager::drawModel()
{
    _udpateModel();
    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    //Users space to draw objects on screen
    _background->drawBackground();
    _bird->display(_globalFrame);
    EndDrawing();
}

void ScreenManager::_initWindow(int screenWidth, int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Blow Me!");
    SetTargetFPS(FPS);
    _globalFrame = 0;
    _createObjects();
}

void ScreenManager::_udpateModel()
{
    _globalFrame++;
    _background->updateScrolling();
    _background->resetScrolling();
    _bird->move();
}