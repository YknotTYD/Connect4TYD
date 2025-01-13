//main.c

#include "../include/main.h"

static int ask_user(void)
{
    int input;

    printf("Enter a column's index: ");
    scanf("%i", &input);
    printf("\n");
    return input;
}

static int next_round(board_t *board)
{
    int result;
    
    result = drop(board, ask_user());
    if (result) {
        return result;
    }
    stockpufferfish(board);
    return 0;
}

int main(void)
{
    board_t *board = malloc(sizeof(board_t));

    init_board(board);

    do {
        display_board(board);
        printf("\n");
    } while (next_round(board) == 0);
    display_board(board);

    return 0;
}
