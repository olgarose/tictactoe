// Olga Rocheeva
// tictactoe.cpp

// Implementation file for tic tac toe class

#include "tictactoe.h"
#include <iostream>
#include <iomanip>
using namespace std;

TicTacToe::TicTacToe()
{
    vertical = '|';
    dash = '-';
    space = ' ';
    col_width = 3;
    size = 3;
    board = nullptr;
    
    xWins = 0;
    oWins = 0;
    gameTies = 0;

createTwoDimArray();
}

TicTacToe::~TicTacToe()
{
    for (int i = 0; i < size; ++i){
        
        delete [] board[i];
    }
    delete [] board;
}

void TicTacToe::gameStats()
{
    cout << "X has won " << xWins << " times." << endl
    << "O has won " << oWins << " times." << endl
    << "There have been " << gameTies << " ties." << endl;
    
}
void TicTacToe::resetBoard()
{
 
}
void TicTacToe::createTwoDimArray()
{
    board = new char*[size];
    for(int i = 0; i < size; i++)
    {
        board[i] = new char[size];
    }
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            board[r][c] = ' ';
}

void TicTacToe::displayBoard()
{
    
    cout << endl << endl;
    for (int i = 0; i < col_width - 1; i++)
        cout << space;
    for (int i = 0; i < size; i++)
        cout << setw(col_width) << i;
    cout << endl;
    for (int r = 0; r < size; r++){
        cout << setw(col_width) << r;
        for (int c = 0; c < size; c++)
            cout << space<< board[r][c]<< vertical;
        cout << endl;
        for (int i = 0; i < size; i++)
            cout << space;
        for (int d = 0; d < size * col_width; d++)
            cout << dash;
        cout << endl;
    }
}

void TicTacToe::welcome()
{
    cout << endl << "Hi! Welcome!" << endl;
}

TicTacToe TicTacToe::operator=(const TicTacToe &right)
{
    resetBoard();
    // TODO: copy previous board into a new board

    return *this;
}

bool TicTacToe::placePiece(char piece, int row, int col)
{
    if (row >= 0 && row < size &&
        col >= 0 && col < size && board[row][col] == space){
        board[row][col] = piece;
        cout << board[row][col] << endl;
        return true;
    }else
        return false;
}

bool TicTacToe::winner(char &piece)
{
    bool win = false;
    
    for (int row = 0; row < size; row++) {
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2] && board[row][0] != space) {
            piece = board[row][0];
            win = true;
        }
    }
    
    // Check columns
    for (int col = 0; col < size; col++) {
        if (board[0][col] == board[1][col] && board[0][col] == board[2][col] && board[0][col] != space) {
            piece = board[col][0];
            win = true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != space) {
        piece = board[0][0];
        win = true;
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != space) {
        piece = board[2][0];
        win = true;
    }
    // check ties
    int moves = 0;
	for(int i = 0; i < size; i++) {
		for(int j=0; j < size; j++) {
			if (board[i][j] != space) {
                moves++;
            }
        }
    
    if (moves == 9) {
        piece = gameTies;
        win = true;
    }
        
    }
    return win;
}

void TicTacToe::goodBye()
{
    cout << endl << "Thanks for playing, goodbye!" << endl;
}
