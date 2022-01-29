#include "player.hpp"

Player::Player() {}

Player::~Player() {}

void Player::draw(int card) {
	_cards.push_back(card);
}

