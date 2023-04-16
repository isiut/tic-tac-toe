#include <stdio.h>

void tutorialBoard(void)
{
    printf("      |     |     \n");
    printf("   0  |  1  |  2  \n");
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   3  |  4  |  5  \n");
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   6  |  7  |  8  \n");
    printf("      |     |     \n");
}

int printBoard(int board[9])
{
    char drawnBoard[9];

    for (int i = 0; i <= 8; i++)
    {
        if (board[i] == 0)
        {
            drawnBoard[i] = '-';
        }
        else if (board[i] == 1)
        {
            drawnBoard[i] = 'x';
        }
        else if (board[i] == -1)
        {
            drawnBoard[i] = 'o';
        }
        else
        {
            return -1;
        }
    }

    printf("------------------\n\n");
    printf("      |     |     \n");
    printf("   %c  |  %c  |  %c  \n", drawnBoard[0], drawnBoard[1], drawnBoard[2]);
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   %c  |  %c  |  %c  \n", drawnBoard[3], drawnBoard[4], drawnBoard[5]);
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   %c  |  %c  |  %c  \n", drawnBoard[6], drawnBoard[7], drawnBoard[8]);
    printf("      |     |     \n\n");

    return 0;
}

int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int handleInput(int player)
{
    char playerUses = player == 1 ? 'x' : 'o';

    int input;
    printf("%c: ", playerUses);
    scanf(" %d", &input);

    if (board[input] != 0)
    {
        printf("That square is taken\n");
        return -1;
    }
    else
    {
        player == 1 ? board[input]++ : board[input]--;
    }

    return 0;
}

int winner = 0;

int main(void)
{
    printf("--Tic-Tac-Toe--\n");
    printf("Input a number 0-8 to mark that square: \n");
    tutorialBoard();

    while (winner == 0)
    {
        handleInput(1);
        printBoard(board);
        if (printBoard(board) == -1)
        {
            printf("Invalid input\n");
            return -1;
        }

        handleInput(-1);
        printBoard(board);
        if (printBoard(board) == -1)
        {
            printf("Invalid input\n");
            return -1;
        }
    }

    return 0;
}