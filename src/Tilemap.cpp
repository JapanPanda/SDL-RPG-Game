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
			int type = this->tilemap[i][j]->getType();
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
			else if (type == 21) {
				TextureManager::drawTexture(cobble , this->position);
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
	std::string mapFilePath = Global::FILE_DIRECTORY + filePath;
	std::string assetsDirectory = Global::FILE_DIRECTORY + "/assets/";
	this->position = { -16, 0, 48, 48 };
	this->tilemap.clear();
	// for now, file path = SDL-RPG-Game/Levels/start.lvl
	this->dirt = TextureManager::loadTexture(assetsDirectory + "blocks/dirt/dirt.png");
	std::cout << assetsDirectory + "blocks/dirt/dirt.png" << std::endl;
	this->stone = TextureManager::loadTexture(assetsDirectory + "blocks/stone/stone.png");
	this->grass = TextureManager::loadTexture(assetsDirectory + "blocks/grass/grass.png");
	this->stump = TextureManager::loadTexture(assetsDirectory + "tree/stump.png");
	this->dirt_to_grass_top = TextureManager::loadTexture(assetsDirectory + "blocks/dirt/dirt_to_grass_top.png");
	this->dirt_to_grass_right = TextureManager::loadTexture(assetsDirectory + "blocks/dirt/dirt_to_grass_right.png");
	this->dirt_to_grass_down = TextureManager::loadTexture(assetsDirectory + "blocks/dirt/dirt_to_grass_down.png");
	this->dirt_to_grass_left = TextureManager::loadTexture(assetsDirectory + "blocks/dirt/dirt_to_grass_left.png");
	this->dirt_to_grass_top_left = TextureManager::loadTexture(assetsDirectory + "blocks/dirt/dirt_to_grass_top_left.png");
	this->dirt_to_grass_top_right = TextureManager::loadTexture(assetsDirectory + "blocks/dirt/dirt_to_grass_top_right.png");
	this->dirt_to_grass_down_right = TextureManager::loadTexture(assetsDirectory + "blocks/dirt/dirt_to_grass_down_right.png");
	this->dirt_to_grass_down_left = TextureManager::loadTexture(assetsDirectory + "blocks/dirt/dirt_to_grass_down_left.png");
	this->cobble = TextureManager::loadTexture(assetsDirectory + "assets/blocks/stone/cobble.png");
	this->hitbox = TextureManager::loadTexture(assetsDirectory + "hitbox.png");

	std::ifstream reader(mapFilePath.c_str());
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
		Global::HAS_UP_MAP = false;
	}
	else {
		Global::HAS_UP_MAP = true;
	}
	if (this->leftMap == "none") {
		std::cout << "no left map" << std::endl;
		Global::HAS_LEFT_MAP = false;
	}
	else {
		Global::HAS_LEFT_MAP = true;
	}
	if (this->rightMap == "none") {
		std::cout << "no right map" << std::endl;
		Global::HAS_RIGHT_MAP = false;
	}
	else {
		Global::HAS_RIGHT_MAP = true;
	}
	if (this->downMap == "none") {
		std::cout << "no down map" << std::endl;
		Global::HAS_DOWN_MAP = false;
	}
	else {
		Global::HAS_DOWN_MAP = true;
	}

	int type;
	int totalSize = this->height * this->width;
	for (int i = 0; i < height; i++) {
		std::vector<int> currentRow;
		for (int j = 0; j < width; j++) {
			reader >> type;
			currentRow.push_back(type);
		}
		parseTiles(currentRow, i);
	}
	reader.close();
}

void Tilemap::parseTiles(std::vector<int> types, int counter) {
	std::vector<Tiles*> tileRow;
	Tiles* tilePtr;
	for (unsigned int i = 0; i < types.size(); i++) {
		SDL_Rect position = { i * 48 - 16, counter * 48, 48, 48 };
		switch (types[i]) {
			case 0:
				//std::cout << "Stone detected" << std::endl;
				tilePtr = new Stone(position);
				tileRow.push_back(tilePtr);
				break;

			case 1:
				//std::cout << "Dirt detected" << std::endl;
				tilePtr = new Dirt(position);
				tileRow.push_back(tilePtr);
				break;

			default:
				std::cout << "Invalid type of tile detected: " << types[i];

		}
	}
	this->tilemap.push_back(tileRow);
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

bool Tilemap::validTile(int tileCoordX, int tileCoordY) {
	Tiles* tile = this->tilemap[tileCoordY][tileCoordX];
	return tile->isCollidable();
}

Tilemap::~Tilemap() {
	std::cout << "Destroying tilemap" << std::endl;
	SDL_DestroyTexture(this->dirt);
	SDL_DestroyTexture(this->grass);
	SDL_DestroyTexture(this->stone);
	SDL_DestroyTexture(this->cobble);
}
