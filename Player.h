#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector> 

class Player {
private:
	//private members
	string name;
	int num_of_cards;
	bool winner;
	sign cs;
	//vector of cards
	vector<Card> cards;

public:
	//public members
	Player(string name, int num_of_cards) :name(name), num_of_cards(num_of_cards), cs(NAS), winner(false) {};
	bool play(Card&);
	void add_cards(int num_of_cards);
	bool is_winner() { return winner; }
	sign getCS() { return cs; }
	void resetCS() { cs = NAS; }
};
#endif



