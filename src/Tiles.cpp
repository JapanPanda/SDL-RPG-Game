#include "Tiles.h"

Tiles::Tiles(SDL_Rect position) : collidable(true), position(position) {
	
}

bool Tiles::playerHitBorder(const int destX, const int destY) {
	bool hitBorder = false;
	if (destX > this->position.x) {
		hitBorder = true;
	}
	if (destX < this->position.x + 48) {
		hitBorder = true;
	}
	if (destY > this->position.y) {
		hitBorder = true;
	}
	if (destY < this->position.y + 48) {
		hitBorder = true;
	}
	return hitBorder;
}

Dirt::Dirt(SDL_Rect position) : Tiles(position) {
	this->type = 1;
	this->collidable = false;
}

void Dirt::activate() { }

Stone::Stone(SDL_Rect position) : Tiles(position) {
	this->type = 0;
	this->collidable = true;
}

void Stone::activate() {

}
