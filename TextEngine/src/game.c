// src/game.c

#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "game.h"

static char **arrayView2D;
static int rows, cols;
static char assetArray[6] = {'-', '|', '/', '\\', '_', ' '};

void game_initialize(int r, int c) {
    rows = r;
    cols = c;

    // Allocate memory for the 2D array
    arrayView2D = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        arrayView2D[i] = malloc(cols * sizeof(char));
    }

    // Initialize the game state (create bordered scene)
    drawBasicSceneBordered(arrayView2D, rows, cols, assetArray);
}

void game_update(char **buffer, int rows, int cols, int frame) {
    if (frame % 48 < 24) {
        drawBasicSceneBordered(buffer, rows, cols, assetArray);
    } else {
        drawBasicSceneSpaced(buffer, rows, cols, assetArray);
    }
}

void game_render() {
    // Clear the screen
    system("cls"); // Use "clear" for Unix-like systems

    // Draw the current game state
    drawView(arrayView2D, rows, cols);
}

void game_cleanup() {
    freeViewArray(arrayView2D, rows);
}

void game_getDimensions(int *r, int *c) {
    *r = rows;
    *c = cols;
}

char **game_getViewArray() {
    return arrayView2D;
}

