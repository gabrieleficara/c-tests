#include "chess.h"

int     c_board::o_move(int coor[2], int dest[2])
{
    int tmp[2];

    if (coor[1] != dest[1])
        return (0);
    init_move(coor[0], dest[0], tmp);
    while (tmp[0] < tmp[1])
    {
        if (board[coor[1]][tmp[0]]->name != '.')
            return (0);
        tmp[0]++;
    }
    return (1);
}

int     c_board::v_move(int coor[2], int dest[2])
{
    int tmp[2];

    if (coor[0] != dest[0])
        return (0);
    init_move(coor[1], dest[1], tmp);
    while (tmp[0] < tmp[1])
    {
        if (board[tmp[0]][coor[0]]->name != '.')
            return (0);
        tmp[0]++;
    }
    return (1);
}

int     c_board::k_move(int coor[2], int dest[2])
{
    int tmp[2];

    tmp[0] = abs(coor[0] - dest[0]);
    tmp[1] = abs(coor[1] - dest[1]);
    if (tmp[0] == 0 || tmp[1] == 0)
        return (0);
    if (tmp[0] + tmp[1] == 3)
        return (1);
    return(0);
}

int     c_board::p_move(c_pawn pawn, int coor[2], int dest[2])
{
    int dir;
    int enemy;

    if (pawn.player == 1)
    {
        enemy = 2;
        dir = 1;
    }
    else
    {
        enemy = 1;
        dir = -1;
    }
    if (dest[1] == coor[1] + dir && dest[0] == coor[0]
        && board[dest[1]][dest[0]]->name == '.')
        return (1);
    if (P_move(pawn, coor, dest, dir))
        return (1);
    if (dest[1] == coor[1] + dir && abs(dest[0] - coor[0]) == 1 && 
        board[dest[1]][dest[0]]->player == enemy)
        return (1);
    return (0);
}

int     c_board::d_move(int coor[2], int dest[2])
{
    int tmp[2];
    int sign[2];

    tmp[0] = dest[0] - coor[0];
    tmp[1] = dest[1] - coor[1];
    if (abs(tmp[0]) != abs(tmp[1]) || tmp[0] == 0)
        return (0);
    sign[0] = (tmp[0] < 0) ? 1 : -1;
    sign[1] = (tmp[1] < 0) ? 1 : -1;
    tmp[0] += sign[0];
    tmp[1] += sign[1];
    while (tmp[0])
    {
        std::cout << tmp[0] << endl;
        std::cout << tmp[1] << endl;
        if (board[coor[1] + tmp[1]][coor[0] + tmp[0]]->name != '.')
            return (0);
        tmp[0] += sign[0];
        tmp[1] += sign[1];
    }
    return (1);
}