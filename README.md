# Terminal Tic-Tac-Toe 

A classic, command-line Tic-Tac-Toe game written entirely in C. This project was built to practice C programming fundamentals (2D arrays, game loops, matrix logic) and Git version control.

## Features
* **2-Player Local Multiplayer:** Take turns as Player 1 (X) and Player 2 (O).
* **Input Validation:** Prevents overwriting existing moves and catches out-of-bounds inputs.
* **Automatic Referee:** Detects row, column, and diagonal win conditions, as well as draws.
* **Clean UI:** Terminal is cleared and redrawn every turn for a smooth experience.

## How to Play

### Prerequisites
You will need a C compiler (like `gcc`) installed on your system.

### Compilation
Open your terminal, navigate to the project directory, and compile the code:
```bash
gcc main.c -o tictactoe
Running the Game
On Windows:

tictactoe.exe
On Linux/Mac:

./tictactoe