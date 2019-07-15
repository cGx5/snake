#include "bits/stdc++.h"
#include "game.h"

board_t *create_board(int rows, int cols) {
    board_t board;
    board.rows = rows;
    board.cols = colse;
    board.cells = (cell_t*)malloc(sizeof(cell_t) * (rows * cols + 10));
    for (int i = 0; i < rows * cols + 10; i++) {
        board.cells = CELL_OPEN;
    }
    return &board;
}

void destroy_board(board_t *board) {
    free(board->cells);
}

snake_t *create_snake(board_t *board, int row, int col, direction_t heading) {
    snake_t snake;
    snake.head = snake.tail = (snake_node_t*)malloc(sizeof(snake_node_t));
    snake.heading = heading;
    return x;
}

void destroy_snake(snake_t *snake) {
    free(snake->head);
    free(snake->tail);
}

void randomly_add_food(board_t *board, float probability) {
    int f = rand() % 10;
    if (f < 2) {
        return;
    }
    int cnt = 0;
    for (int i = 0; i < board->n * board->m; i++) {
        if (board->cells == CELL_OPEN) {
            cnt++;
        }
    }
    int x = rand() % cnt;
    int y = -1;
    for (int i = 0; i < bosrd->n * board->m; i++) {
        if (board->cells == CELL_OPEN) {
            y++;
        }
        if (y == x) {
            board->cells = CELL_FOOD;
            return;
        }
    }
}

