#include <cstdio>
#include <cstdlib>
#define MAXN 1001
#define MINH -10001

int Heap[MAXN], size;
void Creat(){
	size = 0;
	Heap[0] = MINH;
}

void Insert(int X){
	int i;
	for( i = ++size; Heap[i/2] > X; i/=2)
		Heap[i] = Heap[i/2];
	Heap[i] = X;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	Creat();
	for(int i = 0; i < N; i++){
		int X;
		scanf("%d", &X);
		Insert(X);
	}
	for(int i = 0; i < M; i++){
		int j;
		scanf("%d", &j);
		printf("%d", Heap[j]);
		while(j > 1){
			j /= 2;
			printf(" %d", Heap[j]);
		}
		printf("\n");
	}
	return 0;
}