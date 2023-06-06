#include "BiTree.h"
#include <cstdio>
#include <cstdlib>

#include<stack>
#include<queue>

BiTree 	TreeInsert(BiTree& T, ElemType e)
{
    if (T)
    {
        if (e <= T->Data)
        {
            T->lchild = TreeInsert(T->lchild, e);
        }
        else {
            T->rchild = TreeInsert(T->rchild, e);
        }
        return T;
    }   
    else {
        BiTreeNode *p = (BiTreeNode*)malloc(sizeof(BiTreeNode));
        p->Data = e;
        p->lchild = p->rchild = NULL;
        return p;
    }
}

bool 	TreeDelete(BiTree& T, ElemType e)
{
    return true;
}

bool 	PrintTree(BiTree& T)
{
    if (T)
    {
        std::queue<BiTree> queue;
        queue.push(T);

        while (!queue.empty())
        {
            BiTree t = queue.front();
            queue.pop();
            printf("%d ", t->Data);

            if (t->lchild){ 
                queue.push(t->lchild);
            }
            if (t->rchild){
                queue.push(t->rchild);
            }

        }
    }
    return true;
}

//先先序遍历
void PreOrder(BiTree& T)
{
    if (T) 
    { 
        printf("%d", T->Data); 
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历
void InOrder(BiTree& T)
{
    if (T)
    {
        printf("%d", T->Data);
        InOrder(T->lchild);
        InOrder(T->rchild);
    }
}
//后序遍历
void PostOrder(BiTree& T)
{
    if (T)
    {
        printf("%d", T->Data);
        PostOrder(T->lchild);
        PostOrder(T->rchild);
    }
}
void LevelOrder(BiTree& T)
{
    if (T)
    {
        std::queue<BiTree> queue;
        queue.push(T);
        while (!queue.empty())
        {
            BiTree t = queue.front();
            queue.pop();
            printf("%d ", t->Data);
            
            if (t->lchild) queue.push(t->lchild);
            if (t->rchild) queue.push(t->rchild);
        }
    }
}

void    BiTreeTest(BiTree T)
{
    
    int i = 0;
    for (i = 0; i < 100; i++)
        TreeInsert(T, rand());

    PrintTree(T);

}
