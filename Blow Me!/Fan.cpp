#include "Fan.hpp"
#include <raylib.h>

Fan::Fan(float x_, float radius, float velocity_, float scale_, 
    const char* path, int frameCount, int frameSpeed, state state_of_fan_)
 : stateOfFan(state_of_fan_)
{
    RADIUS = radius * scale_;
    scale = scale_;
    velocity = velocity_;
    x = x_;
    animComponent = new Animation(path, frameCount, frameSpeed);
}

Fan::Fan(float x_, float radius, float velocity_, float scale_, 
    Texture2D & txtr, int frameCount, int frameSpeed, state state_of_fan_)
 : stateOfFan(state_of_fan_)
{
    RADIUS = radius * scale_;
    scale = scale_;
    velocity = velocity_;
    x = x_;
    animComponent = new Animation(txtr, frameCount, frameSpeed);
}

Fan::~Fan()
{
    delete animComponent;
}

void Fan::updatePosition(int direction, int screenWidth)
{ 
    int expectedPos = x + direction*velocity;
    if ((expectedPos - RADIUS/2 >= 0 && expectedPos + RADIUS/2 <= screenWidth))
    {
        x = expectedPos;
    }
}

void Fan::update(int screenWidth, int64_t& globalFrame)
{
    handleInput();
    draw(globalFrame);
}

void Fan::switchState()
{
    if (stateOfFan == WIND)
        stateOfFan = FIRE;
    else
        stateOfFan = WIND;
}

void Fan::draw(int64_t& globalFrame)
{
    animComponent->draw(globalFrame, x, 840, scale);
}


bool Fan::checkCollision(float x1)
{
    if (x - RADIUS/2 <= x1 && x1 <= x + RADIUS/2)
        return true;
    else
        return false;
}

state Fan::getFanState()
{
    return stateOfFan;
}

void Fan::handleInput()
{
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) updatePosition(-1, 1200);
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) updatePosition(1, 1200);
}
