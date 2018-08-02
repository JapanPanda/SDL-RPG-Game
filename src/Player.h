#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Object.h"

// Player class derived from Object.h
class Player : public Object {
public:
	Player(const char* filePath, SDL_Renderer *renderer);
	virtual void update();
	~Player();
private:
	int hp;
	int mana;
};