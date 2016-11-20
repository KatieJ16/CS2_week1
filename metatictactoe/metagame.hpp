
// metagame.hpp


/**
* @brief A class for the game of tic-tac-toe
*/

class Game
{
private:
    Board board[3][3];
    int player;
    int player1Score;
    int player2Score;
    int boardState[9];
    
public:
    Game();
    void metaDisplay();
    void turn();
    void run();
    int findWinner();
};
