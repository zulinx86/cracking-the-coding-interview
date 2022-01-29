#include <iostream>
#include "blackjack.hpp"


int main(void)
{
	int num_players;
	std::cout << "How many players?\n> ";
	std::cin >> num_players;

	Blackjack bj(num_players);
	bj.start();

	return 0;
}
