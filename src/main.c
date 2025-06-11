#include "draw.h"
#include "input.h"
#include "logic.h"
#include <stdio.h>

int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int process_selection(int player, int *board_positions)
{
    Selection selection = handle_input(player, board_positions);
    board[selection.position] = selection.player;

    return 0;
}

int main(void)
{
    draw_tutorial_board();

    int winner = 0;
    while (winner == 0)
    {
        // Process input for X
        if (process_selection(1, board) != 0)
            return 1;

        draw_board(board);
        if (check_win(board) != 0)
        {
            break;
        }

        // Process input for O
        if (process_selection(-1, board) != 0)
            return 1;

        draw_board(board);
        if (check_win(board) != 0)
        {
            break;
        }
    }

    return 0;
}