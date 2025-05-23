#include <memory>           // for std::make_unique
#include <stdexcept>
#include "terminal_chess/Piece.hpp"

namespace terminal_chess {

std::unique_ptr<Piece> create_piece(PieceType t, Color c) {
  switch (t) {
    case PieceType::King:   return std::make_unique<King>(c);
    case PieceType::Queen:  return std::make_unique<Queen>(c);
    case PieceType::Rook:   return std::make_unique<Rook>(c);
    case PieceType::Bishop: return std::make_unique<Bishop>(c);
    case PieceType::Knight: return std::make_unique<Knight>(c);
    case PieceType::Pawn:   return std::make_unique<Pawn>(c);
  }
  throw std::invalid_argument("Unknown PieceType");
}
}

