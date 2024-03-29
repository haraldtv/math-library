#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "defenitions.h"
#include "./headers/matrix.h"
#include "./headers/graph.h"

int main()
{
    printf("HelloWorrld!\n");
    /*
        //double a = 36;
        //printf("%d\n", (int)a);
        matrix testMat = newMatrix(3,3);
        fillMatrixGen(testMat);
        printMatrix(testMat);
        printf("%f\n", determinant(testMat));
        testMat = transpose(testMat);
        printMatrix(testMat);
        */

    dataPoints data = allocateDatapoints(10, 10);

    // Why does it not assign i???
    for (int i = 0; i < 10; i++)
    {
        printf("\n");
        printf("Debug:: %d - %f\n", i, (double)i);
        data.x[i] = (3.23 + (double)i);
        data.y[i] = (double)i;
        printf("\n");
    }
    for (int i = 0; i < 10; i++)
    {
        printf("Output:: %f - %f \n", data.x[i], data.y[i]);
    }

    // plotGraph(data);

    // normalizeData(&data);

    double a[5] = {3, 6, 3, 8, 2};

    for (int i = 0; i < 5; i++)
    {
        a[i] = ( (a[i] - 2) / (8-2) );
    }

    printf("----------\n");

    for (int i = 0; i < 5; i++)
    {
        printf("a: %lf", a[i]);
    }

    return 0;
}