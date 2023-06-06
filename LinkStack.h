#ifndef _LinkStack_
#define _LinkStack_

#include<cstdbool>
#include<cstdlib>
#include<cstdio>

typedef int ElemType;
typedef struct SLiNode {
	ElemType Data;
	struct SLiNode* next;
} SLiNode, * LiStack;

void InitStack(LiStack& S);/*³õÊ¼»¯Ë³Ðò±í*/
bool StackEmpty(LiStack& S);

bool Push(LiStack& S, ElemType e);
bool Pop(LiStack& S, ElemType& e);/**/
bool GetTop(LiStack& S, ElemType& e);

void PrintStack(LiStack& S);
void StackTest();
#endif