#ifndef BUBBLE_HPP
#define BUBBLE_HPP
#include <raylib.h>

#include "Fan.hpp"
#include "Entity.hpp"

class Bubble : public Entity
{
private:
    bool isDead = false;
    int maxHeigth = 20.0;
    int minHeight = 0.0;
    const float VELOCITY_UP = -2.0;
    const float VELOCITY_DOWN = 1.0;
    float radius;
    float velocity;
    float weight_factor;
    int framesElapsedSinceWeightFactorChanged = 0;
    void checkFanInfluence(Fan& fan);
    void move();
    std::pair<bool, enemyType> checkCollisionWithEntity(EntityQueue& eq);
    void changeWeightFactor(float factor)
    {
        weight_factor = factor;
    }
    void manageWeightFactor();
   

    //debug
   

public:
    void reset() { isDead = false; position.y = 250; }
    Bubble(float radius_, float velocity_, int scrH, const char* path, Vector2 pos,
        int frameSpd, int frameCnt, float velocityX, bool shouldInvert, float scale = 1.f);
    Bubble(float radius_, float velocity_, int scrH, Texture2D & txtr, Vector2 pos,
        int frameSpd, int frameCnt, float velocityX, bool shouldInvert, float scale = 1.f);
    ~Bubble();
    void update(Fan& fan);
    void checkCollision(int screenHeight, EntityQueue& eq);
    void show(int64_t& globalframes);
    bool checkDeath() {return isDead; }
};

#endif
