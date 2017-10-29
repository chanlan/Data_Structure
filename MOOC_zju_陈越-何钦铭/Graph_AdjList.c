#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 100 //最大顶点数设为100
typedef int Vertex; //边 int型
typedef int WeightType; //权值 int型
typedef char DataType; //顶点储存的数据类型 char

//边的定义
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2; //有向边<V1,V2>
    WeightType Weight; //权值
};
typedef PtrToENode Edge;

//邻接点的定义
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV; //邻接点的下标
    WeightType Weight; //边权值
    PtrToAdjVNode Next; //指针
};
//顶点表头结点的定义
typedef struct Vnode{
    PtrToAdjVNode FirstEdage; //边表头指针
    DataType Data; // 存顶点的数据（大多数情况下，顶点无数据Data可以不出现
} AdjList[MaxVertexNum]; //AdjList是邻接点的类型
//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv; //顶点数
    int Ne; //边数
    AdjList G; //邻接表
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum){
    Vertex V;
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for (V = 0; V < Graph->Nv; V++)
        Graph->G[V].FirstEdage = NULL;
    return Graph;
}
void InsertEdge(LGraph Graph, Edge E){
    PtrToAdjVNode NewNode;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdage;
    Graph->G[E->V1].FirstEdage = NewNode;
    //若是无向图还要插入边<V2, V1>
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next =Graph->G[E->V2].FirstEdage;
    Graph->G[E->V2].FirstEdage = NewNode;
}
LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    scanf("%d", &Nv); //读入顶点个数
    Graph = CreateGraph(Nv); //初始化
    scanf("%d", &(Graph->Ne)); //读入边数
    if(Graph->Ne != 0){ //如果有边
        E = (Edge)malloc(sizeof(struct ENode)); //建立边结点
        for (i= 0; i<Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight); //起点 终点 权值
            InsertEdge(Graph, E);
        }
    }
    //如果顶点有数据的话读入数据
    for(V=0; V<Graph->Nv; V++)
        scanf("%c", &(Graph->G[V].Data));
    return Graph;
}
