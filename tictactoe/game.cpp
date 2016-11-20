// game.cpp

#include <iostream>
#include "game.hpp"

using namespace std;


/**
* @brief Constructs a blank Game, with blank board and player1's turn.
*/
Game::Game()
{
    Board board;
    player = 1;
    
}

/** 
 *  @brief Executes one turn
 *  
 *  Asks for row, col and enters into board
 */
 
void Game::turn(){
	int row, col;
	//getting row and col from player
	cout << "Player" << player << "'s turn. Enter row:";
	cin >> row;
	cout << "Enter column: ";
	cin >> col;
	//placing 'X' for player1 and 'O' for player2
	if (player == 1){
		board.place(row - 1, col - 1, 'X');
	} else {
		board.place(row - 1, col - 1, 'O');
	}
	board.display();
}

/** 
 *  @brief Runs the game, stops when there is a winning or draw
 */

void Game::run(){
	cout << "Let's play Tic-Tac-Toe"<< endl;
	bool playing = true;
	while (playing){
		turn();
		if (board.checkWin()){
			playing = false;
			cout << "Player" << player << " wins!!!" << endl;
		} else if (board.checkDraw()){
			playing = false;
			cout << "Draw :(" << endl;
		}
		//change player
		if (player == 1){
			player = 2;
		} else {
			player = 1;
	}
	}
}


