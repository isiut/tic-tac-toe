#include "logic.h"
#include <stdio.h>

int check_win(int *board_positions)
{
    static const int win_combinations[8][3] = {// Rows
                                               {0, 1, 2},
                                               {3, 4, 5},
                                               {6, 7, 8},
                                               // Columns
                                               {0, 3, 6},
                                               {1, 4, 7},
                                               {2, 5, 8},
                                               // Diagonals
                                               {0, 4, 8},
                                               {2, 4, 6}};

    int filledSquares = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (board_positions[i] != 0)
        {
            filledSquares++;
        }
    }

    for (int i = 0; i < 8; ++i)
    {
        int sum = board_positions[win_combinations[i][0]] + board_positions[win_combinations[i][1]] +
                  board_positions[win_combinations[i][2]];
        if (sum == 3)
        {
            printf("x won!\n");
            return 1;
        }
        else if (sum == -3)
        {
            printf("o won!\n");
            return -1;
        }
    }

    if (filledSquares == 9)
    {
        printf("It's a draw!\n");
        return -2;
    }

    return 0;
}