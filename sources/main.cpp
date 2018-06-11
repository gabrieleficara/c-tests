#include "chess.h"

int main() {
    int i;
    int j;
    c_board n_board;


    define_board(board);
    i = 0;
    j = 0;
    while (j < 8)
    {
        while (i < 8)
        {
            std::cout << board[j][i].name;
            i++;
        }
        i = 0;
        std::cout << std::endl;
        j++;
    }
    for(int i = 0; i < 8; i++)
        delete board[i];
    delete board;
    return 0;
}