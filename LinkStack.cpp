#include "LinkStack.h"

void	InitStack(LiStack& S)/*初始化顺序表*/
{
    S = NULL;
}
bool	StackEmpty(LiStack& S)
{
    /*如果不为空返回true*/
    return S != NULL ? true : false;
}

bool 	 Push(LiStack& S, ElemType e)
{
    SLiNode* T = (SLiNode*)malloc(sizeof(SLiNode));
    T->Data = 0x80000000;
    T->next = NULL;

    T->Data = e;
    T->next = S;
    S = T;
    return true;
}
bool	 Pop(LiStack& S, ElemType& e)/**/
{
    SLiNode* T = S;
    e = S->Data;
    S = S->next;
    free(T);
    return true;
}
bool GetTop(LiStack& S, ElemType& e)
{
    e = S->Data;
    return true;
}

void PrintStack(LiStack& S)
{
    SLiNode* T = S;
    int count = 0;
    //printf("--------------\n");
    for (; T; T = T->next, count++)
        printf("|%d\t|\n", T->Data);
    printf("----------\n");
    printf("栈大小：%d\n", count);

}
void StackTest()
{
    LiStack S;
    InitStack(S);

    int i = 0;
    for (i = 0; i < 10; i++)
        Push(S, rand());

    PrintStack(S);
}