#include "draw.h"
#include <stdio.h>

void draw_tutorial_board(void)
{
    printf("--Tic-Tac-Toe--\n");
    printf("Input a number 0-8 to mark that square: \n");

    printf("      |     |     \n");
    printf("   1  |  2  |  3  \n");
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   4  |  5  |  6  \n");
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   7  |  8  |  9  \n");
    printf("      |     |     \n");
}

void draw_board(int board_positions[9])
{
    char board[9];

    for (int i = 0; i <= 8; i++)
    {
        switch (board_positions[i])
        {
        case 0:
            board[i] = '-';
            break;
        case 1:
            board[i] = 'x';
            break;
        case -1:
            board[i] = 'o';
            break;
        }
    }

    printf("------------------\n\n");
    printf("      |     |     \n");
    printf("   %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("      |     |     \n\n");
}
