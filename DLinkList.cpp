#include"DLinkList.h"

/*初始化链�*/
DLinkList InitList()
{
	DLinkList L = (DLNode*)malloc(sizeof(DLNode));
	L->Prior = L->next = NULL;
	L->data = 0x80000000;
	return L;
}
/*ͷ�巨��ʼ������*/
DLinkList List_HeadInsert(DLinkList L);
/*β�巨��ʼ������*/
DLinkList List_TailInsert(DLinkList L);
/*����������*/
bool 		ListInsert(DLinkList L, int i, ElemType e)
{
	if (i >= 1 && i <= Length(L) + 1)
	{
		/*�����ڵ�*/
		DLNode* p = L;
		DLNode* T = (DLNode*)malloc(sizeof(DLNode));
		T->data = e;
		T->Prior = T->next = NULL;

		for (; i - 1 > 0; i--, p = p->next);/*Ѱ��Ҫ�����λ��*/

		/*�������*/
		/*������ָ��*/
		T->next = p->next;
		p->next = T;

		/*����ǰ��ָ��*/
		/*���T�ĺ�̴��ڣ����ú��ָ��T*/
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
	printf("������:%d\n\n", Length(L));

	printf("�������:\n");
	for (p = L; p->next; p = p->next);

	for (; p->Prior; p = p->Prior)
		printf("%d ", p->data);
}