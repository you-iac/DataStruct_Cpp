#pragma once
#pragma once

#ifndef _SqTree_
#define _SqTree_

typedef int ElemType;
#define MaxSize 100
#define Length 0

typedef struct BiTreeNode{
    ElemType Data;
    BiTreeNode *lchild, *rchild;
} BiTreeNode,*BiTree;

void 		BiTreeInit(BiTree& T);/*³õÊ¼»¯Ë³Ðò±í*/
BiTree 		TreeInsert(BiTree& T, ElemType e);
bool 		TreeDelete(BiTree& T, ElemType e);/**/
bool 		PrintTree(BiTree& T);
int 		LocateElem(BiTree& T, ElemType i);

void    BiTreeTest(BiTree T);


#endif 

