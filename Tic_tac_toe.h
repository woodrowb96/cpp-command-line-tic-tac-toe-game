/*
 * This header file declares the Game and Board class
 * both classes are placed in a single Tic_tac_toe namespace, so they can share some
 * constants between them
 */
#include <unordered_map>
#include <string>

namespace Tic_tac_toe{

	//symbols to represent players one and two, and an empty spot on the board
	static const char player_one = 'x'; 
	static const char player_two = 'o';
	static const char empty = ' ';
	
	//symbols to represent player wins
	static const char player_one_win = player_one;
	static const char player_two_win = player_two;

	//a still playing game is represented by the empty charcter
	static const char still_playing  = empty;

	//a draw is represented by a d
	static const char draw  = 'd';


	//the board class describes a tic tac toe board
	//the board uses the following coordinate system 
	//    1  2  3
	// A  A1 A2 A3
	// B  B1 B2 B3
	// C  C1 C2 C3	
	class Board{
	
		public:
			Board();
			bool place_mark(std::string,char);
			void print();
			void clear();
			char state();

		private:
			//the game board is represented as an unordered map
			//the keys of the map are strings indicating the coord we are accessing
			//each key is used to access whatever charecter should be displayed 
			//at that coord, i.e x,o or empty
			std::unordered_map<std::string,char> board; 
		
			//a constant map representing an empty board	
			static const std::unordered_map<std::string,char> empty_board;
		};

	//this class describes a game of tic tac toe
	//a game is made up of a board, from the Board class
	class Game{
		public: 
			bool play();
			bool state();
			void player_move(char player);

		private:
			Board board;
	};
}
