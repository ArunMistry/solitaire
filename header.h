#ifndef header  // Guard
#define header

typedef struct hist {  // History list struct
  char *input;
  struct hist *node;
} Hist;

void intro();
void outro(int board[7][7]);
void printBoard(int board[7][7]);
char *getInput();
int checkSpecial(char *input, Hist *history);
void listHist(Hist *history);
int undo(int board[7][7], char *input, Hist **history);
int restart(int board[7][7], char *input, Hist **history);
int validMove(int board[7][7], char *input);
void movePeg(int board[7][7], char *input);
Hist *addHist(Hist *history, char *input);
int movesLeft(int board[7][7]);
int gameWin(int board[7][7]);

#endif