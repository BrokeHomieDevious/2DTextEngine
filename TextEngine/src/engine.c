// src/engine.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "engine.h"
#include "game.h"

static int running = 1;
static char **bufferArray;
static int rows, cols;

void swapBuffers(char ***currentView, char ***buffer) {
    char **temp = *currentView;
    *currentView = *buffer;
    *buffer = temp;
}

void refreshView(char **currentView, int rows, int cols) {
    system("cls"); // Use "cls" for Windows
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", currentView[i][j]);
        }
        printf("\n");
    }
}

void engine_init(int r, int c) {
    rows = r;
    cols = c;
    game_initialize(rows, cols);
    
    // Allocate memory for the buffer array
    bufferArray = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        bufferArray[i] = malloc(cols * sizeof(char));
    }
}

void engine_run() {
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 1000000000 / 24; // 24 FPS
    int frame = 0;

    while (running) {
        // Handle input (this is a placeholder, input handling should be implemented as needed)
        if (getchar() == 'q') {
            running = 0;
        }

        // Update the game state using the buffer array
        game_update(bufferArray, rows, cols, frame);

        // Get the current view array
        char **currentView = game_getViewArray();

        // Swap the current view array with the buffer array
        swapBuffers(&currentView, &bufferArray);

        // Refresh the view
        refreshView(currentView, rows, cols);

        // Sleep to control the frame rate
        nanosleep(&ts, NULL);

        // Increment the frame number
        frame++;
    }
}

void engine_cleanup() {
    game_cleanup();
    
    // Free the buffer array
    for (int i = 0; i < rows; i++) {
        free(bufferArray[i]);
    }
    free(bufferArray);
}