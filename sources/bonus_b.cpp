#include "chess.h"

void    c_board::choose(int dest[2], int coor)
{
    if (coor > 2)
    {
        if (coor > 3)
            board[dest[1]][dest[0]] = &((dest[1] == 0) ? pieces.b_knights : pieces.w_knights);
        else
            board[dest[1]][dest[0]] = &((dest[1] == 0) ? pieces.b_bishops : pieces.w_bishops);
    }
    else
    {
        if (coor > 1)
            board[dest[1]][dest[0]] = &((dest[1] == 0) ? pieces.b_rooks : pieces.w_rooks);
        else
            board[dest[1]][dest[0]] = &((dest[1] == 0) ? pieces.b_queens : pieces.w_queens);
    }
}

/*
int     c_board::check(void)
{
    while()
}
*/