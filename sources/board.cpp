#include "chess.h"

void c_board::define_line(c_piece **board, int player)
{
    int i;

    i = 0;
    if (player == 1)
    {
        board[0] = &(pieces.w_rooks);
        board[1] = &(pieces.w_knights);
        board[2] = &(pieces.w_bishops);
        board[3] = &(pieces.w_queens);
        board[4] = &(pieces.w_kings);
        board[5] = &(pieces.w_bishops);
        board[6] = &(pieces.w_knights);
        board[7] = &(pieces.w_rooks);
    }
    else
    {
        board[0] = &(pieces.b_rooks);
        board[1] = &(pieces.b_knights);
        board[2] = &(pieces.b_bishops);
        board[3] = &(pieces.b_queens);
        board[4] = &(pieces.b_kings);
        board[5] = &(pieces.b_bishops);
        board[6] = &(pieces.b_knights);
        board[7] = &(pieces.b_rooks);
    }
    while (i < 8)
    {
        board[i]->player = player;
        board[i]->moved = 0;
        if (player == 1)
            board[i]->color = 37;
        else
            board[i]->color = 30;
        i++; 
    }
}

void c_board::define_board(void)
{
    int i;
    int j;

    i = 0;
    define_line(board[0], 1);
    define_line(board[7], 2);
    pieces.w_rooks.s_pos = 0;
    pieces.b_rooks.s_pos = 7;
    while (i < 8)
    {
        board[1][i] = &(pieces.w_pawns);
        board[6][i] = &(pieces.b_pawns);
        board[1][i]->player = 1;
        board[6][i]->player = 2;
        board[1][i]->color = 37;
        board[6][i]->color = 30;
        board[1][i]->moved = 0;
        board[6][i]->moved = 0;
        i++;
    }
}

void    c_board::print_board(void)
{
    int i;
    int j;
    int b_color;

    i = 0;
    j = 7;
    std::cout << " abcdefgh" << std::endl;
    while (j >= 0)
    {
        std::cout << j + 1;
        while (i < 8)
        {
            b_color = ((i + j) % 2 == 0) ? 46 : 44;
            if (board[j][i]->color == 0)
                std::cout << "\033["<<  b_color << ";" << b_color - 10 <<"m";
            else
                std::cout << "\033["<<  b_color << ";" << board[j][i]->color <<"m";
            std::cout << board[j][i]->name;
            i++;
        }
        i = 0;
        std::cout << "\033[0m" << j + 1 << std::endl;
        j--;
    }
    std::cout << " abcdefgh" << std::endl;
}