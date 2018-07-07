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
            c_piece;
};

class c_king : public c_piece
{
    public:
            c_king;
    private:
        int castling;
}

class c_queen : public c_piece
{
    public:
}

class c_knight : public c_piece
{
    public:
}

class c_rook : public c_piece
{
    public:
}

class c_bishop : public c_piece
{
    public:
}

class c_pawn : public c_piece
{
    public:
}

typedef struct  s_pieces;
{
    c_king w_kings;
    c_queen w_queens;
    c_knight w_knights;
    c_rook w_rooks;
    c_bishop w_bishops;
    c_pawn w_pawns;
    c_king b_kings;
    c_queen b_queens;
    c_knight b_knights;
    c_rook b_rooks;
    c_bishop b_bishops;
    c_pawn b_pawns;
    c_piece empty;
}               t_pieces;

using namespace std;
class c_board
{
    public:
        c_piece ***board;
                c_board(void);
                ~c_board(void);
        void    define_board(void);
        void    print_board(void);
        int     turn(int turn,std::string player[2]);
        int     end_move(int coor[2], int dest[2]);
    private:
        t_pieces pieces;
        void    define_line(c_piece *board, int player);
        int     move(int coor[2], int turn);
        void    retrive_data(int coor[2], int turn);
};

#endif