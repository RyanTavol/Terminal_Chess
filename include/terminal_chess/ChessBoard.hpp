// Header file dedicated to how the board functions.

// Includes grid, applying moves, querying legal moves, etc.
// Make sure to include a dark mode flag that flips the piece colors since in a dark mode terminal it automatically is opposite.``

#pragma once

#include <array>
#include <memory>
#include <vector>

#include "Piece.hpp"
#include <string>

namespace terminal_chess {
  

class ChessBoard {
public:
  explicit ChessBoard(bool darkMode = false);

  void reset();
  
  std::string to_string() const;
  

  //TODO Provide more functionality for other important methods.
  //

private:
  std::array<std::array<std::unique_ptr<Piece>, 8>, 8> _grid;

  // If true, swap which color is considered 'white' vs 'black'
  bool _darkMode;

  // Helper: test if a square is on board
  static bool on_board(const Position& p) {
    return p.row >= 0 && p.row < 8 && p.col >= 0 && p.col < 8;
  }

  // Clear grid
  void clear();

};

}
