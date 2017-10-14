#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int Position;
#define ElementType int
struct QNode {
    ElementType *Data;
    Position Front, Rear;
    int MaxSize;
};
typedef struct QNode *Queue;
Queue CreateQueue( int MaxSize){
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
bool IsFull( Queue Q ){
    return ((Q->Rear+1)%Q->MaxSize == Q->Front); // ?
}
bool AddQ( Queue Q, ElementType X){
    if( IsFull(Q) ){
        printf("Queue full");
        return 0;
    }
    else {
    Q->Rear = (Q->Rear+1)%Q->MaxSize; // ?
    Q->Data[Q->Rear] = X;
    return 1;
    }
}
bool IsEmpty(Queue Q){
    return (Q->Front == Q->Rear);
}
ElementType DeleteQ(Queue Q){
    if(IsEmpty(Q)){
        printf("Queue empty");
        return 0;
    }
    else {
        Q->Front = (Q->Front+1)%Q->MaxSize;
        return Q->Data[Q->Front];//删除 Q->Front？
    }
}
