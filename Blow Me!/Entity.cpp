#include <queue>
#include <raylib.h>
#include <utility>

#include "Entity.hpp"
#include "Details.hpp"

Entity::Entity(const char* path, Vector2 pos, int frameSpd, 
	int frameCnt, float velocityX, bool shouldInvert, float scale)
: position(pos), velX(velocityX), scale(scale)
{
	animComponent = new Animation(path, frameCnt, frameSpd, shouldInvert);

	collisionBox.x = pos.x - animComponent->getSize() * scale/2; collisionBox.y = pos.y - animComponent->getSize() * scale /2;
	collisionBox.width = animComponent->getSize(); collisionBox.height =  animComponent->getSize();
}

Entity::Entity(Texture2D & _texture, Vector2 pos, int frameSpd, 
	int frameCnt, float velocityX, bool shouldInvert, float scale)
: position(pos), velX(velocityX), scale(scale)
{
	animComponent = new Animation(_texture, frameCnt, frameSpd, shouldInvert);

	collisionBox.x = pos.x - animComponent->getSize() * scale/2; collisionBox.y = pos.y - animComponent->getSize() * scale /2;
	collisionBox.width = animComponent->getSize(); collisionBox.height =  animComponent->getSize();
}

Entity::~Entity()
{
	delete animComponent;
}

bool Entity::isOutOfScreen()
{
	if (position.x < 0)
		return true;
	return false;
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

EntityQueue::EntityQueue()
{
	enemiesTypeQuantities = {0};
}

EntityQueue::~EntityQueue()
{
	while (queue.empty())
	{
		delete queue.front().first;
		queue.pop();
	}
}

void EntityQueue::addEntity(int i)
{
	if (queue.size() >= 3) return;

	Vector2 pos = {screenWidth, static_cast<float>(GetRandomValue(100, 700))};

	int selectedType = i; //GetRandomValue(0, enemyTypeCount - 1);
	
	while (enemiesTypeQuantities[selectedType] >= maxEnemiesPerType)
		if (selectedType == enemyTypeCount)
			selectedType = 0;
		else
			++selectedType;
	++enemiesTypeQuantities[selectedType];
	
	const char *const path = initArr[selectedType].path;
	int frameCnt = initArr[selectedType].frameCount;
	float newScale = initArr[selectedType].scale * static_cast<float>(GetRandomValue(100, 200)) / 200.0f;
	bool shouldInvert = initArr[selectedType].shouldInvert;

	queue.push(std::make_pair(new Entity(path, pos, animationSpeed, frameCnt, velocityX, shouldInvert, newScale), enemyType(selectedType)));
}

void EntityQueue::addEntity(int i, Texture2D & txtr)
{
	if (queue.size() >= 3) return;

	Vector2 pos = {screenWidth, static_cast<float>(GetRandomValue(100, 700))};

	int selectedType = i; //GetRandomValue(0, enemyTypeCount - 1);
	
	while (enemiesTypeQuantities[selectedType] >= maxEnemiesPerType)
		if (selectedType == enemyTypeCount)
			selectedType = 0;
		else
			++selectedType;
	++enemiesTypeQuantities[selectedType];
	
	//const char *const path = initArr[selectedType].path;
	int frameCnt = initArr[selectedType].frameCount;
	float newScale = initArr[selectedType].scale * static_cast<float>(GetRandomValue(100, 200)) / 200.0f;
	bool shouldInvert = initArr[selectedType].shouldInvert;

	queue.push(std::make_pair(new Entity(txtr, pos, animationSpeed, frameCnt, velocityX, shouldInvert, newScale), enemyType(selectedType)));
}

void EntityQueue::update()
{
	for (int i = 0; i < queue.size(); ++i)
	{
		auto t = queue.front();
		queue.pop();
		t.first->move();
		//there is no bird deletion
		//if (!t->isOutOfScreen())
			queue.push(t);
	}
}

void EntityQueue::display(int64_t &global_frame)
{
	for (int i = 0; i < queue.size(); ++i)
	{
		auto t = queue.front();
		queue.pop();
		t.first->display(global_frame);
		queue.push(t);
	}
}
