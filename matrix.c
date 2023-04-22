#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

matrix newMatrix(int rows, int columns) {
    int i;
    matrix tempMat;
    tempMat.rows = rows;
    tempMat.columns = columns;
    tempMat.data = malloc(rows*sizeof(int));
    for (i=0;i<rows;i++) {
        *(tempMat.data + i) = malloc(columns * sizeof(int));
    }
    return tempMat;
}

matrix newMatrixMan(int rows, int columns, int );

matrix fillMatrix(matrix tempMat) {
    int i, j;
    int count = 1;

    for (i=0;i<tempMat.rows;i++) {
        for (j=0;j<tempMat.columns;j++) {
            tempMat.data[i][j] = count;
            count++;
        }
    }
}

double determinant(matrix tempMat) {
    //matrix returnMat = newMatrix(tempMat.rows, tempMat.columns);

    if (tempMat.rows == tempMat.columns) {
        if (tempMat.rows == 2) {
            return (tempMat.data[0][0] * tempMat.data[1][1] - tempMat.data[0][1] * tempMat.data[1][0]);
        }
    }
    printf("Dimension error.");
}

matrix printMatrix(matrix tempMat) {
    int i, j;

    printf("--\n");
    for (i=0;i<tempMat.rows;i++) {
        for (j=0;j<tempMat.columns;j++) {
            printf("%d\n", tempMat.data[i][j]);
        }
        printf("--\n");
    }
}

matrix addMat(matrix mat1, matrix mat2) {
    if (mat1.rows == mat2.rows) {
        if (mat1.columns == mat2.columns) {
            matrix tempMat;
            tempMat.rows = mat1.rows;
            tempMat.columns = mat1.columns;
            int i, j;
            for (i=0;i<mat1.rows;i++) {
                for (j=0;j<mat1.columns;j++) {
                    tempMat.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
                }
            }

            return tempMat;
        }
    }
    printf("Matrix dimension error\n");
}

int factorial(int n) {
    int i;
    int fact = 1;
    for (i=1; i<=n; i++) {
        fact *= i;
    }
    return fact;
}