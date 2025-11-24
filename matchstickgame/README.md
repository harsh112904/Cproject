# Matchstick Game

This project implements a classic matchstick game where players take turns picking matchsticks from a pile. The objective is to avoid being the player who picks the last matchstick.

## Game Rules

- The game starts with **101 matchsticks**.
- On each turn, a player can pick between **1 and 9 matchsticks**.
- The player forced to pick the **last matchstick** loses the game.

## Features

- Input validation for player moves.
- Computer opponent with basic strategy.
- Game state tracking (sticks remaining, round number, last player pick).
- Utility functions for randomization and value clamping.

## File Structure

- `game.h`: Header file containing function declarations and data structures for the game logic.

## How to Play

1. Follow the prompts to pick matchsticks on your turn.
2. The computer will respond with its move.
3. Continue until only one matchstick remains.
4. The player who picks the last matchstick loses.

## Building

To build the project, include `game.h` in your source files and implement the corresponding functions in your C project.

## License

This project is provided for educational purposes.
