#ifndef _SqStack_
#define _SqStack_
#include<cstdbool>
#include<cstdlib>
#include<cstdio>

typedef int ElemType;
#define MaxSize 50

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;

void	InitStack(SqStack& S);/*³õÊ¼»¯Ë³Ðò±í*/
bool	StackEmpty(SqStack& S);

bool 	 Push(SqStack& S, ElemType e);
bool	 Pop(SqStack& S, ElemType& e);/**/
ElemType GetTop(SqStack& S);

void PrintStack(SqStack& S);
void SqStackTest();
#endif