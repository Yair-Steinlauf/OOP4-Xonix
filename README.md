# Territory Blocker Game

A 2D arcade-style game inspired by classic games like *Qix* and *JezzBall*. The player moves around the board, attempting to conquer a specific percentage of territory while avoiding enemies and managing movement trails. Each level increases in difficulty.

---

## 🕹️ Gameplay Overview

- **Player**: White square.
- **Enemies**: Green squares moving diagonally.
- **Trail**: Red trail left by the player while moving in unconquered areas.
- **Conquered Area**: Blue.
- **Unconquered Area**: Black.
- **Objective**: Conquer a required percentage of the board without touching enemies or your own trail during movement.

---

## 📁 Project Structure

### Source Files:

| File / Class         | Description |
|----------------------|-------------|
| `main.cpp`           | Entry point of the game. Initializes the engine and handles global exceptions. |
| `Engine`             | Manages the main game loop, window creation, and state transitions. |
| `FilesManager`       | Loads level configurations (resolution, enemies, lives, etc.) from `levels.txt`. |
| `GameStateManager`   | Manages the game states using a stack-based structure (menu, gameplay, end screens). |
| `GamePlayState`      | Core gameplay logic: controls player, enemies, board updates, and win/loss conditions. |
| `GameOverState`      | Displays the game over screen. |
| `WinState`           | Displays the victory screen. |
| `Board`              | Manages the game grid, territory logic, and collision detection. |
| `Player`             | Represents the player, handles movement, lives, trail logic, and conquer percentage. |
| `Enemy`              | Diagonally-moving enemy objects that pose threats to the player. |
| `Cell`               | Represents a single cell on the board (unconquered, conquered, trail). |
| `GameObject / MovingObject` | Base classes for position, movement, and rendering. |
| `ScoreBoard`         | Displays lives, level, score, and territory percentage. |
| `FontManager`        | Ensures consistent and safe font loading (e.g. `arial.ttf`). |

---

## 🧠 Key Data Structures

- `std::vector<std::vector<Cell>> m_matrix` — 2D grid representing the game board.
- `std::stack<std::unique_ptr<GameState>> m_states` — Stack managing the active game states.

---

## 🧮 Notable Algorithms

- **Flood Fill (BFS-based)**: Used to determine whether a closed trail by the player can be converted into conquered territory. If an enemy is found inside the region, the operation is canceled.
  - Uses `std::queue` for BFS.
  - `std::list` is preferred over `std::vector` for visited tracking due to lower overhead in insertion-only usage.
  
- **Enemy Placement**: Random placement of enemies using a `std::set` to avoid duplication.

- **Game State Design**: Clean separation of concerns — each game state (Menu, GamePlay, GameOver, Win) is implemented as a polymorphic class inheriting from `GameState`.

---

## 🧱 Architecture Design

- **Engine**: Central manager calling the active state's `update`, `handleInput`, and `render` methods.
- **GameStateManager**: Stack-based state machine allowing easy transition and backtracking between game modes.
- **GamePlayState**: Core class that maintains the `Board` and owns the `Player` (via `unique_ptr`). It ensures continuity of player state between levels.
- **Board**: Controls territory logic, collisions, and game state updates.
- **Player / Enemy**: Independent moving entities with their own logic.
- **ScoreBoard**: Displays key game stats separately from the board.
- **FilesManager**: Provides an abstraction layer for loading external game configuration files.

---

## 🧩 Requirements

- C++17 or later
- SFML (Simple and Fast Multimedia Library)
