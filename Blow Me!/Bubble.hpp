#ifndef BUBBLE_HPP
#define BUBBLE_HPP
#include <raylib.h>

#include "Fan.hpp"

class Bubble
{
private:
    int maxHeigth = 20.0;
    int minHeight = 0.0;
    const float VELOCITY_UP = -2.0;
    const float VELOCITY_DOWN = 1.0;

    Vector2 position;
    double radius;
    double velocity;
    double weight_factor;

public:
    Bubble(float x_ = 1.0, float y_ = 1.0, float radius_ = 1.0, float velocity_ = 0.f, int scrH = 1200);

    void move();
    void checkFanInfluence(Fan& fan);
    void show();
};

#endif