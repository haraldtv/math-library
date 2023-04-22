#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

#define HEIGHT  100
#define WIDTH   100

struct dataPoints {
    double *x;
    double *y;
}; typedef struct dataPoints dataPoints;

void plotGraph(dataPoints inputData) {
    int i, j;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            if ((i == 0) || (i==HEIGHT) || (j == 0) || (j == WIDTH)) {
                printf("*");
            }
            printf("\n");
        }
    }
    
}