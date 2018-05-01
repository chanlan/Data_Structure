#include <cstdio>
const int MAX = 1005;
const int INF = 123456;

int G[MAX][MAX];
int N, M;
int dist[MAX];

int findMin() {
	int minCost = INF;
	int v = 0;
	for (int i = 1; i <= N; ++i) {
		if (dist[i] && minCost > dist[i]) {
			minCost = dist[i];
			v = i;
		}
	}
	return v;
}
void prim() {
	for (int i = 1; i <= N; ++i)
		dist[i] = G[1][i];
	dist[1] = 0;
	int ans = 0;

	for (int i = 1; i < N; ++i) {
		int v = findMin();
		if (v) {
			ans += dist[v];
			dist[v] = 0;
			for (int j = 2; j <= N; ++j)
				if (dist[j] && G[v][j] < dist[j])
					dist[j] = G[v][j];
		}
		else {
			ans = -1;
			break;
		}
	}
	printf("%d", ans);
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (i == j) G[i][j] = 0;
			else G[i][j] = INF;
		}
	int s, e, w;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &w);
		G[s][e] = G[e][s] = w;
	}
	prim();
	return 0;
}