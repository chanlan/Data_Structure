typedef struct Node* PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};

typedef PtrToNode Position;

struct QNode{
        Position Front, Rear;
        int MaxSize;
};
typedef struct QNode* Queue;

bool isEmpty( Queue Q ){
    return (Q->Front == NULL);
}

ElementType DelQ( Queue Q){
    if(isEmpty(Q)){
        printf("QUEUE EMPTY");
        return ERROR;
    }
    Position FrontCell;
    ElementType FrontElem;
    FrontCell = Q->Front;
    if(Q->Front == Q->Rear) Q->Front = Q->Rear = NULL;
    else Q->Front = Q->Front->Next;
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}