#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

dataPoints allocateDatapoints(int xSize, int ySize) {
    dataPoints data;

    data.x = malloc(xSize * sizeof(double));
    data.y = malloc(ySize * sizeof(double));

    
}

void plotGraph(dataPoints inputData) {
    int i, j;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            if ((i == 0) || (i == (HEIGHT-1)) || (j == 0) || (j == (WIDTH-1))) {
                printf("*");
            }
            else if ((i == ( (HEIGHT/2)-1)) && (j == (( (WIDTH/2) - 1)))) {
                printf("+");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    
}