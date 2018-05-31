#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
#define MAX 105
#define INFINITY 65535

int N, M, A[MAX][MAX], ECT, EarliestTime[MAX] = {0}, LatestTime[MAX], D[MAX][MAX], idx;

int getMax(int arr[]){
	int max = 0;
	for(int i = 0; i < N; i++)
		if(max < arr[i]){
			max = arr[i];
			idx = i;
		}
	return max;
}

int TopSort_Earliest(){
	int v, cnt = 0, inDegree[MAX] = {0};
	queue<int> q;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(A[i][j] != INFINITY)
				inDegree[j]++;
	for(int i = 0; i < N; i++)
		if(0 == inDegree[i])
			q.push(i);
	while(!q.empty()){
		v = q.front();
		q.pop();
		cnt++;
		for(int j = 0; j < N; j++)
			if(A[v][j] != INFINITY){
				if(EarliestTime[v] + A[v][j] > EarliestTime[j])
					EarliestTime[j] = EarliestTime[v] + A[v][j];
				if(--inDegree[j] == 0)
					q.push(j);
			}
	}
	if(cnt != N) return 0;
	ECT = getMax(EarliestTime);
	return 1;
}

void TopSort_Latest(){
	int v, outDegree[MAX] = {0};
	queue<int> q;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(A[i][j] != INFINITY)
				outDegree[i]++;
	for(int i = 0; i < N; i++)
		if(0 == outDegree[i])
			q.push(i);
	for(int i = 0; i < N; i++)
		LatestTime[i] = INFINITY;
	
	LatestTime[idx] = ECT;
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(int j = 0; j < N; j++)
			if(INFINITY != A[j][v]){
				if(LatestTime[j] >= LatestTime[v] - A[j][v]){
					LatestTime[j] = LatestTime[v] - A[j][v];
					D[j][v] = LatestTime[v] - EarliestTime[j] - A[j][v];
				}
			if( 0 == --outDegree[j] )
				q.push(j);
			}
	}
}
void printKeyRoute(){
	for(int i = 0; i < N; i++)
		for(int j = N-1; j >= 0; j--)
			if(0 == D[i][j])
				printf("%d->%d\n", i+1, j+1);
}

int main(){
	int a,b;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			D[i][j] = A[i][j] = INFINITY;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &a, &b);
		scanf("%d", &A[--a][--b]);
	}
	if(!TopSort_Earliest())
		printf("0");
	else{
		printf("%d\n", ECT);
		TopSort_Latest();
		printKeyRoute();
	}
	return 0;
}














