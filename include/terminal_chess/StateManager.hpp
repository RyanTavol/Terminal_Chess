// Header file designated for I/O with terminal (including rendering and input parsing).
#pragma once

#include "GameManager.hpp"
#include <string>

namespace terminal_chess {

class StateManager {

public:
  explicit StateManager(bool darkMode = false);

  void run_local_multi();

private:
  GameManager _game;

  // Handles I/O of prompting for move, reading input, and returning.
  std::string prompt_move() const;

  // Calls the necessary functions to correctly utilize the move.
  bool handle_move(const std::string& input);

};
  
}
