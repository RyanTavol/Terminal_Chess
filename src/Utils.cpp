#include "terminal_chess/Utils.hpp"
#include <stdexcept>
#include <iostream>

namespace terminal_chess::utils {

static int file_char_to_col(char f) {
  if (f < 'a' || f > 'h')
    throw std::invalid_argument("Bad file letter");
  return f - 'a'; 
}

static char col_to_file_char(int c) {
  return char('a' + c);
}

static int rank_char_to_row(char r) {
  if (r < '1' || r > '8')
    throw std::invalid_argument("Bad rank digit");
  return 8 - (r - '0');
}

static char row_to_rank_char(int r) {
  return char('0' + (8-r));
}

Move parse_move(const std::string& notation) {
  //notation is of the form: "e2e4" or optionally "e2=>e4".
  
  //TODO Handle any capitalization, whitespaces, etc (any other fomratting issues);

  //Strip the optional "=>".
  //TODO Consider handling other optional notation like "e2-e4", "e2->e4", etc.
  std::string s = notation;
  auto pos = s.find("=>");
  if (pos != std::string::npos)
    s.erase(pos, 2);

  if (s.size() != 4)
    throw std::invalid_argument("Notation must provide exactly 2 arguments (4 characters)");

  //TODO Handle case of casling.
  //Now guarantees an input of something like "e2e4" ==> first 2 characters are "from" and final 2 are 'to".

  int from_col = file_char_to_col(s[0]);
  int from_row = rank_char_to_row(s[1]);
  int to_col = file_char_to_col(s[2]);
  int to_row = rank_char_to_row(s[3]);

  //Don't need to check if the move is legal or on the board.
  
  return Move{
    Position{from_row, from_col},
    Position{to_row, to_col}
  };
  
}

std::string format_move(const Move& m) {
  std::string s;
  s.push_back(col_to_file_char(m.from.col));
  s.push_back(row_to_rank_char(m.from.row));
  s.push_back(col_to_file_char(m.to.col));
  s.push_back(row_to_rank_char(m.to.row));
  return s;
}
  
}
