//图的临接矩阵表示法
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
#define MaxVertexNum 100    //最大顶点数
#define INFINITY 65535      //最大值设为无符号整数的最大值65535
typedef int Vertex;         //用顶点下标表示顶点
typedef int WeightType;     //权值
typedef char DataType;      //顶点储存的数据类型
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;
    int MaxSize;
};
typedef struct QNode *Queue;
bool IsEmpty( Queue Q ){
    return ( Q->Front == NULL);
}
ElementType DeleteQ( Queue Q ){//? 和Queue一样的问题为啥print Q->Next->Data
    Position FrontCell;
    ElementType FrontElem;
    if( IsEmpty(Q) ){
        printf("Queue empty");
        return 0;
    }
    else {
        FrontCell = Q->Front;
        if( Q->Front == Q->Rear )
            Q->Front = Q->Rear = NULL;
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell ->Data;
        free(FrontCell);
        return FrontElem;
    }
}
//Edge Definnation
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;
//Graph Node definnation
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;     //Num of Vertex
    int Ne;     //Num of edge
    WeightType G[MaxVertexNum][MaxVertexNum];   //AdjMatrix
    DataType Data[MaxVertexNum];        //stroage the Vertex
};
typedef PtrToGNode MGraph;
//初始化一个有VertexNum个顶点但没有边的图
MGraph CreateGraph(int VertexNum){
    Vertex V, W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(V=0; V<Graph->Nv; V++)
        for(W=0; W<Graph->Nv;W++)
            Graph->G[V][W] = INFINITY;
    return Graph;
}
void InsertEdge(MGraph Graph, Edge E){
    Graph->G[E->V1][E->V2] = E->Weight;
    // if is Undigraph
    Graph->G[E->V2][E->V1] = E->Weight;
}
//
MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    scanf("%d", &(Graph->Ne));
    if(Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0; i<Graph->Ne; i++){
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }
    //当顶点有数据时读入
    for(V=0; V<Graph->Nv; V++)
        scanf(" %c", &(Graph->Data[V]));
    return Graph;
}
void Visit(Vertex V){
    printf("Vist the node %d", V);
}
bool IsEdge(MGraph Graph, Vertex V, Vertex W){
    return Graph->G[V][W] < INFINITY ? true : false;
}
bool Visited[MaxVertexNum];
void BFS(MGraph Graph, Vertex S, void(*Vist)(Vertex)){
    Queue Q;
    Vertex V, W;
    Q = CreateQueue( MaxVertexNum );
    Vist(S);
    Visited[S] = true;
    AddQ(Q, S);
    while (!IsEmpty(Q)){
        V = Delete(Q);
        for (W = 0; W < Graph->Nv ; W++)
            if(!Visited[W] && IsEdge(Graph, V, W)){
                Visit(W);
                Visited[W] = true;
                AddQ(Q, W);
            }
    }
}
