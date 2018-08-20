#ifndef CHESS_H
# define CHESS_H

# include <iostream>
# include <string>
# include <cstdlib>

using namespace std;
class c_piece
{
    public:
        char name;
        int player;
        int color;
        int moved;
            c_piece(void);
};

class c_king : public c_piece
{
    public:
            c_king(void);
            int castling;
};

class c_queen : public c_piece
{
    public:
            c_queen(void);
};

class c_knight : public c_piece
{
    public:
            c_knight(void);
};

class c_rook : public c_piece
{
    public:
            c_rook(void);
};

class c_bishop : public c_piece
{
    public:
            c_bishop(void);
};

class c_pawn : public c_piece
{
    public:
        c_pawn(void);
};

typedef struct  s_pieces
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
        int     en_p[3];
        t_pieces pieces;
        int     castling;
        void    define_line(c_piece **board, int player);
        int     move(int coor[2], int turn);
        void    retrive_data(int coor[2], int turn);
        int     o_move(int coor[2], int dest[2]);
        int     v_move(int coor[2], int dest[2]);
        int     k_move(int coor[2], int dest[2]);
        int     d_move(int coor[2], int dest[2]);
        int     cast(int coor[2], int dest[2]);
        int     p_move(c_pawn pawn, int coor[2], int dest[2]);
        int     P_move(c_pawn pawn, int coor[2], int dest[2], int dir);
        void    init_move(int a, int b, int tmp[2]);
        int     move(c_king king, int coor[2], int dest[2]);
        int     move(c_queen queen, int coor[2], int dest[2]);
        int     move(c_bishop bishop, int coor[2], int dest[2]);
        int     move(c_knight knight, int coor[2], int dest[2]);
        int     move(c_rook rook, int coor[2], int dest[2]);
        int     move(c_pawn pawn, int coor[2], int dest[2]);
        int     move(c_piece *piece, int coor[2], int dest[2]);
};

#endif