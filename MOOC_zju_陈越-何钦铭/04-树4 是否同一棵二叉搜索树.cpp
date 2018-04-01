#include <cstdio>
#include <cstdlib>

typedef struct Node *Tree;
struct Node{
    int v;
    Tree Left, Right;
    int flag;
};

Tree NewNode(int v){
    Tree T = (Tree)malloc(sizeof(struct Node));
    T->flag = 0;
    T->v = v;
    T->Left = T->Right = NULL;
    return T;
}

Tree InsertTree(Tree T, int v){
    if(!T) T = NewNode(v);
    else{
        if (v > T->v) T->Right = InsertTree(T->Right, v);
        else T->Left = InsertTree(T->Left, v);
    }
    return T;
}

Tree BuildTree(int N){
    int i, v;
    Tree T;
    scanf("%d", &v);
    T = NewNode(v);
    for(i = 1; i < N; i++){
        scanf("%d", &v);
        T = InsertTree(T, v);
    }
    return T;
}

bool check(Tree T, int v){
    if(T->flag){
        if(v > T->v) return check(T->Right, v);
        else if(v < T->v) return check(T->Left, v);
        else return false;
    } else{
        if(T->v == v){
            T->flag = 1;
            return true;
        }else return false;
    }
}
bool judge(Tree T, int N){
    int i, v, flag = 0;
    scanf("%d", &v);
    if(T->v != v) flag = 1;
    else T->flag = 1;
    for(i = 1; i < N; i++){
        scanf("%d", &v);
        if((!flag) && (!check(T, v))) flag = 1;
    }
    if(flag) return false;
    else return true;
}
void ResetF(Tree T){
    if(T->Left) ResetF(T->Left);
    if(T->Right) ResetF(T->Right);
    T->flag = 0;
}
void FreeTree(Tree T){
    if(T->Left) FreeTree(T->Left);
    if(T->Right) FreeTree(T->Right);
    free(T);
}
int main(){
    int N;
    scanf("%d", &N);
    while(N){
        int L;
        scanf("%d", &L);
        Tree T = BuildTree(N);
        for(int i = 0; i < L; i++){
            if(judge(T, N)) printf("Yes\n");
            else printf("No\n");
            ResetF(T);
        }
        FreeTree(T);
        scanf("%d", &N);
    }
    return 0;
}