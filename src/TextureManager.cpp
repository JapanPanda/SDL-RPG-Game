#include "TextureManager.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

SDL_Texture* TextureManager::loadTexture(const char *filePath) {
	SDL_Surface *tmpSurface = IMG_Load(filePath);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return texture;
}

void TextureManager::drawTexture(SDL_Texture* texture, SDL_Rect crop, SDL_Rect position) {
	SDL_RenderCopy(Game::renderer, texture, &crop, &position);
}

void TextureManager::drawTexture(SDL_Texture* texture, SDL_Rect position) {
	SDL_RenderCopy(Game::renderer, texture, NULL, &position);
}