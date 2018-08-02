#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

class Tilemap {
public:
	Tilemap(const char* filePath);
	void drawMap();
	~Tilemap();
private:
	int width;
	int height;
	std::vector<std::vector<int>> level;
	SDL_Rect position;
	SDL_Texture* dirt;
	SDL_Texture* stone;

};

