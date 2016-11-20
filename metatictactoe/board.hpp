
// board.hpp

/**
* @brief A class for the board of tic-tac-toe
*/

class Board
{
private:
    char squares[3][3];
    
public:
    Board();
    char query(int row, int col);
    void place(int row, int col, char XO);
    void display();
    bool checkWin();
    bool checkDraw();
};
