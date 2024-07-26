#include "draw.h"
#include "input.h"
#include "logic.h"
#include <stdio.h>

int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int process_selection(int player, int board_positions[9])
{
    Selection selection = handle_input(player, board_positions);
    board[selection.position] = selection.player;
}

int main(void)
{
    draw_tutorial_board();

    int winner = 0;
    while (winner == 0)
    {
        // Process input for X
        process_selection(1, board);

        draw_board(board);
        if (check_win(board) != 0)
        {
            break;
        }

        // Process input for O
        process_selection(-1, board);
        draw_board(board);
        if (check_win(board) != 0)
        {
            break;
        }
    }

    return 0;
}