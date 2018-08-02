#include "Player.h"
#include <iostream>

Player::Player(const char * filePath) : Object(filePath), hp(100), mana(100) {
	// Create position at center of screen
	this->position.x = (800 / 2) - (16);
	this->position.y = (600 / 2) - (16);
	this->position.w = 32;
	this->position.h = 32;
	std::cout << "Created player" << std::endl;
}

Player::~Player() {
	std::cout << "Deleting player now" << std::endl;
}

void Player::update() {

	std::cout << "Updating player to position" << position.x << " x " << position.y << std::endl;

}

