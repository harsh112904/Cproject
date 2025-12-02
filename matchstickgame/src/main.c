#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matchstick_game.h"

int main() {
    int matchsticks = TOTAL_MATCHSTICKS;
    int playerTurn = 1;
    int move;
    int playerWins = 0, computerWins = 0;
    char playAgain;
    
    srand(time(NULL));

    printf("=== MATCHSTICK GAME (simple - Sem-1 style) ===\n");
    printf("There are %d matchsticks. On each turn pick %d to %d.\n", TOTAL_MATCHSTICKS, MIN_PICK, MAX_PICK);
    printf("Whoever picks the LAST matchstick loses.\n\n");

    do {
        matchsticks = TOTAL_MATCHSTICKS;

        printf("Do you want to start first? (y/n): ");
        char answer = 'y';
        scanf(" %c", &answer);

        if (answer == 'y' || answer == 'Y') {
            playerTurn = 1;
            printf("\nYou will start first.\n");
        } else {
            playerTurn = 0;
            printf("\nComputer will start first.\n");
        }
        
        while (matchsticks > 0) {
            printf("\nRemaining matchsticks: %d\n", matchsticks);
            
            if (playerTurn) {
                move = getUserMove(matchsticks);
                printf("You picked %d matchstick(s)\n", move);
            } else {
                move = getComputerMove(matchsticks);
                printf("Computer picked %d matchstick(s)\n", move);
            }
            
            matchsticks -= move;
            
            if (matchsticks == 0) {
                displayWinner(playerTurn);
                if (playerTurn) {
                    computerWins++;
                } else {
                    playerWins++;
                }
                break;
            }
            
            playerTurn = !playerTurn;
        }
        
        displayGameStats(playerWins, computerWins);

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("\nThanks for playing!\n");
    return 0;
}
