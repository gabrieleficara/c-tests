#include "chess.h"

void    c_board::init_move(int a, int b, int tmp[2])
{
    if (a < b)
    {
        tmp[0] = a + 1;
        tmp[1] = b;    
    }
    else 
    {
        tmp[0] = b + 1;
        tmp[1] = a;    
    }
}

int     c_board::end_cast(int coor[2], int dest[2], int turn)
{
    int     dir;

    dir = (dest[0] > 0) ? 1 : -1;
    board[coor[1]][coor[0] + (2 * dir)] = board[coor[1]][coor[0]];
    board[coor[1]][coor[0] + (dir)] = board[dest[1]][dest[0]];
    board[coor[1]][coor[0]] = &(pieces.empty);
    board[dest[1]][dest[0]] = &(pieces.empty);
    castling[turn - 1] = 1;
    return (1);
}

int     c_board::cast(int coor[2], int dest[2], int turn)
{
    c_rook  *rook;

    if (!castling[turn - 1])
        if (board[coor[1]][coor[0]]->moved == 0 &&
            board[coor[1]][coor[0]]->name == 'K' &&
            board[dest[1]][dest[0]]->name == 'r')
            {
                rook = (turn == 1) ? &(pieces.w_rooks) : &(pieces.b_rooks);
                if (((dest[0] == 0 && rook->moved < 2) ||
                    (dest[0] == 0 && rook->moved % 2 == 0)) &&
                    o_move(coor, dest))
                        return(end_cast(coor, dest, turn));
            }
    return (0);
}

int     c_board::P_move(c_pawn pawn, int coor[2], int dest[2], int dir)
{
    if (dest[1] == coor[1] + (dir * 2) && dest[0] == coor[0]
        && board[dest[1]][dest[0]]->name == '.'
        && (coor[1] == 1 || coor[1] == 6))
    {
        en_p[0] = dest[0];
        en_p[1] = dest[1];
        en_p[2] = 2;
        return (1);
    }
    if (dest[1] == coor[1] + dir && abs(dest[0] - coor[0]) == 1 && 
        en_p[1] == coor[1] & abs(en_p[0] - coor[0]) == 1
        && en_p[2] > 0)
    {
        board[en_p[1]][en_p[0]] = &(pieces.empty);
        return (1);
    }
    return (0);
}

void     c_board::transform(int dest[2])
{
    std::string command;
    int     coor;

    std::cout << "What will your pawn transform to?" << endl;
    while (1)
    {
        std::cout << "1)queen - 2)rook - 3)bishop - 4)knight" << endl;
        std::getline(std::cin, command);
        if (command[0] && !command[2])
            if (command[0] >= '1' && command[0] < '5')
            {
                coor = command[0] - 48;
                break;
            }
        std::cout << "i don't understand, can you repeat please?" << endl;
    }
    if (coor > 2)
    {
        if (coor > 3)
            board[dest[1]][dest[0]] = &((dest[1] == 0) ? pieces.b_knights : pieces.w_knights);
        else
            board[dest[1]][dest[0]] = &((dest[1] == 0) ? pieces.b_bishops : pieces.w_bishops);
    }
    else
    {
        if (coor > 1)
            board[dest[1]][dest[0]] = &((dest[1] == 0) ? pieces.b_rooks : pieces.w_rooks);
        else
            board[dest[1]][dest[0]] = &((dest[1] == 0) ? pieces.b_queens : pieces.w_queens);
    }
}