#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char *filePath, SDL_Renderer *renderer);

private:

};

