#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Tiles.h"


class Tilemap {
public:
	Tilemap(const char* filePath);
	void drawMap();
	void loadMap(const char* filePath);
	std::string returnMap(char direction);
	void parseTiles(std::vector<int> types, int counter);
	~Tilemap();
private:
	int width;
	int height;
	std::vector<std::vector<Tiles*>> tilemap;
	std::string upMap;
	std::string leftMap;
	std::string rightMap;
	std::string downMap;
	SDL_Rect position;
	SDL_Texture* dirt;
	SDL_Texture* stone;
	SDL_Texture* cobble;
	SDL_Texture* grass;
	SDL_Texture* stump;
	SDL_Texture* dirt_to_grass_top;
	SDL_Texture* dirt_to_grass_right;
	SDL_Texture* dirt_to_grass_down;
	SDL_Texture* dirt_to_grass_left;
	SDL_Texture* dirt_to_grass_top_left;
	SDL_Texture* dirt_to_grass_top_right;
	SDL_Texture* dirt_to_grass_down_right;
	SDL_Texture* dirt_to_grass_down_left;
	SDL_Texture* volcano;
	SDL_Texture* hitbox;
};

