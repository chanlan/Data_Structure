typedef int Position;
struct QNode {
    ElementType *Data;
    Position Front, Rear;
    int MaxSize;
};
typedef struct QNode* Queue;

Queue CreateQueue( int MaxSize ){
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool isFull( Queue Q ){
    return((Q->Front+1) % Q->MaxSize == Q->Front);
}
bool AddQ( Queue Q, ElementType X ){
    if(isFull(Q)){
        printf("QUEUE FULL");
        return false;
    }
    Q->Rear = (Q->Rear+1) % Q->MaxSize;
    Q->Data[Q->Rear] = X;
    return true;
}

bool isEmpty( Queue Q ){
    return (Q->Front == Q->Rear);
}
ElementType DelQ( Queue Q ){
    if(isEmpty(Q)){
        printf("QUEUE EMPTY");
        return ERROR;
    }
    Q->Front = (Q->Front+1) % Q->MaxSize;
    return Q->Data[Q->Front];
}