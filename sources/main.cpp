#include "chess.h"

int main() {
    int end;
    std::string player[2];
    c_board n_board;

    end = 0;
    while (end < 2)
    {
        std::cout << "Enter player " << end + 1 << " name: ";
        std::getline(std::cin, player[end]);
        if (player[end][0] && player[end][0] != '\n')
            end++;
    }
    n_board.print_board();
    end = 1;
    while (end)
        end = n_board.turn(end, player);
    return 0;
}