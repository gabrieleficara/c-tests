#include "chess.h"

c_board::c_board(void)
{
    int i;
    int j;
    int color;

    board = new c_piece **[8];
    for(int i = 0; i < 8; i++)
        board[i] = new c_piece *[8];
    i = 0;
    j = 0;
    while (j < 8)
    {
        while (i < 8)
            board[j][i++] = &(pieces.empty);
        i = 0;
        j++;
    }
    define_board();
    en_p[0] = -1;
    en_p[1] = -1;
    en_p[2] = 0;
    castling[0] = 0;
    castling[1] = 0;
}

c_board::~c_board(void)
{
    int i;

    for(int i = 0; i < 8; i++)
        delete board[i];
    delete board;
}

c_piece::c_piece(void)
{
    name = '.';
    player = 0;
    color = 0;
}

c_king::c_king(void)
{
    name = 'K';
}

c_queen::c_queen(void)
{
    name = 'q';
}

c_knight::c_knight(void)
{
    name = 'k';
}

c_bishop::c_bishop(void)
{
    name = 'b';
}

c_rook::c_rook(void)
{
    name = 'r';
}

c_pawn::c_pawn(void)
{
    name = 'p';
}