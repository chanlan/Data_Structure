//邻接矩阵存储-有权图的单源最短路算法
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]){
    //返回未被收录顶点中dist最小者
    Vertex MinV, V;
    int MinDist = INFINITY;
    for(V = 0; V < Graph->Nv; V++){
        if(collected[V] = false && dist[V] < MinDist){
            MinDist = dist[V];
            MinV = V;
        }
    }
    if(MinDist < INFINITY)
        return MinV;
    else
        return ERROR;
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S){
    int collected[MaxVertexNum];
    Vertex V, W;
    //初始化：此处默认邻接矩阵中不存在的边用INFINITY表示
    for( V=0; V < Graph->Nv; V++){
        dist[V] = Graph->G[S][V];
        if(dist[V] < INFINITY)
            path[V] = S;
        else
            path[V] = -1;
        collected[V] false;
    }
    dist[S] = 0;
    collected[S] = true;
    while(true){
        V = FindMinDist(Graph, dist, collected);
        if(V == ERROR)//V不存在
            break;
        for(W = 0; W < Graph->NV; W++)
        if(!collected[W] && Graph->G[V][W] < INFINITY){
            if(Graph->G[V][W] <0)//负值圈返回ERROR
                return false;
            if(dist[W] > (Graph->G[V][W]+ dist[V])){
                dist[W] = Graph->G[V][W] + dist[V]);
                path[W] = V;
            }
        }
    }
    return true;
}
