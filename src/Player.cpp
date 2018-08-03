#include "Player.h"
#include <iostream>



Player::Player(const char * filePath) : Entity(filePath), isMoving(false), sprite(texture, 2), hp(100), mana(100) {

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

	/*std::cout << "Updating player to position" << position.x << " x " << position.y << std::endl;*/
//	this->position.x += this->xVel;
//	this->position.y += this->yVel;
}

void Player::render() {
	this->sprite.animateSprite(this->position);
}

const int XVEL_ = 5, YVEL_ = 5;

void Player::move(Directions direction) {
	switch (direction) {
		case Up:
			if (this->position.y - YVEL_ >= 0) {
				this->position.y -= YVEL_;
			}
			else {
				this->position.y = 0;
			}
			break;
		case Down:
			if (this->position.y + YVEL_ <= 576 - this->position.h) {
				this->position.y += YVEL_;
			}
			else {
				this->position.y = 576 - this->position.h;
			}
			break;
		case Left:
			if (this->position.x - XVEL_ >= 0) {
				this->position.x -= XVEL_;
			}
			else {
				this->position.x = 0;
			}
			break;
		case Right:
			if (this->position.x + XVEL_ <= 1024 - this->position.w) {
				this->position.x += XVEL_;
			}
			else {
				this->position.x = 1024 - this->position.w;
			}
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
			this->move(Up);
		}
		else if (keyState[SDL_SCANCODE_S]) {
			this->move(Down);
		}
		else if (keyState[SDL_SCANCODE_D]) {
			this->move(Right);
		}
		else if (keyState[SDL_SCANCODE_A]) {
			this->move(Left);
		}
	}
}

