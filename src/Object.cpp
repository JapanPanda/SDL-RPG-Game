#include "Object.h"
#include "TextureManager.h"

Object::Object(const char* filePath) {
	this->texture = TextureManager::LoadTexture(filePath);
}

Object::~Object() {
	SDL_DestroyTexture(this->texture);
}

void Object::render() {
	SDL_RenderCopy(Game::renderer, this->texture, NULL, &this->position);
}

