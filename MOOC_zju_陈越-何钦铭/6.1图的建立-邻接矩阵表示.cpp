#include <cstdio>
#include <cstdlib>


#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;

//边的定义
struct ENode{
	Vertex V1, V2; // 有向边<V1, V2>
	WeightType Weight; //Weight
};
typedef PtrToENode Edge;

//图结点的定义
typedef struct GNode *PtrToGNode; 
struct GNode{
	int Nv; //Vertex Num
	int Ne; // Edge Num
	WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
	DataType Data[MaxVertexNum]; // Vertex
};
typedef PtrToGNode MGraph;

MGraph CreatGraph( int VertexNum){
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));	
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(V = 0; V < Graph->Nv; V++)
		for(W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E){
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;//有向图的话插入<V2,V1>
}

MGraph BuildGraph(){
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	scanf("%d", &Nv);
	Graph = CreatGraph(Nv);
	scanf("%d", &(Graph->Ne));
	if(Graph->Ne != 0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(i = 0; i < Graph->Ne; i++){
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}

	//如果顶点有数据的话就读入
	for(V = 0; V < Graph->Nv; V++)
		scanf("%c",&(Graph->Data[V]));
	return Graph;
}

