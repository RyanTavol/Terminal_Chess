#include <iostream>

int main() {
  std::cout <<"Welcome to Terminal Chess!\n";


  // Example code for seeing how the printing will look.
  std::setlocale(LC_ALL, "");

  // Define the 8×8 starting board as strings
  const std::vector<std::vector<std::string>> board = {
      // Rank 8 (Black back row)
      { "♜", "♞", "♝", "♛", "♚", "♝", "♞", "♜" },
      // Rank 7 (Black pawns)
      { "♟", "♟", "♟", "♟", "♟", "♟", "♟", "♟" },
      // Ranks 6–3 (empty)
      { " ",  " ",  " ",  " ",  " ",  " ",  " ",  " "  },
      { " ",  " ",  " ",  " ",  " ",  " ",  " ",  " "  },
      { " ",  " ",  " ",  " ",  " ",  " ",  " ",  " "  },
      { " ",  " ",  " ",  " ",  " ",  " ",  " ",  " "  },
      // Rank 2 (White pawns)
      { "♙", "♙", "♙", "♙", "♙", "♙", "♙", "♙" },
      // Rank 1 (White back row)
      { "♖", "♘", "♗", "♕", "♔", "♗", "♘", "♖" }
  };

      // Function to draw a horizontal separator line
    auto print_separator = [&]() {
        std::cout << "   +";
        for (int i = 0; i < 8; ++i) {
            std::cout << "---+";
        }
        std::cout << "\n";
    };

    // Print top file labels
    std::cout << "     a   b   c   d   e   f   g   h\n";
    print_separator();

    // Print each rank
    for (int rank = 0; rank < 8; ++rank) {
        // Rank label on the left
        std::cout << " " << (8 - rank) << " |";

        // Print each square with vertical separators
        for (int file = 0; file < 8; ++file) {
            std::cout << " " << board[rank][file] << " |";
        }

        // Rank label on the right
        std::cout << " " << (8 - rank) << "\n";

        // Separator under the rank
        print_separator();
    }

    // Print bottom file labels
    std::cout << "     a   b   c   d   e   f   g   h\n";


  return 0;
}
