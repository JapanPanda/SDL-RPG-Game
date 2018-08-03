#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Global {
public:
	Global(const double textureScale, const int screenWidth, const int screenHeight);
	~Global();
	static float timeElapsed;
	static double TEXTURE_SCALE;
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
};

