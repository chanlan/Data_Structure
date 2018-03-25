#include <cstdio>
#include <cstdlib>

typedef struct Node* Stack;
struct Node{
    int *Data;
    int Top;
    int MaxSize;
};

Stack CreateStack(int MaxSize){
    Stack S = (Stack)malloc(sizeof(struct Node));
    S->Data = (int*)malloc(MaxSize*sizeof(int));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}
bool isEmpty(Stack S){
    return (S->Top == -1);
}
bool isFull(Stack S){
    return (S->Top == S->MaxSize-1);
}
bool Push(Stack S, int X){
    if(isFull(S))
        return false;
    S->Data[++(S->Top)] = X;
    return true;
}
int Pop(Stack S){
    if(isEmpty(S))
        return false;
    return (S->Data[(S->Top)--]);
}

int main(){
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    while(K--){
        int array[100000] = {0};
        for(int i = 0; i < N; i++)
            scanf("%d", &array[i]);
        Stack S = CreateStack(M);
        int count = 0;
        bool isFull = false;
        for(int j = 1; j <= N; j++){
            if(!Push(S, j)) {
                isFull = true;
                break;
            }
            while(S->Data[S->Top] == array[count]){
                count++;
                Pop(S);
            }
        }
        if(isEmpty(S) && !isFull) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
