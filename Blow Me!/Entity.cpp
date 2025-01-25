#include "Entity.hpp"
#include "Details.hpp"
#include <raylib.h>

Entity::Entity(const char* path, Vector2 pos, int frameSpd, 
	int frameCnt, float velocityX, bool shouldInvert, float scale)
: position(pos), velX(velocityX), scale(scale)
{
	animComponent = new Animation(path, frameCnt, frameSpd, shouldInvert);
	collisionBox.x = 0; collisionBox.y = 0;
	collisionBox.width = 0; collisionBox.height = 0;
	
	

}

Entity::~Entity()
{
	delete animComponent;
}

//void Entity::shiftSpriteFrame()
//{
//	frameCounter++;
//
//	if (frameCounter >= (60 / frameSpeed))
//	{
//		frameCounter = 0;
//		currentFrame++;
//
//		if (currentFrame > frameCount) currentFrame = 0;
//		destRect.x = currentFrame * spriteSheet.width / frameCount;
//
//	}
//}

void Entity::display(int64_t& global_frame)
{
	animComponent->draw(global_frame, position.x, position.y, scale);
}

void Entity::move()
{
	position.x -= velX;
}

void EntityQueue::add_entity(const char* path, 
	int frameSpd, int frameCnt, 
	float velocityX, bool shouldInvert, float scale)
{
	Vector2 pos = {screenWidth, static_cast<float>(GetRandomValue(100, 700))};
	queue.push(Entity(path, pos, frameSpd, frameCnt, velocityX, shouldInvert, scale));
}
