#ifndef _LinkList_
#define _LinkList_
#include<stdbool.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *Next; 
} LNode, *LinkList;

LinkList	InitList	();/*��ʼ������*/
LinkList 	List_HeadInsert	(LinkList &L);/*ͷ�巨��ʼ������*/
LinkList 	List_TailInsert	(LinkList &L);/*β�巨��ʼ������ */
bool 		ListInsert	(LinkList &L, int i, ElemType e);
bool 		ListDelete	(LinkList &L, int i);/**/
bool 		PrintList	(LinkList &L);
int 		LocateElem	(LinkList &L, ElemType i);
ElemType 	GetElem		(LinkList &L, int i);


int  Length		(LinkList &L);
bool Empty			(LinkList &L);
bool DestroyList	(LinkList &L);

void LinkListTest();
#endif

