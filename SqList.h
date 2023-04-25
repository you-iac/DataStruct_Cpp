#ifndef _SqList_
#define _SqList_
#include<cstdbool>

typedef int ElemType;
#define InitSize 100

typedef struct SLNode{
	ElemType* data;
	int Length, Maxsize;
} *SqList;

SqList 		InitList	();/*³õÊ¼»¯Ë³Ðò±í*/
bool 		ListInsert	(SqList &L, int i, ElemType e);
bool 		ListDelete	(SqList &L, int i);/**/
bool 		PrintList	(SqList &L);
int 		LocateElem	(SqList &L, ElemType i);
ElemType 	GetElem		(SqList &L, int i);

int  Length	(SqList &L);
bool Empty	(SqList &L);
bool Destroy(SqList &L);

void SqListTest();
#endif