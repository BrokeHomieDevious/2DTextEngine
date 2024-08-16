// src/view.c

#include <stdio.h>
#include <stdlib.h>
#include "view.h"

void freeViewArray(char **array, int rows) //free's allocated memory for view array
{
    // Free each row
    for (int i = 0; i < rows; i++) 
    {
        free(array[i]);
    }
    // Free the array of pointers
    free(array);
}

void drawView(char **array, int rows, int cols) //puts contents of view array on the screen
{
    // Print the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
        {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

void fillEntireView(char **array, int rows, int cols, char placeholder) // fills the entire viewArray to anything you want
{
    // Fill the array with the placeholder character
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
        {
            array[i][j] = placeholder;
        }
    }
}

void drawBasicSceneBordered(char **array, int rows, int cols, char *asset) // draws a bordered scene 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (i == 0 || i == (rows - 1)) 
            {
                array[i][j] = asset[BORDER_HORIZONTAL];
            } 
            else if (j == 0 || j == (cols - 1)) 
            {
                array[i][j] = asset[BORDER_VERTICAL];
            }
            else 
            {
                array[i][j] = asset[PLACEHOLDER];
            }
        }
    }
}

void drawBasicSceneSpaced(char **array, int rows, int cols, char *asset) // draws a bordered scene, but with the vertical border comprised of dashes 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (i == 0 || i == (rows - 1)) 
            {
                array[i][j] = asset[BORDER_HORIZONTAL];
            } 
            else if (j == 0 || j == (cols - 1)) 
            {
                array[i][j] = asset[BORDER_HORIZONTAL_MID];
            }
            else 
            {
                array[i][j] = asset[PLACEHOLDER];
            }
        }
    }
}

void drawHorizontalLine(char **array, int row, int rows, char *asset) //draws a horizontal line at the selected row
{
    for(int i = 0; i < rows; i++)
    {
        array[row][i] = asset[BORDER_HORIZONTAL_MID];
    }
}

void drawVerticalLine(char **array, int col, int rows, char *asset) // draws a vertical line at a selected col
{
    for (int i = 0; i < rows; i++)
    {
        array[i][col] = asset[BORDER_VERTICAL];
    }
}

void drawVerticalLineDashed(char **array, int col, int rows, char *asset) // draws a vertical line at a selected col made with -
{
    for (int i = 0; i < rows; i++)
    {
        array[i][col] = asset[BORDER_HORIZONTAL_MID];
    }
}