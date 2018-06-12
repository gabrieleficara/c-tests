#include "chess.h"

int main() {
    int end;
    std::string player[2];
    c_board n_board;

    end = 0;
    
    std::cout << "Enter player 1 name: ";
    std::getline(std::cin, player[0]);
    std::cout << "Enter player 2 name: ";
    std::getline(std::cin, player[1]);
    n_board.print_board();
    return 0;
}