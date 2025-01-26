#pragma once

#include <array>
#include <raylib.h>
#include <queue>

#include "Animation.hpp"
#include "Details.hpp"

class Entity
{
public:

	Entity(const char* path, Vector2 pos, 
		int frameSpd, int frameCnt, 
		float velocityX, bool shouldInvert, float scale = 1.f);
	~Entity();

	void display(int64_t& globalFrame);
	void move();
	bool isOutOfScreen();

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
	std::queue<Entity *> queue;
	std::array<int, enemyTypeCount> enemiesTypeQuantities;

  public:
	EntityQueue();
	~EntityQueue();

	void addEntity(int i);


	const Entity *getEntity() { return queue.front(); }
	std::queue<Entity *> &getQueue() { return queue; }
	void update();
	void display(int64_t &global_frame);
};
