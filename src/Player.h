#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "Sprite.h"

class Game;

enum Directions {
	Up, Down, Left, Right, Stop
};

// Player class derived from Object.h
class Player : public Entity {
	friend Game;
public:
	Player(const char* filePath);
	virtual void update();
	virtual void render() override;
	void move(Directions direction);
	void handleInput();
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