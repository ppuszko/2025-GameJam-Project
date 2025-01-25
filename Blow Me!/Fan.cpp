#include <iostream>

#include "Fan.hpp"

Fan::Fan(float x_, float radius, const char* path, int frameCount, int frameSpeed, state state_of_fan_)
 : stateOfFan(state_of_fan_)
{
    x = x_;
    animComponent = new Animation(path, frameCount, frameSpeed);
}

void Fan::updateVelocity(float velocity_)
{
    velocity = velocity_;
}

void Fan::update()
{
    x += velocity;
}

void Fan::switchState()
{
    if (stateOfFan == WIND)
        stateOfFan = FIRE;
    else
        stateOfFan = WIND;
}

void Fan::draw()
{
    std::cout << "x: "<< x <<" state_of_fan: "<< stateOfFan <<" velocity: "<< velocity << std::endl;
}

bool Fan::checkCollision(float x1)
{
    std::cout << "x: " << x << std::endl;
    std::cout << "x1: " << x1 << std::endl;
    if (x >= x1 && x1 <= x + RADIUS)
    {
       
        return true;
    }
    else
        return false;
}

state Fan::getFanState()
{
    return stateOfFan;
}
