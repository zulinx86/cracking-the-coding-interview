#include <algorithm>

#include "deck.hpp"


std::string card2str(int card) {
	if (card == 0)
		return "joker";

	int type = card / 14;
	int number = card % 14;

	std::string str;
	if (type == 0) {
		str += 'C';
	} else if (type == 1) {
		str += 'S';
	} else if (type == 2) {
		str += 'H';
	} else if (type == 3) {
		str += 'D';
	}

	return str + std::to_string(number);
}


Deck::Deck() : Deck::Deck(true) {}

Deck::Deck(bool joker) : _idx(0), _joker(joker) {
	for (int i = 0; i < 4; ++i)
		for (int j = 1; j <= 13; ++j)
			_cards.push_back(i * 14 + j);

	if (_joker) {
		_cards.push_back(0);
		_cards.push_back(0);
	}
}

void Deck::shuffle() {
	std::mt19937 engine(_seed());
	std::shuffle(_cards.begin(), _cards.end(), engine);
}

int Deck::draw() {
	if (_idx == _cards.size())
		return -1;

	return _cards[_idx++];
}
