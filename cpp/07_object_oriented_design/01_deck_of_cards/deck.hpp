#pragma once

#include <vector>
#include <random>
#include <string>


std::string card2str(int card);

class Deck {
public:
	Deck();
	Deck(bool joker);
	~Deck() {}

	void shuffle();
	int draw();

protected:
	std::vector<int> _cards;
	unsigned int _idx;
	bool _joker;
	std::random_device _seed;
};

