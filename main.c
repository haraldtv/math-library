#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "defenitions.h"
#include "matrix.h"
#include "graph.h"


int main() {
    printf("HelloWorrld!\n");

    matrix testMat = newMatrix(2,2);
    fillMatrix(testMat);
    printMatrix(testMat);

    printf("%d\n", factorial(1000));

    return 0;
}