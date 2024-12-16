# Mölkky Game - C++ Implementation

## Overview

This project is a C++ implementation of the **Mölkky** game, a Finnish throwing game where players aim to reach exactly 50 points. Players take turns throwing a wooden stick (the "Mölkky") at a set of numbered pins, and points are scored based on which pins are knocked down. If a player exceeds 50 points, their score is reset to 25 points. The game ends when a player reaches exactly 50 points.

The program simulates the score counting and game flow for two players, and automatically handles the rules for penalties, exceeding points, and determining the winner.

## Features

- **Two Player Setup**: The game supports two players. Each player has a name and a score.
- **Turn-Based Gameplay**: Players alternate turns, entering their score for each turn.
- **Score Handling**:
  - The program keeps track of each player's score and updates it after each turn.
  - If a player's score exceeds 50 points, their score is reset to 25 points.
  - If a player enters a negative score (penalty), the score is reduced accordingly, and if the score goes below zero, it is reset to zero.
- **Game Termination**: The game ends when a player reaches exactly 50 points.
- **Scoreboard Display**: After each turn, the current scoreboard is displayed showing both players' scores.

## Technological Description

### Language and Libraries

- **Programming Language**: The program is implemented in **C++**, which is a powerful and widely-used object-oriented programming language. C++ provides the necessary tools for creating efficient, object-oriented simulations like this one.
- **Standard Libraries**:
  - `#include <iostream>`: For input and output operations (reading user input and printing results to the console).
  - `#include <cstdlib>`: For standard utility functions, including exit codes.
  - `#include <string>`: For working with strings (such as player names).

### Core Concepts

#### Object-Oriented Design

The program uses **Object-Oriented Programming (OOP)** principles, where the main class, `Player`, encapsulates the attributes and behaviors of a player:

- **Player Class**:
  - **Attributes**: Each player has a name and a score.
  - **Methods**:
    - `get_name()`: Returns the player's name.
    - `get_points()`: Returns the player's current score.
    - `has_won()`: Returns `true` if the player has reached 50 points, indicating the player has won.
    - `add_points(int points)`: Adds points to the player’s score, handles penalties, and checks if the player has exceeded 50 points.

#### Pointers and Dynamic Memory

- **Pointer Usage**: The game uses a pointer `in_turn` that alternates between the two player objects (`player1` and `player2`). This pointer is used to call methods on the player whose turn it is, demonstrating how pointers can be used to manage dynamic behavior in the game.
- **Arrow Operator (`->`)**: The `in_turn` pointer is used to access the methods of the player currently in turn using the arrow operator, e.g., `in_turn->get_name()`.

### Program Flow

1. **Game Initialization**: The two players are initialized with names and an initial score of 0.
2. **Turn Handling**:
   - The game alternates between players in each turn. A score is inputted for the player whose turn it is.
   - The `add_points(int points)` method is used to update the player's score.
3. **Score Checking**: 
   - If the player's score exceeds 50 points, it is reset to 25 points.
   - If the player’s score goes below zero (due to a penalty), it is reset to zero.
4. **End of Game**: The game ends when a player’s score reaches exactly 50 points. The winner is announced.
5. **Scoreboard**: After each turn, the current scoreboard is printed, showing both players' names and their respective scores.

### Example of Program Execution


