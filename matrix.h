struct matrix {
    int rows;
    int columns;
    int **data;
}; 
typedef struct matrix matrix;


matrix newMatrix(int rows, int colums);
matrix fillMatrix(matrix tempMat);
matrix printMatrix(matrix tempMat);
matrix addMat(matrix mat1, matrix mat2);

double determinant(matrix tempMat);

int factorial(int n); 