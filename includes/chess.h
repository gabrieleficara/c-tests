#ifndef CHESS_H
# define CHESS_H

# include <iostream>
# include <string>
# include <cstdlib>

class c_piece
{
    public:
        char name;
        int player;
        int color;
};

using namespace std;
class c_board
{

    public:
        c_piece **board;
                c_board(void);
                ~c_board(void);
        void    define_board(void);
        void    print_board(void);
        int     turn(int turn,std::string player[2]);
        int     end_move(int coor[2], int dest[2]);
    private:
        void    define_line(c_piece *board, int player);
        int     move(int coor[2], int turn);
        void    retrive_data(int coor[2], int turn);
};

#endif