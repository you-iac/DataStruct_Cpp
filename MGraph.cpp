#include "MGraph.h"
#include <queue>
using namespace std;

//void MGraph_Init(MGraph& MG)
//{
//    MG.Vex;
//    MG.
//}


void MGraph_Build(MGraph& MG)
{
    int Nv = 0, Ne= 0,i = 0, j = 0;
    scanf_s("%d %d", &Nv, &Ne);
    /*输入数据*/
    MGraph_AddDate(MG,Nv);

    /*添加边*/
    ENode e;
    for (i = 0; i < Ne; i++)
    {
        scanf_s("%d %d %d", &e.V1, &e.V2, &e.Weight);
        MGraph_AddEdge(MG,e);
    }
    
}
void MGraph_AddDate(MGraph& MG, int Nv)
{
    int  i = 0;
    for (i = 0; i < Nv; i++)
        scanf_s("%d", &MG.Vex[i]);
    EdgeType *p = NULL;
    for (i = 0, p = &MG.Edge[0][0]; i < (MaxSize * MaxSize); i++)
    {
        *(p+i) = 0;
    }
}
void MGraph_AddEdge(MGraph& MG, ENode e)
{
    int  i = 0;
    MG.Edge[e.V1][e.V2] = e.Weight;

}
void visited(MGraph& MG, VertexType Nv)
{
    printf("%d ", MG.Vex[Nv]);
}
void Neighbors(MGraph& MG, VertexType Nv)
{
    int i = Nv;

}


void BFS(MGraph& MG)
{
    queue<int> Que;
    Que.push(0);

    while (!Que.empty())
    {
        VertexType v = Que.front(); /*获取*/
        Que.pop();
        
        visited(MG,v);
        


    }

}

/*
8 20
0 1 2 3 4 5 6 7 
0 1 1
1 0 1
0 4 1
4 0 1
1 5 1
5 1 1
2 5 1
5 2 1
5 6 1
6 5 1
2 6 1
6 2 1
3 6 1
6 3 1
6 7 1
7 6 1
2 3 1
3 2 1
3 7 1
7 3 1
*/

