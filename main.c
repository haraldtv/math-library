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
    fillMatrixGen(testMat);
    printMatrix(testMat);
    printf("%f\n", determinant(testMat));
    testMat = transpose(testMat);
    printMatrix(testMat);

    //dataPoints data;
    //plotGraph(data);

    return 0;
}