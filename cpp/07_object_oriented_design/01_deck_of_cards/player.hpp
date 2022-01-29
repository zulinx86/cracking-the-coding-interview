#pragma once

#include <vector>

class Player {
public:
	Player();
	~Player();

	void draw(int card);

protected:
	std::vector<int> _cards;
};

