#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "Global.h"

std::string returnBaseDirectory(const char* exeLocation) {
	std::string tempString = exeLocation;
	std::string directoryString;
	bool foundBaseDirectory = false;
	int offset = tempString.length();
	std::string subDirectory;
	while (subDirectory.length() != 0) {
		subDirectory.clear();
		int index = tempString.find_last_of('\\', offset);
		int secondIndex = tempString.find_last_of('\\', index - 1);
		for (int i = secondIndex; i <= index; i++) {
			subDirectory += tempString[i];
		}
		if (subDirectory == "\\SDL-RPG-Game\\") {
			for (int i = 0; i < index; i++) {
				directoryString += tempString[i];
			}
			std::cout << "Found directory " << directoryString << std::endl;
			return directoryString;
		}
		else {
			std::cout << "Could not find it this time, setting offset at " << --index << std::endl;
			offset = --index;
		}
	}
	return "BASE DIRECTORY NOT FOUND";
}

int main(int argc, char* argv[]) {
	Global::FILE_DIRECTORY = returnBaseDirectory(argv[0]);
	std::cout << Global::FILE_DIRECTORY << std::endl;


	const int FRAMES_PER_SECOND = 60;
	const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

	Uint32 timeStart;
	Uint32 prevTime = 0;
	Uint32 frameStart;
	int frameDiff;


	Game *game = new Game();
	while (game->getRunning()) {
		
		timeStart = frameStart = SDL_GetTicks();	
		Global::TIME_ELAPSED = (timeStart - prevTime) / 1000.0f;
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