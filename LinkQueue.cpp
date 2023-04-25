#include "LinkQueue.h"
void InitQueue(LinkQueue& Q)/*初始化*/
{
    LinkNode*T = (LinkNode*)malloc(sizeof(LinkNode));
    T->data = 0x80000000;
    T->next = NULL;
    Q.rear = Q.front = T;
}
bool QueueEmpty(LinkQueue& Q)
{
    if (Q.front == NULL && Q.rear == NULL)
        return false;
    else
        return true;
}
bool EnQueue(LinkQueue& Q, ElemType e)
{
    LinkNode* T = (LinkNode*)malloc(sizeof(LinkNode));
    T->data = e;
    T->next = NULL;

    Q.rear->next = T;
    Q.rear = T;
    return true;
}
bool DeQueue(LinkQueue& Q, ElemType& e)/**/
{
    if (QueueEmpty(Q))
    {
        LinkNode* T = Q.front->next;
        Q.front->next = T->next;

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
    LinkNode *T = Q.front;
    for(; T != Q.rear; T=T->next)
        printf("%d->", T->data);
    printf("NULL\n");
}

void LinkQueueTest()
{
    LinkQueue Q;
    InitQueue(Q);
    
    int i = 0;
    for (i = 0; i < 10; i++)
        EnQueue(Q, rand());
    PrintQueue(Q);
    printf("插入一组数据\n");
    
    int x = 0;
    for (i = 0; i < 4; i++)
        DeQueue(Q, x);
    PrintQueue(Q);
    printf("删除一组数据\n");
    
    for (i = 0; i < 3; i++)
        EnQueue(Q, rand());
    PrintQueue(Q);
    printf("再插入一组数据\n");
    
    for (i = 0; QueueEmpty(Q); i++)
        DeQueue(Q, x);
    PrintQueue(Q);
    printf("删除全部数据\n");
}