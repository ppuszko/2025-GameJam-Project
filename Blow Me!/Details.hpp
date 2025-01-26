#ifndef DETAILS_HPP
#define DETAILS_HPP

#include <raylib.h>

//screen & animation details

const int screenHeight = 900;
const int screenWidth = 1600;
const int fps = 60;

// Taka kolejność, żeby się pokrywało z enemyType kurwa
enum textureType {DUCK_TXTR, CLOUD_TXTR, RAIN_CLOUD_TXTR, STORM_CLOUD_TXTR, BUBBLE_TXTR, FAN_TXTR};
const int textureCount = 6;

const int animationSpeed = 8;
const float velocityX = 1;
const float enemyVelocityX = 1;
const char* const title = "Blow Me!";

enum enemyType { DUCK, CLOUD, RAIN_CLOUD, STORM_CLOUD };
const int enemyTypeCount = 4;
const int maxEnemiesPerType = 2;

struct initParams
{
    const int frameCount;
    const char* const path;
    const float scale;
    const bool shouldInvert;
};

const initParams initArr[enemyTypeCount] =
{
    {
        7,
        "../Assets/bird.png",
        2.0f,
        true
    },
    {
        1,
        "../Assets/cloud.png",
        5.0f,
        false
    },
    {
        0,
        "../Assets/rain_cloud.png",
        0.0f,
        false
    },
    {
        0,
        "../Assets/storm_cloud.png",
        0.0f,
        false
    }
};

//fan constructor details
const int fanFrameCount = 10;
const char* const fanPath = "../Assets/fan.png";
const float fanVelocity = 5;
const float fanRadius = 32;
const float fanPositionX = 200;
const float fanScale = 3.0f;

//bubble constructor details
const float bubbleRadius = 32;
const float bubbleVelocityY = 12;
const float bubbleScale = 2.0f;
const Vector2 bubblePosition{ 100, screenHeight / 4.f};
//bubble pop
const int bubblePopFrameCount = 6;
const char* const bubblePopPath = "../Assets/bubble_pop.png";
//bubble idle
const int bubbIdleFrameCount = 5;
const char* const bubbIdlePath = "../Assets/bubble_idle.png";

#endif
