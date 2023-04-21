#include<cstdio>
#include<cstdlib>
#include<cstdbool>
#include<cmath>
#include"SqList.h"

SqList InitList ()
{
	SqList L = (SqList)malloc(sizeof(SqList));
	if (L == NULL) return 0; /*判断申请内存是否成功*/

	L->data = (int*)malloc(sizeof(InitSize));
	if (L->data == NULL) return 0; /*判断申请内存是否成功*/
	
		
	L->Length = 0;
	L->Maxsize = InitSize;
	return L;
}

bool ListInsert(SqList &L, int i, ElemType e)/*插入操作，从一开始*/
{
	if(i < 1 || i > L->Length+1)/*判断插入位置是否合法，从1 开始，可以从第一位到最后一位后一位*/
		return false;
	
	if(L->Length > L->Maxsize)/*判断顺序表是否为空*/
		return false;
	int j = 0;
	for(j = L->Length-1; j >= i-1; j--)/*从后向前挪*/
		L->data[j+1] = L->data[j];
	
	L->data[i-1] = e;
	L->Length++;
	return true;
}

bool ListDelete(SqList &L, int i)
{
	if(i < 1 || i > L->Length )/*判断删除位置是否合法，从1开始*/
		return false;
	
	int j = 0;
	for(j = i-1; j < L->Length-1; j++)
		L->data[j] = L->data[j+1];
	
	L->Length--;
	return true;
}

bool PrintList(SqList &L)
{
	int i = 0;
	for( i = 0; i < L->Length;i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
	return true;
}

int Length(SqList &L)
{
	return L->Length;
}
bool Empty(SqList &L)
{
	return L->Length == 0 ? true:false; 
}

int LocateElem(SqList &L, ElemType e)
{	
	int i = 0; 
	for(i = 0; i < L->Length; i++)
	{
		if(L->data[i] == e)
			return i+1;
	}
	return 0;
}
ElemType GetElem(SqList &L, int i)
{
	if(i > 0 && i < L->Length)
		return 65539;
	
	return L->data[i-1];
}


void SqListTest()
{
	SqList L = InitList();
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		
		ListInsert(L,1,rand());
	 
	}
	PrintList(L);
	
	for(i = 100; i > 0; i--)
	{	
		ListDelete(L,i);
		PrintList(L);
	}
	
}
