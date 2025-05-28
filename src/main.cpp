#include <iostream>
#include <vector>
#include <memory>
#include <locale>

#include "terminal_chess/ChessBoard.hpp"
#include "terminal_chess/GameManager.hpp"
#include "terminal_chess/StateManager.hpp"
#include "terminal_chess/Utils.hpp"

using namespace terminal_chess;
using namespace terminal_chess::utils;

void move_test() {
  terminal_chess::ChessBoard board(true);
  std::cout << board.to_string() << "\n";
  Move pawnMove = {{6,4}, {4,4}};
  bool pawnResult = board.move_piece(pawnMove, Color::White);
  // std::cout << pawnResult << "\n";
  std::cout << board.to_string() << "\n";

  Move pawnMoveB = {{1,4}, {3,4}};
  bool pawnResultB = board.move_piece(pawnMoveB, Color::Black);
  // std::cout << pawnResult << "\n";
  std::cout << board.to_string() << "\n";

  Move knightMove = {{7, 6}, {5, 5}};
  bool knightResult = board.move_piece(knightMove, Color::White);
  // std::cout << knightResult << "\n";
  std::cout << board.to_string() << "\n";
}

void manager_test() {

  terminal_chess::GameManager game(true);  
  game.next_move({{6,4}, {4,4}});
  game.next_move({{1,4}, {3,4}});
  game.next_move({{7,6}, {5,5}});
}

void move_parser_test() {
  GameManager game(true);  
  for (auto notation : { "e2=>e4", "e7e5", "g1f3" }) {
    try {
      Move m = parse_move(notation);
      game.next_move(m);
    }
    catch (const std::exception& e) {
      std::cout << "ERROR parsing \"" << notation << "\": "
                << e.what() << "\n";
    }
  }
}

void io_test() {
  std::cout << "Testing I/O" << "\n";
  terminal_chess::StateManager state(true);
  state.run_local_multi();
}

int main() {
  std::cout << "Welcome to Terminal Chess" << "\n";
  
  io_test();

  return 0;
}
