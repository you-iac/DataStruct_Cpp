#include "SqStack.h"

/*初始化顺序表*/
void InitStack(SqStack& S)
{
    S.top = -1;
}

bool	StackEmpty(SqStack& S)
{
    return S.top > -1 ? true : false;
}


bool 		Push(SqStack& S, ElemType e)
{
    if (S.top < MaxSize - 1)
    {
        S.data[++S.top] = e;
        return true;
    }
    else
        return false;
}
bool 		Pop(SqStack& S, ElemType& e)/**/
{
    if (S.top > -1)
    {
        e = S.data[S.top--];
        return true;
    }
    else
        return false;
}
ElemType GetTop(SqStack& S)
{
    return S.data[S.top];
}

void 	PrintStack(SqStack& S)
{
    int i = 0;
    //printf("--------------\n");
    for (i = S.top; i >= 0; i--)
        printf("|%d\t|\n", S.data[i]);
    printf("----------\n");
    printf("栈大小：%d\n", S.top + 1);

}

void SqStackTest()
{
    SqStack S;
    InitStack(S);

    int i = 0;
    for (i = 0; i < 10; i++)
        Push(S, rand());

    PrintStack(S);


}