#include "chess.h"

void    c_board::choose(int dest[2], int coor)
{
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


void     c_board::check(int turn)
{
    int     i[2];
    c_king  &king = (turn == 1) ? pieces.b_kings : pieces.w_kings;


    i[0] = -1;
    i[1] = -1;
    c_check = 1;
    while (++i[1] < 8)
    {
        while (++i[0] < 8)
            if (board[i[1]][i[0]]->player == turn &&
                move(board[i[1]][i[0]], i, king.pos))
                {
                    std::cout << "Player " << king.player << " is in check." << endl;
                    break;
                }
        i[0] = -1;
    }
    c_check = 0;
}

int     c_board::stop_game(std::string command, int turn)
{
    std::string com;

    if (!command.compare("resign"))
    {
        std::cout << "player " << turn << " resigned." << endl;
        std::cout << "player " << ((turn == 1) ? 2 : 1) << " wins!" << endl;
        return (0);
    }
    if (!command.compare("draw"))
    {
        while (1)
        {
            std::cout << "player " << turn << " proposed a draw, confirm? (y/n)" << endl;
            std::getline(std::cin, com);
            if (com[0] && !com[1])
                if (com[0] == 'y' || com[0] == 'n')
                {
                    if (com[0] == 'y')
                        return (0);
                    else
                        return (1);
                }
        }
    }
    return(1);
}