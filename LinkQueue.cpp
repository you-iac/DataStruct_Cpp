#include "LinkQueue.h"
void InitQueue(LinkQueue& Q)/*��ʼ��*/
{
    LinkNode*T = (LinkNode*)malloc(sizeof(LinkNode));
    T->data = 0x80000000;
    T->next = NULL;
}
bool QueueEmpty(LinkQueue& Q)
{
        return false;
    else
        return true;
}
bool EnQueue(LinkQueue& Q, ElemType e)
{
    LinkNode* T = (LinkNode*)malloc(sizeof(LinkNode));
    T->next = NULL;

    return true;
}
bool DeQueue(LinkQueue& Q, ElemType& e)/**/
{
    if (QueueEmpty(Q))
    {

        e = T->data;
        free(T);
        return true;
    }
    else {
        return false;
    }
}

void PrintQueue(LinkQueue& Q)
{
        printf("%d->", T->data);
    printf("NULL\n");
}
{
    LinkQueue Q;
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