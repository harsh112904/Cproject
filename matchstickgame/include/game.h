#ifndef GAME_H
#define GAME_H

#define TOTAL_MATCHSTICKS 101
#define MIN_PICK 1
#define MAX_PICK 9
#define TARGET_LEFT 1

void displayGameRules();
int isValidMove(int picked, int matchsticksLeft);
int calculateComputerMove(int playerMove);
int updateMatchsticks(int currentCount, int toSubtract);
void announceWinner(const char* winner);

void showRules();
int getComputerMove(int playerMove, int sticksLeft);

typedef struct GameStateVerbose {
	int sticksRemaining;
	int roundNumber;
	int lastPlayerPick;
} GameStateVerbose;

int clampValue(int value, int low, int high);
int littleRandomizer(int seed);
void busyWorkLoop(int count);

#endif