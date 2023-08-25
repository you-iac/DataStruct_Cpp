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
        if (T->Data == e) /*�����Ҫɾ����Ԫ��*/
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
            while (P)//�ж��Ƿ�Ϊ���Ԫ��
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
        if (e >= BST->Data) //�ݹ��������
            Tree_BlaceInsert(BST->rchild, e);
        else
            Tree_BlaceInsert(BST->lchild, e);
        //�������������߶�
        int high = Tree_high(BST->lchild) - Tree_high(BST->rchild);

        if (high == 2)
        {
            if (e < BST->lchild->Data)// �жϳ�����λ������������� LL��ת
                Single_Right_Rotation(BST);
            else 
                Double_LeftRight_Rotation(BST);
        }
        if (high == -2)
        {
            if (e > BST->rchild->Data)// �жϳ�����λ���������� RR��ת
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
    Single_Left_Rotation(BST->lchild);  //�ȶ�������ת
    Single_Right_Rotation(BST);         //����ת
}
void Double_RightLeft_Rotation(BinTree &BST)  //RL
{
    Single_Right_Rotation(BST->rchild);  //�ȶ��Һ�����ת
    Single_Left_Rotation(BST);         //����ת
}
//���������
void PreOrder(BinTree& T)
{
    if (T) 
    { 
        printf("%d", T->Data); 
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//�������
void InOrder(BinTree& T)
{
    if (T)
    {
        printf("%d", T->Data);
        InOrder(T->lchild);
        InOrder(T->rchild);
    }
}
//�������
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