#include "Tiles.h"

// hash function
//
//int hash(int posX, int posY) {
//
//}


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

}

void Dirt::activate() { }