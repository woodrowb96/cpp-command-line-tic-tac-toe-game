/*
 * this file contains definitions for the game class
 */

#include "Tic_tac_toe.h"
#include <iostream>
#include <string>

using namespace Tic_tac_toe;
using std::cout;
using std::cin;

//this fucntion is used to initialize and start the game
//returns true if the game is to be played
//false if not
bool Game::play(){

	board.clear(); //initialize the board

	cout << "Enter P to play or Q to Quit:";

	for(std::string prompt;cin >> prompt;)	//read prompt in until valid input
		if(prompt == "P") return true;
		else if(prompt == "Q") return false;
		else cout << "Invalid input, enter P to play or Q to quit:";
		
	return false;	
}

//this function gets the current state of the board
//it prints the board to the screen
//then checks if anyone has one, or if there is a draw
//it returns false if one of those has happend,
//else it returns true and the gamekeeps playing
bool Game::state(){

	board.print();

	switch(board.state()){ //check the state of the game board
		case player_one_win: 
			cout << "Game over:Player " << player_one << " has won!\n";
			return false;	
		case player_two_win: 
			cout << "Game over:Player " << player_two << " has won!\n";
			return false;	
		case draw: 
			cout << "Game over:Draw!\n";
			return false;	
		case still_playing: 	
			return true;	
	}	
	return true;
}

//this function is used to facilitate player moves
//it gets user input,in the form of coord to place a mark, then if valid coord it places a mark at that coord
void Game::player_move(char player){

	cout << "Player " << player << " enter coordinates to place mark(e.g. A1,B2,...):";
	
	for(std::string coordinate;cin >> coordinate;) //loop to get user input
		if(board.place_mark(coordinate,player)) break; //if placement was succesfull leave loop
		else cout << "Please Enter valid coordinate in form LetterNum(e.g. A1,B2,...):"; //else reprompt
}




