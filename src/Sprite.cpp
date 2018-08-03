#include "Sprite.h"



Sprite::Sprite(SDL_Texture* spriteSheet, const int frames) : spriteSheet(spriteSheet), ANIMATION_FRAMES(frames), currentFrame(0) {
	std::cout << "Sprite initialized with " << frames << std::endl;
	for (int i = 0; i < ANIMATION_FRAMES; i++) {
		SDL_Rect currentFrameRect = { 32 * i, 0, 32, 32 };
		this->sprites.push_back(currentFrameRect);
	}
}


Sprite::~Sprite() {
	SDL_DestroyTexture(this->spriteSheet);
}

void Sprite::animateSprite(SDL_Rect position) {
	this->currentFrame = (SDL_GetTicks() / 500) % ANIMATION_FRAMES;
	TextureManager::drawTexture(this->spriteSheet, this->sprites[currentFrame], position);
	// std::cout << currentFrame << std::endl;
}