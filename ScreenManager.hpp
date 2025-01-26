#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP

#include <raylib.h>
#include "Details.hpp"
#include "Background.hpp"
#include "Bubble.hpp"
#include "Fan.hpp"
#include "Menu.hpp"
class ScreenManager
{
public:
	ScreenManager();
	~ScreenManager();
	bool _isGameStarted = false;
	bool _isGameOver = false;
	void drawModel();
	Texture2D & getTexture(textureType txtr) {return textureArr[txtr];}
	bool _getExitFlag();
private:
  	Texture2D textureArr[textureCount];
	void _initWindow(int screenWidth, int screenHeight);
  	void _loadTextures();
	void _createObjects();
	void _udpateModel();
	void _generateEntity();
	Menu* _menu;
	Background* _background;
	int64_t globalFrames = 0;
	Bubble* _bubble; 
	Fan* _fan;
	EntityQueue* _entityQueue;
  float deathTimer = 0;
};
#endif
