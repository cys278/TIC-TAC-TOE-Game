# Tic-Tac-Toe Game

## Overview
This is a simple console-based Tic-Tac-Toe game implemented in C++. The game supports both single-player mode (player vs AI) and double-player mode (player vs player). It provides a user-friendly interface and maintains a score tally for each player.

---

## Features
- **Game Modes:**
  - Single Player Mode: Play against an AI.
  - Double Player Mode: Two players can play against each other.
- **Dynamic Game Board:** The 3x3 board dynamically updates after every move.
- **Score Tracking:** Maintains scores for all players and displays them after each game.
- **Replay Option:** Allows players to replay multiple games.

---

## How to Run
### Prerequisites
- A C++ compiler such as GCC.
- A terminal or command prompt.

### Steps
1. Clone or download the repository.
2. Compile the code using a C++ compiler:
   ```sh
   g++ -o TicTacToe TicTacToe.cpp
   ```
3. Run the executable:
   ```sh
   ./TicTacToe
   ```

---

## Game Instructions
1. Upon starting the game, choose the mode:
   - Enter `1` for Double Player Mode.
   - Enter `2` for Single Player Mode.
2. Provide player names if prompted.
3. The board is displayed as a 3x3 grid. Each cell can be chosen by specifying its row and column numbers (e.g., `1 2` for the first row and second column).
4. Players take turns marking the grid:
   - Player 1 uses `X`.
   - Player 2 (or AI) uses `O`.
5. The game ends when:
   - A player forms a horizontal, vertical, or diagonal line.
   - The grid is filled without a winner (tie).
6. Scores are displayed after each game, and players can choose to play again or exit.
