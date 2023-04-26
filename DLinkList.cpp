#include"DLinkList.h"

/*åå§åé¾è¡?/
DLinkList InitList()
{
	DLinkList L = (DLNode*)malloc(sizeof(DLNode));
	L->Prior = L->next = NULL;
	L->data = 0x80000000;
	return L;
}
/*å¤´ææ³åå§åé¾è¡¨*/
DLinkList List_HeadInsert(DLinkList L);
/*å°¾ææ³åå§åé¾è¡¨*/
DLinkList List_TailInsert(DLinkList L);
/*é¾è¡¨æå¥æä½*/
bool 		ListInsert(DLinkList L, int i, ElemType e)
{
	if (i >= 1 && i <= Length(L) + 1)
	{
		/*åå»ºèç¹*/
		DLNode* p = L;
		DLNode* T = (DLNode*)malloc(sizeof(DLNode));
		T->data = e;
		T->Prior = T->next = NULL;

		for (; i - 1 > 0; i--, p = p->next);/*å¯»æ¾è¦æå¥çä½ç½®*/

		/*æå¥æä½*/
		/*å¤çåç»§æé*/
		T->next = p->next;
		p->next = T;

		/*å¤çåé©±æé*/
		/*å¦æTçåç»§å­å¨ï¼å°±è®©åç»§æåT*/
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
	printf("é¾è¡¨é¿åº¦:%d\n\n", Length(L));

	printf("éåè¾åºï¼\n");
	for (p = L; p->next; p = p->next);

	for (; p->Prior; p = p->Prior)
		printf("%d ", p->data);
}