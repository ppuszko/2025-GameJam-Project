#include "Background.hpp"

Background::Background()
{
    loadTexture(); 
    setScrolling(); 
    setShaders();
}

Background::~Background()
{
    UnloadShader(shader);
    UnloadTexture(background);
    UnloadTexture(midground); 
    UnloadTexture(foreground);
}

void Background::loadTexture()
{
    background = LoadTexture("../Assets/background/Ocean_2/2.png");
    midground = LoadTexture("../Assets/background/Ocean_2/3.png");
    foreground = LoadTexture("../Assets/background/Ocean_2/4.png");
}

void Background::setScrolling()
{
    _scrollingBackScreen = 0.0f;
    _scrollingMidScreen = 0.0f;
    _scrollingForeScreen = 0.0f;
}

void Background::setShaders()
{
    secondsLoc = GetShaderLocation(shader, "seconds");
    freqXLoc = GetShaderLocation(shader, "freqX");
    freqYLoc = GetShaderLocation(shader, "freqY");
    ampXLoc = GetShaderLocation(shader, "ampX");
    ampYLoc = GetShaderLocation(shader, "ampY");
    speedXLoc = GetShaderLocation(shader, "speedX");
    speedYLoc = GetShaderLocation(shader, "speedY");

    // Shader uniform values that can be updated at any time
    freqX = 40.0f;
    freqY = 5.0f;
    ampX = 3.0f;
    ampY = 3.0f;
    speedX = 3.0f;
    speedY = 4.0f;

    SetShaderValue(shader, GetShaderLocation(shader, "size"), &screenSize, SHADER_UNIFORM_VEC2);
    SetShaderValue(shader, freqXLoc, &freqX, SHADER_UNIFORM_FLOAT);
    SetShaderValue(shader, freqYLoc, &freqY, SHADER_UNIFORM_FLOAT);
    SetShaderValue(shader, ampXLoc, &ampX, SHADER_UNIFORM_FLOAT);
    SetShaderValue(shader, ampYLoc, &ampY, SHADER_UNIFORM_FLOAT);
    SetShaderValue(shader, speedXLoc, &speedX, SHADER_UNIFORM_FLOAT);
    SetShaderValue(shader, speedYLoc, &speedY, SHADER_UNIFORM_FLOAT);

    seconds = 0.0f;
}

void Background::updateScrolling()
{
    seconds += GetFrameTime();
    SetShaderValue(shader, secondsLoc, &seconds, SHADER_UNIFORM_FLOAT);
    _scrollingBackScreen -= _backScreenScrollValue;
    _scrollingMidScreen -= _midScreenScrollValue;                  
    _scrollingForeScreen -= _foreScreenScrollValue;
    
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
    DrawTextureEx(midground, { _scrollingMidScreen, 0 }, 0.0f, _midScreenScale, Fade(WHITE, 0.7f));
    DrawTextureEx(midground, { midground.width * _midScreenScale + _scrollingMidScreen, 0 }, 0.0f, _midScreenScale, Fade(WHITE, 0.7f));

    BeginShaderMode(shader);
    DrawTextureEx(foreground, { _scrollingForeScreen, 4 }, 0.0f, _foreScreenScale, Fade(DARKBLUE, 0.5f));
    DrawTextureEx(foreground, { foreground.width * _foreScreenScale + _scrollingForeScreen, 4 }, 0.0f, _foreScreenScale, Fade(DARKBLUE, 0.5f));
    EndShaderMode();
    EndBlendMode();
}
