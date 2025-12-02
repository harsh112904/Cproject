#ifndef MATCHSTICK_GAME_H
#define MATCHSTICK_GAME_H

#define TOTAL_MATCHSTICKS 101
#define MAX_PICK 9
#define MIN_PICK 1

int getUserMove(int remaining);
int getComputerMove(int remaining);
int isValidMove(int move, int remaining);
void displayWinner(int player);
void displayGameStats(int playerWins, int computerWins);

#endif
