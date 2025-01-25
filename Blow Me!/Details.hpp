#include <raylib.h>


//bubble idle
const int bubbIdleFrameCount = 5;
const char* bubbIdlePath = "../Assets/bubble_idle.png";

//bubble pop
const int bubblePopFrameCount = 6;
const char* bubblePopPath = "../Assets/bubble_pop.png";

//bubble initial position
Vector2 bubbleInitialPosition = { 100, screenHeight / 2 };

//bird
const int birdFrameCount = 7;
const char* birdPath = "../Assets/bird.png";

//fan
const int fanFrameCount = 10;
const char* fanPath = "../Assests/fan.png";


//screen & animation details
const int screenHeight = 800;
const int screenWidth = 1200;
const int animationSpeed = 8;
const char* title = "Blow Me!";