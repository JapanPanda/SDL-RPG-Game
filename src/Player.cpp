#include "Player.h"
#include <iostream>



Player::Player(const char * filePath) : Entity(filePath), sprite(texture, 2), hp(100), mana(100) {

	// Create position at center of screen
	this->position.x = (1024 / 2) - (48);
	this->position.y = (576 / 2) - (48);
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

const int XVEL_ = 16, YVEL_ = 16;

void Player::move(Directions direction) {
	switch (direction) {
		case Up:
			if (this->position.y - YVEL_ >= 0) {
				this->position.y -= YVEL_;
			}
			break;
		case Down:
			if (this->position.y + YVEL_ <= 576 - this->position.h) {
				this->position.y += YVEL_;
			}
			break;
		case Left:
			if (this->position.x - XVEL_ >= 0) {
				this->position.x -= XVEL_;
			}
			break;
		case Right:
			if (this->position.x + XVEL_ <= 1024 - this->position.w) {
				this->position.x += XVEL_;
			}
			break;
		case DiagonalLD:
			if (this->position.x - XVEL_ >= 0) {
				this->position.x -= XVEL_;
			}
			if (this->position.y + YVEL_ <= 576 - this->position.h) {
				this->position.y += YVEL_;
			}
			break;
		case DiagonalLU:
			if (this->position.x - XVEL_ >= 0) {
				this->position.x -= XVEL_;
			}
			if (this->position.y - YVEL_ >= 0) {
				this->position.y -= YVEL_;
			}
			break;
		case DiagonalRD:
			if (this->position.x + XVEL_ <= 1024 - this->position.w) {
				this->position.x += XVEL_;
			}
			if (this->position.y + YVEL_ <= 576 - this->position.h) {
				this->position.y += YVEL_;
			}
			break;
		case DiagonalRU:
			if (this->position.x + XVEL_ <= 1024 - this->position.w) {
				this->position.x += XVEL_;
			}
			if (this->position.y - YVEL_ >= 0) {
				this->position.y -= YVEL_;
			}
			break;
		default:
			break;
	}
	/*std::cout << "Player has moved " << direction << std::endl;*/
}

void Player::handleInput() {
	// Read key states
	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	if (keyState[SDL_SCANCODE_W] && keyState[SDL_SCANCODE_A]) {
		this->move(DiagonalLU);
	}
	else if (keyState[SDL_SCANCODE_W] && keyState[SDL_SCANCODE_D]) {
		this->move(DiagonalRU);
	}
	else if (keyState[SDL_SCANCODE_S] && keyState[SDL_SCANCODE_A]) {
		this->move(DiagonalLD);
	}
	else if (keyState[SDL_SCANCODE_S] && keyState[SDL_SCANCODE_D]) {
		this->move(DiagonalRD);
	}
	else if (keyState[SDL_SCANCODE_W]) {
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

