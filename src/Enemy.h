#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"

class Enemy : public Entity {
public:
	Enemy(const char* filePath);
	~Enemy();
};

