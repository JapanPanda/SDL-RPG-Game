#include "Game.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
SDL_Texture *player;
SDL_Rect destRect = { 0, 0, 32, 32 };
Game::Game() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Failed to initialize SDL" << std::endl;
		SDL_Delay(5000);
	}
	else {
		this->window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );

		// May have to change this depending on your project layout
		player = TextureManager::LoadTexture("SDL-RPG-Game/assets/player.png", renderer);
		this->isRunning = true;
	}
}

Game::~Game() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
}

void Game::processEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
}

void Game::updateGame() {
	destRect.x += 2;
	
}

void Game::renderGame() {
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(renderer, player, NULL, &destRect);
	SDL_RenderPresent(this->renderer);

}