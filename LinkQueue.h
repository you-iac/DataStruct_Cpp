#include"LinkList.h"
#include<cstdbool>
#include<cstdio>
#include<cstdlib>
#include<cmath>

#include"LinkList.h"

#ifndef _LinkQueue_
#define _LinkQueue_
//��ͷ�ڵ����ʽ����
typedef struct {
	LinkNode* front, *rear;
} *LinkQueue;
void InitQueue(LinkQueue &Q);/*��ʼ��*/
bool QueueEmpty(LinkQueue &Q);
bool EnQueue(LinkQueue &Q, ElemType e);
bool DeQueue(LinkQueue &Q, ElemType &e);/**/

void PrintQueue(LinkQueue &Q);
void LinkQueueTest();

#endif

