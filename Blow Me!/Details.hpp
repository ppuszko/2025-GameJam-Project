#include <raylib.h>

//screen & animation details
const int screenHeight = 800;
const int screenWidth = 1200;
const int animationSpeed = 8;
const char* const title = "Blow Me!";
const int fps = 60;

//bird entity
const int birdFrameCount = 7;
const char* const birdPath = "../Assets/bird.png";
const float velocityX = 14;


//fan constructor details
const int fanFrameCount = 10;
const char* const fanPath = "../Assests/fan.png";
const float fanVelocity = 7;
const float fanRadius = 32;

//bubble constructor details
const float radius = 32;
const float bubbleVelocityY = 12;
const Vector2 bubblePosition{ 100, screenHeight / 2.0f };
//bubble pop
const int bubblePopFrameCount = 6;
const char* const bubblePopPath = "../Assets/bubble_pop.png";
//bubble idle
const int bubbIdleFrameCount = 5;
const char* const bubbIdlePath = "../Assets/bubble_idle.png";
