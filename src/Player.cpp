#include "Player.h"
#include <iostream>
#include "Game.h"
#include "Global.h"


Player::Player(const char * filePath) : Entity(filePath), isMoving(false), sprite(texture, 2), hp(100), mana(100), destX(0), destY(0), movingDirection(Stop) {

	// Create position at center of screen

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

void Player::update() {
	if (this->isMoving) {
		switch (this->movingDirection) {
			case Up:
				if (this->position.y <= (int)this->destY) {
					this->position.y = (int)this->destY;
					isMoving = false;
				}
				break;
			case Down:
				if (this->position.y >= this->destY) {
					this->position.y = this->destY;
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
				if (this->position.x >= this->destX) {
					this->position.x = this->destX;
					isMoving = false;
				}
				break;
		}
	}
	if (this->isMoving) {
		this->move(this->movingDirection);
	}
}

void Player::render() {
	this->sprite.animateSprite(this->position);
}



void Player::move(Directions direction) {

	float XVEL_ = 300 * Global::timeElapsed, YVEL_ = 300 * Global::timeElapsed;

	if (this->destX + 16 < 0 || this->destY + 10 < 0 || this->destX - 16 > 1024 - this->position.w || this->destY > 576 - this->position.h) {
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

void Player::handleInput() {
	// Read key states
	float position = 48.00;
	if (!this->isMoving) {
		const Uint8* keyState = SDL_GetKeyboardState(NULL);
		if (keyState[SDL_SCANCODE_W]) {
			this->destX = this->posX;
			this->destY = this->posY - (float) 48.00;
			std::cout << "moving to " << this->destX << " : " << this->destY << std::endl;
			this->move(Up);
		}
		else if (keyState[SDL_SCANCODE_S]) {
			this->destX = this->posX;
			this->destY = this->posY + (float)48.00;
			std::cout << "moving to " << this->destX << " : " << this->destY << std::endl;
			this->move(Down);
		}
		else if (keyState[SDL_SCANCODE_D]) {
			std::cout << "moving from " << this->posX << " : " << this->posY << std::endl;
			this->destX = this->posX + position;
			this->destY = this->posY;
			std::cout << "moving to " << this->destX << " : " << this->destY << " " << position << std::endl;
			this->move(Right);
		}
		else if (keyState[SDL_SCANCODE_A]) {
			std::cout << "moving from " << this->posX << " : " << this->posY << std::endl;
			this->destX = this->posX - position;
			this->destY = this->posY;
			std::cout << "moving to " << this->destX << " : " << this->destY << " " << position << std::endl;
			this->move(Left);
		}
	}
}

