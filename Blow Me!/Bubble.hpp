#ifndef BUBBLE_HPP
#define BUBBLE_HPP
#include <raylib.h>

#include "Fan.hpp"
#include "Entity.hpp"

class Bubble : public Entity
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
    Bubble(float radius_, float velocity_, int scrH, const char* path, Vector2 pos,
        int frameSpd, int frameCnt, float velocityX, bool shouldInvert, float scale = 1.f);

    void move();
    void checkFanInfluence(Fan& fan);
    void show();
    void manageMovement(Fan& fan);
};

#endif