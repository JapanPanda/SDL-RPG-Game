#include "Entity.h"
#include "TextureManager.h"
#include "Global.h"

Entity::Entity(const char* filePath) {
	std::string newFilePath = Global::FILE_DIRECTORY + filePath;
	this->texture = TextureManager::loadTexture(newFilePath);
}

Entity::~Entity() {
	SDL_DestroyTexture(this->texture);
}

void Entity::render() {
	SDL_RenderCopy(Game::renderer, this->texture, NULL, &this->position);
}
