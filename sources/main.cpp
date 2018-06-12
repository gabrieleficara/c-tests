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
    end = 1;
    while (end)
        end = 0;
    n_board.print_board();
    return 0;
}