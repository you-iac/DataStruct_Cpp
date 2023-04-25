#include "SqQueue.h"

void	InitQueue(SqQueue& Q)
{
    Q.front = Q.rear = 0;
}
bool	StackEmpty(SqQueue& Q)
{
    if(Q.front == Q.rear)
    return false;
    else
    return true;
}
bool	QueueEmpty(SqQueue& Q)
{
    if(Q.front == Q.rear)
        return false;
    else
        return true;
}

bool 	 EnQueue(SqQueue& Q, ElemType e)
{
    /*��ѭ����������������� rearһֱ��front�����棬����rear�����λ��*/
    if ((Q.rear+1)%MaxSize != Q.front)
    {
        Q.data[Q.rear] = e;
        //��һȡģ;
        Q.rear = (Q.rear+1) % MaxSize;
        return true;
    }
    else {
        return false;
    }

}
bool DeQueue(SqQueue& Q, ElemType& e)
{
    /*������зǿ�*/
    if (QueueEmpty(Q))
    {
        e = Q.front;
        Q.front = (Q.front+1)%MaxSize;
        return true;
    }
    else {
        return false;
    }
}

void PrintQueue(SqQueue& Q)
{
    int i = 0;
    for (i = MaxSize-1; i >= 0; i--)
    {
        if (Q.rear >= Q.front && i<Q.rear && i>=Q.front || Q.rear < Q.front && (i > Q.front || i < Q.rear) )
        {
            printf("%d\n", Q.data[i]);
        }
        else {
            printf("%d\n", 0);
        }
    }
}
void QueueTest()
{
    SqQueue Q;
    InitQueue(Q);

    int i = 0;
    for (i = 0; i < 10; i++)
        EnQueue(Q, rand());
    PrintQueue(Q);
    printf("����һ������\n");

    int x = 0;
    for (i = 0; i < 4; i++)
        DeQueue(Q, x);
    PrintQueue(Q);
    printf("ɾ��һ������\n");

    for (i = 0; i < 3; i++)
        EnQueue(Q, rand());
    PrintQueue(Q);
    printf("�ٲ���һ������\n");

    for (i = 0; QueueEmpty(Q); i++)
        DeQueue(Q, x);
    PrintQueue(Q);
    printf("ɾ��ȫ������\n");
}