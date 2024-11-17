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
   - **Hard**: Fast gameplay
   - **Normal**: Moderate speed
   - **Easy**: Slow - paced for beginners
## Game Controls

| Key   | Action                   |
|-------|--------------------------|
| `↑`   | Move Up                  |
| `↓`   | Move Down                |
| `←`   | Move Left                |
| `→`   | Move Right               |
| `P`   | Pause/Resume the Game    |
| `S`   | Start the Game           |
| `E`   | Exit the Game            |
| `A`   | Play Again               |

## Code Structure

### `main.cpp`
**Entry point of the game.**

- **Purpose**: Manages the main game loop, user inputs, and game states.
- **Key Responsibilities**:
  - Initializes the game environment, including setting up the title, player name input, and difficulty selection.
  - Handles the main game loop where the snake moves, checks for collisions, and updates the game state.
  - Processes user inputs for controlling the snake, pausing/resuming the game, and starting a new game after a game over.
  - Displays results such as the player’s score, high score, and offers options to restart or exit the game.

---

### `Snake.h` and `Snake.cpp`
**Defines the Snake class.**

- **Purpose**: Handles snake drawing, movement, growth, and collision detection.
- **Key Functions**:
  - `Draw()`: Draws the snake on the screen.
  - `Erase()`: Erases the snake from the screen.
  - `Move_Snake()`: Moves the snake, with an option to grow the snake when eating food.
  - `Change_dir()`: Changes the snake’s direction based on user input.
  - `CollisionBody()`: Detects if the snake collides with its own body.
  - `Eat_food()`: Checks if the snake eats food and updates the score.

---

### `Food.h` and `Food.cpp`
**Defines the Food class.**

- **Purpose**: Manages food spawning and rendering.
- **Key Functions**:
  - `Respawn_food()`: Spawns food at a random position on the game screen.
  - `Draw_Food()`: Draws the food on the screen.
  - **Attributes**:
    - `Pos_food`: The position of the food on the screen.
    - `point`: The point value for the food item.

---

### `mylib.h` and `mylib.cpp`
**Utility functions for console operations.**

- **Purpose**: Provides utility functions for setting colors, positioning text, and drawing walls.
- **Key Functions**:
  - `SetColor()`: Sets the console text color.
  - `GetXY()`: Sets the position of the cursor on the console screen.
  - `DrawWall()`: Draws the game wall around the playing area.
  - Other helper functions for console-based input/output handling.

### Acknowledgments
 **Snake ASCII art used in the start and result screens.**
 **Implementation inspired by the classic snake game logic**

### Contributos
1. Lê Quốc Huy
**Role: Developer**
**Contributions:**
2. Lê Nhật Quang
**Role: Developer**
**Contributions:**
3. Nguyễn Anh Tuấn
**Role: Developer**
**Contributions:**
4. Ngô Thái Vinh
**Role: Leader**
**Contributions:** 
