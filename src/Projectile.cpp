#include "Projectile.h"
#include "Tilemap.h"

int Projectile::existingProjectiles = 0;

Projectile::Projectile(const char* filePath, int posX, int posY, Directions direction) : Entity(filePath), vectorPos(existingProjectiles), direction(direction) {
	this->posX = posX;
	this->posY = posY;
	this->position = { (int)this->posX, (int)this->posY, 16, 16 };
	std::cout << "Created projectile" << std::endl;
	Projectile::existingProjectiles++;
}

void Projectile::update(Tilemap& tilemap) {

}

void Projectile::update(Tilemap& tilemap, Player& player) {
	float velocity = Global::PROJECTILE_SPEED * Global::TIME_ELAPSED;
	std::cout << Global::TIME_ELAPSED << " : " << velocity << std::endl;
	switch (this->direction) {
		case Up:
			if (this->posY - velocity <= 0) {
				player.destroyProjectile(this->vectorPos);
				break;
			}
			this->posY -= velocity;
			break;
		case Down:
			if (this->posY + velocity >= Global::SCREEN_HEIGHT) {
				player.destroyProjectile(this->vectorPos);
				break;
			}
			this->posY += velocity;
			break;
		case Left:
			if (this->posX - velocity <= 0) {
				player.destroyProjectile(this->vectorPos);
				break;
			}
			break;
		case Right:
			if (this->posX + velocity >= Global::SCREEN_WIDTH) {
				player.destroyProjectile(this->vectorPos);
				break;
			}
			this->posX += velocity;
			break;
	}

	// TO DO: INVESTIGATE WHY BULLET IS BEING DESTROYED EARLY
	int tileCoordX = ((int)(this->posX)) / 48;
	int tileCoordY = ((int)(this->posY)) / 48;
	if (!tilemap.validTile(tileCoordX, tileCoordY)) {
		player.destroyProjectile(this->vectorPos);
	}
	this->position.x = this->posX;
	this->position.y = this->posY;
}

Projectile::~Projectile() {
	Projectile::existingProjectiles--;
	std::cout << "Destroyed projectile" << std::endl;
}
