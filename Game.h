#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
class Game {
private:
	//private members and functions
	int turn;
	int direction;
	int num_of_players;
	int init_num_of_cards;
	bool over = false;
	Card current;
	vector<Player> players;
public:
	//public members and functions
	Game() :turn(0), direction(1) {};
	void start();
	void normalize_turn();
};
#endif




