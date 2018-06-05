#include "chess.h"

int main() {
    int i;
    int j;
    t_piece **board;

    board = new t_piece *[8];
    for(int i = 0; i < 8; i++)
        board[i] = new t_piece [8];
    i = 0;
    j = 0;
    while (j < 8)
    {
        while (i < 8)
        {
            board[j][i].name = '.';
            board[j][i].player = 0;
            i++;
        }
        i = 0;
        j++;
    }
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