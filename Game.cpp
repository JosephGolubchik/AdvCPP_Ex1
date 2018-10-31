#include "Game.h"

void Game::start() {
	current = generate_card();
	cout << "How many players?" << endl;
	cin >> this->num_of_players;
	if (this->num_of_players <= 0) {
		cout << "Number of players must be a positive integer" << endl;
		over = true;
	}
	if (!over) {
		cout << "How many cards?" << endl;
		cin >> this->init_num_of_cards;
	}
	if (this->init_num_of_cards <= 0 && !over) {
		cout << "Number of cards must be a positive integer" << endl;
		over = true;
	}
	if (!over) {
		for (int i = 0; i < this->num_of_players; i++)
		{
			string name;
			cout << "Player number " + to_string((long long)(i + 1)) + " name?" << endl;
			cin >> name;
			this->players.push_back(Player(name, init_num_of_cards));
			this->players.at(i).add_cards(init_num_of_cards);
		}
		current = generate_card();
	}
	while (!over) {
		this->players.at(turn).play(this->current);
		if (this->players.at(turn).is_winner()) {
			over = true;
		}
		else if (this->players.at(turn).getCS() == CD) {
			direction = -direction;
		}
		else if (this->players.at(turn).getCS() == STOP) {
			turn += direction;
		}
		turn += direction;
		this->normalize_turn();
		this->players.at(turn).resetCS();
	}

}

void Game::normalize_turn() {
	if (turn < 0) {
		while (turn < 0) {
			turn += this->num_of_players;
		}
	}
	else {
		turn = turn % num_of_players;
	}
}
