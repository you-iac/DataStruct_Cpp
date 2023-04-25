#ifndef _SqQueue_
#define _SqQueue_
#include<cstdbool>
#include<cstdlib>
#include<cstdio>

typedef int ElemType;
#define MaxSize 10

typedef struct {
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;

void	InitQueue(SqQueue &Q);/*³õÊ¼»¯Ë³Ðò±í*/
bool	QueueEmpty(SqQueue &Q);

bool 	 EnQueue(SqQueue &Q, ElemType e);
bool	 DeQueue(SqQueue &Q, ElemType& e);/**/
ElemType GetTop(SqQueue &Q);

void PrintQueue(SqQueue &Q);
void QueueTest();
#endif