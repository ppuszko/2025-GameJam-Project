//tmp header for move
#include <iostream>

#include "Bubble.hpp"

Bubble::Bubble(float radius_, float velocity_, 
    int scrH, const char* path, Vector2 pos, int frameSpd,
    int frameCnt, float velocityX, bool shouldInvert, float scale) : Entity(path, pos, frameSpd,
   frameCnt,  velocityX,  shouldInvert,  scale), maxHeigth(0), minHeight(scrH)
{
    position.x = pos.x;
    position.y = pos.y;
    radius = radius_ * scale;
    velocity = velocity_;
    weight_factor = 1;
}

void Bubble::move()
{
    position.y += velocity;
    if (position.y < maxHeigth)
        position.y = maxHeigth;
    else if (position.y + radius > minHeight)
        position.y = minHeight - radius;
}

void Bubble::checkFanInfluence(Fan& fan)
{
    if(fan.checkCollision(position.x + radius/2))
    {
        if (fan.getFanState() == WIND)
        {
            velocity = VELOCITY_UP * (1.f / weight_factor);
        } 
    }
    else
    {
        velocity = VELOCITY_DOWN * ( weight_factor);
    }

}



void Bubble::show()
{
    std::cout <<"y: "<< position.y << std::endl;
}

void Bubble::update(Fan& fan)
{
    checkFanInfluence(fan);
    move();
}
