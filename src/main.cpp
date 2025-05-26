#include <iostream>
#include <vector>
#include <memory>
#include <locale>

#include "terminal_chess/ChessBoard.hpp"
#include "terminal_chess/GameManager.hpp"

using namespace terminal_chess;

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

int main() {
  std::cout << "Welcome to Terminal Chess" << "\n";
  
  // test_1();
  test_2();

  return 0;
}
