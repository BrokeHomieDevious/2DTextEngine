// src/main.c

#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "input.h"
#include "game.h"

int main() {
    int rows, cols;

    // Get the input for rows and columns
    inputWidthHeight(&rows, &cols);

    game_initialize(rows, cols);

    // Initialize the engine
    engine_init(rows, cols);

    // Run the game loop
    engine_run();

    // Cleanup the engine
    engine_cleanup();

    // Pause before exiting
    printf("Press Enter to exit...");
    while(getchar() != '\n'); // Wait for the user to press Enter
    while(getchar() != '\n'); // Another getchar to actually wait for the Enter key

    return 0;
}