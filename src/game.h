#ifndef GAME_H
#define GAME_H

typedef enum {
    CELL_OPEN,
    CELL_FOOD,
    CELL_WALL,
    CELL_SNAKE,
} cell_t;

typedef enum {
    EAST,
    SOUTH,
    WEST,
    NORTH,
} direction_t;

/*! A node of a snake (each node occupies a cell)
    This is like a node in a linked list. */
typedef struct SnakeNode {
    /* Row of the cell the node occupies */
    int row;
    /* Column of the cell the node occupies */
    int col;
    /* Pointer to the next node, in the direction of snake movement */
    struct SnakeNode *next;
} snake_node_t;

/*! Defines a snake, which is like a linked-list with the
    head and tail reversed. */
typedef struct Snake {
    /* The front node of the snake, or NULL if snake has no nodes */
    snake_node_t *head;
    /* The rear node of the snake, or NULL if snake has no nodes */
    snake_node_t *tail;
    /* The direction the snake head is going to move on the next iteration */
    direction_t heading;
} snake_t;

/*! Defines a board, which is a just a grid of cells. */
typedef struct Board {
    /* Number of rows in the grid */
    int rows;
    /* Number of columns in the grid */
    int cols;
    /* Pointer to the beginning of the board cell data.  The cells are organized
       in a row-major layout ( http://en.wikipedia.org/wiki/Row-major_order ) */
    cell_t *cells;
} board_t;

/*! Defines the game data structure, which consists of the board, the two
   snakes, and some game parameters. */
typedef struct Game {
    /* The game board */
    board_t *board;
    /* The human controlled snake */
    snake_t *snake;
    /* Time delay between each game iteration, in seconds */
    float time_step;
    /* Probability of one food cell appeared in each game iteration */
    float food_probability;
} game_t;

/* create a board with `rows` * `cols` */
board_t *create_board(int rows, int cols);

/* free a board */
void destroy_board(board_t *board);

/* get cell in specific position */
cell_t *board_cell(board_t *board, int row, int col);

/* create a snake */
snake_t *create_snake(board_t *board, int row, int col, direction_t heading);

/* free a snake */
void destroy_snake(snake_t *snake);

/* add food to board with probalility */
void randomly_add_food(board_t *board, float probability);

#endif // GAME_H
