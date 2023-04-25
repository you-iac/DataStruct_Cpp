#include<cstdbool>
#include<cstdlib>
#include<cstdio>

#ifndef _SqStack_
#define _SqStack_
/*静态存储实现循环队列
//使用 1 放弃一个空间
//2 用size 3 用tag*/
typedef int ElemType;
#define MaxSize 50

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;

void	InitStack(SqStack& S);/*初始化循环队列*/
bool	StackEmpty(SqStack& S);

bool 	 Push(SqStack& S, ElemType e);
bool	 Pop(SqStack& S, ElemType& e);/**/
ElemType GetTop(SqStack& S);

void PrintStack(SqStack& S);
void SqStackTest();
#endif