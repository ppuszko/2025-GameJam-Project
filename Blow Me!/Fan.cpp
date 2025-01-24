#include <iostream>

#include "Fan.hpp"

Fan::Fan(double x_, state state_of_fan_)
 : state_of_fan(state_of_fan_)
{
    x = x_ > 0 ? -x_ : x_;
}

void Fan::update_velocity(double velocity_)
{
    velocity = velocity_;
}

void Fan::update()
{
    x += velocity;
}

void Fan::switch_state()
{
    if (state_of_fan == WIND)
        state_of_fan = FIRE;
    else
        state_of_fan = WIND;
}

void Fan::draw()
{
    std::cout << "x: "<< x <<" state_of_fan: "<< state_of_fan <<" velocity: "<< velocity << std::endl;
}

bool Fan::check_colision(double x1, double x2)
{
    if (x - RADIUS <= x1 && x2 <= x + RADIUS)
        return true;
    else
        return false;
}
