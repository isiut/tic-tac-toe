#include "input.h"
#include <stdio.h>

Selection handle_input(int player, int board_positions[9])
{
    char player_uses = player == 1 ? 'x' : 'o';

    int input;
    printf("%c: ", player_uses);

    while (scanf(" %d", &input) != 1 || input < 0 || input > 8 || board_positions[input] != 0)
    {
        printf("That square is taken or the input is incorrect; please try again.\n");
        printf("%c: ", player_uses);

        // Clear input buffer to prevent an infinite loop
        while (getchar() != '\n')
            ;
    }

    Selection selection;
    selection.player = player;
    selection.position = input;
    return selection;
}