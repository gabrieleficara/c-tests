#ifndef CHESS_H
# define CHESS_H

# include <iostream>

typedef struct  s_piece
{
    char name;
    int player;
}               t_piece;

class c_board
{
    private:
        void define_line(t_piece board[8], int player);
    public:
        void define_board(t_piece board[8][8]);
};

#endif