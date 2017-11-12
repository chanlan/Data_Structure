#include <stdio.h>
#define MAXN 1000
int G[MAXN][MAXN], Nv, Ne;
void BuildGraph() {
	int i, j, v1, v2, w;
	scanf("%d", &Nv);
	for (i = 0; i < Nv; i++)
		for (j = 0; j < Nv; j++)
			G[i][j] = 0;
	scanf("%d", &Ne);
	for (i = 0; i < Ne; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		G[v1][v2] = w;
		G[v2][v1] = w;
	}
}