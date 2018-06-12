#ifndef CHESS_H
# define CHESS_H

# include <iostream>
# include <string>

class c_piece{
    public:
        char name;
        int player;
};

using namespace std;
class c_board{
    public:
        c_piece **board;
                c_board(void);
                ~c_board(void);
        void    define_board(void);
        void    print_board(void);
    private:
        void    define_line(c_piece *board, int player);
};
#endif