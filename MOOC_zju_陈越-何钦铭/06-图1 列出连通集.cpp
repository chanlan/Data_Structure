#include <cstdio>

bool G[10][10] = {false};
int N, E;
bool visit[10];
void InitVisit()
{
    for (int i = 0; i < 10; i++)
        visit[i] = false;
}
void DFS(int S){
	visit[S] = true;
	printf("%d ", S);
	for(int i =0; i < N; i++){
		if(!visit[i] && G[S][i])
			DFS(i);
	}
}

void BFS(int S){
	int Queue[100];
	int front = -1, rear = -1;
	Queue[++rear] = S;
	visit[S] = true;
	while(front < rear){
		int v = Queue[++front];
		printf("%d ", v);
		for(int i = 0; i < N; i++)
			if(G[v][i] && !visit[i]){
				Queue[++rear] = i;
				visit[i] = true;
			}
	}
}

int main(){
	scanf("%d %d", &N, &E);
	for(int i = 0; i < E; i++){
		int j, k;
		scanf("%d %d", &j, &k);
		G[j][k] =G[k][j]= true;
	}
	InitVisit();
	for(int i =0; i < N; i++)
		if(!visit[i]){
			printf("{ ");
			DFS(i);
			printf("}\n");
		}
	InitVisit();
	for(int i =0; i < N; i++)
		if(!visit[i]){
			printf("{ ");
			BFS(i);
			printf("}\n");
		}
	
	return 0;
}