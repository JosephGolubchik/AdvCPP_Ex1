/* Yosef Golubchik 209195353 */

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
	bool over;
	Card current;
	vector<Player> players;
	
	// Private copy constructor and = operator to avoid creating more than one instance of Game
	Game(const Game& game) {};
	Game operator= (const Game& p) {};
public:
	//public members and functions
	Game() :turn(0), direction(1), over(false) {};
	void start();
	void normalize_turn();
};
#endif




