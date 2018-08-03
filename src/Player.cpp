#include "Player.h"
#include <iostream>
#include "Game.h"



Player::Player(const char * filePath) : Entity(filePath), isMoving(false), sprite(texture, 2), hp(100), mana(100), destX(0), destY(0), movingDirection(Stop) {

	// Create position at center of screen
	this->position.x = 480;
	this->position.y = 240 - 20;
	this->position.w = 48;
	this->position.h = 48;
	std::cout << "Created player" << std::endl;
}

Player::~Player() {
	std::cout << "Deleting player now" << std::endl;
}

void Player::update() {
	if (this->isMoving) {
		switch (this->movingDirection) {
			case Up:
				if (this->position.y <= this->destY) {
					isMoving = false;
				}
				break;
			case Down:
				if (this->position.y >= this->destY) {
					isMoving = false;
				}
				break;
			case Left:
				if (this->position.x <= this->destX) {
					isMoving = false;
				}
				break;
			case Right:
				if (this->position.x >= this->destX) {
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

const int XVEL_ = 4, YVEL_ = 4;

void Player::move(Directions direction) {
	if (this->destX < 0 || this->destY < 0 || this->destX > 1024 - this->position.w || this->destY > 576 - this->position.h) {
		std::cout << "Player tried to do an illegal move"  << destX << " : " << destY << std::endl;
		return;
	}
	isMoving = true;
	switch (direction) {
		case Up:
			this->movingDirection = Up;
			this->position.y -= YVEL_;
			break;
		case Down:
			this->movingDirection = Down;
			this->position.y += YVEL_;
			break;
		case Left:
			this->movingDirection = Left;
			this->position.x -= YVEL_;
			break;
		case Right:
			this->movingDirection = Right;
			this->position.x += YVEL_;
			break;

		default:
			break;
	}
	/*std::cout << "Player has moved " << direction << std::endl;*/
}

void Player::handleInput() {
	// Read key states

	if (!this->isMoving) {
		const Uint8* keyState = SDL_GetKeyboardState(NULL);
		if (keyState[SDL_SCANCODE_W]) {
			this->destX = this->position.x;
			this->destY = this->position.y - 48;
			std::cout << "moving to " << this->destX << " : " << this->destY << std::endl;
			this->move(Up);
		}
		else if (keyState[SDL_SCANCODE_S]) {
			this->destX = this->position.x;
			this->destY = this->position.y + 48;
			this->move(Down);
		}
		else if (keyState[SDL_SCANCODE_D]) {
			this->destX = this->position.x + 48;
			this->destY = this->position.y;
			this->move(Right);
		}
		else if (keyState[SDL_SCANCODE_A]) {
			this->destX = this->position.x - 48;
			this->destY = this->position.y;
			this->move(Left);
		}
	}
}

