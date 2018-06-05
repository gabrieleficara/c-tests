#ifndef CHESS_H
# define CHESS_H

# include <iostream>

typedef struct  s_piece
{
    char name;
    int player;
}               t_piece;


        void define_line(t_piece board[8], int player);
        void define_board(t_piece **board);

#endif