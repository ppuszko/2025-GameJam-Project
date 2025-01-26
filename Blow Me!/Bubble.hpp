#ifndef BUBBLE_HPP
#define BUBBLE_HPP
#include <raylib.h>
#include <utility>


#include "Fan.hpp"
#include "Entity.hpp"

class Bubble : public Entity
{
private:
    int maxHeigth = 20.0;
    int minHeight = 0.0;
    const float VELOCITY_UP = -2.0;
    const float VELOCITY_DOWN = 1.0;
    float radius;
    float velocity;
    float weight_factor;
    void checkFanInfluence(Fan& fan);
    void move();
    std::pair<bool, enemyType> isCollidingWithEntity(EntityQueue& eq)
    {
        auto res = std::make_pair<bool, enemyType>(false, DUCK);
    }
   

    //debug
    void show();

public:
    Bubble(float radius_, float velocity_, int scrH, const char* path, Vector2 pos,
        int frameSpd, int frameCnt, float velocityX, bool shouldInvert, float scale = 1.f);
    void update(Fan& fan);
    void checkCollision(int screenHeight);

};

#endif
