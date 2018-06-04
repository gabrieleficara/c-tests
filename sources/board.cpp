#include "chess.h"

        void define_line(t_piece board[8], int player)
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

        void define_board(t_piece board[8][8])
        {
            int i;
            int j;

            i = 0;
            j = 2;
            define_line(board[0], 1);
            define_line(board[8], 2);
            while (i < 8)
            {
                board[1][i].name = 'p';
                board[6][i].name = 'p';
                board[1][i].player = 1;
                board[6][i].player = 2;
                i++;
            }
            i = 0;
            while (j < 6)
            {
                while (i < 7)
                {
                    board[j][i].name = '.';
                    board[j][i].player = 0;
                    i++;
                }
                j++;
            }
        }