#ifndef _DLinkList_
#define _DLinkList_
#include<cstdbool>
#include<cstdio>
#include<cstdlib>
#include<cmath>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode* Prior, * next;
} DLNode, * DLinkList;

DLinkList InitList();/*��ʼ������*/
DLinkList List_HeadInsert(DLinkList L);/*ͷ�巨��ʼ������*/
DLinkList List_TailInsert(DLinkList L);/*β�巨��ʼ������*/
bool 		ListInsert(DLinkList L, int i, ElemType e);
bool 		ListDelete(DLinkList L, int i);/**/
bool 		PrintList(DLinkList L);
int 		LocateElem(DLinkList L, ElemType i);
ElemType	GetElem(DLinkList L, int i);


int  Length(DLinkList L);
bool Empty(DLinkList L);
bool DestroyList(DLinkList L);

void DLinkListTest();
#endif

