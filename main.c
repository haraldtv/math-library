#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "defenitions.h"
#include "matrix.h"
#include "graph.h"


int main() {
    printf("HelloWorrld!\n");

    //double a = 36;
    //printf("%d\n", (int)a);
    matrix testMat = newMatrix(3,3);
    fillMatrix(testMat);
    printMatrix(testMat);
    printf("%f\n", determinant(testMat));

    //dataPoints data;
    //plotGraph(data);

    return 0;
}