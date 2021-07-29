#include <Windows.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void intro() {
  printf(">>    _____           _   _   _             _                  <<\n");
  printf(">>   / ____|         | | (_) | |           (_)                 <<\n");
  printf(">>  | (___     ___   | |  _  | |_    __ _   _   _ __    ___    <<\n");
  printf(">>   \\___ \\   / _ \\  | | | | | __|  / _` | | | | '__|  / _ \\   <<\n");
  printf(">>   ____) | | (_) | | | | | | |_  | (_| | | | | |    |  __/   <<\n");
  printf(">>  |_____/   \\___/  |_| |_|  \\__|  \\__,_| |_| |_|     \\___|   <<\n");
  printf("\nWelcome to Solatire!!\n");
  printf("Enter the coordinates of the peg to move, followed by the direction with wasd.");
  printf("\nExample: 22s, 57a, 32d.  Enter u to undo, r to restart, i to list inputs, q to quit.\n\n");
}

void outro(int board[7][7]) { 
  printBoard(board);   
  printf("   _____                            _         _       _   _                 _ \n");
  printf("  / ____|                          | |       | |     | | (_)               | |\n");
  printf(" | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___| |\n");
  printf(" | |    / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __| |\n");
  printf(" | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\_|\n");
  printf("  \\_____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___(_)\n");
  printf("                     __/ |                                                    \n");
  printf("                    |___/     \n\n");
  printf("Congratulations! You have won the game!");
  exit(0);
  }

void printBoard(int board[7][7]) {
  char coordBoard[15][114] = {
      "          ╔════╦════╦════╗ w = Up     ",
      "          ║ 13 ║ 14 ║ 15 ║ s = Down   ",
      "          ╠════╬════╬════╣ a = Left   ",
      "          ║ 23 ║ 24 ║ 25 ║ d = Right  ",
      "╔════╦════╬════╬════╬════╬════╦════╗  ",
      "║ 31 ║ 32 ║ 33 ║ 34 ║ 35 ║ 36 ║ 37 ║  ",
      "╠════╬════╬════╬════╬════╬════╬════╣  ",
      "║ 41 ║ 42 ║ 43 ║ 44 ║ 45 ║ 46 ║ 47 ║  ",
      "╠════╬════╬════╬════╬════╬════╬════╣  ",
      "║ 51 ║ 52 ║ 53 ║ 54 ║ 55 ║ 56 ║ 57 ║  ",
      "╚════╩════╬════╬════╬════╬════╩════╝  ",
      "          ║ 63 ║ 64 ║ 65 ║ q = Quit   ",
      "          ╠════╬════╬════╣ u = Undo   ",
      "          ║ 73 ║ 74 ║ 75 ║ r = Restart",
      "          ╚════╩════╩════╝ i = Inputs "};
  char finalBoard[15][90] = {
      "        ╔═══╦═══╦═══╗        ",
      "  X   X ║ X ║ X ║ X ║ X   X  ",
      "        ╠═══╬═══╬═══╣        ",
      "  X   X ║ X ║ X ║ X ║ X   X  ",
      "╔═══╦═══╬═══╬═══╬═══╬═══╦═══╗",
      "║ X ║ X ║ X ║ X ║ X ║ X ║ X ║",
      "╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣",
      "║ X ║ X ║ X ║ X ║ X ║ X ║ X ║",
      "╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣",
      "║ X ║ X ║ X ║ X ║ X ║ X ║ X ║",
      "╚═══╩═══╬═══╬═══╬═══╬═══╩═══╝",
      "  X   X ║ X ║ X ║ X ║ X   X  ",
      "        ╠═══╬═══╬═══╣        ",
      "  X   X ║ X ║ X ║ X ║ X   X  ",
      "        ╚═══╩═══╩═══╝        ",
  };

  // Prepare final board with pegs and holes
  for (int rowNum = 0; rowNum < 7; rowNum++) {
    int i = 0;
    char *row = finalBoard[(rowNum * 2) + 1]; 
    while (*row) {        // Loop over a row of X
      if (*row == 'X') {  // If the character is X
        char temp[90];    // Replace X with peg or hole
        switch (board[rowNum][i++]) {
          case 2:
          case 0:
            *row = ' ';
            break;
          case 1:
            strcpy(temp, row + 1); // Copy string after X
            *row = '\0';           // Replace X with '\0'
            strcat(row, "●");      // Add peg to the end
            strcat(row, temp);     // Add the string back
            break;
        }
      }
      *row++; // Move to next character
    };
  };

  // Print both boards
  printf(
      "              Coordinates             "
      "   ::            Game Board        \n");
  for (int i = 0; i < 15; i++) {
    printf("  %s ::   %s\n", coordBoard[i], finalBoard[i]);
  }
}

char *getInput() {
  printf("\nInput: ");
  char *coord = malloc(sizeof(char) * 4);
  scanf("%3s", coord);         // Scan only first 3 characters
  while ((getchar()) != '\n'); // Clear input buffer
  char *temp = coord;
  while ((*temp = tolower(*temp))) {
    temp++; // Loop over all characters and make them lower case
  }
  return coord;
}

int checkSpecial(char *input, Hist *history) {
  if (!strcmp(input, "q")) {  // Check if quit
    printf("Program will now quit.");
    exit(0);
  }
  if (!strcmp(input, "i")) {  // Check if list inputs
    if (history->node) {      // Check if node exists
      listHist(history->node);
      printf("\n\n");
    } else {
      printf("No inputs have been entered yet.\n\n");
    }
    return 1;
  }
  return 0;
}

void listHist(Hist *history){
  if (history->node == NULL) {
    printf("Inputs: %s", history->input);
    return;
  }
  listHist(history->node);
  printf(" -> %s", history->input);
}

int undo(int board[7][7], char *input, Hist **history) {
  if (!strcmp(input, "u")) {
    if ((*history)->node) {  // Check if list has atleast 2 nodes
      Hist *temp = *history; // Remove first node if so
      *history = temp->node;
      free(temp);
      int x, y;  // Extract coordinates and direction
      char dir;  // From the node input
      sscanf((*history)->input, "%1d%1d%c", &x, &y, &dir);
      board[--x][--y] = 1; // Decrement coordinates, then place peg
      switch (dir) { // Change values on board as needed 
        case 'w':
          board[x - 1][y] = 1;
          board[x - 2][y] = 0;
          break;
        case 's':
          board[x + 1][y] = 1;
          board[x + 2][y] = 0;
          break;
        case 'a':
          board[x][y - 1] = 1;
          board[x][y - 2] = 0;
          break;
        case 'd':
          board[x][y + 1] = 1;
          board[x][y + 2] = 0;
          break;
      }
    } else {
      printf("No more undos available.\n");
    }
    return 1;
  }
  return 0;
}

int restart(int board[7][7], char *input, Hist **history) {
  if (!strcmp(input, "r")) {
    if ((*history)->node) { // Check if list has atleast 2 nodes
      while ((*history)->node) {
        undo(board, "u", history); // Undo all inputs in list
      }
    } else {
      printf("Game has already been intialized from the start.\n");
    }
    return 1;
  }
  return 0;
}

int validMove(int board[7][7], char *input) {
  int x, y;  // Coordinates
  char dir;  // Direction
  if (sscanf(input, "%1d%1d%c", &x, &y, &dir) == EOF) {
    printf("Input is not recognized.");
    return 0;
  }
  if (x < 1 || x > 7 || y < 1 || y > 7) {
    printf("Coordinate provided is not valid.");
    return 0;
  }
  if (board[--x][--y] == 1) {  // Decrement coordinates, then check if peg present
    char *direction = "";      // direction holds string to be printed if can't move
    if (dir == 'w') {          // Check all inputs and return 1 if move is possible
      if (x - 2 >= 0 && board[x - 1][y] == 1 && board[x - 2][y] == 0) return 1;
      direction = " upwards";  // Assign keyword to direction if can not be moved
    } else if (dir == 's') {
      if (x + 2 <= 6 && board[x + 1][y] == 1 && board[x + 2][y] == 0) return 1;
      direction = " downwards";
    } else if (dir == 'a') {
      if (y - 2 >= 0 && board[x][y - 1] == 1 && board[x][y - 2] == 0) return 1;
      direction = " left";
    } else if (dir == 'd') {
      if (y + 2 <= 6 && board[x][y + 1] == 1 && board[x][y + 2] == 0) return 1;
      direction = " right";
    }
    printf("Chosen peg can not be moved%s.", direction); // Print if can not move
    return 0;
  } else {
    printf("No peg at chosen coordinates.");
    return 0;
  }
}

void movePeg(int board[7][7], char *input) {
  int x, y;  // Save coordinates and direction
  char dir;
  sscanf(input, "%1d%1d%c", &x, &y, &dir);
  board[--x][--y] = 0;  // Decrement, then remove peg
  switch (dir) { // Change values on board as necessary
    case 'w':
      board[x - 1][y] = 0;
      board[x - 2][y] = 1;
      break;
    case 's':
      board[x + 1][y] = 0;
      board[x + 2][y] = 1;
      break;
    case 'a':
      board[x][y - 1] = 0;
      board[x][y - 2] = 1;
      break;
    case 'd':
      board[x][y + 1] = 0;
      board[x][y + 2] = 1;
      break;
  }
}

Hist *addHist(Hist *history, char *input) {
  history->input = strdup(input); // Assign input to first node
  Hist *temp = (Hist *)malloc(sizeof(Hist)); 
  temp->node = history; // New first node points to previous first node
  return temp;
}

int gameWin(int board[7][7]) {
  int sum = 0;
  for (int row = 0; row < 7; row++) {
    for (int col = 0; col < 7; col++) {
      sum += board[row][col]; // Add all values
    }
  }
  if (sum == 33 && board[3][3] == 1) {
    return 1;  // Game won if only 1 peg left, at center
  }
  return 0;
}

int movesLeft(int board[7][7]) {
  // Check if any further moves are possible
  for (int x = 0; x < 7; x++) {
    for (int y = 0; y < 7; y++) {
      if (board[x][y] == 1) { // If peg present, check if it can be moved
        if (x - 2 >= 0 && board[x - 2][y] == 0 && board[x - 1][y] == 1) return 1; // Left check
        if (x + 2 <= 6 && board[x + 2][y] == 0 && board[x + 1][y] == 1) return 1; // Right check
        if (y - 2 >= 0 && board[x][y - 2] == 0 && board[x][y - 1] == 1) return 1; // Up check
        if (y + 2 <= 6 && board[x][y + 2] == 0 && board[x][y + 1] == 1) return 1; // Down check
      }
    }
  }
  return 0;
}