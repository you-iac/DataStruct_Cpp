#pragma once
#include <stdio.h>
#ifndef _MGraph_
#define _MGraph_

typedef int VertexType; /*顶点类型*/
typedef int EdgeType;   /*边类型*/
#define MaxSize 100

typedef struct BiTreeNode {
    VertexType Vex[MaxSize];
    EdgeType Edge[MaxSize][MaxSize];
} MGraph;

/*边节点定义*/
typedef int WeightType; /*边的权值设为整型*/
typedef struct ENode {
    VertexType V1, V2;      /*有向边<V1, V2>*/
    WeightType Weight;  //权重 */
} ENode;


//void MGraph_Init(MGraph &MG);

void MGraph_Build(MGraph& MG);
void MGraph_AddDate(MGraph& MG, int Nv);
void MGraph_AddEdge(MGraph& MG, ENode e);


#endif 

