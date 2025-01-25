#include "Background.hpp"
#include "raylib.h"

Background::Background()
{
    loadTexture();
    setScrolling();
}

Background::~Background()
{
    UnloadTexture(background);
    UnloadTexture(midground); 
    UnloadTexture(foreground);
}

void Background::loadTexture()
{
    background = LoadTexture("../assets/background/ocean_2/1.png");
    midground = LoadTexture("../assets/background/ocean_2/2.png");
    foreground = LoadTexture("../assets/background/ocean_2/3.png");
}

void Background::setScrolling()
{
    _scrollingBackScreen = 0.0f;
    _scrollingMidScreen = 0.0f;
    _scrollingForeScreen = 0.0f;
}

void Background::updateScrolling()
{
    _scrollingBackScreen -= 0.1f;
    _scrollingMidScreen -= 0.5f;
    _scrollingForeScreen -= 1.0f;
}

void Background::resetScrolling()
{
    if (_scrollingBackScreen <= -background.width * 2) _scrollingBackScreen = 0;
    if (_scrollingMidScreen <= -midground.width * 2) _scrollingMidScreen = 0;
    if (_scrollingForeScreen <= -foreground.width * 2) _scrollingForeScreen = 0;
}

void Background::drawBackground()
{
    DrawTextureEx(background, { _scrollingBackScreen, 20 }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(background, { background.width * 2 + _scrollingBackScreen, 20 }, 0.0f, 2.0f, WHITE);

    DrawTextureEx(midground, { _scrollingMidScreen, 20 }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(midground, { midground.width * 2 + _scrollingMidScreen, 20 }, 0.0f, 2.0f, WHITE);

    DrawTextureEx(foreground, { _scrollingForeScreen, 70 }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(foreground, { foreground.width * 2 + _scrollingForeScreen, 70 }, 0.0f, 2.0f, WHITE);
}
