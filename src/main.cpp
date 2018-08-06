#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "Global.h"


#define FRAME_VALUES 10

// An array to store frame times:
Uint32 frametimes[FRAME_VALUES];

// Last calculated SDL_GetTicks
Uint32 frametimelast;

// total frames rendered
Uint32 framecount;

// the value you want
float framespersecond;

// This function gets called once on startup.
void fpsinit() {

	// Set all frame times to 0ms.
	memset(frametimes, 0, sizeof(frametimes));
	framecount = 0;
	framespersecond = 0;
	frametimelast = SDL_GetTicks();

}

void fpsthink() {

	Uint32 frametimesindex;
	Uint32 getticks;
	Uint32 count;
	Uint32 i;

	// frametimesindex is the position in the array. It ranges from 0 to FRAME_VALUES.
	// This value rotates back to 0 after it hits FRAME_VALUES.
	frametimesindex = framecount % FRAME_VALUES;

	// store the current time
	getticks = SDL_GetTicks();

	// save the frame time value
	frametimes[frametimesindex] = getticks - frametimelast;

	// save the last frame time for the next fpsthink
	frametimelast = getticks;

	// increment the frame count
	framecount++;

	// Work out the current framerate

	// The code below could be moved into another function if you don't need the value every frame.

	// I've included a test to see if the whole array has been written to or not. This will stop
	// strange values on the first few (FRAME_VALUES) frames.
	if (framecount < FRAME_VALUES) {

		count = framecount;

	}
	else {

		count = FRAME_VALUES;

	}

	// add up all the values and divide to get the average frame time.
	framespersecond = 0;
	for (i = 0; i < count; i++) {

		framespersecond += frametimes[i];

	}

	framespersecond /= count;

	// now to make it an actual frames per second value...
	framespersecond = 1000.f / framespersecond;

}

std::string returnBaseDirectory(const char* exeLocation) {
	std::string tempString = exeLocation;
	std::string directoryString;
	bool foundBaseDirectory = false;
	int offset = tempString.length();

	while (offset > 0) {
		std::string subDirectory;
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
		fpsthink();
		std::cout << framespersecond << std::endl;
		frameDiff = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameDiff) {
			SDL_Delay(FRAME_DELAY - frameDiff);
		}

	}
	delete game;
	game = nullptr;
	return 0;
}