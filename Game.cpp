/* Yosef Golubchik 209195353 */

#include "Game.h"

void Game::start() {
	int played;
	int steps_to_move;
	
	cout << "How many players?" << endl;
	cin >> num_of_players;
	if (num_of_players <= 0) {
		cerr << "Number of players must be a positive integer." << endl;
		return;
	}

	cout << "How many cards?" << endl;
	cin >> init_num_of_cards;
	if (init_num_of_cards <= 0) {
		cerr << "Number of cards must be a positive integer." << endl;
		return;
	}

	// Get the names of the players
	for (int i = 0; i < num_of_players; i++)
	{
		string name;
		cout << "player number " + to_string((long long)(i + 1)) + " name?" << endl;
		cin >> name;
		players.emplace_back(name, init_num_of_cards);
		players.at(i).add_cards(init_num_of_cards);
		
	}
	// Generate first card
	current = generate_card();
	
	while (true) {
		// By default move to the next turn after a turn
		steps_to_move = 1;
		
		// Start current player's turn
		players.at(turn).play(current);
		
		// If current player won, end the game
		if (players.at(turn).is_winner()) {
			cout << players.at(turn).get_name() + " wins!" << endl;
			return;
		}
		
		// If current player used a CD card:
		// Flip the direction of the game then move to the next turn
		if (players.at(turn).get_curr_sign() == CD) {
			direction = -direction;
		}
		
		// If current player used a STOP card:
		// Move two turns forward
		else if (players.at(turn).get_curr_sign() == STOP) {
			steps_to_move = 2;
		}
		
		// If player used a PLUS card:
		// The turn will not be changed and he will get another turn
		else if (players.at(turn).get_curr_sign() == PLUS){
			steps_to_move = 0;
		}
		
		// Change turn
		turn = turn + direction*steps_to_move;
		
		// Makes turn a number in the range [0, num_of_players)
		normalize_turn();
		
		// Reset current sign to default
		players.at(turn).reset_curr_sign();
		
		
	}

}

void Game::normalize_turn() {
	if (turn >= 0) {
		turn = turn % num_of_players;
	}
	// The modulo operator doesn't work correctly for negative numbers
	else {
		while (turn < 0) {
			turn += this->num_of_players;
		}
	}
}