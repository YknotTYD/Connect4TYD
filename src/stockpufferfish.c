//stockpufferfish.c

#include "../include/connect.h"

static int minimax(board_t *board, int depth)
{
    int sum = 0;
    board_t *new;
    int drop_result;
    int max_x;
    int max_value;

    if (depth <= 0) {
        return 0;
    }

    for (int i = 0; i < WIDTH; i++) {
        if (CINDEX(board->any, i, 0) == 0) {

            new = board_copy(board);
            drop_result = drop(new, i) == TURN_NONE ? 0: 1;

            sum -= minimax(new, depth - 1);

        }
    }
    free(board);

    return sum;
}

static int randomove(board_t *board)
{
    int x;

    do {
        x = rand() % WIDTH;
    } while (CINDEX(board->any, x, 0));

    return x;
}

int stockpufferfish(board_t *board)
{
    int x = minimax(board_copy(board), 7);
    return drop(board, x);
}
