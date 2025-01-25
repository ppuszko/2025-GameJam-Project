#include <iostream>

#include "Fan.hpp"

Fan::Fan(float x_, state state_of_fan_)
 : stateOfFan(state_of_fan_)
{
    x = x_ > 0 ? -x_ : x_;
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
    if (x >= x1 && x1 <= x + RADIUS)
        return true;
    else
        return false;
}

state Fan::getFanState()
{
    return stateOfFan;
}
