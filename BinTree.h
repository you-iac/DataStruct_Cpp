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
} BinTreeNode,*BinTree;

void 		BiTreeInit  (BinTree& T);              
void 		TreeInsert  (BinTree& T, ElemType e);
bool 		TreeDelete  (BinTree& T, ElemType e);/**/
bool 		PrintTree   (BinTree& T);
int 		LocateElem  (BinTree& T, ElemType i);

void    BiTreeTest(BinTree &T);

int  Tree_high  (BinTree& BST);
void Single_Left_Rotation   (BinTree& BST);
void Single_Right_Rotation  (BinTree& BST);
void Double_RightLeft_Rotation  (BinTree& BST);
void Double_LeftRight_Rotation  (BinTree& BST);
#endif 

