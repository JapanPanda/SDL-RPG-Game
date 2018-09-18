#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"

class Tiles {
public:
	Tiles(SDL_Rect position);
	virtual void activate() = 0;
	bool playerHitBorder(const int destX, const int destY);
	bool isCollidable() { return collidable; }
	int getType() { return this->type; }
	~Tiles();
protected:
	int type;
	bool collidable;
	SDL_Rect position;
};

class Stone : public Tiles {
public:
	Stone(SDL_Rect position);
	virtual void activate() override;
};

class Dirt : public Tiles {
public:
	Dirt(SDL_Rect position);
	virtual void activate() override;
	
};
