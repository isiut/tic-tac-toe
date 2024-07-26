#include "logic.h"
#include <stdio.h>

int check_win(int board_positions[9])
{
    // Horizontal combination
    int h1 = board_positions[0] + board_positions[1] + board_positions[2];
    int h2 = board_positions[3] + board_positions[4] + board_positions[5];
    int h3 = board_positions[6] + board_positions[7] + board_positions[8];

    // Vertical combination
    int v1 = board_positions[0] + board_positions[3] + board_positions[6];
    int v2 = board_positions[1] + board_positions[4] + board_positions[7];
    int v3 = board_positions[2] + board_positions[5] + board_positions[8];

    // Diagonal combination
    int d1 = board_positions[0] + board_positions[4] + board_positions[8];
    int d2 = board_positions[2] + board_positions[4] + board_positions[6];

    int filledSquares = 0;
    for (int i = 0; i <= 8; i++)
    {
        if (board_positions[i] != 0)
        {
            filledSquares++;
        }
    }

    if (h1 == 3 || h2 == 3 || h3 == 3 || v1 == 3 || v2 == 3 || v3 == 3 || d1 == 3 || d2 == 3)
    {
        printf("x won!\n");
        return 1;
    }
    else if (h1 == -3 || h2 == -3 || h3 == -3 || v1 == -3 || v2 == -3 || v3 == -3 || d1 == -3 || d2 == -3)
    {
        printf("o won!\n");
        return -1;
    }
    else if (filledSquares >= 9)
    {
        printf("It's a draw!\n");
        return -2;
    }

    return 0;
}