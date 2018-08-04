#include "LevelManager.h"


LevelManager::LevelManager(const char* filePath, std::string levelName) : levelName(levelName), tilemap(filePath) {
	std::cout << "Initializing level manager with level " << levelName << std::endl;
}

void LevelManager::changeLevel(const char* filePath, std::string levelName) {
	std::cout << "Changing level to " << levelName << std::endl;
	this->levelName = levelName;
	this->tilemap.loadMap(filePath);
}

void LevelManager::renderMap() {
	this->tilemap.drawMap();
}

void LevelManager::update(Player* player) {
	if (player->isMoving) {
		return;
	}
	SDL_Rect& playerPosition = player->returnPosition();
	if (playerPosition.x < -16) {
		playerPosition.x = Global::SCREEN_WIDTH - 32;
		player->syncPos();
		player->resetDest(Global::SCREEN_WIDTH - 16, playerPosition.y);
		this->changeLevel("SDL-RPG-Game/maps/left.lvl", "left");
	}
	else if (playerPosition.x > Global::SCREEN_WIDTH - 10) {
		playerPosition.x = -16;
		player->syncPos();
		player->resetDest(-16, playerPosition.y);
		this->changeLevel("SDL-RPG-Game/maps/right.lvl", "right");
	}
	else if (playerPosition.y <= -38) {
		playerPosition.y = Global::SCREEN_HEIGHT - 58;
		player->syncPos();
		player->resetDest(playerPosition.x, Global::SCREEN_HEIGHT - 58);
		this->changeLevel("SDL-RPG-Game/maps/up.lvl", "up");
	}
	else if (playerPosition.y > Global::SCREEN_HEIGHT - 58) {
		playerPosition.y = -10;
		player->syncPos();
		player->resetDest(playerPosition.x, -10);
		this->changeLevel("SDL-RPG-Game/maps/down.lvl", "down");
	}
}

LevelManager::~LevelManager() {
	std::cout << "Destroying level manager" << std::endl;
}
