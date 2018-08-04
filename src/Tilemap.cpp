#include "Tilemap.h"
#include "TextureManager.h"
#include "Global.h"

Tilemap::Tilemap(const char* filePath) {
	this->loadMap(filePath);
}

void Tilemap::drawMap() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			this->position.y = 48 * i;
			this->position.x = 48 * j - 16;
			int type = this->tilemap[i][j];
			if (type == 0) {
				TextureManager::drawTexture(stone, this->position);
				/*std::cout << "Drawing stone at " << this->position.x << " " << this->position.y << std::endl;*/
			}
			else if (type == 1) {
				TextureManager::drawTexture(dirt, this->position);
				/*std::cout << "Drawing dirt at " << this->position.x << " " << this->position.y << std::endl;*/
			}
			else if (type == 2) {
				TextureManager::drawTexture(grass, this->position);
			}
			else if (type == 6) {
				TextureManager::drawTexture(stump, this->position);
			}
			else if (type == 12) {
				TextureManager::drawTexture(dirt_to_grass_top, this->position);
			}
			else if (type == 13) {
				TextureManager::drawTexture(dirt_to_grass_right, this->position);
			}
			else if (type == 14) {
				TextureManager::drawTexture(dirt_to_grass_down, this->position);
			}
			else if (type == 15) {
				TextureManager::drawTexture(dirt_to_grass_left, this->position);
			}
			else if (type == 16) {
				TextureManager::drawTexture(dirt_to_grass_top_left, this->position);
			}
			else if (type == 17) {
				TextureManager::drawTexture(dirt_to_grass_top_right, this->position);
			}
			else if (type == 18) {
				TextureManager::drawTexture(dirt_to_grass_down_right, this->position);
			}
			else if (type == 19) {
				TextureManager::drawTexture(dirt_to_grass_down_left, this->position);
			}
			else if (type == 20) {
				TextureManager::drawTexture(volcano, this->position);
			}
			else if (type == 99) {
				TextureManager::drawTexture(hitbox, this->position);
			}
			else {
				std::cout << "Invalid type of tile: " << type << " at index " << i << " by " << j << std::endl;
			}
		}
	}
}

void Tilemap::loadMap(const char * filePath) {
	this->position = { -16, 0, 48, 48 };
	this->tilemap.clear();
	// for now, file path = SDL-RPG-Game/Levels/start.lvl
	this->dirt = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt.png");
	this->stone = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/stone/stone.png");
	this->grass = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/grass/grass.png");
	this->stump = TextureManager::loadTexture("SDL-RPG-Game/assets/tree/stump.png");
	this->dirt_to_grass_top = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt_to_grass_top.png");
	this->dirt_to_grass_right = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt_to_grass_right.png");
	this->dirt_to_grass_down = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt_to_grass_down.png");
	this->dirt_to_grass_left = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt_to_grass_left.png");
	this->dirt_to_grass_top_left = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt_to_grass_top_left.png");
	this->dirt_to_grass_top_right = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt_to_grass_top_right.png");
	this->dirt_to_grass_down_right = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt_to_grass_down_right.png");
	this->dirt_to_grass_down_left = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt_to_grass_down_left.png");
	this->hitbox = TextureManager::loadTexture("SDL-RPG-Game/assets/hitbox.png");

	std::ifstream reader(filePath);
	if (!reader.is_open()) {
		std::cout << "Couldn't open level at " << filePath << std::endl;
	}
	reader >> this->height;
	reader >> this->width;
	reader >> this->upMap;
	reader >> this->leftMap;
	reader >> this->rightMap;
	reader >> this->downMap;

	if (this->upMap == "none") {
		std::cout << "no up map" << std::endl;
		Global::hasUpMap = false;
	}
	else {
		Global::hasUpMap = true;
	}
	if (this->leftMap == "none") {
		std::cout << "no left map" << std::endl;
		Global::hasLeftMap = false;
	}
	else {
		Global::hasLeftMap = true;
	}
	if (this->rightMap == "none") {
		std::cout << "no right map" << std::endl;
		Global::hasRightMap = false;
	}
	else {
		Global::hasRightMap = true;
	}
	if (this->downMap == "none") {
		std::cout << "no down map" << std::endl;
		Global::hasDownMap = false;
	}
	else {
		Global::hasDownMap = true;
	}

	int type;
	int totalSize = this->height * this->width;
	for (int i = 0; i < height; i++) {
		std::vector<int> currentRow;
		for (int j = 0; j < width; j++) {
			reader >> type;
			currentRow.push_back(type);
		}
		this->tilemap.push_back(currentRow);
	}
	reader.close();
}

std::string Tilemap::returnMap(char direction) {
	switch (direction) {
		case 'u':
			return this->upMap;
			break;
		case 'l':
			return this->leftMap;
			break;
		case 'r':
			return this->rightMap;
			break;
		case 'd':
			return this->downMap;
			break;
	}

	return std::string();
}

Tilemap::~Tilemap() {
	std::cout << "Destroying tilemap" << std::endl;
	SDL_DestroyTexture(this->dirt);
	SDL_DestroyTexture(this->grass);
	SDL_DestroyTexture(this->stone);
}
