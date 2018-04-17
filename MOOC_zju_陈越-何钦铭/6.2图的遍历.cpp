//邻接表图 DFS
void Visit(Vertex V){
	printf("正在访问顶点%d\n", V);
}

void DFS(LGraph Graph, Vertex V, void(*Vistit)(Vertex)){
	PtrToAdjVNode W;
	Visit(V);
	Visited[V] = true;

	for(W = Graph->G[V].FirstEdge; W; W = W->Next)
		if(!Visited[W->AdjV])
			DFS(Graph, W->AdjV, Visit);
}

bool isEdge(MGraph Graph, Vertex V, Vertex W){
	return Graph->G[V][W] < INFINITY ? true:false;
}

//邻接矩阵存储的图 BFS
void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex)){
	Queue Q;
	Vertex V, W;
	Q = CreatQueue(MaxSize);
	Visit(S);
	Visited[S] = true;
	AddQ(Q, S);
	while(!isEmpty(Q)){
		V = DeleteQ(Q);
		for(W = 0; W <Graph->Nv; W++)
			if(!Vistited[W] && IsEdge(Graph, V, W){
				Visit(W);
				Visited[W] = true;
				AddQ(Q, W);
			}
	}
}