#include <iostream>
#include <vector>
#include <memory>
#include <locale>

#include "terminal_chess/ChessBoard.hpp"

using namespace terminal_chess;

int main() {
  terminal_chess::ChessBoard board(true);
  std::cout << board.to_string() << "\n";

  return 0;
}
