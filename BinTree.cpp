#include "BinTree.h"
#include <cstdio>
#include <cstdlib>

#include<stack>
#include<queue>

void 	TreeInsert(BinTree &T, ElemType e)
{
    if (T)
    {
        if(T->Data > e)
            TreeInsert(T->lchild,e);
        else
            TreeInsert(T->rchild,e);
    }       
    else {
        T = (BinTree)malloc(sizeof(BiTreeNode));
        T->Data = e;
        T->lchild = T->rchild = NULL;

    }
}

bool 	TreeDelete(BinTree &T, ElemType e)
{
    if (T) {
        if (T->Data == e) /*如果是要删除的元素*/
        {
            if(T->lchild == NULL && T->rchild == NULL)
                T = NULL;
            else if(T->lchild == NULL)
                T = T->rchild;
            else if(T->rchild == NULL)
                T->lchild = NULL;
            else 
                T->Data = T->rchild->Data;
                TreeDelete(T->rchild,T->rchild->Data);
        }
        else {
            if(T->Data > e)
                TreeDelete(T->lchild,e);
            else
                TreeDelete(T->rchild, e);
        }

    }
    return true;
}

bool 	PrintTree(BinTree& T)
{
    if (T)
    {
        std::queue<BinTree> queue;
        queue.push(T);

        while (!queue.empty())
        {
            BinTree t = queue.front();
            queue.pop();
            printf("%d ", t->Data);

            if (t->lchild){ 
                queue.push(t->lchild);
            }
            if (t->rchild){
                queue.push(t->rchild);
            }

            BinTree P = T;
            while (P)//判断是否为最侧元素
            {
                if(P->Data == t->Data)
                    printf("\n");

                P = P->rchild;
            }
        }
    }
    printf("\n");
    return true;
}


void Tree_BlaceInsert(BinTree &BST, ElemType e)
{
    if (BST)
    {
        if (e >= BST->Data) //递归插入子树
            Tree_BlaceInsert(BST->rchild, e);
        else
            Tree_BlaceInsert(BST->lchild, e);
        //计算左右子树高度
        int high = Tree_high(BST->lchild) - Tree_high(BST->rchild);

        if (high == 2)
        {
            if (e < BST->lchild->Data)// 判断出插入位置在左子树左边 LL旋转
                Single_Right_Rotation(BST);
            else 
                Double_LeftRight_Rotation(BST);
        }
        if (high == -2)
        {
            if (e > BST->rchild->Data)// 判断出插入位置在子树边 RR旋转
                Single_Left_Rotation(BST);
            else 
                Double_RightLeft_Rotation(BST);
        }
    }
    else 
    {
        BST = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        BST->Data = e;
        BST->Data = e;BST->lchild = BST->rchild = NULL;
    }
}

int Tree_high(BinTree& BST)
{
    if (BST)
    {
        int Lhigh = Tree_high(BST->lchild) + 1;
        int Rhigh = Tree_high(BST->rchild) + 1;
        return Lhigh > Rhigh ? Lhigh:Rhigh;
    }
    else {
        return 0;
    }
}

void Single_Right_Rotation(BinTree& BST) //LL
{
    BinTree P = NULL;
    P = BST->lchild;
    BST->lchild = BST->lchild->rchild;
    P->rchild = BST;
    BST = P;
}
void Single_Left_Rotation(BinTree& BST) //RR
{
    BinTree P = NULL;
    P = BST->rchild;
    BST->rchild = BST->rchild->lchild;
    P->lchild = BST;
    BST = P;
}

void Double_LeftRight_Rotation(BinTree &BST) //LR
{
    Single_Left_Rotation(BST->lchild);  //先对左孩子左转
    Single_Right_Rotation(BST);         //再右转
}
void Double_RightLeft_Rotation(BinTree &BST)  //RL
{
    Single_Right_Rotation(BST->rchild);  //先对右孩子右转
    Single_Left_Rotation(BST);         //再左转
}
//先先序遍历
void PreOrder(BinTree& T)
{
    if (T) 
    { 
        printf("%d", T->Data); 
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历
void InOrder(BinTree& T)
{
    if (T)
    {
        printf("%d", T->Data);
        InOrder(T->lchild);
        InOrder(T->rchild);
    }
}
//后序遍历
void PostOrder(BinTree& T)
{
    if (T)
    {
        printf("%d", T->Data);
        PostOrder(T->lchild);
        PostOrder(T->rchild);
    }
}
void LevelOrder(BinTree& T)
{
    if (T)
    {
        std::queue<BinTree> queue;
        queue.push(T);
        while (!queue.empty())
        {
            BinTree t = queue.front();
            queue.pop();
            printf("%d ", t->Data);
            
            if (t->lchild) queue.push(t->lchild);
            if (t->rchild) queue.push(t->rchild);
        }
    }
}

void    BiTreeTest(BinTree &T)
{
    
    int i = 0;
    for (i = 0; i < 10000; i++)
    {
        Tree_BlaceInsert(T, rand());
        //PrintTree(T);
    }
}