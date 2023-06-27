#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "graph.h"

dataPoints allocateDatapoints(int xSize, int ySize) {
    dataPoints data;

    data.x = (double*)malloc(xSize * sizeof(double));
    data.y = (double*)malloc(ySize * sizeof(double));

    return data;

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
    normalizeData(&inputData);

    //Scales data to the size of the terminal
    scaleData(&inputData, maxlines, maxcols);

    //Prints the data
    //WARNING! Input not scaled to size, and will most likely break (most likely as in absolutely)
    for (i=0; i<inputData.size; i++) {
        mvaddch(inputData.y[i], inputData.x[i], '*');
    }

    //refresh();
    getch();
    endwin();
    
}

//This function needs to normalize the datapoints between 0 and 1
//formula: z = (x-min) / (max-min)
//Need the min and max values from the dataset
void normalizeData(dataPoints *inp) {
    int i;
    double minX, minY, maxX, maxY;

    minX = minValue(inp->size, inp->x);
    minY = minValue(inp->size, inp->y);

    maxX = maxValue(inp->size, inp->x);
    maxY = maxValue(inp->size, inp->y);

    for (i=0; i < inp->size; i++) {
        inp->y[i] = ( (inp->y[i] - minX) / (maxX - minX) );
        inp->x[i] = ( (inp->x[i] - minY) / (maxY - minY) );
    }

}

//Unsure if i want the function to take a dataset as input, or hardcode it to return min value for both inp.x and inp.y
double minValue(int size, double *datalist) {
    int i;
    double temp;
    temp = datalist[0];
    for (i=0; i<size; i++) {
        if (temp > datalist[i]) {
            temp = datalist[i];
        }
    }
    return temp;
}

double maxValue(int size, double *datalist) {
    int i;
    double temp;
    temp = datalist[0];
    for (i=0; i<size; i++) {
        if (temp < datalist[i]) {
            temp = datalist[i];
        }
    }
    return temp;
}


void scaleData(dataPoints *inp, int maxlines, int maxcols) {
    int i;
    int size = inp->size;
    for (i=0;i<size;i++) {
        inp->x[i] = inp->x[i] * maxlines;
        inp->y[i] = inp->y[i] * maxcols;
    }
}