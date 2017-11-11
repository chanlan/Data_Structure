bool IsEdge(MGraph Graph, Vertex V, Vertex W){
	return Graph->G[V][W] < INFINITy ? true : false;
}
void BFS(Mgraph Graph, Vertex S, void (*Visit)(Vertex)){
	Queue Q;
	Vertex V, W;
	Q = CreatQueue(MaxSize);
	Visit (S);
	Visited[S] = true;
	AddQ(Q, S);
	while (!IsEmpty(Q)){
		V = DeleteQ(Q);
		for(W =0; W <Graph->Nv; W++)
			if(!Visited[W] && IsEdge(Graph, V, W)){
				Visit(W);
				Visited[W] = true;
				AddQ(Q, W);
			}
	}
}