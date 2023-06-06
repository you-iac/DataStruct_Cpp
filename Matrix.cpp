#include "Matrix.h"
#include <stdio.h>


void MatrixInit(Matrix& matrix, int n, int m)
{
    matrix.n = n;
    matrix.m = m;

    int i = 0, j = 0;
    for (i = 0, j = 0; i < matrix.n; i++)
    {
        for (j = 0; j < matrix.m; j++)
            matrix.Data[i][j] = i+j;
    }
}



void MatrixPrint(Matrix& matrix)
{
    int i = 0, j = 0;
    for (i = 0, j = 0; i < matrix.n; i++) 
    {
        for (j = 0; j < matrix.m; j++)
            printf("%d ", matrix.Data[i][j]);
        printf("\n");
    }
       
    
}
