#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP

#include <raylib.h>
#include "Details.hpp"
#include "Background.hpp"
#include "Bubble.hpp"
#include "Fan.hpp"
//#include "Entity.hpp"

class ScreenManager
{
public:
	ScreenManager();
	~ScreenManager();
	void drawModel();
	Texture2D & getTexture(textureType txtr) {return textureArr[txtr];}
private:
  	Texture2D textureArr[textureCount];
	void _initWindow(int screenWidth, int screenHeight);
  	void _loadTextures();
	void _createObjects();
	void _udpateModel();
	void _generateEntity();
	Background* _background;
	int64_t globalFrames = 0;
	Bubble* _bubble; 
	Fan* _fan;
	//prototype
	//Entity* _entity;

	//final entity list
	EntityQueue* _entityQueue;

};

#endif