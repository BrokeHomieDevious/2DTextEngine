// include/view.h

#ifndef VIEW_H
#define VIEW_H

void drawView(char **array, int rows, int cols);
void fillEntireView(char **array, int rows, int cols, char placeholder);
void freeViewArray(char **array, int rows);
void drawBasicSceneBordered(char **array, int rows, int cols, char *asset);
void drawBasicSceneSpaced(char **array, int rows, int cols, char *asset);
void drawHorizontalLine(char **array, int row, int rows, char *asset);
void drawVerticalLine(char **array, int col, int rows, char *asset);
void drawVerticalLineDashed(char **array, int col, int rows, char *asset);


#define BORDER_HORIZONTAL_MID 0
#define BORDER_VERTICAL 1
#define BORDER_HORIZONTAL 4
#define PLACEHOLDER 5

#endif // VIEW_H
