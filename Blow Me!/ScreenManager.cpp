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
    textureArr[BUBBLE_DEATH_TXTR] = LoadTexture(bubblePopPath);
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
    //_entity = new Entity(initArr[DUCK].path, { 800, 500 }, animationSpeed, initArr[DUCK].frameCount, enemyVelocityX, 1, initArr[DUCK].scale);
    _entityQueue = new EntityQueue();
    _bubble->checkCollision(screenHeight, *_entityQueue);
}

void ScreenManager::drawModel()
{
    _udpateModel();
    BeginDrawing();
    ClearBackground(WHITE);

    //Users space to draw objects on screen
    _background->drawBackground();

    //_bubble->show(globalFrames);
    ////_entity->display(globalFrames);
    //_fan->update(screenWidth, globalFrames);
    //_entityQueue->display(globalFrames);
    //_bubble->checkCollision(screenHeight, *_entityQueue);

    if (_menu->get_startflag())
    {
        if (!_bubble->checkDeath()) {
            _bubble->show(globalFrames);
            _fan->update(screenWidth, globalFrames);
            _entityQueue->display(globalFrames);
            _bubble->checkCollision(screenHeight, *_entityQueue);
        }
        else {
            Rectangle death_source {
                (int)deathTimer * bubbleRadius,
                0,
                32,
                32
            };
            Rectangle death_dest {
                _bubble->get_x()-32,
                _bubble->get_y()-32,
                64,
                64
            };
            DrawTexturePro(textureArr[BUBBLE_DEATH_TXTR], death_source, death_dest, {0, 0}, 0, WHITE);
            if (deathTimer < 5) deathTimer += 0.5;
        }
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
    //_entity->move();
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
