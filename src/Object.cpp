#include "Object.h"
#include "TextureManager.h"

Object::Object(const char* filePath, SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->texture = TextureManager::LoadTexture(filePath, this->renderer);
}

Object::~Object() {
	SDL_DestroyTexture(this->texture);
}

void Object::render() {
	SDL_RenderCopy(renderer, this->texture, NULL, &this->position);
}

