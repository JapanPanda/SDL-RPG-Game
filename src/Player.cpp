#include "Player.h"
#include <iostream>
#include "Game.h"
#include "Global.h"
#include "Tilemap.h"
#include "Projectile.h"

Player::Player(const char * filePath) : Entity(filePath), isMoving(false), sprite(texture, 2), hp(100), mana(100), 
										destX(0), destY(0), movingDirection(Stop), keepTrackTime(false), firstShot(true), timeTracker(0) {

	// Create position at center of screen
	this->projectileCoolDown = 0;
	this->position.x = 480.00 - 16.00;
	this->position.y = 240.00 - 10.00;
	this->position.w = 48;
	this->position.h = 48;
	this->posX = this->position.x;
	this->posY = this->position.y;
	std::cout << "Created player" << std::endl;
}

Player::~Player() {
	std::cout << "Deleting player now" << std::endl;
}

void Player::update(Tilemap& tilemap) {
	if (this->isMoving) {
		switch (this->movingDirection) {
			case Up:
				if (this->position.y <= (int)this->destY) {
					this->position.y = (int)this->destY;
					isMoving = false;
				}
				break;
			case Down:
				if (this->position.y >= (int) this->destY) {
					this->position.y = (int)this->destY;
					isMoving = false;
				}
				break;
			case Left:
				if (this->position.x <= (int)this->destX) {
					this->position.x = (int)this->destX;
					isMoving = false;
				}
				break;
			case Right:
				if (this->position.x >= (int)this->destX) {
					this->position.x = (int)this->destX;
					isMoving = false;
				}
				break;
		}
	}
	if (this->isMoving) {
		this->move(this->movingDirection, tilemap);
	}
	for (int i = 0; i < this->projectiles.size(); i++) {
		this->projectiles[i].update(tilemap, *this);
	}
}

void Player::render() {
	this->sprite.animateSprite(this->position);
	for (int i = 0; i < this->projectiles.size(); i++) {
		this->projectiles[i].render();
	}
}



void Player::move(Directions direction, Tilemap& tilemap) {

	float XVEL_ = 400 * Global::TIME_ELAPSED, YVEL_ = 400 * Global::TIME_ELAPSED;

	//if (this->destX + 16 < 0 || this->destY + 10 < 0 || this->destX - 16 > 1024 - this->position.w || this->destY > 576 - this->position.h) {
	//	isMoving = false;
	//	return;
	//}

	if (!Global::HAS_UP_MAP) {
		if (this->destY + 10 < 0) {
			isMoving = false;
			return;
		}
	}
	if (!Global::HAS_LEFT_MAP) {
		if (this->destX + 16 < 0) {
			isMoving = false;
			return;
		}
	}
	if (!Global::HAS_RIGHT_MAP) {
		if (this->destX - 16 > 1024 - this->position.w) {
			isMoving = false;
			return;
		}

	}
	if (!Global::HAS_DOWN_MAP) {
		if (this->destY > 576 - this->position.h) {
			isMoving = false;
			return;
		}

	}
	int tileCoordX = ((int)(this->destX + 16)) / 48;
	int tileCoordY = ((int)(this->destY + 10)) / 48;

	if (!tilemap.validTile(tileCoordX, tileCoordY)) {
		isMoving = false;
		return;
	}

	isMoving = true;
	switch (direction) {
		case Up:
			this->movingDirection = Up;
			if (this->posY - YVEL_ < this->destY) {
				this->posY = this->destY;
				break;
			}
			this->posY -= YVEL_;
			break;
		case Down:
			this->movingDirection = Down;
			if (this->posY + YVEL_ > this->destY) {
				this->posY = this->destY;
				break;
			}
			this->posY += YVEL_;
			break;
		case Left:
			this->movingDirection = Left;
			if (this->posX - XVEL_ < this->destX) {
				this->posX = this->destX;
				break;
			}
			this->posX -= XVEL_;
			break;
		case Right:
			this->movingDirection = Right;
			if (this->posX + XVEL_ > this->destX) {
				this->posX = this->destX;
				break;
			}
			this->posX += XVEL_;
			break;

		default:
			break;
	}

	this->position.x = (int)this->posX;
	this->position.y = (int)this->posY;

	/*std::cout << "Player has moved " << direction << std::endl;*/
}

void Player::handleInput(Tilemap& tilemap) {
	// Read key states
	float position = 48.00;
	if (!this->isMoving) {
		const Uint8* keyState = SDL_GetKeyboardState(NULL);
		if (keyState[SDL_SCANCODE_W]) {
			this->destX = this->posX;
			this->destY = this->posY - position;
			//std::cout << "moving to " << this->destX << " : " << this->destY << std::endl;
			this->move(Up, tilemap);
		}
		else if (keyState[SDL_SCANCODE_S]) {
			this->destX = this->posX;
			this->destY = this->posY + position;
			//std::cout << "moving to " << this->destX << " : " << this->destY << std::endl;
			this->move(Down, tilemap);
		}
		else if (keyState[SDL_SCANCODE_D]) {
			//std::cout << "moving from " << this->posX << " : " << this->posY << std::endl;
			this->destX = this->posX + position;
			this->destY = this->posY;
			//std::cout << "moving to " << this->destX << " : " << this->destY << " " << position << std::endl;
			this->move(Right, tilemap);
		}
		else if (keyState[SDL_SCANCODE_A]) {
			//std::cout << "moving from " << this->posX << " : " << this->posY << std::endl;
			this->destX = this->posX - position;
			this->destY = this->posY;
			//std::cout << "moving to " << this->destX << " : " << this->destY << " " << position << std::endl;
			this->move(Left, tilemap);
		}
		else if (keyState[SDL_SCANCODE_SPACE]) {
			this->projectileCoolDown = SDL_GetTicks();
			if (!keepTrackTime) {
				timeTracker = this->projectileCoolDown;
				keepTrackTime = true;
			}
			if (projectileCoolDown - timeTracker >= 1000 || firstShot) {
				firstShot = false;
				std::string filePath = "/assets/bullet.png";
				std::cout << "Shooting projectile at " << this->posX << ":" << this->posY << std::endl;
				this->projectiles.emplace_back(filePath.c_str(), this->posX + 8, this->posY + 10, Down);
				keepTrackTime = false;
			}
			else {
				std::cout << "Projectile is on cooldown, time passed is " << this->projectileCoolDown - timeTracker << std::endl;
			}
		}
	}
}

void Player::syncPos() {
	this->posX = this->position.x;
	this->posY = this->position.y;
}

void Player::resetDest(float offsetX, float offsetY) {
	this->destX = offsetX;
	this->destY = offsetY;
}

void Player::destroyProjectile(int vectorPos) {
	this->projectiles.erase(this->projectiles.begin() + vectorPos);
}