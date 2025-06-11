#include "input.h"
#include <stdio.h>

Selection handle_input(int player, int *board_positions)
{
    char player_uses = player == 1 ? 'x' : 'o';

    int input;
    printf("%c: ", player_uses);

    // Input goes from 1-9 while the array goes from 0-8
    while (scanf(" %d", &input) != 1 || input < 1 || input > 9 || board_positions[input - 1] != 0)
    {
        printf("That square is taken or the input is incorrect; please try again.\n");
        printf("%c: ", player_uses);

        // Clear input buffer to prevent an infinite loop
        while (getchar() != '\n')
            ;
    }

    Selection selection;
    selection.player = player;
    selection.position = input - 1;
    return selection;
}