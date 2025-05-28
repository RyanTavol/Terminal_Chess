#include "terminal_chess/ChessBoard.hpp"
#include <iostream>

namespace terminal_chess {

ChessBoard::ChessBoard(bool darkMode) {
  _darkMode = darkMode;
  reset();
}

void ChessBoard::reset() {
  clear();

  // Determine actual colors based on darkMode flag
  Color topColor = Color::Black;
  Color bottomColor = Color::White;

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
      if (_grid[r][f]) out += ' ' + _grid[r][f]->symbol(_darkMode) + " |";
      else              out += "   |";
    }
    out += ' ' + std::to_string(8 - r) + "\n";
    print_sep(out);
  }
  out += "     a   b   c   d   e   f   g   h\n";

  return out;
}

void ChessBoard::print_board(bool printWhite) {
  std::cout << this->to_string() << "\n";
}

bool ChessBoard::is_legal_move(const Move& m, Color side) const {
  // TODO Remove the print statements.
  // If the move is not fully on the board it is not legal.
  if (!on_board(m.from) || !on_board(m.to)) { 
    std::cout << "Not on board" << "\n";
    return false;
  }

  // This should be already handled but if the move reults in no change.
  if (m.from.row == m.to.row && m.from.col == m.to.col) {
    std::cout << "Piece doesn't move" << "\n";
    return false;
  }

  // The 'from' square must be a piece and not empty
  auto& piecePtr = _grid[m.from.row][m.from.col];
  if (!piecePtr) {
    std::cout << "From square is empty" << "\n";
    return false;
  }

  // The piece must be the same color as the side moving.
  // Dereferences the pointer and calls the color method.
  if (piecePtr->color() != side) {
    std::cout << "Cannot move piece that isn't your color" << "\n";
    return false;
  }

  // Ensure that the move is valid as defined by the piece.
  if (!piecePtr->can_move(m.from, m.to, *this)) {
    std::cout << "Piece does not move geometrically like that" << "\n";
    return false;
  }

  // Ensure that the piece does not move onto a piece occupied by the same color piece.
  auto& toPiecePtr = _grid[m.to.row][m.to.col];
  if(toPiecePtr && toPiecePtr->color() == side) {
    std::cout << "Piece cannot occupy the same square as a piece of its color" << "\n";
    return false;
  }

  // TODO Many other checks are releavant and important.
  // Castling, enpassant, pieces blocking, king safety, etc.
  
  return true;
}

bool ChessBoard::move_piece(const Move& m, Color side) {
  if (!is_legal_move(m, side))
    return false;

  // Whatever is on the "to" position, capture it. Even if it is nothing.
  _grid[m.to.row][m.to.col].reset();

  // Move the piece pointer to the destination.
  _grid[m.to.row][m.to.col] = std::move(_grid[m.from.row][m.from.col]);
  _grid[m.from.row][m.from.col].reset();

  return true;

}

}

  
