#include "Tilemap.h"
#include "TextureManager.h"

Tilemap::Tilemap(const char* filePath) {
	// for now, file path = SDL-RPG-Game/Levels/start.lvl
	this->dirt = TextureManager::LoadTexture("assets/dirt.png");
	this->stone = TextureManager::LoadTexture("assets/stone.png");
	std::ifstream reader(filePath);
	if (!reader.is_open()) {
		std::cout << "Couldn't open level at " << filePath << std::endl;
	}
	reader >> this->height;
	reader >> this->width;

	int type;
	int totalSize = this->height * this->width;

	for (int i = 0; i < height; i++) {
		std::vector<int> currentRow;
		for (int j = 0; j < width; j++) {
			reader >> type;
			currentRow.push_back(type);
		}
		this->level.push_back(currentRow);
	}
	reader.close();
}

void Tilemap::drawMap() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			int type = this->level[i][j];
			if (type == 0) {
				
			}
			else if (type == 1) {

			}
			else {
				std::cout << "Invalid type of tile: " << type << "at index " << i << " by " << j << std::endl;
			}
		}
	}
}

Tilemap::~Tilemap() {

}
