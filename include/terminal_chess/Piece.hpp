// Header file including logic for the base piece class (and the enums for piece type and color).

#pragma once
#include <memory>
#include <stdexcept>
#include <string>

namespace terminal_chess {

struct Position {
  int row;
  int col;
};

struct BoardState;

enum class PieceType { King, Queen, Rook, Bishop, Knight, Pawn };
enum class Color { White, Black };

class Piece {
public:
  Piece(Color c) : _color(c) {}
  virtual ~Piece() = default;

  Color color() const { return _color; }

  virtual PieceType type() const = 0;

  virtual bool can_move(const Position& from, 
                        const Position& to, 
                        const BoardState& board) const = 0;
  
  virtual std::string symbol() const = 0;

private:
  Color _color;
};

// Individual piece subclass declarations.
class King: public Piece {
public:
  explicit King(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::King; }
  std::string symbol() const override { return color()==Color::White ? "♔" : "♚"; }
  bool can_move(const Position&, const Position&, const BoardState&) const override {
    throw std::logic_error("King::can_move not implemented");
  }
};

class Queen: public Piece {
public:
  explicit Queen(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Queen; }
  std::string symbol() const override { return color()==Color::White ? "♕" : "♛"; }
  bool can_move(const Position&, const Position&, const BoardState&) const override {
    throw std::logic_error("Queen::can_move not implemented");
  }
};

class Rook: public Piece {
public:
  explicit Rook(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Rook; }
  std::string symbol() const override { return color()==Color::White ? "♖" : "♜"; }
  bool can_move(const Position&, const Position&, const BoardState&) const override {
    throw std::logic_error("Rook::can_move not implemented");
  }
};

class Bishop: public Piece {
public:
  explicit Bishop(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Bishop; }
  std::string symbol() const override { return color()==Color::White ? "♗" : "♝"; }
  bool can_move(const Position&, const Position&, const BoardState&) const override {
    throw std::logic_error("Bishop::can_move not implemented");
  }
};

class Knight: public Piece {
public:
  explicit Knight(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Knight; }
  std::string symbol() const override { return color()==Color::White ? "♘" : "♞"; }
  bool can_move(const Position&, const Position&, const BoardState&) const override {
    throw std::logic_error("Knight::can_move not implemented");
  }
};

class Pawn: public Piece {
public:
  explicit Pawn(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Pawn; }
  std::string symbol() const override { return color()==Color::White ? "♙" : "♟"; }
  bool can_move(const Position&, const Position&, const BoardState&) const override {
    throw std::logic_error("Pawn::can_move not implemented");
  }
};

std::unique_ptr<Piece> create_piece(PieceType type, Color color);
  
}
