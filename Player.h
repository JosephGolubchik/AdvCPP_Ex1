/* Yosef Golubchik 209195353 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector> 

class Player {
private:
	//private members
	string name;
	int num_of_cards;
	//vector of cards
	vector<Card> cards;
	sign curr_sign;

public:
	//public members
	Player() {};
	Player(string name, int num_of_cards) :name(name), num_of_cards(num_of_cards), curr_sign(NAS) {};
	Player(const Player& p);
	Player operator= (const Player& p);
	bool play(Card& c);
	void add_cards(const int& num_of_cards);
	bool is_winner() const { return cards.empty(); }
	sign get_curr_sign() const { return curr_sign; }
	void set_curr_sign(const sign& new_sign) { curr_sign = new_sign; }
	string get_name() const { return name; }
	void reset_curr_sign() { curr_sign = NAS; }
};
#endif

























