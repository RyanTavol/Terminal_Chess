#include <iostream>
#include <vector>
#include <memory>
#include <locale>

#include "terminal_chess/ChessBoard.hpp"

using namespace terminal_chess;

int main() {
  terminal_chess::ChessBoard board(true);
  std::cout << board.to_string() << "\n";
  Move pawnMove = {{6,4}, {4,4}};
  bool pawnResult = board.move_piece(pawnMove, Color::White);
  // std::cout << pawnResult << "\n";
  std::cout << board.to_string() << "\n";

  Move knightMove = {{7, 6}, {5, 5}};
  bool knightResult = board.move_piece(knightMove, Color::White);
  // std::cout << knightResult << "\n";
  std::cout << board.to_string() << "\n";

  return 0;
}
