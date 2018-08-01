#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"



int main(int argc, char* argv[]) {
	const int FRAMES_PER_SECOND = 60;
	const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

	Uint32 frameStart;
	int frameDiff;

	Game *game = new Game();
	while (game->getRunning()) {
		frameStart = SDL_GetTicks();	

		// Game Loop
		game->processEvents();
		game->updateGame();
		game->renderGame();

		// FPS Limit
		frameDiff = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameDiff) {
			SDL_Delay(FRAME_DELAY - frameDiff);
		}
	}
	delete game;
	game = nullptr;
	return 0;
}