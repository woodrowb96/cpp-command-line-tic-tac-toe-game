/*
 * this file contains definitions for the board class 
 * this class describes the game board used to play tic tac toe on
 */

#include "Tic_tac_toe.h"
#include <vector>
#include <iostream>

using namespace Tic_tac_toe;
using std::cout;


//constant map representing an empty game board
const std::unordered_map<std::string, char> Board::empty_board = {
							{"A1",empty},{"B1",empty},{"C1",empty},
							{"A2",empty},{"B2",empty},{"C2",empty},
							{"A3",empty},{"B3",empty},{"C3",empty}
							};


//default constructor
Board::Board():board{empty_board}{}; // inititialize board to empty 


//place a mark on the board
//checks if spot is a valid place to put a mark
//return false if its not
//returns true adn places mark if it is valid
bool Board::place_mark(std::string coordinate, char symbol){
	
	if(symbol != player_one && symbol != player_two) //if symbol to place was invalid
		return false;
	if(board.find(coordinate) == board.end()) //or if coord was not in map
		return false;
	if(board[coordinate] != empty)	//or if something else was already at that coord 
		return false;
			
	board[coordinate] = symbol;
	return true;
		
}

//this function prints the board to the screen
void Board::print(){
	cout <<"\n  A B C\n";
	cout << '1' << '|' << board["A1"] << '|' << board["B1"] << '|' << board["C1"] << "|\n";
	cout << '2'  << '|' << board["A2"] << '|' << board["B2"] << '|' << board["C2"] << "|\n";
	cout << '3'  << '|' << board["A3"] << '|' << board["B3"] << '|' << board["C3"] << "|\n";
}

//this fucntion clears the board
void Board::clear(){

	board = empty_board; // set board to be empty
}

//this funciton returns the state of the board
//the board can be in 4 different states
//player_one_win:return player one symbol
//player_two_win:return player two symbol
//draw: return d
//still_playing: return empty symbol
char Board::state(){

	//check if there are any winningconditions
	//if there is return the symbol that won, to indicate which player won the game	
	if(board["A1"] != empty)
		if(board["A1"] == board["A2"] && board["A1"] == board["A3"]) return board["A1"];
		else if(board["A1"] == board["B1"] && board["A1"] == board["C1"]) return board["A1"];
		else if(board["A1"] == board["B2"] && board["A1"] == board["C3"]) return board["A1"];

	if(board["B1"] != empty)
		if(board["B1"] == board["B2"] && board["B1"] == board["B3"]) return board["B1"];

	if(board["C1"] != empty)
		if(board["C1"] == board["C2"] && board["C1"] == board["C3"]) return board["C1"];

	if(board["A2"] != empty)
		if(board["A2"] == board["B2"] && board["A2"] == board["C2"]) return board["A2"];

	if(board["A3"] != empty)
		if(board["A3"] == board["B3"] && board["A3"] == board["C3"]) return board["A3"];
		else if(board["A3"] == board["B2"] && board["A3"] == board["C1"]) return board["A3"];

	//loop through the map
	for(auto p:board)
		//if we encounter an empty space, then the game is still active
		if(p.second == empty) return still_playing;		
	
	//if non of the above conditions are true then we are in a draw
	return draw;
}
