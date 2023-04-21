#ifndef _LinkList_
#define _LinkList_
#include<stdbool.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *Next; 
} LNode, *LinkList;

LinkList	InitList	();/*初始化链表*/
LinkList 	List_HeadInsert	(LinkList &L);/*头插法初始化链表*/
LinkList 	List_TailInsert	(LinkList &L);/*尾插法初始化链表 */
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

