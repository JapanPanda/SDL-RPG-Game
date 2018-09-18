#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "Global.h"


class Projectile : public Entity {
public:
	Projectile(const char* filePath, int posX, int posY, Directions direction);
	virtual void update(Tilemap& tilemap);
	void update(Tilemap& tilemap, Player& player);
	~Projectile();

	static int existingProjectiles;
private:
	int vectorPos;
	Directions direction;
};

