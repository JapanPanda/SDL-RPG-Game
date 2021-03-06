#pragma once

#include "SDL.h"
#include "SDL_image.h"

class Tilemap;
// Base class for all game objects
class Entity {
public:
	Entity(const char* filePath);
	virtual void update(Tilemap& tilemap) = 0;
	virtual void render();
	SDL_Rect& returnPosition() { return this->position; }
	~Entity();
protected:
	float posX;
	float posY;
	SDL_Rect position;
	SDL_Rect cropRect;
	SDL_Texture *texture;
};

