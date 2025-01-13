//main.c

#include "../include/main.h"

int main(int argc, char **argv)
{
    board_t board;

    init_board(&board);

    drop(&board, 0);
    drop(&board, 1);
    drop(&board, 1);
    drop(&board, 2);
    drop(&board, 2);
    drop(&board, 3);
    drop(&board, 2);
    drop(&board, 3);
    drop(&board, 3);
    drop(&board, 5);
    drop(&board, 3);
    
    board.turn = !board.turn;

    printf("%i", has_won(&board));

    display_board(&board);

    (void)argc;
    (void)argv;
    return 0;
}
