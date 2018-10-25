#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector> 

class Player {
private:
	//private members
	string name;
	int num_of_cards;
	bool winner = false;
	bool played_cd = false;
	bool played_stop = false;
	//vector of cards
	vector<Card> cards;

public:
	//public members
	Player(string name, int num_of_cards) :name(name), num_of_cards(num_of_cards) {};
	bool play(Card&);
	void add_cards(int num_of_cards);
	bool is_winner() { return winner; }
	bool has_played_cd() { return played_cd; }
	bool has_played_stop() { return played_stop; }
	void zero_played_cd() { this->played_cd = false; }
	void zero_played_stop() { this->played_stop = false; }
};
#endif



