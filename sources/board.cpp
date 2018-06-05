#include "chess.h"

        void define_line(t_piece *board, int player)
        {
            int i;

            i = 0;
            board[0].name = 'r';
            board[1].name = 'k';
            board[2].name = 'b';
            board[3].name = 'q';
            board[4].name = 'K';
            board[5].name = 'b';
            board[6].name = 'k';
            board[7].name = 'r';
            while (i < 8)
            {
                board[i].player = player;
                i++;
            } 
        }

        void define_board(t_piece **board)
        {
            int i;
            int j;

            i = 0;
            define_line(board[0], 1);
            define_line(board[7], 2);
            while (i < 8)
            {
                board[1][i].name = 'p';
                board[6][i].name = 'p';
                board[1][i].player = 1;
                board[6][i].player = 2;
                i++;
            }
        }