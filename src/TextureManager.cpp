#include "TextureManager.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char *filePath, SDL_Renderer *renderer) {
	SDL_Surface *tmpSurface = IMG_Load(filePath);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return texture;
}