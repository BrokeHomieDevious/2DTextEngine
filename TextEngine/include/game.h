// include/game.h

#ifndef GAME_H
#define GAME_H

void game_initialize(int rows, int cols);
void game_update(char **buffer, int rows, int cols, int frame);
void game_render();
void game_cleanup();
void game_getDimensions(int *rows, int *cols);
char **game_getViewArray();

#endif // GAME_H
