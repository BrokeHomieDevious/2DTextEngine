// src/input.c

#include <stdio.h>
#include <stdlib.h>
#include "input.h"

void inputWidthHeight(int *rows, int *cols)
{
    printf("Enter the number of rows: ");
    while (scanf("%d", rows) != 1 || *rows <= 0) {
        printf("Invalid input. Please enter a positive integer for rows: ");
        while(getchar() != '\n'); // clear the buffer
    }

    printf("Enter the number of columns: ");
    while (scanf("%d", cols) != 1 || *cols <= 0) {
        printf("Invalid input. Please enter a positive integer for columns: ");
        while(getchar() != '\n'); // clear the buffer
    }
}

void manualScreenClear()
{
    printf("Press enter to clear the screen.");
    getchar();
    system("cls");
}

void unpauseAtUserDiscretion() //pauses output, and allows user to unpause at their discretion by pressing enter
{
    printf("Press Enter to exit...");
    while(getchar() != '\n'); // Wait for the user to press Enter
    while(getchar() != '\n'); // Another getchar to actually wait for the Enter key
}

void autoScreenClear()
{
    system("cls");
}