// include/ENGINE.h

#ifndef ENGINE_H
#define ENGINE_H

 //code that makes the engine work here
 void swapBuffers(char ***currentView, char ***buffer);
 void refreshView(char **currentView, int rows, int cols);
 void engine_init(int rows, int cols);
 void engine_run();
 void engine_cleanup();

#endif // ENGINE_H