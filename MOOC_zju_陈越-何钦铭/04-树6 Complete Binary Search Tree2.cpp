#include <cstdio>
#include <cstdlib>
#include <cmath>

int N;
int T[1001] = {0};
int A[1001] = {0};

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int GetLeftLength(int n){
    int H = log(n+1)/log(2);
    int X = n - pow(2,H) +1;
    X = X > pow(2,H-1) ? pow(2,H-1) : X;
    return ( pow(2,H-1) - 1 + X);
}
void Solve(int ALeft, int ARight, int TRoot){
    int n = ARight - ALeft +1;
    if(n == 0) return ;
    int L = GetLeftLength(n);
    T[TRoot] = A[ALeft + L];
    int LeftTRoot = TRoot*2 + 1;
    int RightTRoot = LeftTRoot + 1;
    Solve(ALeft, ALeft+L-1, LeftTRoot);
    Solve(ALeft+L+1, ARight, RightTRoot);
}


int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    qsort(A,N,sizeof(int), compare);
    Solve(0,N-1,0);
    printf("%d", T[0]);
    for(int i = 1; i < N; i++)
        printf(" %d", T[i]);
    return 0;
}
