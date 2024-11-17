# DeAn-CK1-2024-SS004.P12

Link git: https://github.com/Vi-Alviss/DeAn-CK1-2024-SS004.P12  
Link Slack: https://app.slack.com/client/T07L41M7TJ7/C07UD362Q12  
Link Overleaf HDN: https://www.overleaf.com/read/dfmqptqxcxsj#b89294

# Greedy Snake Game

A classic "Greedy Snake" game implemented in C++ with customizable difficulty levels and enhanced features such as pausing the game, high score tracking, and blinking start prompts.

---

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [How to Build](#how-to-build)
- [How to Play](#how-to-play)
- [Game Controls](#game-controls)
- [Code Structure](#code-structure)
- [Customization](#customization)
- [Acknowledgments](#acknowledgments)

---

## Features

1. **Snake Movement**: Arrow keys to move the snake in four directions.
2. **Dynamic Gameplay**:
   - Food spawns randomly.
   - Snake grows when food is eaten.
   - Game ends upon collision with itself.
3. **Difficulty Levels**:
   - Easy, Normal, and Hard modes affecting the snake's speed.
4. **Pause/Resume Feature**: Press `P` to pause or resume the game.
5. **High Score System**:
   - Stores and displays the highest score and the top player's name.
   - Updates the leaderboard if a new high score is achieved.
6. **Visual Enhancements**:
   - Colorful game environment.
   - Blinking text prompts.
   - ASCII art of a snake displayed on start and end screens.

---

## Requirements

- **Operating System**: Windows
- **Compiler**: MinGW or Microsoft Visual Studio
- **Libraries**: 
  - `<conio.h>` for keyboard inputs.
  - `<windows.h>` for console graphics.

---

## How to Build

1. Clone the repository:
   ```bash
   git clone https://github.com/your-repository/snake-game.git
2. Move to file contain program
   ```bash
   cd snake-game
3. Compile Program
   ```bash
   g++ -o SnakeGame main.cpp Snake.cpp Food.cpp mylib.cpp -std=c++11
4. Add file
   ```bash
   /SnakeGame


## How to play
1. Launch game.
2. Enter your name to starting tracking your score.
3. Choose the desired difficulty level:
* **Hard**: Fast gameplay
* **Normal**: Moderate speed
* **Easy**: Slow - paced for beginners


