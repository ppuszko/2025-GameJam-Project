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
    void loadTexture();
    void setScrolling();
};