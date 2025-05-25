// Header file including logic for the base piece class (and the enums for piece type and color).

#pragma once
#include <memory>
#include <stdexcept>
#include <string>
#include <cmath>

namespace terminal_chess {

struct Position {
  int row;
  int col;
};

class ChessBoard;

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
                        const ChessBoard& board) const = 0;
  
  virtual std::string symbol(bool darkMode) const = 0;

private:
  Color _color;
};

// TODO Implement move complicated Piece moving (such as blocking pieces, check, etc);

// Individual piece subclass declarations.
class King: public Piece {
public:
  explicit King(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::King; }
  std::string symbol(bool darkMode) const override {
    if (darkMode) 
      return color()==Color::White ? "♚" : "♔"; 
    return color()==Color::White ? "♔" : "♚"; 
  }
  bool can_move(const Position& from, const Position& to, const ChessBoard& board) const override {
    // King can only move one step in 1 direction.
    // Castling logic is handled separetely. This is only meant to see if this move is a "King" move.
    int deltaRow = std::abs(to.row - from.row);
    int deltaCol = std::abs(to.col - from.col);
    // Ensures that any move is exactly 1 space away (not more and not 0).
    return (deltaRow <= 1 && deltaCol <= 1) && !(deltaRow == 0 && deltaCol == 0);
  }
};

class Queen: public Piece {
public:
  explicit Queen(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Queen; }
  std::string symbol(bool darkMode) const override { 
    if (darkMode)
      return color()==Color::White ? "♛" : "♕"; 
    return color()==Color::White ? "♕" : "♛"; 

  }
  bool can_move(const Position& from, const Position& to, const ChessBoard& board) const override {
    // Queen can move only vertical, horizontal, or diagonal.
    int deltaRow = std::abs(to.row - from.row);
    int deltaCol = std::abs(to.col - from.col);

    // Straight moves (vertical, horizontal).
    bool straightMove = (deltaRow == 0 || deltaCol == 0);

    // Diagonal moves have the same deltas (in abs).
    bool diagMove = (deltaRow == deltaCol);

    // Move must be either straight or diagonal (and not (0,0)).
    return (straightMove || diagMove) && !(deltaRow == 0 && deltaCol == 0);
  }
};

class Rook: public Piece {
public:
  explicit Rook(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Rook; }
  std::string symbol(bool darkMode) const override {
    if (darkMode) 
      return color()==Color::White ? "♜" : "♖"; 
    return color()==Color::White ? "♖" : "♜"; 
  }
  bool can_move(const Position& from, const Position& to, const ChessBoard& board) const override {
    // Rook can move only vertical or horizontal.
    int deltaRow = std::abs(to.row - from.row);
    int deltaCol = std::abs(to.col - from.col);
    return (deltaRow == 0 && deltaCol != 0) || (deltaRow != 0 && deltaCol == 0);
  }
};

class Bishop: public Piece {
public:
  explicit Bishop(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Bishop; }
  std::string symbol(bool darkMode) const override {
    if (darkMode) 
      return color()==Color::White ? "♝" : "♝"; 
    return color()==Color::White ? "♗" : "♝"; 
  }
  bool can_move(const Position& from, const Position& to, const ChessBoard& board) const override {
    // Bishops can only move diagonally.
    int deltaRow = std::abs(to.row - from.row);
    int deltaCol = std::abs(to.col - from.col);
    return (deltaRow == deltaCol) && !(deltaRow == 0 && deltaCol == 0);
  }
};

class Knight: public Piece {
public:
  explicit Knight(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Knight; }
  std::string symbol(bool darkMode) const override {
    if (darkMode) 
      return color()==Color::White ? "♞" : "♘"; 
    return color()==Color::White ? "♘" : "♞"; 
  }
  bool can_move(const Position& from, const Position& to, const ChessBoard& board) const override {
    // Knights can move in "L" shapes. (2,1) or (1,2).
    int deltaRow = std::abs(to.row - from.row);
    int deltaCol = std::abs(to.col - from.col);
    return (deltaRow == 2 && deltaCol == 1) || (deltaRow == 1 && deltaCol == 2);
  }
};

class Pawn: public Piece {
public:
  explicit Pawn(Color c) : Piece(c) {}
  PieceType type() const override { return PieceType::Pawn; }
  std::string symbol(bool darkMode) const override {
    if (darkMode) 
      return color()==Color::White ? "♟" : "♙";
    return color()==Color::White ? "♙" : "♟"; 
  }
  bool can_move(const Position& from, const Position& to, const ChessBoard& board) const override {
    // Pawns have weird behavior. Pawns can do one of 3 moves.
      // (1) Move forward by 1.
      // (2) Move forward by 2 (If on starting square).
      // (3) Move diagonally forward (If capturing).
    int direction = (color() == Color::White ? -1 : 1);
    //The only time when the sign of the direction matters.
    int deltaRow = to.row - from.row;
    int deltaCol = std::abs(to.col - from.col);

    // Case (1).
    if (deltaCol == 0 && deltaRow == direction) 
      return true;

    // Case (2).
    if (deltaCol == 0 && deltaRow == 2*direction){
      // Check to see if the pawn is at the starting rank.
      int startRank = (color() == Color::White ? 6 : 1);
      return from.row == startRank;
    }

    // Case (3). Now going to check if a piece is capturable (Chess Board will handle that).
    if (deltaCol == 1 && deltaRow == direction) return true;

    // If it reaches here, then it is not a valid Pawn move.
    return false;
  }
};

std::unique_ptr<Piece> create_piece(PieceType type, Color color);
  
}
