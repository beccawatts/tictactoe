#include <iostream>
#include "ttt.hpp"


// Greeting Function
void greet() {
  std::cout << "===========\n";
  std::cout << "TIC TAC TOE\n";
  std::cout << "===========\n";
  std::cout << "Welcome to Tic Tac Toe, a two player game where your aim is to get three in a row, either vertically, horizontally, or diagonally!\n\n";
}


// Display TTT Grid
void display_grid(std::vector<std::vector<char>> grid) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (column > 0) {
        std::cout << " | ";
      }
      
      std::cout << grid[row][column];
    }
    std::cout << "\n";
  }
}


// Make Move & Add To Grid
void make_move(std::vector<std::vector<char>>& grid, char current_player, std::string player) {
  int choice;
  bool valid_move = false;

  while (valid_move == false) {
    std::cout << player << " make your move: ";
    std::cin >> choice;

    if (choice < 1 || choice > 9) {
      std::cout << "Choose a number between 1 and 9.";
    } else {
      int row = (choice - 1) / 3;
      int column = (choice - 1) % 3;

      if (grid[row][column] == 'X' || grid[row][column] == 'O') {
        std::cout << "That square is already taken.\n";
      } else {
        grid[row][column] = current_player;
        valid_move = true;
      }
    }
  }
}


// Check For Winning Patterns
bool check_wins(std::vector<std::vector<char>> grid, char current_player) {
  for (int row = 0; row < 3; row++) {
    if (grid[row][0] == current_player &&
        grid[row][1] == current_player &&
        grid[row][2] == current_player) {
          return true;
    }
  }

  for (int column = 0; column < 3; column++) {
    if (grid[0][column] == current_player &&
        grid[1][column] == current_player &&
        grid[2][column] == current_player) {
          return true;
    }

    if (grid[0][0] == current_player &&
        grid[1][1] == current_player &&
        grid[2][2] == current_player) {
          return true;
    }

    if (grid[0][2] == current_player &&
        grid[1][1] == current_player &&
        grid[2][0] == current_player) {
          return true;
    }
  }

  return false;
}


// Check For Draws
bool check_draw(std::vector<std::vector<char>> grid) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (grid[row][column] != 'X' && 
          grid[row][column] != 'O') {
            return false;
      }
    }
  }
  
  return true;
}






