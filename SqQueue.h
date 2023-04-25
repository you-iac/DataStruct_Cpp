#ifndef _SqQueue_
#define _SqQueue_
#include<cstdbool>
#include<cstdlib>
#include<cstdio>

typedef int ElemType;
#define MaxSize 50

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqQueue;

void	InitStack(SqQueue &S);/*³õÊ¼»¯Ë³Ðò±í*/
bool	StackEmpty(SqQueue &S);

bool 	 Push(SqQueue &S, ElemType e);
bool	 Pop(SqQueue &S, ElemType& e);/**/
ElemType GetTop(SqQueue &S);

void PrintStack(SqQueue &S);
void QueueTest();
#endif