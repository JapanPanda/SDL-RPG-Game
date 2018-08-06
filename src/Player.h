#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "Sprite.h"

class Tilemap;

class Game;

enum Directions {
	Up, Down, Left, Right, Stop
};

// Player class derived from Object.h
class Player : public Entity {
	friend Game;
public:
	Player(const char* filePath);
	virtual void update(Tilemap& tilemap);
	virtual void render() override;
	void move(Directions direction, Tilemap& tilemap);
	void handleInput(Tilemap& tilemap);
	void syncPos();
	void resetDest(float offsetX, float offsetY);
	~Player();
	bool isMoving;
	Directions movingDirection;
private:
	int hp;
	int mana;
	Sprite sprite;
	float destX;
	float destY;
};