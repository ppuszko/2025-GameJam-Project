#include "ScreenManager.hpp"
#include "Details.hpp"
#include <raylib.h>

ScreenManager::ScreenManager() {
    _initWindow(screenWidth, screenHeight);
}

ScreenManager::~ScreenManager()
{
    delete _background;
    delete _bubble;
    delete _fan;
    delete _menu;
    delete _entityQueue;
}

void ScreenManager::_loadTextures() {
    textureArr[BUBBLE_TXTR] = LoadTexture(bubbIdlePath);
    textureArr[FAN_TXTR] = LoadTexture(fanPath);
    textureArr[DUCK_TXTR] = LoadTexture("../Assets/bird.png");
    textureArr[CLOUD_TXTR] = LoadTexture("../Assets/cloud.png");
}

void ScreenManager::_createObjects()
{
    _background = new Background(); 
    _menu = new Menu();
    _bubble = new Bubble (bubbleRadius, bubbleVelocityY, screenHeight, textureArr[BUBBLE_TXTR], bubblePosition, animationSpeed, bubbIdleFrameCount, 0, 0, bubbleScale);
    _fan = new Fan(fanPositionX, fanRadius, fanVelocity, fanScale, textureArr[FAN_TXTR], fanFrameCount, animationSpeed);
    _entityQueue = new EntityQueue();
    //_bubble->checkCollision(screenHeight, *_entityQueue);
}

void ScreenManager::drawModel()
{
    _udpateModel();
    BeginDrawing();
    ClearBackground(WHITE);

    //Users space to draw objects on screen
    _background->drawBackground();

    if (_menu->get_startflag())
    {
        _bubble->show(globalFrames);
        _fan->update(screenWidth, globalFrames);
        _entityQueue->display(globalFrames);
        _bubble->checkCollision(screenHeight, *_entityQueue);
    }
    else if (_menu->get_exitflag())
    {
        EndDrawing();
        CloseWindow();
    }
    else
    {
        _menu->draw_options();
        _menu->check_options();
    }

    EndDrawing();
}

void ScreenManager::_initWindow(int screenWidth, int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Blow Me!");
    SetTargetFPS(fps);
    globalFrames = 0;
    _loadTextures();
    _createObjects();
}

void ScreenManager::_udpateModel()
{
    globalFrames++;
    _background->updateScrolling();
    _background->resetScrolling();
    _bubble->update(*_fan);
    _fan->update(screenWidth, globalFrames);
    _generateEntity();
    _entityQueue->update();
}

void ScreenManager::_generateEntity()
{
    if(globalFrames%50 == 0)
    {
        _entityQueue->addEntity(textureArr);
    }
}

bool ScreenManager::_getExitFlag()
{
    return _menu->get_exitflag();
}
