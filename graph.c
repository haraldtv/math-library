#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "graph.h"

dataPoints allocateDatapoints(int xSize, int ySize) {
    dataPoints data;

    data.x = (double*)malloc(xSize * sizeof(double));
    data.y = malloc(ySize * sizeof(double));

}

void plotGraph(dataPoints inputData) {
    int i;
    int maxcols, maxlines;
    
    //Some initialization of ncurses
    initscr();
    cbreak();
    noecho();
    clear();

    //Defines a usable max value for horizontal and vertical axis
    maxlines = LINES - 1;
    maxcols = COLS - 1;

    //Need a function to normalize and scale the datapoints from inputData

    //Prints the data
    //WARNING! Input not scaled to size, and will most likely break
    for (i=0; i<inputData.size; i++) {
        mvaddch(inputData.y[i], inputData.x[i], '*');
    }

    refresh();
    getch();
    endwin();
    
}