//tmp header for move
#include <iostream>

#include "Bubble.hpp"

Bubble::Bubble(double x_, double y_, double radius_, double velocity_)
{
    x = x_ < 0 ? -x_ : x_;
    y = y_ < 0 ? -y_ : y_;
    radius = radius_ < 0 ? -radius_ : radius_;
    velocity = velocity_;
    weight_factor = 1;
}

void Bubble::move()
{
        y += velocity;
        if (y > MAX_HEIGHT)
            y = MAX_HEIGHT;
        else if (y < MIN_HEIGHT)
            y = MIN_HEIGHT;
    }

void Bubble::updateVelocity(double x1, double x2)
{
    if (x1 <= (x - radius) && (x + radius) <= x2)
        velocity = VELOCITY_UP * (1.0 / weight_factor);
    else
        velocity = VELOCITY_DOWN * weight_factor;
}

void Bubble::show()
{
    std::cout <<"y: "<< y << std::endl;
}
