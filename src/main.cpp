#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "Global.h"

int main(int argc, char* argv[]) {
	const int FRAMES_PER_SECOND = 60;
	const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

	Uint32 timeStart;
	Uint32 prevTime = 0;
	Uint32 frameStart;
	int frameDiff;


	Game *game = new Game();
	while (game->getRunning()) {
		
		timeStart = frameStart = SDL_GetTicks();	
		Global::timeElapsed = (timeStart - prevTime) / 1000.0f;
		prevTime = timeStart;


		// Game Loop
		game->processEvents();
		game->updateGame();
		game->renderGame();
		// std::cout << Global::timeElapsed << std::endl;

		frameDiff = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameDiff) {
			SDL_Delay(FRAME_DELAY - frameDiff);
		}

	}
	delete game;
	game = nullptr;
	return 0;
}