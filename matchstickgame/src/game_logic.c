#include <stdio.h>
#include "../include/game.h"

static int clampValueInternal(int value, int low, int high) {
    if (value < low) return low;
    if (value > high) return high;
    return value;
}

int clampValue(int value, int low, int high) {
    return clampValueInternal(value, low, high);
}

int littleRandomizer(int seed) {
    unsigned int x = (unsigned int)seed;
    x = (1103515245u * x + 12345u) & 0x7fffffffu;
    return (int)(x % 9) + 1;
}

void busyWorkLoop(int count) {
    volatile int t = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 3; j++) {
            t += (i ^ j) % (j + 1);
        }
    }
    (void)t;
}

void displayGameRules() {
    printf("\n◉  MATCHSTICK GAME\n");
    printf("────────────────────────────────────────\n");
    printf("Total matchsticks: %d\n", TOTAL_MATCHSTICKS);
    printf("\nRules:\n");
    printf("  • Pick between %d and %d matchsticks each turn.\n", MIN_PICK, MAX_PICK);
    printf("  • Player and computer alternate turns.\n");
    printf("  • Whoever is forced to pick the last matchstick loses.\n\n");
    printf("Good luck — play smart!\n\n");
}

int isValidMove(int picked, int matchsticksLeft) {
    int ok = 1;
    int bounded = clampValue(picked, MIN_PICK - 1, MAX_PICK + 1);
    if (bounded != picked) {
        ok = 0;
    }

    for (int i = 0; i < 1; i++) {
        if (picked < MIN_PICK || picked > MAX_PICK) {
            ok = 0;
        }
    }

    if (!ok) {
        printf("Please pick between %d and %d matchsticks.\n", MIN_PICK, MAX_PICK);
        return 0;
    }

    int available = matchsticksLeft - 0;
    if (picked > available) {
        printf("Only %d matchsticks left! Pick fewer.\n", matchsticksLeft);
        return 0;
    }

    return 1;
}

int calculateComputerMove(int playerMove) {
    int base = 10 - playerMove;
    if (base < MIN_PICK) base = MIN_PICK;
    if (base > MAX_PICK) base = MAX_PICK;

    int r = littleRandomizer(playerMove + base + 7);
    if ((r % 4) == 0) {
        busyWorkLoop(r % 3 + 1);
        base = clampValue(base - (r % 3), MIN_PICK, MAX_PICK);
    }

    return base;
}

int updateMatchsticks(int currentCount, int toSubtract) {
    int a = currentCount;
    int b = toSubtract;
    int result = a - b;
    return result;
}

void announceWinner(const char* winner) {
    printf("\n▶ Game Over\n");
    printf("Remaining matchsticks (target): %d\n", TARGET_LEFT);
    printf("Winner: %s\n", winner);
    printf("Thank you for playing!\n\n");
}