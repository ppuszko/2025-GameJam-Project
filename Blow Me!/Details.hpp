#include <raylib.h>

//screen & animation details
const int screenHeight = 800;
const int screenWidth = 1200;
const int animationSpeed = 8;
const char* const title = "Blow Me!";
const int fps = 60;

//enemy entity:
const float enemyVelocityX = 9;
//bird entity
const int birdFrameCount = 7;
const char* const birdPath = "../Assets/bird.png";
const float birdScale = 3.f;



//fan constructor details
const int fanFrameCount = 10;
const char* const fanPath = "../Assets/fan.png";
const float fanVelocity = 7;
const float fanRadius = 32;
const int fanPositionX = 100;
const float fanScale = 3.f;

//bubble constructor details
const float bubbleRadius = 32;
const float bubbleVelocityY = 1;
const Vector2 bubblePosition{ 100, screenHeight / 2.0f };
const float bubbleScale = 2;
//bubble pop
const int bubblePopFrameCount = 6;
const char* const bubblePopPath = "../Assets/bubble_pop.png";
//bubble idle
const int bubbIdleFrameCount = 5;
const char* const bubbIdlePath = "../Assets/bubble_idle.png";
