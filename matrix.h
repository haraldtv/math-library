struct matrix {
    int rows;
    int columns;
    double **data;
}; 
typedef struct matrix matrix;

void freeMatrix(matrix tempMat);

matrix newMatrix(int rows, int colums);
matrix fillMatrixGen(matrix tempMat);
matrix fillMatrix(matrix tempMat);
matrix printMatrix(matrix tempMat);
matrix addMat(matrix mat1, matrix mat2);

double determinant(matrix tempMat);

int factorial(int n); 