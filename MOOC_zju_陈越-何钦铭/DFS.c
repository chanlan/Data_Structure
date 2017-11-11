void Visit(Vertex V){
	printf("访问顶点%d\n", V);
}

void DFS(LGraph Graph, Vertex V, void (*Vistit)(Vertex)){
	PtrToAdjVnode W;
	Visit(V);
	Visited[V] = true;
	for (W =Graph->G[V].FitstEdge; W; W = W->Next)
		if(!Visited[W->AdjV])
			DFS(Graph, W->AdjV, Visit);
}