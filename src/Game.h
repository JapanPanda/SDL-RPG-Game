#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Game {
public:
	Game();
	~Game();
	void processEvents();
	void updateGame();
	void renderGame();
	bool getRunning() { return this->isRunning; }
	bool setRunning(bool running) { this->isRunning = running; }
private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

