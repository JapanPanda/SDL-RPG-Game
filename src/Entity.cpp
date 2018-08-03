#include "Entity.h"
#include "TextureManager.h"

Entity::Entity(const char* filePath) {
	this->texture = TextureManager::loadTexture(filePath);
}

Entity::~Entity() {
	SDL_DestroyTexture(this->texture);
}

void Entity::render() {
	SDL_RenderCopy(Game::renderer, this->texture, NULL, &this->position);
}
