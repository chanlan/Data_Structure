//DFS  Adj_List
 #include <stdio.h>
 #define Vertex int
 void Visit(Vertex V){
     printf("Visting the node %d\n", V);
 }
 void DFS(LGraph Graph, Vertex V, Void (*Visit)(Vertex)){
     PtrToAdjVNode W;
     Visit(V);
     Visited[V] = true;
     for(W=Graph->G[V].FirstEdge; W; W=W->Next)
        if(!Visited[W->AdjV])
            DFS(Graph, W->AdjV, Visit);
 }
 //BFS Adj_Matrix
 bool IsEdge(MGraph Graph, Vertex)
