#include<cstdbool>
#include<cstdlib>
#include<cstdio>

#ifndef _SqStack_
#define _SqStack_
/*��̬�洢ʵ��ѭ������
//ʹ�� 1 ����һ���ռ�
//2 ��size 3 ��tag*/
typedef int ElemType;
#define MaxSize 50

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;

void	InitStack(SqStack& S);/*��ʼ��ѭ������*/
bool	StackEmpty(SqStack& S);

bool 	 Push(SqStack& S, ElemType e);
bool	 Pop(SqStack& S, ElemType& e);/**/
ElemType GetTop(SqStack& S);

void PrintStack(SqStack& S);
void SqStackTest();
#endif