#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"

class Tiles {
public:
	Tiles();
	// virtual void activate() = 0;
	bool checkBorder(const SDL_Rect* position);
	~Tiles();
private:
	bool collidable;
	SDL_Rect* position;
};

class Dirt : public Tiles {
	
};