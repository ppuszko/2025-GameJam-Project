#pragma once
#include <raylib.h>
#include "Background.hpp"
#include "Entity.hpp"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define FPS 60

static class ScreenManager
{
public:
	ScreenManager();
	~ScreenManager();
	void drawModel();
private:
	void _initWindow(int screenWidth, int screenHeight);
	void _createObjects();
	void _udpateModel();
	Background* _background;
	int64_t _globalFrame;
	Entity* _bird;
	/*
	Bubble bubble;
	Fan fan;
	entity list;
	*/
};