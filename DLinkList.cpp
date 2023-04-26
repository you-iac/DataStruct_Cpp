#include"DLinkList.h"

/*鍒濆鍖栭摼琛*/
DLinkList InitList()
{
	DLinkList L = (DLNode*)malloc(sizeof(DLNode));
	L->Prior = L->next = NULL;
	L->data = 0x80000000;
	return L;
}
/*头插法初始化链表*/
DLinkList List_HeadInsert(DLinkList L);
/*尾插法初始化链表*/
DLinkList List_TailInsert(DLinkList L);
/*链表插入操作*/
bool 		ListInsert(DLinkList L, int i, ElemType e)
{
	if (i >= 1 && i <= Length(L) + 1)
	{
		/*创建节点*/
		DLNode* p = L;
		DLNode* T = (DLNode*)malloc(sizeof(DLNode));
		T->data = e;
		T->Prior = T->next = NULL;

		for (; i - 1 > 0; i--, p = p->next);/*寻找要插入的位置*/

		/*插入操作*/
		/*处理后继指针*/
		T->next = p->next;
		p->next = T;

		/*处理前驱指针*/
		/*如果T的后继存在，就让后继指向T*/
		if (T->next)T->next->Prior = T;
		T->Prior = p;
	}
	return 0;
}
bool 		ListDelete(DLinkList L, int i);/**/
bool 		PrintList(DLinkList L)
{
	DLinkList p = L->next;

	for (; p; p = p->next)
		printf("%d ", p->data);
	printf("\n");

	return 0;
}
int 		LocateElem(DLinkList L, ElemType i);
ElemType	GetElem(DLinkList L, int i);


int  Length(DLinkList L)
{
	int i = 0;
	LinkNode* p = L;
	for (i = 0; p->next != NULL; i++, p = p->next);

	return i;
}
bool Empty(DLinkList L);
bool DestroyList(DLinkList L);

void DLinkListTest()
{
	DLinkList L = InitList();

	int i = 0;
	DLinkList p = NULL;
	for (; i < 10; i++)
		ListInsert(L, 1, rand());

	PrintList(L);
	printf("链表长度:%d\n\n", Length(L));

	printf("逆向输出:\n");
	for (p = L; p->next; p = p->next);

	for (; p->Prior; p = p->Prior)
		printf("%d ", p->data);
}