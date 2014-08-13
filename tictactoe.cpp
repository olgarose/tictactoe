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
    for (int i = 0; i < size; ++i){
        
        delete [] board[i];
    }
    delete [] board;
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
            cout << setw(col_width-1) << board[r][c]<< vertical;
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
    createTwoDimArray();
    // TODO: copy previous board into a new board
    
    return *this;
}

bool TicTacToe::placePiece(char piece, int row, int col)
{
    if (row >= 0 && row < size &&
        col >= 0 && col < size && board[row][col] == space){
        board[row][col] = piece;
        return true;
    }else
        return false;
}

bool TicTacToe::winner(char &piece)
{
    //   bool win = false;
    
    // TODO: Figure out how to search row and return if row matches so don't need
    // to hardcode in the win
    
    
    bool equals = false;
    
    /*
     int Xmatches = findMatches('X');
     int Omatches = findMatches('0');
     
     if (Omatches == size)
     {
     equals = true;
     }
     if (Xmatches == size){
     equals = true;
     }
     */
    return equals;
    
    
}
bool TicTacToe::findMatches(char piece)
{
    bool foundRows = false;
    bool foundCols = false;
    // bool foundDiag1 = false;
    
    int row = 0;
    int col = 0;
    while (row < size) {
        col = 0;
        while (col < size) {
            if (board[row][0] == board[row][col] && board[row][col] != space) {
                foundRows = true;
            } else {
                foundRows = false;
            }
            col++;
        }
        if(foundRows) break;
        row++;
    }
    col++;
    
    col = 0;
    while (col < size) {
        row = 0;
        while (row < size) {
            if (board[0][col] == board[row][col] && board[row][col] != space) {
                foundCols = true;
            } else {
                foundCols = false;
            }
            
            row++;
        }
        if(foundCols) break;
        col++;
    }
/*
    col = 0;
    row = 0;
    while (col < size) {
        row = col;
        while (row < size - 1) {
            if (board[row][col] == board[row + 1][col + 1] && board[row][col] != space) {
                foundDiag1 = true;
            } else {
                foundDiag1 = false;
            }
            row++;
        }
        if(foundDiag1) break;
        col++;
    }

*/
    return foundRows || foundCols;
}


void TicTacToe::goodBye()
{
    cout << endl << "Thanks for playing, goodbye!" << endl;
}
void TicTacToe::stats()
{
    cout << "X won: " << xWins << endl;
    cout << "O won: " << oWins << endl;
    cout << "Ties: " << gameTies << endl;
    
}

void TicTacToe::collectStats(char piece)
{
    if (piece == 'X')
        xWins++;
    if (piece == 'T')
        gameTies++;
    if (piece == 'O')
        oWins++;
}

