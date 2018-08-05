#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"

class Tiles {
public:
	Tiles(SDL_Rect position);
	virtual void activate() = 0;
	bool playerHitBorder(const int destX, const int destY);
	~Tiles();
protected:
	bool collidable;
	SDL_Rect position;
};

class Dirt : public Tiles {
public:
	Dirt(SDL_Rect position);
	virtual void activate() override;
	
};