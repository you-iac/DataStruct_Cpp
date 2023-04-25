#include"LinkList.h"
#include<cstdio>
#include<cstdlib>

LinkList InitList	()/*初始化链表*/
{
	LinkList L = (LinkList)malloc(sizeof(LinkList));
	L->data = 0x80000000;
	L->next = NULL;
	return L;
}
LinkList List_HeadInsert	(LinkList &L)/*头插法初始化链表*/
{
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;
	
	int x = 0;
	LinkList P = NULL;
	
	scanf("%d", &x);
	while(x != 65536)
	{
		P = (LinkList)malloc(sizeof(LinkList));
		P->data = x;
		P->next = L->next;
		L->next = P;
		scanf("%d", &x);
	}
	return L;
}
LinkList List_TailInsert	(LinkList &L)/*尾插法初始化链表*/
{
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;
	int x = 0;
	LinkList Tail = L;
	
	scanf("%d", &x);
	while(x != 65536)
	{
		Tail->next = (LinkList)malloc(sizeof(LinkList));
		Tail->data = x;
		Tail = Tail->next;
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
		LinkNode* p = L;
		LinkNode* T = (LinkNode*)malloc(sizeof(LinkNode));
		T->data = e;
		T->next = NULL;

		for (; i-1 > 0; i--, p = p->next);/*寻找要插入是位置*/

		/*插入操作*/
		T->next = p->next;
		p->next = T;

	}
	return 0;
}
bool ListDelete	(LinkList *L, int i)/**/
{
	return 0;
}
bool PrintList	(LinkList &L)
{
	LinkList p = L->next;

	for(; p; p=p->next)
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
	LinkNode* p = L;
	for(i = 0; p->next!=NULL; i++, p=p->next);
		
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
