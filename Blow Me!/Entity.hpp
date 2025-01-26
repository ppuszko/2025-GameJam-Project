#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <array>
#include <raylib.h>
#include <utility>
#include <queue>

#include "Animation.hpp"
#include "Details.hpp"

class Entity
{
public:

	Entity(const char* path, Vector2 pos, 
		int frameSpd, int frameCnt, 
		float velocityX, bool shouldInvert, float scale = 1.f);
	Entity(Texture2D & _texture, Vector2 pos, 
		int frameSpd, int frameCnt, 
		float velocityX, bool shouldInvert, float scale = 1.f);
	~Entity();

	void display(int64_t& globalFrame);
	void move();
	bool isOutOfScreen();

	Rectangle getCollider(){return collisionBox;}

protected:
	Rectangle collisionBox;
	Vector2 position;
	float velX;
	float scale;
	Animation* animComponent = nullptr;
};

class EntityQueue
{
  private:
	std::queue<std::pair<Entity *, enemyType>> queue;
	std::array<int, enemyTypeCount> enemiesTypeQuantities;

  public:
	EntityQueue();
	~EntityQueue();

	void addEntity(int i);
	void addEntity(int i, Texture2D & txtr);


	const std::pair<Entity *, enemyType> &getEntity() { return queue.front(); }
	std::queue<std::pair<Entity *, enemyType>> &getQueue() { return queue; }
	
	void update();
	void display(int64_t &global_frame);
};

#endif