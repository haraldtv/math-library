#include <stdio.h>
#include <stdlib.h>

#include "./headers/matrix.h"

matrix newMatrix(int rows, int columns) {
    int i;
    matrix tempMat;
    tempMat.rows = rows;
    tempMat.columns = columns;
    tempMat.data = malloc(rows*sizeof(double));
    for (i=0;i<rows;i++) {
        *(tempMat.data + i) = malloc(columns * sizeof(double ));
    }
    return tempMat;
}

void freeMatrix(matrix tempMat) {
    for (int i=0; i < tempMat.rows; i++) {
        free(tempMat.data[i]);
    }
    free(tempMat.data);
}

matrix fillMatrix(matrix tempMat) {
    int i, j;
    for (i=0;i<tempMat.rows;i++) {
        for (j=0;j<tempMat.columns;j++) {
            double input;
            printf("Val %dx%d: ", i, j);
            scanf("%lf", &input);
            printf("\n%f\n", input);
            tempMat.data[i][j] = input;
            printf("\n");
        }
    }
}

matrix fillMatrixGen(matrix tempMat) {
    int i, j;
    int count = 1;

    for (i=0;i<tempMat.rows;i++) {
        for (j=0;j<tempMat.columns;j++) {
            tempMat.data[i][j] = (double)count;
            printf("%lf\n", tempMat.data[i][j]);
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
        else if (tempMat.rows == 3) {
            double a, b, c;
            a = (tempMat.data[1][1] * tempMat.data[2][2] - tempMat.data[1][2] * tempMat.data[2][1]);
            b = (tempMat.data[1][0] * tempMat.data[2][2] - tempMat.data[1][2] * tempMat.data[2][0]);
            c = (tempMat.data[1][0] * tempMat.data[2][1] - tempMat.data[1][1] * tempMat.data[2][0]);
            return (tempMat.data[0][0]*a - tempMat.data[0][1]*b + tempMat.data[0][2]*c);
        }
    }
    printf("Dimension error.");
}

matrix transpose(matrix inputMat) {
    matrix tempMat = newMatrix(inputMat.rows, inputMat.columns);
    
    if (inputMat.rows == inputMat.columns) {
        if (inputMat.rows == 2) {
            int i, j;
            for (i=0; i<inputMat.rows; i++) {
                for (j=0; j<inputMat.columns; j++) {
                    tempMat.data[i][j] = inputMat.data[j][i];
                }
            }
        }
    }
    inputMat = tempMat;
    freeMatrix(tempMat);
}

matrix printMatrix(matrix tempMat) {
    int i, j;

    printf("-%dx%d-\n", tempMat.rows, tempMat.columns);
    for (i=0;i<tempMat.rows;i++) {
        for (j=0;j<tempMat.columns;j++) {
            printf("%lf  ", tempMat.data[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
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

matrix nullMatrix() {
    matrix tempMat = newMatrix(1,1);
    tempMat.data = 0;
    return tempMat;
}

int factorial(int n) {
    int i;
    int fact = 1;
    for (i=1; i<=n; i++) {
        fact *= i;
    }
    return fact;
}