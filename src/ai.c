#include "ai.h"
#include <stdlib.h>
#include <stdio.h>

const static int dx[] = {0, 1, 0, -1};
const static int dy[] = {1, 0, -1, 0};

direction_t rand_action(game_t *game, snake_t *snake) {
  int x = snake->head->row;
  int y = snake->head->col;
  for (int i = 0; i < 10000; i++) {
    int d = rand() % 4;
    int tx = x + dx[d], ty = y + dy[d];
    if (*board_cell(game->board, tx, ty) < 2) {
      return (direction_t)d;
    }
  }
  return NORTH;
}

direction_t get_action1(game_t *game) {
  return rand_action(game, game->snake1);
}

direction_t get_action2(game_t *game) {
  return rand_action(game, game->snake2);
}
