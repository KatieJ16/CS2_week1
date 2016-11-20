// metagame.cpp

#include <iostream>
#include "metagame.hpp"

using namespace std;


/**
* @brief Constructs a blank Game, with blank boards and player1's turn.
*/
Game::Game(){
    player = 1;
    player1Score = 0;
    player2Score = 0;
    for (int i = 0; i < 9; i ++){
		boardState[i] = 0;
	}
    
}
/**
 * @brief Displays the metaTicTacToe board
 */

void Game::metaDisplay(){
	 for (int boardRow = 0; boardRow < 3; boardRow ++){
		 for (int row = 0; row < 3; row ++){
			for (int boardCol = 0; boardCol < 3; boardCol ++){
				for (int col = 0; col < 3; col ++){
					cout << board[boardRow][boardCol].query(row, col) << "|";
				}
			}
			cout << endl << "------------------" << endl;
		 }
	 }
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
	//adjust to right board
	int boardRow, boardCol;
	if (row <= 3){
		boardCol = 0;
	} else if (row <= 6){
		boardCol = 1;
	} else {
		boardCol = 2;
	}
	
	if (col <= 3){
		boardRow = 0;
	} else if (col <= 6){
		boardRow = 1;
	} else {
		boardRow = 2;
	}
		
	//placing 'X' for player1 and 'O' for player2
	if (player == 1){
		board[boardRow][boardCol].place((row - 1) % 3, (col - 1) % 3, 'X');
	} else {
		board[boardRow][boardCol].place((row - 1) % 3, (col - 1) % 3, 'O');
	}
	metaDisplay();
}

/** 
 *  @brief Runs the game, stops when there is a winning or draw
 */

void Game::run(){
	int quit;
	int numBoardsDone;
	cout << "Let's play Tic-Tac-Toe"<< endl;
	bool playing = true;
	while (playing){
		turn();
		for(int i = 0; i < 3; i ++){
			for (int j = 0; j < 3; j ++){
				if (boardState[i] == 0){
					if (board[i][j].checkWin()){
						cout << "Player" << player << " wins a board!!!" << endl;
						if(player == 1){
							player1Score ++;
						} else{
							player2Score ++;
						}
						numBoardsDone ++;
						boardState[i] ++;
					} else if (board[i][j].checkDraw()){
						numBoardsDone ++;
						cout << "Draw on board:(" << endl;
						boardState[i] ++;
					}
				}
			}
			if (numBoardsDone == 9){
				playing = false;
			} 
		}
		//change player
		if (player == 1){
			player = 2;
		} else {
			player = 1;
		}
		cout << "Quit? (0 for yes)";
		cin >> quit;
		if (quit == 0){
			playing = false;
		}
	}
}

int Game::findWinner(){
	if(player1Score > player2Score){
		return 1;
	}
	if (player1Score < player2Score){
		return 2;
	}
	return 0;
}
