#pragma once
#include <raylib.h>
#include "Animation.hpp";

class Entity
{

	
public:

	Entity(const char* path, Vector2 pos, 
		int frameSpd, int frameCnt, 
		float velocityX, bool shouldInvert, float scale = 1.f);
	~Entity();
	

	void display(int64_t& globalFrame);
	void move();


protected:
	Rectangle collisionBox;
	Vector2 position;
	float velX;
	float scale;
	Animation* animComponent = nullptr;


};