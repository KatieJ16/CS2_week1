
// game.hpp


/**
* @brief A class for the game of tic-tac-toe
*/

class Game
{
private:
    Board board;
    int player;
    
public:
    Game();
    void turn();
    void run();
};
