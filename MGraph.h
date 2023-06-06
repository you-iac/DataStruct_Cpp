#pragma once
#include <stdio.h>
#ifndef _MGraph_
#define _MGraph_

typedef int VertexType; /*��������*/
typedef int EdgeType;   /*������*/
#define MaxSize 100

typedef struct BiTreeNode {
    VertexType Vex[MaxSize];
    EdgeType Edge[MaxSize][MaxSize];
} MGraph;

/*�߽ڵ㶨��*/
typedef int WeightType; /*�ߵ�Ȩֵ��Ϊ����*/
typedef struct ENode {
    VertexType V1, V2;      /*�����<V1, V2>*/
    WeightType Weight;  //Ȩ�� */
} ENode;


//void MGraph_Init(MGraph &MG);

void MGraph_Build(MGraph& MG);
void MGraph_AddDate(MGraph& MG, int Nv);
void MGraph_AddEdge(MGraph& MG, ENode e);


#endif 

