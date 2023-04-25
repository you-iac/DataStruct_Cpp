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

void	InitQueue(SqQueue &S);/*³õÊ¼»¯Ë³Ðò±í*/
bool	QueueEmpty(SqQueue &S);

bool 	 EnQueue(SqQueue &S, ElemType e);
bool	 DeQueue(SqQueue &S, ElemType& e);/**/
ElemType GetTop(SqQueue &S);

void PrintQueue(SqQueue &S);
void QueueTest();
#endif