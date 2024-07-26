#ifndef INPUT_H
#define INPUT_H

typedef struct
{
    int player;
    int position;
} Selection;

Selection handle_input(int player, int board_positions[9]);

#endif