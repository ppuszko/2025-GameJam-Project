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
    _bubble = new Bubble (bubbleRadius, bubbleVelocityY, screenHeight, bubbIdlePath, bubblePosition, animationSpeed, bubbIdleFrameCount, 0, 0, bubbleScale);
    _fan = new Fan(fanPositionX, fanRadius, fanVelocity, fanScale, fanPath, fanFrameCount, animationSpeed);
    _entity = new Entity(birdPath, { 800, 500 }, animationSpeed, birdFrameCount, enemyVelocityX, 1, birdScale);
}

void ScreenManager::drawModel()
{
    _udpateModel();
    BeginDrawing();
    ClearBackground(LIGHTGRAY);

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