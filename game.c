#include <Windows.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main() {
  SetConsoleOutputCP(CP_UTF8); // To allow CMD to print Unicode
  
  // Defining Variables
  int board[7][7] = {{2, 2, 1, 1, 1, 2, 2}, 
                     {2, 2, 1, 1, 1, 2, 2},
                     {1, 1, 1, 1, 1, 1, 1}, 
                     {1, 1, 1, 0, 1, 1, 1},
                     {1, 1, 1, 1, 1, 1, 1}, 
                     {2, 2, 1, 1, 1, 2, 2},
                     {2, 2, 1, 1, 1, 2, 2}};
  int winStatus = 0;
  int anyMovesLeft = 1;
  char *input;
  Hist *history = (Hist *)malloc(sizeof(Hist));
  history->node = NULL;

  intro();
  while (!winStatus) {   // Loop as long as game is not won
    printBoard(board);
    if (!anyMovesLeft) { // Prompt if no further moves possible
      printf("No more moves left. Please restart or undo the last move.");
    }

    input = getInput();
    checkQuit(input); // Check for special inputs q/r/u
    if (undo(board, input, &history) || restart(board, input, &history)) {
      anyMovesLeft = 1;
      continue;
    }

    if (validMove(board, input)) {
      printf("Move is valid.\n\n");      // Check if input is valid
      movePeg(board, input);             // Move peg if valid
      history = addHist(history, input); // Push input to history list

      anyMovesLeft = movesLeft(board);   // Check if any more moves left
      if (!anyMovesLeft) {               // If no more moves left,
        winStatus = gameWin(board);      // Check if game is won
      }
    } else {
      printf(" Please try again.\n\n");
    }
  }
  outro(board); // Print outro when game is won
}
