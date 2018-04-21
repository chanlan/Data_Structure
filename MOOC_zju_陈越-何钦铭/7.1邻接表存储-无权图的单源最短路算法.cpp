//邻接表存储 无权图的单源最短路算法
//dist[] 和 path[] 全部初始化为 -1

void UnWeighted(LGraph Graph, int dist[], int path[], Vertex S){
    Queue Q;
    Vertex V;
    PtrToAdjVNode W;
    Q = CreatQueue(Graph->Nv);
    dist[S] = 0;
    AddQ(Q, S);
    while(!isEmpty(Q)){
        V = DeleteQ(Q);
        for(W = Graph[V].FirstEdge; W; W = W->Next)
            if(dist[W->AdjV] == -1){
                dist[W->AdjV] = dist[V] +1;
                path[W->AdjV] = V;
                AddQ(Q, W->AdjV);
            }
    }
}
