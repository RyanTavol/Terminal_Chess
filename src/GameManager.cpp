#include "terminal_chess/GameManager.hpp"
#include <iostream>

namespace terminal_chess {

GameManager::GameManager(bool darkMode)
{
  _board = ChessBoard(darkMode);
  new_game();
}

void GameManager::new_game() {
  _board.reset();
  // Every game starts with white.
  _turn = Color::White;
}

bool GameManager::next_move(const Move& m) {
  // Try to make the move. It already returns true or false for validation. 
  bool did_move_work = _board.move_piece(m, _turn);
  
  if(!did_move_work) {
    std::cout << "Move did not work" << "\n";
    return false;
  }

  std::cout << _board.to_string() << "\n";

  _turn = (_turn == Color::White ? Color::Black : Color::White);
  return true;
}

const ChessBoard& GameManager::get_board() const {
  return _board;
}

Color GameManager::get_current_turn() const {
  return _turn;
}

}
