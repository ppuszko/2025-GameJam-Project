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
    //delete _entity;
    delete _entityQueue;
}

void ScreenManager::_createObjects()
{
    _background = new Background();
    _bubble = new Bubble (bubbleRadius, bubbleVelocityY, screenHeight, bubbIdlePath, bubblePosition, animationSpeed, bubbIdleFrameCount, 0, 0, bubbleScale);
    _fan = new Fan(fanPositionX, fanRadius, fanVelocity, fanScale, fanPath, fanFrameCount, animationSpeed);
    //_entity = new Entity(initArr[DUCK].path, { 800, 500 }, animationSpeed, initArr[DUCK].frameCount, enemyVelocityX, 1, initArr[DUCK].scale);
    _entityQueue = new EntityQueue();

}

void ScreenManager::drawModel()
{
    _udpateModel();
    BeginDrawing();
    ClearBackground(WHITE);

    //Users space to draw objects on screen
    _background->drawBackground();
    _bubble->display(globalFrames);
    //_entity->display(globalFrames);
    _fan->update(screenWidth, globalFrames);
    _entityQueue->display(globalFrames);
    _bubble->checkCollision(screenHeight);
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
    //_entity->move();
    _generateEntity();
    _entityQueue->update();
}

void ScreenManager::_generateEntity()
{
    if(globalFrames%40 == 0)
    {
        _entityQueue->addEntity(0);
    }
}
