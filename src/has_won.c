//has_won.c

#include "../include/connect.h"

//use masks instead

static int has_won_1_0(board_t *board)
{
    if (board->last_drop_x > (WIDTH - 4)) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (CINDEX(CURRENT_COLOR(board), board->last_drop_x + i, board->last_drop_y) == 0) {
            return 0;
        }
    }
    return 1;
}

static int has_won_m1_0(board_t *board)
{
    if (board->last_drop_x < 3) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (CINDEX(CURRENT_COLOR(board), board->last_drop_x - i, board->last_drop_y) == 0) {
            return 0;
        }
    }
    return 1;
}

static int has_won_0_1(board_t *board)
{
    if (board->last_drop_y > (HEIGHT - 4)) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (CINDEX(CURRENT_COLOR(board), board->last_drop_x, board->last_drop_y + i) == 0) {
            return 0;
        }
    }
    return 1;
}

static int has_won_0_m1(board_t *board)
{
    if (board->last_drop_y < 3) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (CINDEX(CURRENT_COLOR(board), board->last_drop_x, board->last_drop_y - i) == 0) {
            return 0;
        }
    }
    return 1;
}

static int has_won_1_1(board_t *board)
{
    if (board->last_drop_x > (WIDTH - 4) || board->last_drop_y > (HEIGHT - 4)) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (CINDEX(CURRENT_COLOR(board), board->last_drop_x + i, board->last_drop_y + i) == 0) {
            return 0;
        }
    }
    return 1;
}

static int has_won_1_m1(board_t *board)
{
    if (board->last_drop_x > (WIDTH - 4) || board->last_drop_y < 3) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (CINDEX(CURRENT_COLOR(board), board->last_drop_x + i, board->last_drop_y - i) == 0) {
            return 0;
        }
    }
    return 1;
}

static int has_won_m1_1(board_t *board)
{
    if (board->last_drop_x < 3 || board->last_drop_y > (HEIGHT - 4)) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (CINDEX(CURRENT_COLOR(board), board->last_drop_x - i, board->last_drop_y + i) == 0) {
            return 0;
        }
    }
    return 1;
}

static int has_won_m1_m1(board_t *board)
{
    if (board->last_drop_x < 3 || board->last_drop_y < 3) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (CINDEX(CURRENT_COLOR(board), board->last_drop_x - i, board->last_drop_y - i) == 0) {
            return 0;
        }
    }
    return 1;
}

int has_won(board_t *board)
{
    if ((FULLMASK ^ board->any) == 0) {
        return TURN_NONE;
    }
    return has_won_1_0(board) || has_won_m1_0(board) || has_won_0_1(board) || has_won_0_m1(board) ||
        has_won_1_1(board) || has_won_1_m1(board) || has_won_m1_1(board) || has_won_m1_m1(board);
}
