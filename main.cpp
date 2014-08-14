// Olga Rocheeva
// Purpose: Plays game of Tic Tac Toe

#include <iostream>
#include "tictactoe.h"
using namespace std;


void welcome();
void clearScreen();

int main()
{
    // TicTacToe gameboard;
    
    int row, col;
    char answer = 'y';
    bool xTurn = true;
    char winningPiece;
    char xPiece = 'X';
    char oPiece = 'O';
    char tie = 'T';
    int moves = 0;
    bool win = false;
    
    
    
    TicTacToe newGameboard;
    
    
    welcome();
    
    cout << "Would you like to play?(y/n): ";
    cin >> answer;
    
    clearScreen();
    
    while (tolower(answer) == 'y'){
        TicTacToe gameboard;
        while (!win){
            gameboard.displayBoard();
            if (xTurn){
                cout << "X, it is your turn." << endl;
                cout << "Which row? ";
                cin >> row;
                cout << "Which column? ";
                cin >> col;
                if (gameboard.placePiece(xPiece, row, col)) {
                    moves++;
                    win = gameboard.findMatches(xPiece);
                    if (win)
                        winningPiece = xPiece;
                    xTurn = false;
                } else {
                    cout << "Bad location, try again." << endl;
                }
            }else{
                cout << "O, it is your turn." << endl;
                cout << "Which row? ";
                cin >> row;
                cout << "Which column? ";
                cin >> col;
                if (gameboard.placePiece(oPiece, row, col)){
                    moves++;
                win = gameboard.findMatches(xPiece);
                   if (win)
                    winningPiece = oPiece;
                    xTurn = true;
                }
                else
                    cout << "Bad location, try again." << endl;
            }
        
        // Display board with the final results of the game
        // gameboard.displayBoard();
        }
        
     if (winningPiece == xPiece){
            gameboard.collectStats(xPiece);
            cout << "X won! Congratulations!" << endl;
        }else if (winningPiece == oPiece){
            cout << "O won! Congratulations!" << endl;
                 gameboard.collectStats(oPiece);
        }
        else if (moves == 9){
            winningPiece = tie;
            cout << "No winner - it was a tie!" << endl;
            gameboard.collectStats(tie);
        }
        
   
        
        // Displays all game stats
        gameboard.stats();
        
        cout << "Do you want to play again? ";
        cin >> answer;
    
    }
    return 0;
}
void welcome()
{
    cout << endl << "Welcome!" << endl;
}

void clearScreen()
{
        cout << string( 50, '\n' );
}
