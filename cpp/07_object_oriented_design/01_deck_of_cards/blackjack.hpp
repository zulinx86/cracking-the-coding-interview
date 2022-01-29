#pragma once

#include <vector>
#include "deck.hpp"
#include "player.hpp"


class BlackjackPlayer : Player {
public:
	BlackjackPlayer();
	~BlackjackPlayer();

	bool get_status() const;
	bool check_will();
	void draw(int card);
	void show() const;
	int calc_score() const;

private:
	bool _status; /* true: active, false: ended */
	unsigned int _sum;
	unsigned int _count_one;
	std::vector<std::string> _scards;
};


class Blackjack : public Deck {
public:
	Blackjack(unsigned int num_players);
	~Blackjack();

	void start();

private:
	std::vector<BlackjackPlayer> _players;
};

