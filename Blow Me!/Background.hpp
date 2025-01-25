#pragma once
#include "raylib.h"

class Background 
{
public:
    Background();
    ~Background();
    void updateScrolling();
    void resetScrolling();
    void drawBackground();

private:
    Texture2D background, midground, foreground;
    float _scrollingBackScreen;
    float _scrollingMidScreen;
    float _scrollingForeScreen;
    float _backScreenScale = 2.8f;
    float _midScreenScale = 2.8f;
    float _foreScreenScale = 2.8f;
    void loadTexture();
    void setScrolling();
};