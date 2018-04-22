#include <cstdio>
#include <cstdlib>
const int MAXN = 505;
const int INFINITY = 1000000;

int N, M, S, D;
int G[MAXN][MAXN];
int Mo[MAXN][MAXN];
int dist[MAXN];
int cost[MAXN];
int Visited[MAXN] = {false};

void Dijkstra(int S){
	int shortdist, v;
	Visited[S] = true;

	while(true){
		shortdist = INFINITY;
		v = -1;
		for(int i = 0; i < N; i++)
			if(!Visited[i] && dist[i] < shortdist){
				v = i;
				shortdist = dist[i];
			}
		if(v == -1) break;
		Visited[v] = true;
		for(int i = 0; i < N; i++){
			if(!Visited[i] && dist[v] + G[v][i] < dist[i]){
				dist[i] = G[v][i] + dist[v];
				cost[i] = cost[v] + Mo[v][i];
			}else if(!Visited[i] && dist[v] + G[v][i] == dist[i] && cost[i] > Mo[v][i] + cost[v]){
				cost[i] = Mo[v][i] + cost[v];
			}
		}
	}
}
int main(){
    scanf("%d %d %d %d", &N, &M, &S, &D);
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++){
			if(i == j){
				G[i][j] = 0;
				Mo[i][j] = 0;
			}else{
				G[i][j] = INFINITY;
				Mo[i][j] = INFINITY;
			}
		}
	int c1, c2, l, m;
	for(i = 0; i < M; i++){
		scanf("%d %d %d %d", &c1, &c2, &l, &m);
		G[c1][c2] = G[c2][c1] = l;
		Mo[c1][c2] = Mo[c2][c1] = m;
	}
	for( i = 0; i < N; i++){
		dist[i] = G[S][i];
		cost[i] = Mo[S][i];
	}
	Dijkstra(S);
	printf("%d %d\n", dist[D], cost[D]);
	system("pause");
	return 0;
}
