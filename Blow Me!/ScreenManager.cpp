#include "ScreenManager.hpp"

ScreenManager::ScreenManager()
{
    _initWindow(screenWidth, screenHeight);
}

ScreenManager::~ScreenManager()
{
    delete _background;
    delete _bubble;
    delete _fan;
    delete _entity;
}

void ScreenManager::_createObjects()
{
    _background = new Background();
    _bubble = new Bubble (32, 5, screenHeight, "../Assets/bubble_pop.png", { 100, screenHeight / 2.f }, 8, 6, 0, 0, 2);
    _fan = new Fan(100, 32, 5, 3, "../Assets/fan.png", 10, 6);
    _entity = new Entity("../Assets/bird.png", { 800, 500 }, 8, 7, 1, 1, 2.0f);
}

void ScreenManager::drawModel()
{
    _udpateModel();
    BeginDrawing();
    ClearBackground(WHITE);

    //Users space to draw objects on screen
    _background->drawBackground();
    _bubble->display(globalFrames);
    _entity->display(globalFrames);
    EndDrawing();
}

void ScreenManager::_initWindow(int screenWidth, int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Blow Me!");
    SetTargetFPS(fps);
    globalFrames = 0;
    _createObjects();
}

void ScreenManager::_udpateModel()
{
    globalFrames++;
    _background->updateScrolling();
    _background->resetScrolling();
    _bubble->update(*_fan);
    _fan->update(screenWidth, globalFrames);
    _entity->move();
}