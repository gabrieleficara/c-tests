#include "chess.h"

void c_board::define_line(c_piece *board, int player)
{
    int i;

    i = 0;
    board[0].name = 'r';
    board[1].name = 'k';
    board[2].name = 'b';
    board[3].name = 'q';
    board[4].name = 'K';
    board[5].name = 'b';
    board[6].name = 'k';
    board[7].name = 'r';
    while (i < 8)
    {
        board[i].player = player;
        if (player == 1)
            board[i].color = 37;
        else
            board[i].color = 30;
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
    while (i < 8)
    {
        board[1][i].name = 'p';
        board[6][i].name = 'p';
        board[1][i].player = 1;
        board[6][i].player = 2;
        board[1][i].color = 37;
        board[6][i].color = 30;
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
            if (board[j][i].color == 0)
                std::cout << "\033["<<  b_color << ";" << b_color - 10 <<"m";
            else
                std::cout << "\033["<<  b_color << ";" << board[j][i].color <<"m";
            std::cout << board[j][i].name;
            i++;
        }
        i = 0;
        std::cout << "\033[0m" << j + 1 << std::endl;
        j--;
    }
    std::cout << " abcdefgh" << std::endl;
}

c_board::c_board(void)
{
    int i;
    int j;
    int color;

    board = new c_piece *[8];
    for(int i = 0; i < 8; i++)
        board[i] = new c_piece [8];
    i = 0;
    j = 0;
    while (j < 8)
    {

        while (i < 8)
        {
            board[j][i].name = '.';
            board[j][i].player = 0;
            board[j][i].color = 0;
            i++;
        }
        i = 0;
        j++;
    }
    define_board();
}

c_board::~c_board(void)
{
    int i;

    for(int i = 0; i < 8; i++)
        delete board[i];
    delete board;
}