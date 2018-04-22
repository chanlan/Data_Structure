#include <cstdio>
const int MAX = 100;
const int INF = 1000000;

int G[MAX][MAX];
int D[MAX][MAX];
int N, M;

bool Floyd(){
	int i, j, k;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			D[i][j] = G[i][j];
	for(k = 0; k < N; k++)
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				if(D[i][k] + D[k][j] < D[i][j]){
					D[i][j] = D[i][k] + D[k][j];
					if(i == j && D[i][j] < 0) 
						return false;
				}
	return true;
}
int FindMaxDist(int j){
	int MaxDist = 0;
	for(int i = 0; i < N; i++)
		if(j != i && D[j][i] > MaxDist)
			MaxDist = D[j][i];
	return MaxDist;
}
void FindAnimal(){
	Floyd();
	int MinDist = INF;
	int i, animal;
	for(i = 0; i < N; i++){
		int MaxDist = FindMaxDist(i);
		if(MaxDist == INF){
			printf("0\n");
			return ;
		}
		if(MinDist > MaxDist){
			MinDist = MaxDist;
			animal = i + 1;
		}
	}
	printf("%d %d\n", animal, MinDist);
}
int main(){
	scanf("%d %d", &N, &M);
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			G[i][j] = G[j][i] = INF;
	for(i = 0; i < M; i++){
		int a1, a2, l;
		scanf("%d %d %d", &a1, &a2, &l);
		a1--; a2--;
		G[a1][a2] = G[a2][a1] = l;
	}

	FindAnimal();
	return 0;
}