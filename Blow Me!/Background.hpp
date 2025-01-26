#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include "raylib.h"
#include "Details.hpp"

#define GLSL_VERSION            330

class Background 
{
public:
    Background();
    //~Background();
    void updateScrolling();
    void resetScrolling();
    void drawBackground();

private:
    Texture2D background, midground, foreground;
    float _scrollingBackScreen;
    float _scrollingMidScreen;
    float _scrollingForeScreen;
    //screen scale values
    float _backScreenScale = 2.8f;
    float _midScreenScale = 2.8f;
    float _foreScreenScale = 2.8f;
    //screen speed values
    float _backScreenScrollValue = 1.1f;
    float _midScreenScrollValue = 1.5f;
    float _foreScreenScrollValue = 1.5f;
    void loadTexture();
    void setScrolling(); 
    Shader shader = LoadShader(0, TextFormat("../Assets/shaders/wave.fs", GLSL_VERSION));
    int secondsLoc;
    int freqXLoc;
    int freqYLoc;
    int ampXLoc;
    int ampYLoc;
    int speedXLoc;
    int speedYLoc;
    float freqX;
    float freqY;
    float ampX;
    float ampY;
    float speedX;
    float speedY;
    float screenSize[2] = { (float)GetScreenWidth(), (float)GetScreenHeight() };
    float seconds;
    void setShaders();
};
#endif
