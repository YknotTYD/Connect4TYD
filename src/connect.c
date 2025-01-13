//connect.c

#include "../include/connect.h"

//fix COLOR

board_t init_board(board_t *board)
{
    board->red = 0;
    board->yellow = 0;
    board->any = 0;
    board->turn = TURN_RED;
    board->last_drop_x = -1;
    board->last_drop_y = -1;

    return *board;
}

static int printc(char *str, int color)
{
    int sum = 0;
    int lenght;

    for (lenght = 0; str[lenght]; lenght++);

    switch (color) {
        case COLOR_WHITE:
            sum += write(1, "\x1b[38;2;255;255;255m",19);
            break;
        case COLOR_RED:
            sum += write(1, "\x1b[38;2;255;0;0m",15);
            break;
        case COLOR_YELLOW:
            sum += write(1, "\x1b[38;2;255;255;0m",17);
            break;
    }

    sum += write(1, str, lenght);
    return sum;
}

int display_board(board_t *board)
{
    int sum = 0;
    color_t red = board->red;
    color_t yellow = board->yellow;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            if ((red | yellow) & 1) {
                sum += printc("O ", red & 1 ? COLOR_RED: COLOR_YELLOW);
            } else {
                sum += printc("O ", COLOR_WHITE);
            }

            red >>= 1;
            yellow >>= 1;
        }
        sum += write(1, "\n", 1);
    }
    return sum;
}

int drop(board_t *board, int x)
{
    int y;
    int result;

    for (y = 0; y < HEIGHT; y++) {
        if (CINDEX(board->any, x, y)) {
            break;
        }
    }
    y--;

    CURRENT_COLOR(board) |= OMASK(x, y);
    board->any = board->red | board->yellow;

    board->last_drop_x = x;
    board->last_drop_y = y;

    result = has_won(board);
    board->turn = board->turn == TURN_RED ? TURN_YELLOW: TURN_RED;

    return result;
}
