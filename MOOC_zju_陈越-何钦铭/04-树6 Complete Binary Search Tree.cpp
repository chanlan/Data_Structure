#include <cstdio>
#include <cstdlib>

int N;
int b[1001] {0};
int j = 0;
int a[1001] {0};

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

void mid_tree(int root){
    if(root <= N){
        mid_tree(root*2);
        b[root] = a[j++];
        mid_tree(root*2+1);
    }
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    qsort(a,N,sizeof(int), compare);
    mid_tree(1);
    printf("%d", b[1]);
    for(int i = 2; i <= N; i++)
        printf(" %d", b[i]);
    return 0;
}
