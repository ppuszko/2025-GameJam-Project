#pragma once
#include <raylib.h>


class Entity
{

	
public:

	Entity(Texture2D sprite, Vector2 pos, int frameSpd, int frameCnt, float velocityX, bool shouldInvert, float scale = 1.f) 
		: position(pos), spriteSheet(sprite), frameSpeed(frameSpd), frameCount(frameCnt), velX(velocityX)
	{
		int invertRatio = 1;
		shouldInvert ? invertRatio = -1 : invertRatio = 1;
		collisionBox.x = 0; collisionBox.y = 0;
		collisionBox.width = 0; collisionBox.height = 0;
		currentFrame = 0;
		frameCounter = 0;
		destRect.y = 0;
		destRect.width = invertRatio * sprite.width / frameCnt;
		destRect.height = sprite.height;
		
	}

	void shiftSpriteFrame()
	{
		frameCounter++;

		if (frameCounter >= (60 / frameSpeed))
		{
			frameCounter = 0;
			currentFrame++;

			if (currentFrame > frameCount) currentFrame = 0;
			destRect.x = currentFrame * spriteSheet.width / frameCount;

		}
	}

	void display()
	{
		DrawTextureRec(spriteSheet, destRect, position, WHITE);
	}

	void move()
	{
		position.x -= velX;
	}



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