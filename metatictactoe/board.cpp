// Board.cpp

#include <iostream>
#include "board.hpp"

using namespace std;

/**
* @brief Constructs a blank board.
*/
Board::Board()
{
	//fill blank board
    for (int i = 0; i < 3; i ++){
		for (int j = 0; j < 3; j ++){
		squares[i][j] = ' ';
		}
	}
	
}


/** 
 *  @brief finds the value of a given square
 *  
 *  @param row row of the desired square
 *  @param col colunm of the desired sqaure
 * 
 *  @return character representing what is in the space
 */

char Board::query(int row, int col){
	//given board coordinates, return a square state
	return squares[row][col];
}

/** 
 *  @brief places a char in the square, but only if the square is empty
 * 
 *  @param row row of desired sqaure
 *  @param col colunm of desired square
 *  @param XO char that will be places in square, should be either 'X' or 'O'
 */

void Board::place(int row, int col, char XO){
	if (query(row, col) == ' '){
		//fill blank square
		squares[row][col] = XO;
	} else {
		//when spot taken
		cout << "Spot Taken." << endl;
	}
}

/** 
 *  @brief prints the board in tic-tac-toe format
 */
void Board::display(){
	for (int i = 0; i < 3; i ++){
		for (int j = 0; j < 3; j ++){
			cout << squares[i][j]; 
			if (j < 2){
				cout << "|";
			}
		}
		if (i < 2){
			cout << endl << "-----" << endl;
		}
	}
	cout << endl;
}

/** 
 *  @brief checks to see if there is a winner
 * 
 *  @return boolean that represents whether someone won
 */
 
bool Board::checkWin(){
	for (int i = 0; i < 3; i ++){
		//check rows
		if(squares[i][0] == squares[i][1] and squares[i][1] == squares[i][2] and squares[i][1]!= ' '){
			return true;
		}
		//check cols
		if(squares[0][i] == squares[1][i] and squares[1][i] == squares[2][i] and squares[1][i]!= ' '){
			return true;
		}
	}
	//check diagonal 1
	if(squares[0][0] == squares[1][1] and squares[1][1] == squares[2][2] and squares[1][1]!= ' '){
		return true;
	}
	//check diagonal 2
	if(squares[2][0] == squares[1][1] and squares[1][1] == squares[2][0] and squares[1][1]!= ' '){
		return true;
	}
	return false;
}

/** 
 *  @brief checks to see if there is a draw
 * 
 *  @return boolean that represents whether there is a draw
 */

bool Board::checkDraw(){
	if (checkWin()){
		//no draw if win
		return false;
	}
	for (int i = 0; i < 3; i ++){
		for (int j = 0; j < 3; j ++){
			if (squares[i][j] == ' '){
				//if any squares, no draw
				return false;
			}
		}
	}
	return true;
}

