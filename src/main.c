//main.c

#include "../include/main.h"

int main(void)
{
    board_t board;

    init_board(&board);
int f;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (f = drop(&board, i)) {
                printf("%i\n", f);
            }
        }
    }
    display_board(&board);


    return 0;
}
