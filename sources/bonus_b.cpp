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


void     c_board::check(int turn)
{
    int     i[2];
    c_king  &king = (turn == 1) ? pieces.b_kings : pieces.w_kings;


    i[0] = -1;
    i[1] = -1;
    c_check = 1;
    while (++i[1] < 8)
    {
        while (++i[0] < 8)
            if (board[i[1]][i[0]]->player == turn &&
                move(board[i[1]][i[0]], i, king.pos))
                {
                    std::cout << "Player " << king.player << " is in check." << endl;
                    break;
                }
        i[0] = -1;
    }
    c_check = 0;
}