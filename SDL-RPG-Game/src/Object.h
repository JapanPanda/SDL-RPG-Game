#pragma once

#include "SDL.h"
#include "SDL_image.h"

// Base class for all game objects
class Object {
public:
	Object(const char* filePath);
	virtual void update() = 0;
	void render();
	~Object();
protected:
	SDL_Rect position;
	SDL_Rect cropRect;
	SDL_Texture *texture;
};

