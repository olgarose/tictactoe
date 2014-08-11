// Olga Rocheeva
// Purpose: Plays game of Tic Tac Toe

#include <iostream>
#include "tictactoe.h"
using namespace std;

int main()
{
    TicTacToe gameboard;
    
    int row, col;
    char answer = 'y';
    bool xTurn = true;
    char winningPiece;
    
    gameboard.welcome();
    cout << "Would you like to play?(y/n): ";
    cin >> answer;
    
    // while (tolower(answer) == 'y'){
     while (!gameboard.winner(winningPiece)){
            gameboard.displayBoard();
            if (xTurn){
                cout << "X, it is your turn." << endl;
                cout << "Which row? ";
                cin >> row;
                cout << "Which column? ";
                cin >> col;
                if (gameboard.placePiece('X', row, col))
                    xTurn = false;
                else
                    cout << "Bad location, try again." << endl;
            }else{
                cout << "O, it is your turn." << endl;
                cout << "Which row? ";
                cin >> row;
                cout << "Which column? ";
                cin >> col;
                if (gameboard.placePiece('O', row, col))
                    xTurn = true;
                else
                    cout << "Bad location, try again." << endl;
            }
      }
//    gameboard.resetBoard();
// }
  
    
    /*
     if (winningPiece == gameboard.gameTies)
     cout << "No winner - it was a tie!" << endl;
     else if (winningPiece == X)
     cout << "X won! Congratulations!" << endl;
     else
     cout << "O won! Congratulations!" << endl;
     */
    
    cout << "Do you want to play again? ";
    cin >> answer;
    
    return 0;
    
}
