#include "Tilemap.h"
#include "TextureManager.h"

Tilemap::Tilemap(const char* filePath) {
	position = { 0, 0, 32, 32 };

	// for now, file path = SDL-RPG-Game/Levels/start.lvl
	this->dirt = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt.png");
	this->stone = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/stone.png");
	this->grass = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/grass.png");

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
			this->position.y = 32 * i;
			this->position.x = 32 * j;
			int type = this->level[i][j];
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
			else {
				std::cout << "Invalid type of tile: " << type << " at index " << i << " by " << j << std::endl;
			}
		}
	}
}

Tilemap::~Tilemap() {

}
