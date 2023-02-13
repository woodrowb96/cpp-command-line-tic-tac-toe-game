/*
 * this file is the main function for a game of tic tac toe
 */
#include "Tic_tac_toe.h"
#include <iostream>

using Tic_tac_toe::Game;
using Tic_tac_toe::player_one;
using Tic_tac_toe::player_two;

int main(){

	Game game;
	while(game.play()){ //while player still wants to play
		while(game.state()){	//play until draw, or someone wins
			game.player_move(player_one);
			if(!game.state()) break;	//check if move resulted in draw or win
			game.player_move(player_two);
		}
	}	
		
	
	return 0;
}
