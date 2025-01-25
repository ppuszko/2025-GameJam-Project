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
}

void ScreenManager::drawModel()
{
    _udpateModel();
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    //Users space to draw objects on screen
    _background->drawBackground();
    EndDrawing();
}

void ScreenManager::_initWindow(int screenWidth, int screenHeight)
{
    const int _screenWidth = screenWidth;
    const int _screenHeight = screenHeight;
    InitWindow(_screenWidth, _screenHeight, "Blow Me!");
    SetTargetFPS(FPS);
    _createObjects();
}

void ScreenManager::_udpateModel()
{
    _background->updateScrolling();
    _background->resetScrolling();
}
