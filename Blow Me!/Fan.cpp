#include <iostream>

#include "Fan.hpp"

Fan::Fan(float x_, float radius, float velocity_, float scale_, const char* path, int frameCount, int frameSpeed, state state_of_fan_)
 : stateOfFan(state_of_fan_)
{
    RADIUS = radius * scale_;
    scale = scale_;
    velocity = velocity_;
    x = x_;
    animComponent = new Animation(path, frameCount, frameSpeed);
}

void Fan::updatePosition(int side, int screenWidth)
{
    if (x >= 0 && x + RADIUS <= screenWidth)
    {
        x += side * velocity;
    }
    else
    {
        x = screenWidth - RADIUS;
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
   // std::cout << "x: "<< x <<" state_of_fan: "<< stateOfFan <<" velocity: "<< velocity << std::endl;
    animComponent->draw(globalFrame, x, 750, scale);
}


bool Fan::checkCollision(float x1)
{
    if (x <= x1 && x1 <= x + RADIUS)
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
    if (IsKeyDown(KEY_LEFT)) updatePosition(-1, 1200);
    if (IsKeyDown(KEY_RIGHT)) updatePosition(1, 1200);

    
}
