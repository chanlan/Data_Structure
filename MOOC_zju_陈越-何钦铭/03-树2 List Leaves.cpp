#include <cstdio>
#include <cstdlib>

typedef struct QNode* Queue;
struct Node{
    int index;
    int left;
    int right;
} Tree[10];

struct QNode{
    struct Node *Data;
    int Front, Rear;
};

Queue CreateQueue(){
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (struct Node*)malloc(10*sizeof(struct Node));
    Q->Front = Q->Rear = 0;
    return Q;
}
bool AddQ( Queue Q, struct Node X){
    Q->Rear = (Q->Rear+1) %10;
    Q->Data[Q->Rear] = X;
    return true;
}
bool isEmpty(Queue Q){
    return (Q->Front == Q->Rear);
}
struct Node DelQ(Queue Q){
    if(isEmpty(Q))
        return {-1,-1};
    Q->Front = (Q->Front + 1) % 10;
    return Q->Data[Q->Front];
}

int BuildT(struct Node* T){
    int N;
    scanf("%d", &N);
    int check[N] = {0};
    for(int i = 0; i < N; i++){
        T[i].index = i;
        char cl, cr;
        scanf("\n%c %c", &cl, &cr);
        if(cl != '-'){
            T[i].left = cl - '0';
            check[T[i].left] = 1;
        }else T[i].left = -1;
        if(cr != '-'){
            T[i].right = cr - '0';
            check[T[i].right] = 1;
        }else T[i].right = -1;
    }
    for(int i = 0; i < N; i++)
        if (!check[i]) return i;
    return -1;
}

int main(){
    int Root;
    Root = BuildT(Tree);
    Queue Q = CreateQueue();
    AddQ(Q, Tree[Root]);
    int flag = 0;
    while(!isEmpty(Q)){
        struct Node Temp = DelQ(Q);
        if(Temp.left == -1 && Temp.right == -1){
            if(!flag) {
                printf("%d", Temp.index);
                flag = 1;
            }else printf(" %d", Temp.index);
        }
        if(Temp.left != -1) AddQ(Q, Tree[Temp.left]);
        if(Temp.right != -1) AddQ(Q, Tree[Temp.right]);
    }
    return 0;
}