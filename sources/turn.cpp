#include "chess.h"

int c_board::turn(int player)
{
    std::string command;
    int i;
    int coor[2];

    i = 0;
    std::cout << "Choose a piece: ";
    while (1)
    {
        std::getline(std::cin, command);
        if (command[0] && command[1] && !command[2])
            if (command[0] >= 'a' && command[0] <= 'h' && command[1] >= '1' && command[1] <= '9')
            {
                coor[0] = command[0] - 96;
                coor[1] = command[1] - 48;
                break;
            }
        std::cout << "i don't understand, can you repeat please?" << endl;
    }
    return ((player + 1)% 1);
}