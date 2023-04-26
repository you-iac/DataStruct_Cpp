#include"LinkList.h"
#include<cstdbool>
#include<cstdio>
#include<cstdlib>
#include<cmath>

#include"LinkList.h"

#ifndef _LinkQueue_
#define _LinkQueue_
//带头节点的链式队列
typedef struct {
	LinkNode* front, *rear;

void InitQueue(LinkQueue &Q);/*初始化*/
bool QueueEmpty(LinkQueue &Q);
bool EnQueue(LinkQueue &Q, ElemType e);
bool DeQueue(LinkQueue &Q, ElemType &e);/**/

void PrintQueue(LinkQueue &Q);
#endif

