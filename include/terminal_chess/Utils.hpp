// Header function for any important and relevant helpers.
#pragma once

#include <string>
#include "ChessBoard.hpp"

// Set of helper functions for translating between move notation. (Requires access to the board state).

// parse_move
// format_move

// parse_move_algebraic
// format_move_algebraic

namespace terminal_chess::utils {

Move parse_move(const std::string& notation);

std::string format_move(const Move& m);

//TODO Eventually add functionality for algebraic notation.

}
