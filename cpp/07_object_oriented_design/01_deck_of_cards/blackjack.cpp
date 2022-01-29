#include <iostream>
#include <algorithm>
#include "blackjack.hpp"


BlackjackPlayer::BlackjackPlayer() : _status(true), _sum(0), _count_one(0) {}

BlackjackPlayer::~BlackjackPlayer() {}

bool BlackjackPlayer::get_status() const {
	return _status;
}

bool BlackjackPlayer::check_will() {
	int will;

	std::cout << "Do you want to draw a card? (1: yes, 0: no)\n> ";
	std::cin >> will;

	if (will == 0) {
		_status = false;
		return false;
	}

	return true;
}

void BlackjackPlayer::draw(int card) {
	_cards.push_back(card);
	_scards.push_back(card2str(card));

	_sum += std::min(card % 14, 10);
	if (_sum > 21)
		_status = false;

	if (card % 14 == 1)
		++_count_one;
}

void BlackjackPlayer::show() const {
	std::cout << "Hand: ";
	for (auto itr = _scards.rbegin(); itr != _scards.rend(); ++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

int BlackjackPlayer::calc_score() const {
	if (_sum > 21)
		return -1;

	unsigned int score = _sum;
	for (unsigned int i = 0; i < _count_one; ++i) {
		if (score + 10 > 21)
			break;
		score += 10;
	}

	return score;
}


Blackjack::Blackjack(unsigned int num_players) : Deck(false) {
	_players.resize(num_players);
}

Blackjack::~Blackjack() {}

void Blackjack::start() {
	shuffle();

	for (;;) {
		bool status = false;

		for (unsigned int i = 0; i < _players.size(); ++i) {
			if (!_players[i].get_status())
				continue;

			std::cout << "\n====================\n";
			std::cout << "Player " << i << "'s turn\n";
			_players[i].show();

			if (!_players[i].check_will())
				continue;
			
			int c = draw();
			_players[i].draw(c);
			std::cout << "Draw " << card2str(c) << std::endl;
			status = true;
		}

		if (!status)
			break;
	}

	std::cout << "\n====================\nResults\n";

	std::vector<int> winner(1, -1);
	int best_score = 22;
	for (unsigned int i = 0; i < _players.size(); ++i) {
		int score = _players[i].calc_score();

		if ((21 - score) < best_score) {
			best_score = 21 - score;
			winner.clear();
			winner.push_back(i);
		} else if ((21 - score) == best_score) {
			winner.push_back(i);
		}

		std::cout << "Player " << i << ": ";
		if (score == 22)
			std::cout << "over" << std::endl;
		else
			std::cout << score << std::endl;
	}

	std::cout << "Winner: ";
	if (winner[0] == -1) {
		std::cout << "No one" << std::endl;
	} else {
		std::cout << "Player ";
		for (unsigned int i = 0; i < winner.size(); ++i) {
			std::cout << winner[i];
			if (i != winner.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
	}
}
