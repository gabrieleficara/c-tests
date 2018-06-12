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
        i++;
    }
}

void    c_board::print_board(void)
{
    int i;
    int j;

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
}

c_board::c_board(void)
{
    int i;
    int j;

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