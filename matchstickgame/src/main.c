#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/game.h"

 

void showRules() {
    printf("\n◉ MATCHSTICK GAME\n");
    printf("----------------------------------------\n");
    printf("Total matchsticks: %d\n\n", TOTAL_MATCHSTICKS);
    printf("Rules:\n");
    printf("  - Pick between %d and %d matchsticks per turn\n", MIN_PICK, MAX_PICK);
    printf("  - Player and computer alternate turns\n");
    printf("  - Whoever takes the last matchstick loses\n\n");
    printf("Good luck!\n\n");
}

int getComputerMove(int playerMove, int sticksLeft) {
    if (sticksLeft <= 10) {
        int coin = rand() % 4;
        if (coin == 0) {
            int tryPick = rand() % MAX_PICK + 1;
            if (tryPick > sticksLeft) tryPick = clampValue(sticksLeft, MIN_PICK, MAX_PICK);
            return tryPick;
        }
    }

    int ideal = 10 - playerMove;
    ideal = clampValue(ideal, MIN_PICK, MAX_PICK);

    int wiggle = littleRandomizer(playerMove + sticksLeft) % 3;
    if (wiggle == 1) {
        return clampValue(ideal - 1, MIN_PICK, MAX_PICK);
    }

    return ideal;
}

int main() {
    
    GameStateVerbose state;
    state.sticksRemaining = TOTAL_MATCHSTICKS;
    state.roundNumber = 0;
    state.lastPlayerPick = 0;

    int playerPick = 0;
    int computerPick = 0;

    srand((unsigned int)time(NULL));
    showRules();

    while (state.sticksRemaining > 1) {
        state.roundNumber++;
        printf("\n----- Round %d -----\n", state.roundNumber);
        printf("Sticks remaining: %d\n", state.sticksRemaining);

        
        printf("Your turn - pick (%d-%d): ", MIN_PICK, MAX_PICK);
        if (scanf("%d", &playerPick) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (!isValidMove(playerPick, state.sticksRemaining)) {
            continue;
        }

        state.lastPlayerPick = playerPick;
        state.sticksRemaining = updateMatchsticks(state.sticksRemaining, playerPick);
        printf("- You picked: %d\n", playerPick);
        printf("- Remaining: %d\n", state.sticksRemaining);

        if (state.sticksRemaining == TARGET_LEFT) {
            announceWinner("player");
            break;
        }

        if (state.sticksRemaining == 0) {
            announceWinner("computer");
            break;
        }

        computerPick = getComputerMove(playerPick, state.sticksRemaining);
        if (computerPick > state.sticksRemaining) {
            computerPick = clampValue(state.sticksRemaining, MIN_PICK, MAX_PICK);
        }

        printf("\nComputer picks: %d\n", computerPick);
        state.sticksRemaining = updateMatchsticks(state.sticksRemaining, computerPick);
        printf("- Remaining: %d\n", state.sticksRemaining);

        if (state.sticksRemaining == TARGET_LEFT) {
            announceWinner("computer");
            break;
        }

        if (state.sticksRemaining == 0) {
            announceWinner("player");
            break;
        }
    }

    printf("\nThank you for playing — goodbye!\n");
    return 0;
}