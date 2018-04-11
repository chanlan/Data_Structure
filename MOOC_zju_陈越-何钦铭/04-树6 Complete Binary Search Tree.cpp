#include <cstdio>
#include <cstdlib>

int b[1001];
int j= 0;

int compare(const void *a,const void *b){
	return *(int *)a - *(int *)b;
}
void mid_tree(int root, int N, int a[]){
	if(root <= N){
		mid_tree(2*root, N, a);
		b[root] = a[j++];
		mid_tree(2*root+1,N,a);
	}
}
int main(){
	int N;
	scanf("%d", &N);
	int a[1001] = {0};
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	qsort(a,N,sizeof(int),compare);
	mid_tree(1,N,a);
	printf("%d", b[1]);
	for(int i = 2; i <= N; i++)
		printf(" %d", b[i]);
	system("pause");
	return 0;
}