// Header file dedicated to turn logic, game state, and end condition checks.

// Start game with White then cycle turns until game is terminated.

// If time feature gets implemented, keep track of players time.

#pragma once

#include "ChessBoard.hpp"
#include <string>

namespace terminal_chess {

class GameManager{

public:
  GameManager(bool darkMode);

  void new_game();

  // TODO Consider changing Move to be a struct {from: a2, to: a3}.
  bool next_move(const Move& m);

  // Accessors
  const ChessBoard& get_board() const;
  
  Color get_current_turn() const;


  // TODO Add logic for the following:
  // undo/redo
  // GameResult: ongoing, checkmate, stalemate, draw, resign
  // Move history
  // time control

private:
  ChessBoard _board;
  Color _turn;
  bool _darkMode;

};

}
