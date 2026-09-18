#include <iostream>
#include <vector>
#include "ttt.hpp"

int main() {
  bool game_over = false;
  char current_player = 'X';
  std::string playerA_Name;
  std::string playerB_Name;

  std::vector<std::vector<char>> grid = {
    {'1', '2', '3'}, 
    {'4', '5', '6'}, 
    {'7', '8', '9'}
  };

  greet();
  
  std::cout << "Player One (Xs) enter your name: ";
  std::cin >> playerA_Name;

  std::cout << "\nPlayer Two (Os) enter your name: ";
  std::cin >> playerB_Name;

  std::cout << "\nLet's do this " << playerA_Name << " & " << playerB_Name << "\n";

  while (game_over == false) {
    std::cout << "\n";
    display_grid(grid);

    if (current_player == 'X') {
      make_move(grid, current_player, playerA_Name);
    } else {
      make_move(grid, current_player, playerB_Name);
    }

    if (check_wins(grid, current_player)) {
      display_grid(grid);

      if (current_player == 'X') {
        std::cout << playerA_Name << " Wins!!!\n";
      } else {
        std::cout << playerB_Name << " Wins!!!\n";
      }

      game_over = true;
    } else if (check_draw(grid)) {
        display_grid(grid);
        std::cout << "Good game " << playerA_Name << " & " << playerB_Name << ", it's a draw!!!";

        game_over = true;
    } else {
      if (current_player == 'X') {
        current_player = 'O';
      } else {
        current_player = 'X';
      }
    }
  }
}
