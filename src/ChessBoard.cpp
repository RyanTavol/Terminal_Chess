#include "terminal_chess/ChessBoard.hpp"

namespace terminal_chess {

ChessBoard::ChessBoard(bool darkMode) {
  _darkMode = darkMode;
  reset();
}

void ChessBoard::reset() {
  clear();

  // Determine actual colors based on darkMode flag
  Color topColor = _darkMode ? Color::White : Color::Black;
  Color bottomColor = _darkMode ? Color::Black : Color::White;

  // Place top (row 0) and pawns (row 1)
  _grid[0][0] = create_piece(PieceType::Rook,   topColor);
  _grid[0][1] = create_piece(PieceType::Knight, topColor);
  _grid[0][2] = create_piece(PieceType::Bishop, topColor);
  _grid[0][3] = create_piece(PieceType::Queen,  topColor);
  _grid[0][4] = create_piece(PieceType::King,   topColor);
  _grid[0][5] = create_piece(PieceType::Bishop, topColor);
  _grid[0][6] = create_piece(PieceType::Knight, topColor);
  _grid[0][7] = create_piece(PieceType::Rook,   topColor);
  for (int c = 0; c < 8; ++c)
    _grid[1][c] = create_piece(PieceType::Pawn, topColor);

  // Place bottom (row 7) and pawns (row 6)
  _grid[7][0] = create_piece(PieceType::Rook,   bottomColor);
  _grid[7][1] = create_piece(PieceType::Knight, bottomColor);
  _grid[7][2] = create_piece(PieceType::Bishop, bottomColor);
  _grid[7][3] = create_piece(PieceType::Queen,  bottomColor);
  _grid[7][4] = create_piece(PieceType::King,   bottomColor);
  _grid[7][5] = create_piece(PieceType::Bishop, bottomColor);
  _grid[7][6] = create_piece(PieceType::Knight, bottomColor);
  _grid[7][7] = create_piece(PieceType::Rook,   bottomColor);
  for (int c = 0; c < 8; ++c)
    _grid[6][c] = create_piece(PieceType::Pawn, bottomColor);
}

void ChessBoard::clear() {
  for (auto& row: _grid) {
    for (auto& cell: row)
    cell.reset();
  }
}

std::string ChessBoard::to_string() const {
  // Ensure UTF-8 locale
  std::setlocale(LC_ALL, "");

  auto print_sep = [&](std::string& out) {
    out += "   +";
    for (int i = 0; i < 8; ++i) out += "---+";
    out += "\n";
  };

  std::string out;
  out += "     a   b   c   d   e   f   g   h\n";
  print_sep(out);

  for (int r = 0; r < 8; ++r) {
    out += ' ' + std::to_string(8 - r) + " |";
    for (int f = 0; f < 8; ++f) {
      if (_grid[r][f]) out += ' ' + _grid[r][f]->symbol() + " |";
      else              out += "   |";
    }
    out += ' ' + std::to_string(8 - r) + "\n";
    print_sep(out);
  }
  out += "     a   b   c   d   e   f   g   h\n";

  return out;
}

}

  
