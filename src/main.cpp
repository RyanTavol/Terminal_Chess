#include <iostream>
#include <vector>
#include <memory>
#include <locale>

#include "terminal_chess/ChessBoard.hpp"
#include "terminal_chess/GameManager.hpp"
#include "terminal_chess/Utils.hpp"

using namespace terminal_chess;
using namespace terminal_chess::utils;

void test_1() {
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

void test_2() {
  terminal_chess::GameManager game(true);  
  game.next_move({{6,4}, {4,4}});
  game.next_move({{1,4}, {3,4}});
  game.next_move({{7,6}, {5,5}});
}

void test_3() {
  GameManager game(true);  
  for (auto notation : { "e2=>e4", "e7e5", "g1f3" }) {
    try {
      Move m = parse_move(notation);
      bool ok = game.next_move(m);
    }
    catch (const std::exception& e) {
      std::cout << "ERROR parsing \"" << notation << "\": "
                << e.what() << "\n";
    }
  }
}

int main() {
  std::cout << "Welcome to Terminal Chess" << "\n";
  
  // test_1();
  //  test_2();
  test_3();

  return 0;
}
