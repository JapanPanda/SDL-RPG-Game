#pragma once

#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class Sprite {
public:
	Sprite(SDL_Texture* spriteSheet, const int frames);
	void animateSprite(SDL_Rect position);
	~Sprite();
private:
	const int ANIMATION_FRAMES;
	int currentFrame;
	std::vector<SDL_Rect> sprites;
	SDL_Texture* spriteSheet;
};

