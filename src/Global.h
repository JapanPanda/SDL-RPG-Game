#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Global {
public:
	Global(const double textureScale, const int screenWidth, const int screenHeight);
	~Global();
	static float TIME_ELAPSED;
	static double TEXTURE_SCALE;
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static int PROJECTILE_SPEED;
	static bool HAS_UP_MAP;
	static bool HAS_LEFT_MAP;
	static bool HAS_RIGHT_MAP;
	static bool HAS_DOWN_MAP;
	static std::string FILE_DIRECTORY;
};

