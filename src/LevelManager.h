#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "Tilemap.h"
#include "Global.h"
#include "Player.h"

class LevelManager {
public:
	LevelManager(const char* filePath, std::string levelName);
	void changeLevel(const char* filePath, std::string levelName);
	void renderMap();
	void update(Player* player);
	~LevelManager();
private:
	std::string levelName;
	Tilemap tilemap;
};

