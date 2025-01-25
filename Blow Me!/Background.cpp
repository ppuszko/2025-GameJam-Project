#include "Background.hpp"

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
    background = LoadTexture("../assets/background/ocean_2/2.png");
    midground = LoadTexture("../assets/background/ocean_2/3.png");
    foreground = LoadTexture("../assets/background/ocean_2/4.png");
}

void Background::setScrolling()
{
    _scrollingBackScreen = 0.0f;
    _scrollingMidScreen = 0.0f;
    _scrollingForeScreen = 0.0f;
}

void Background::updateScrolling()
{
    _scrollingBackScreen -= 1.1f;
    _scrollingMidScreen -= 1.5f;
    _scrollingForeScreen -= 2.5f;
}

void Background::resetScrolling()
{
    if (_scrollingBackScreen <= -background.width * _backScreenScale) _scrollingBackScreen = 0;
    if (_scrollingMidScreen <= -midground.width * _midScreenScale) _scrollingMidScreen = 0;
    if (_scrollingForeScreen <= -foreground.width * _foreScreenScale) _scrollingForeScreen = 0;
}

void Background::drawBackground()
{
    DrawTextureEx(background, { _scrollingBackScreen, 0 }, 0.0f, _backScreenScale, WHITE);
    DrawTextureEx(background, { background.width * _backScreenScale + _scrollingBackScreen, 0 }, 0.0f, _backScreenScale, WHITE);

    BeginBlendMode(BLEND_ALPHA);
    DrawTextureEx(midground, { _scrollingMidScreen, 0 }, 0.0f, _midScreenScale, Fade(WHITE, 0.6f));
    DrawTextureEx(midground, { midground.width * _midScreenScale + _scrollingMidScreen, 0 }, 0.0f, _midScreenScale, Fade(WHITE, 0.6f));
    
    DrawTextureEx(foreground, { _scrollingForeScreen, 8 }, 0.0f, _foreScreenScale, Fade(SKYBLUE, 0.3f));
    DrawTextureEx(foreground, { foreground.width * _foreScreenScale + _scrollingForeScreen, 8 }, 0.0f, _foreScreenScale, Fade(SKYBLUE, 0.3f));
    EndBlendMode();
}
