#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "Sprite.h"

enum Directions {
	Up, Down, Left, Right, Stop
};

// Player class derived from Object.h
class Player : public Entity {
public:
	Player(const char* filePath);
	virtual void update();
	virtual void render();
	void move(Directions direction);
	void handleInput();
	~Player();
	bool isMoving;
private:
	int hp;
	int mana;
	Sprite sprite;
};