#include "Tilemap.h"
#include "TextureManager.h"

Tilemap::Tilemap(const char* filePath) {
	position = { 0, 0, 48, 48 };

	// for now, file path = SDL-RPG-Game/Levels/start.lvl
	this->dirt = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/dirt/dirt.png");
	this->stone = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/stone/stone.png");
	this->cobble = TextureManager::loadTexture("SDL-RPG-Game/assets/blocks/stone/cobble.png");
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

void Tilemap::drawMap() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			this->position.y = 48 * i;
			this->position.x = 48 * j;
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

Tilemap::~Tilemap() {
	SDL_DestroyTexture(this->dirt);
	SDL_DestroyTexture(this->grass);
	SDL_DestroyTexture(this->stone);
	SDL_DestroyTexture(this->cobble);
}
