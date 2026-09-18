#include <vector>

void greet();

void display_grid(std::vector<std::vector<char>> grid);

void make_move(std::vector<std::vector<char>>& grid, char current_player, std::string player);

bool check_wins(std::vector<std::vector<char>> grid, char current_player);

bool check_draw(std::vector<std::vector<char>> grid);
