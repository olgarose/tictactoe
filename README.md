tictactoe
=========
The company, Silly Little Games, has decided to expand its repertoire and include the game Tic-Tac-Toe. The game is for two players. One player places the X pieces and the other player places the O pieces. The basic game board is a grid of 9 spaces, in a 3 x 3 arrangement (although your game should be flexible enough to handle a 5 x 5, 7 x 7 or any other size in the future). When one player covers an entire row, column or diagonal, that player wins the game.

In C++, using a class, a multidimensional dynamic array and appropriate-designed methods and functions, write a program that will:

Allow two users to play Tic-Tac-Toe as many times as desired
Display the board
Allow users to place pieces (X or O) by taking turns
Check for a winner
Keep a running scoreboard and print it after each game.
Comments:

The board, with the actions that can be taken on it, will be in a class.
Clear the screen (25 blank lines is sufficient) before explaining your program to the user. There is no need to clear the screen between your explanation and the beginning of the game. A few blank lines will be sufficient.
The board should be displayed after each turn. Empty (available) spaces should appear blank. Used spaces should have the appropriate character in them.
Users should indicate where to place their pieces by using a numbering or lettering system for each row and column. Make sure you label the display to help the user.
The user may place pieces only in empty spaces – check before you place the piece.
Remember that no player may place two pieces in a row – you may choose to require X or O to start or you may leave the choice to the users, but you must enforce the alternating turns.
The game ends as soon as one player has filled one row or one column or one full diagonal.
Name the class source files tictactoe.h and tictactoe.cpp and the program source file p3.cpp

Submit your program by typing the following command from the directory where the files reside:

/home/fac/ohsh/submit/bc2/p3_runme

Extra Credit is not graded unless the original program receives at least 85%. This EC is worth 10 points.

Update your program to allow the user to choose the size of the board, from the smallest (3 x 3) to the largest (probably about 25 x 25, depending upon your display style - assume 80 column window width). It must be an odd-sized board (to allow for nice diagonals) and must be square.

Name your files "tictactoex.h", "tictactoex.cpp" and "p3x.cpp"

Note that you must use #include "tictactoex.h" in your extra credit program. However, the actual name of the class will not need to change.

Submit your program by typing the following command from the directory where the files reside:

/home/fac/ohsh/submit/bc2/p3x_runme

