#include "SqQueue.h"

void	InitQueue(SqQueue& S)
{
    S.front = S.rear = 0;
}
bool	StackEmpty(SqQueue& S)
{
    if(S.front == S.rear)
    return false;
    else
    return true;
}
bool	QueueEmpty(SqQueue& S)
{
    if(S.front == S.rear)
        return false;
    else
        return true;
}

bool 	 EnQueue(SqQueue& S, ElemType e)
{
    /*��ѭ����������������� rearһֱ��front�����棬����rear�����λ��*/
    if ((S.rear+1)%MaxSize != S.front)
    {
        S.data[S.rear] = e;
        //��һȡģ;
        S.rear = (S.rear+1) % MaxSize;
        return true;
    }
    else {
        return false;
    }

}
bool DeQueue(SqQueue& S, ElemType& e)
{
    /*������зǿ�*/
    if (QueueEmpty(S))
    {
        e = S.front;
        S.front = (S.front+1)%MaxSize;
        return true;
    }
    else {
        return false;
    }
}

void PrintQueue(SqQueue& S)
{
    int i = 0;
    for (i = MaxSize-1; i >= 0; i--)
    {
        if (S.rear >= S.front && i<S.rear && i>=S.front || S.rear < S.front && (i > S.front || i < S.rear) )
        {
            printf("%d\n", S.data[i]);
        }
        else {
            printf("%d\n", 0);
        }
    }
}
void QueueTest()
{

    SqQueue S;
    InitQueue(S);

    int i = 0;
    for (i = 0; i < 10; i++)
        EnQueue(S, rand());
    PrintQueue(S);
    printf("����һ������\n");

    int x = 0;
    for (i = 0; i < 4; i++)
        DeQueue(S, x);
    PrintQueue(S);
    printf("ɾ��һ������\n");

    for (i = 0; i < 3; i++)
        EnQueue(S, rand());
    PrintQueue(S);
    printf("�ٲ���һ������\n");

    for (i = 0; QueueEmpty(S); i++)
        DeQueue(S, x);
    PrintQueue(S);
    printf("ɾ��ȫ������\n");
}