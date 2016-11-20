//metatictactoe.cpp

#include <iostream>
#include "board.cpp"
#include "metagame.cpp"

using namespace std;

/** 
 *  @brief makes a game instance and runs game
 */
 
int main(int argc, char ** argv){
	Game game;
	game.run();
	//determine and print winner
	int winner = game.findWinner();
	if (winner == 0) {
		cout << "Draw. Better luck next time :(" << endl;
	} else{
		cout << "Player" << winner << " wins!!!" << endl;
	}
	
}
