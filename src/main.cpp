#include <iostream>
#include <vector>
#include <memory>
#include <locale>

#include "terminal_chess/Piece.hpp"

using namespace terminal_chess;

int main() {
  // Ensure UTF-8 symbols print correctly
  std::setlocale(LC_ALL, "");

  // 1) Create an empty 8×8 board of Piece pointers
  std::vector<std::vector<std::unique_ptr<Piece>>> board(8);
  for (auto &row : board) {
    row.resize(8);
  }

  // 2) Helper to place an entire rank
  auto place_rank = [&](int r, PieceType t, Color c) {
    for (int f = 0; f < 8; ++f) {
      board[r][f] = create_piece(t, c);
    }
  };

  // 3) Set up starting position
  // Black back rank (row 0)
  board[0][0] = create_piece(PieceType::Rook,   Color::Black);
  board[0][1] = create_piece(PieceType::Knight, Color::Black);
  board[0][2] = create_piece(PieceType::Bishop, Color::Black);
  board[0][3] = create_piece(PieceType::Queen,  Color::Black);
  board[0][4] = create_piece(PieceType::King,   Color::Black);
  board[0][5] = create_piece(PieceType::Bishop, Color::Black);
  board[0][6] = create_piece(PieceType::Knight, Color::Black);
  board[0][7] = create_piece(PieceType::Rook,   Color::Black);

  // Black pawns (row 1)
  place_rank(1, PieceType::Pawn, Color::Black);

  // White pawns (row 6)
  place_rank(6, PieceType::Pawn, Color::White);

  // White back rank (row 7)
  board[7][0] = create_piece(PieceType::Rook,   Color::White);
  board[7][1] = create_piece(PieceType::Knight, Color::White);
  board[7][2] = create_piece(PieceType::Bishop, Color::White);
  board[7][3] = create_piece(PieceType::Queen,  Color::White);
  board[7][4] = create_piece(PieceType::King,   Color::White);
  board[7][5] = create_piece(PieceType::Bishop, Color::White);
  board[7][6] = create_piece(PieceType::Knight, Color::White);
  board[7][7] = create_piece(PieceType::Rook,   Color::White);

  // 4) Draw a horizontal separator
  auto print_sep = [&]() {
    std::cout << "   +";
    for (int i = 0; i < 8; ++i) {
      std::cout << "---+";
    }
    std::cout << "\n";
  };

  // 5) Print column labels + board
  std::cout << "     a   b   c   d   e   f   g   h\n";
  print_sep();

  for (int r = 0; r < 8; ++r) {
    std::cout << " " << (8 - r) << " |";
    for (int f = 0; f < 8; ++f) {
      if (board[r][f]) {
        std::cout << " " << board[r][f]->symbol() << " |";
      } else {
        std::cout << "   |";
      }
    }
    std::cout << " " << (8 - r) << "\n";
    print_sep();
  }

  std::cout << "     a   b   c   d   e   f   g   h\n";
  return 0;
}
