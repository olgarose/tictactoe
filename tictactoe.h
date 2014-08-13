// Olga Rocheeva
//  tictactoe.h

// Definition of TicTacToe class

#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

class TicTacToe
{
public:
    TicTacToe();
    
    TicTacToe(int row, int col, char XorO);
    
    ~TicTacToe();
    
    void displayBoard();
    
    void resetBoard();
    
    void gameStats();    // displays wins for X, wins for O, and ties (may take arguments)
    
    void welcome();    // welcomes user to the TicTacToe game
    
    bool placePiece(char piece, int row, int col);    // returns result of attempt
    
    bool winner(char &piece);    // returns false if no winner else; returns true and piece
    
    void goodBye();    // goodbye message
    
    void createTwoDimArray();
    
    void stats();
    
    void collectStats (char piece);
    
    bool findMatches(char piece);
    
    TicTacToe operator=(const TicTacToe &right);
    
private:
    // building the tic tac toe board
    char vertical;
    char dash;
    int size;
    int col_width;
    char space;
    char **board;
    
    // overall game stats
    int oWins;
    int xWins;
    int gameTies;
    
    // current game pieces
    // char winningPiece;
    // int row;
    // int col;
    
};

#endif
