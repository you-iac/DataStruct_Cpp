#include"LinkList.h"
#include<cstdio>
#include<cstdlib>

inline LinkList InitList	()/*初始化链表*/
{
	LinkList L = (LinkList)malloc(sizeof(LinkList));
	L->data = 0x80000000;
	L->Next = NULL;
	return L;
}
LinkList List_HeadInsert	(LinkList &L)/*头插法初始化链表*/
{
	L = (LinkList)malloc(sizeof(LinkList));
	L->Next = NULL;
	
	int x = 0;
	LinkList P = NULL;
	
	scanf("%d", &x);
	while(x != 65536)
	{
		P = (LinkList)malloc(sizeof(LinkList));
		P->data = x;
		P->Next = L->Next;
		L->Next = P;
		scanf("%d", &x);
	}
	return L;
}
LinkList List_TailInsert	(LinkList &L)/*尾插法初始化链表*/
{
	L = (LinkList)malloc(sizeof(LinkList));
	L->Next = NULL;
	int x = 0;
	LinkList Tail = L;
	
	scanf("%d", &x);
	while(x != 65536)
	{
		Tail->Next = (LinkList)malloc(sizeof(LinkList));
		Tail->data = x;
		Tail = Tail->Next;
		Tail = NULL;
		scanf("%d", &x);
	}
	return L;
}

bool ListInsert	(LinkList &L, int i, ElemType e)
{
	if (i >= 1 && i <= Length(L)+1)
	{
		/*创建节点*/
		LNode* p = L;
		LNode* T = (LNode*)malloc(sizeof(LNode));
		T->data = e;
		T->Next = NULL;

		for (; i-1 > 0; i--, p = p->Next);/*寻找要插入是位置*/

		/*插入操作*/
		T->Next = p->Next;
		p->Next = T;

	}
	return 0;
}
bool ListDelete	(LinkList *L, int i)/**/
{
	return 0;
}
bool PrintList	(LinkList &L)
{
	LinkList p = L->Next;

	for(; p; p=p->Next)
		printf("%d ", p->data);
	printf("\n");

	return 0;
}
int LocateElem	(LinkList &L, ElemType i)
{
	return 0;
}
ElemType 	GetElem		(LinkList &L, int i)
{
	return 0;
}

int  Length	(LinkList &L)
{
	int i = 0;
	LNode* p = L;
	for(i = 0; p->Next!=NULL; i++, p=p->Next);
		
	return i;
}
bool Empty	(LinkList &L)
{
	return 0;
}
bool Destroy(LinkList &L)
{
	return 0;
}
void LinkListTest()
{
	LinkList L = InitList();

	int i = 0; 
	LinkList p = NULL;
	for(; i < 10; i++)
		ListInsert(L,1,rand());

	PrintList(L);
	printf("链表长度:%d", Length(L));
}
