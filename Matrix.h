#pragma once


#ifndef _Matrix_
#define _Matrix_

typedef int ElemType;
#define MaxSize 100
typedef struct {
	ElemType Data[MaxSize][MaxSize];
	int n, m;
} Matrix;
void MatrixInit(Matrix& matrix, int n, int m);
void MatrixPrint(Matrix& matrix);

#endif // !_Matrix_