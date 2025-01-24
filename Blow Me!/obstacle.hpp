#pragma once
#include <raylib.h>


class Obstacle
{

	
public:

	Obstacle(Texture2D sprite, Vector2 pos, int frameSpd, int frameCnt, float velocityX) : position(pos), spriteSheet(sprite), frameSpeed(frameSpd), frameCount(frameCnt), velX(velocityX)
	{
		collisionBox.x = 0; collisionBox.y = 0;
		collisionBox.width = 0; collisionBox.height = 0;
		currentFrame = 0;
		frameCounter = 0;
		destRect.y = 0;
		destRect.width = sprite.width / frameCnt;
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