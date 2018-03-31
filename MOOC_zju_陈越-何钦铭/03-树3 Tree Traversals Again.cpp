#include <cstdio>
#define MAXSIZE 30

int preOrder[MAXSIZE] = {0};
int inOrder[MAXSIZE] = {0};
int posOrder[MAXSIZE] = {0};

void Solve(int preL, int inL, int posL, int n){
    if(n == 0)
        return;
    if(n == 1){
        posOrder[posL] = inOrder[inL];
        return;
    }
    int root = preOrder[preL];
    posOrder[posL+n-1] = root;
    int L, R, i;
    for(i = 0; i < n; i++)
        if( inOrder[inL + i] == root)
            break;
    L = i;
    R = n - L - 1;
    Solve(preL+1, inL, posL,L);
    Solve(preL+L + 1, inL + L + 1, posL+L, R);
}
int main(){
    int stack[MAXSIZE] = {0};
    int pre_n = 0;
    int in_n = 0;
    int stack_n = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 2*n; i++){
        char tmp[5];
        scanf("%s", tmp);
        if(tmp[1] == 'u'){
            scanf("%d", &preOrder[pre_n]);
            stack[stack_n++] = preOrder[pre_n++];
        }
        else{
            inOrder[in_n++] = stack[--stack_n];
        }
    }
    Solve(0, 0, 0, n);

    printf("%d", posOrder[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", posOrder[i]);
    return 0;
}