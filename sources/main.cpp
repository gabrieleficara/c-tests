#include "chess.h"

int main() {
    int i;
    int j;
    t_piece board[8][8];
    c_board boa;

    i = 0;
    j = 0;
    boa.define_board(board);
    while (j < 8)
    {
        while (i < 8)
        {
            std::cout << board[j][i].name;
            i++;
        }
        std::cout << '\n';
        j++;
    }
    return 0;
}