# 🎮 Checkers Game

A console-based implementation of the classic **Russian Checkers** game, developed as part of an introductory educational practice. The application features a custom AI opponent and follows official game rules.

## ✨ Features

**Complete Game Logic:** Full implementation of Russian checkers rules, including backward capturing.

**King Mechanics:** Fully implemented logic for "flying" kings (long-range movement and capturing).

**Artificial Intelligence:** Features an AI opponent based on a **Greedy Algorithm**. The AI analyzes all possible moves and prioritizes those that capture the maximum number of opponent pieces.

**Two-Player Mode:** Supports local multiplayer for two human players.

**Save & Resume:** Game progress is saved to a file, allowing the match to be continued after restarting the application.

**Visual Interface:** Clean console-based UI with ANSI color coding to distinguish between board cells, player pieces (cyan), and AI pieces (magenta).

**Move Validation:** The system automatically validates legal moves and enforces captures when available.

## 🛠️ Tech Stack

| | |
| :--- | :--- |
| **Language** | C |
| **Paradigm** | Procedural programming |
| **Target OS** | Windows / Linux (Console) |

## 🚀 How to Play

### Compilation

Compile the source code using any standard C compiler (e.g., GCC or MSVC).

```bash
gcc main.c -o checkers
