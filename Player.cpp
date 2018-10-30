#include "Player.h"

bool Player::play(Card& c) {
	int choice;
	Card chosen_card;
	cout << "current: " << c << endl;
	cout << this->name + ", your turn -" << endl;

	while (true) {
		cout << "Your cards:";
		for (int i = 0; i < this->num_of_cards; i++)
		{
			cout << "(" + to_string(i + 1) + ")" << this->cards.at(i) << " ";
		}
		cout << endl;
		cin >> choice;
		if (choice < 1 || choice > num_of_cards) {
			if (this->cs == TAKI) {
				return 1;
			}
			else {
				this->add_cards(1);
				this->num_of_cards++;
				return 0;
			}
		}
		else {
			chosen_card = this->cards.at(choice - 1);
			if (this->cs != TAKI)
				this->cs = chosen_card.get_sign();
			if (c.is_leggal(chosen_card, this->cs)) {
				c = chosen_card;
				this->cards.erase(cards.begin() + choice - 1);
				this->num_of_cards--;
				if (this->num_of_cards == 0) {
					cout << this->name + " wins!" << endl;
					this->winner = true;
				}
				if (this->cs == PLUS || this->cs == TAKI) {
					cout << "current: " << c << endl;
					continue;
				}
				return 1;
			}
			else {
				if (this->cs == TAKI) cout << "You can't put " << chosen_card << " on " << c << " in TAKI mode" << endl;
				else cout << "You can't put " << chosen_card << " on " << c << endl;
				this->resetCS();
			}
		}
	}
	
}

void Player::add_cards(int num_of_cards) {
	for (int i = 0; i < num_of_cards; i++)
	{
		this->cards.push_back(generate_card());
	}
}