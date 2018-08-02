#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

class TextureManager {
public:
	static SDL_Texture* loadTexture(const char* filePath);
	static void drawTexture(SDL_Texture *texture, SDL_Rect crop, SDL_Rect position);
	static void drawTexture(SDL_Texture *texture, SDL_Rect position);
private:

};

