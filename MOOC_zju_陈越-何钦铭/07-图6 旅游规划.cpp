#include <cstdio>
#include <cstdlib>
const int MaxN = 505;
const int INFINITY = 1000000;
int N, M, S, D;

int G[MaxN][MaxN];
int Mo[MaxN][MaxN];
bool visited[MaxN] = {false};
int dist[MaxN];
int cost[MaxN];

void Dijkstra(int s){
    int i, short1, v0;
    visited[s] = true;
    while(true){
        short1 = INFINITY;
        v0 = -1;
        for(i = 0; i < N; i++){
            if(!visited[i] && dist[i] < short1){
                v0 = i;
                short1 = dist[i];
            }
        }
        if(v0 <0) break;
        visited[v0] = true;
        for(i = 0; i < N; i++){
            if(!visited[i] && G[v0][i]+ dist[v0] < dist[i]){
                dist[i] = G[v0][i] + dist[v0];
                cost[i] = cost[v0] + Mo[v0][i];
            }else if(dist[v0] + G[v0][i] == dist[i] && cost[v0] + Mo[v0][i] < cost[i]){
                cost[i] = cost[v0] + Mo[v0][i];
            }
        }
    }
}

int main(){
	scanf("%d %d %d %d", &N, &M, &S, &D);

	int i, j;
	for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == j){
                G[i][j] = 0;
                Mo[i][j] = 0;
            }
            else{
                G[i][j] = INFINITY;
                Mo[i][j] = INFINITY;
            }
        }
	}
	int c1, c2, l, m;
	for(i = 0; i < M; i++){
		scanf("%d %d %d %d",&c1, &c2, &l, &m);
		G[c1][c2] = G[c2][c1] = l;
		Mo[c1][c2] = Mo[c2][c1] = m;
	}
    for(i = 0; i < N; i++){
        dist[i] = G[S][i];
        cost[i] = Mo[S][i];
    }
    Dijkstra(S);
    printf("%d %d\n", dist[D], cost[D]);
	return 0;
}
