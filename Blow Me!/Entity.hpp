#pragma once
#include <raylib.h>


class Entity
{

	
public:

	Entity(Texture2D sprite, Vector2 pos, int frameSpd, int frameCnt, float velocityX, bool shouldInvert, float scale = 1.f);
	
	void shiftSpriteFrame();
	void display();
	void move();

private:
	Rectangle collisionBox;
	Rectangle destRect;
	Texture2D spriteSheet;
	Vector2 position;
	int frameCounter;
	int currentFrame;
	int frameSpeed;
	int frameCount;
	float velX;

	
};