#ifndef CHESS_H
# define CHESS_H

# include <iostream>

class c_piece{
    public:
        char name;
        int player;
}

class c_board{
    public:
        c_piece board**;
    private:
        void define_line(t_piece *board, int player);
        void define_board(t_piece **board);
}
#endif