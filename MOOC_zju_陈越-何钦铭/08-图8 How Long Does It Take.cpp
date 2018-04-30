#include <cstdio>

const int MAX = 100;
int G[MAX][MAX];
int Earliest[MAX] = { 0 };
int indegree[MAX] = { 0 };
int outdegree[MAX] = { 0 };

int max(int a, int b) {
	return a > b ? a : b;
}
void Earliest_time(int N) {
	int queue[MAX], front = 0, rear = 0;
	for (int i = 0; i < N; i++) 
		if (!indegree[i]) {
			queue[rear++] = i;
			indegree[i]--;
		}
	int cnt = 0, v;
	while (rear > front) {
		v = queue[front++];
		cnt++;
		for (int i = 0; i < N; ++i) {
			if (G[v][i] >= 0) {
				indegree[i]--;
				Earliest[i] = max(Earliest[i], Earliest[v] + G[v][i]);
			}
			if (!indegree[i]) {
				queue[rear++] = i;
				indegree[i]--;
			}
		}
	}
	int res = 0;
	if (cnt != N) {
		printf("Impossible");
		return;
	}
	for (int i = 0; i < N; i++)
		if (outdegree[i] == 0)
			res = max(res, Earliest[i]);
	printf("%d", res);
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			G[i][j] = -1;
	for (int i = 0; i < M; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		G[s][e] = w;
		indegree[e]++;
		outdegree[s]++;
	}
	Earliest_time(N);
	return 0;
}