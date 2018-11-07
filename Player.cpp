/* Yosef Golubchik 209195353 */

#include "Player.h"

bool Player::play(Card& c) {
	int choice;
	Card chosen_card;
	
	cout << "current: " << c << endl;
	cout << this->name + ", your turn -" << endl;
	cout << "Your cards: ";
	for (int i = 0; i < this->num_of_cards; i++) {
		cout << "(" + to_string( (long long)(i + 1) ) + ")" << this->cards.at(i) << " ";
	}
	cout << endl;

	while (true) {
		// Get player's choise of card
		cin >> choice;
		
		// If the player chose a card number outside the range
		if (choice < 1 || choice > num_of_cards) {
			this->add_cards(1);
			this->num_of_cards++;
			return 0;
		}
		
		// If the player chose a card number inside the range
		else {
			// Choose card number 'choice' from the player's deck
			chosen_card = this->cards.at(choice - 1);
			
			// If the chosen card can be placed
			if (c.is_leggal(chosen_card)) {
				// Change the current card to be the chosen card
				c = chosen_card;
				// Set current player's sign to the current card's sign
				curr_sign = c.get_sign();
				// Erase the chosen card from current player's deck
				this->cards.erase(cards.begin() + choice - 1);
				this->num_of_cards--;
				
				return 1;
			}
			
			// If the chosen card can't be placed
			else {
				cout << "You can't put " << chosen_card << " on " << c << endl;
			}
		}
	}
	
}

void Player::add_cards(const int& num_of_cards) {
	for (int i = 0; i < num_of_cards; i++)
	{
		this->cards.push_back(generate_card());
	}
}

Player::Player(const Player& p) {
	name = p.name;
	num_of_cards = p.num_of_cards;
	curr_sign = p.curr_sign;
	for (int i = 0; i < p.cards.size(); i++) {
		cards.push_back(p.cards.at(i));
	}
}

Player Player::operator= (const Player& p) {
	name = p.name;
	num_of_cards = p.num_of_cards;
	curr_sign = p.curr_sign;
	cards.clear();
	for (int i = 0; i < p.cards.size(); i++) {
		cards.push_back(p.cards.at(i));
	}
	return *this;
}

