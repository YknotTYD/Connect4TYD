//main.h

#ifndef CONNECT_HEADER
    #define CONNECT_HEADER

#include <stdio.h>
#include <unistd.h>

#define WIDTH 7
#define HEIGHT 6

#define COLOR_WHITE 0
#define COLOR_YELLOW 1
#define COLOR_RED 2

#define TURN_RED 0
#define TURN_YELLOW 1
#define TURN_NONE -1 //has to not be 0
#define CURRENT_COLOR(board) (*((board)->turn == TURN_RED ? &board->red: &board->yellow))
#define COLOR(board, aturn) (*((board)->turn == (aturn) ? &(board)->red: &(board)->yellow))
#define CINDEX(color, x, y) (((color) << (63 - (y) * WIDTH - (x))) >> 63)

#define HMASK ((unsigned long long int)0b1111)
#define VMASK ((long long int)(1 << (WIDTH * 3)) | (1 << (WIDTH * 2)) | (1 << (WIDTH * 1)) | (1 << (WIDTH * 0)))
#define OMASK(x, y) (1ULL << ((y) * WIDTH + (x)))
#define FULLMASK ((1ULL << (WIDTH * HEIGHT)) - 1)

typedef unsigned long long int color_t;
typedef struct {
    color_t red;
    color_t yellow;
    color_t any;
    char turn;
    int last_drop_x;
    int last_drop_y;
} board_t;

int display_board(board_t *board);
board_t init_board(board_t *board);
int drop(board_t *board, int x);
int has_won(board_t *board);

#endif
