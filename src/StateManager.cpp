#include "terminal_chess/StateManager.hpp"
#include "terminal_chess/Utils.hpp"
#include <iostream>
#include <locale>

namespace terminal_chess {
using namespace terminal_chess::utils;

StateManager::StateManager(bool darkMode):
  _game(darkMode)
{
  std::setlocale(LC_ALL, "");
  _game.new_game();
}

void StateManager::run_local_multi() {
  while (true) {
    //Print board.
    std::cout << _game.get_board() << "\n";
    
    //Get the input from user.
    std::string input;

    //Continue prompting until valid move is made.
    do {
      input = prompt_move();
    }
    while(!handle_move(input));
  }
  return;
}

std::string StateManager::prompt_move() const{
  auto side = _game.get_current_turn();
  std::cout << (side == Color::White ? "White" : "Black") << " to move. Enter your move: ";
  std::string line;
  std::getline(std::cin, line);
  return line;
}

bool StateManager::handle_move(const std::string& input) {
  using std::invalid_argument;

  try {
    //Parse the move.
    Move m = parse_move(input);

    //Return false and print error message if: invalid input, illegal move.
    if (!_game.next_move(m)) {
      std::cout << "Illegal move! Try again.\n";
      return false;
    } 
    return true;

  } catch (const invalid_argument& e){
    std::cout << "Invalid move format: " << e.what() << "\n";
  }
  return false;
}
    
}
