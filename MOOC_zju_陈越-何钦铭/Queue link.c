#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;
    int MaxSize;
};
typedef struct QNode *Queue;
bool IsEmpty( Queue Q ){
    return ( Q->Front == NULL);
}
ElementType DeleteQ( Queue Q ){//? 和Queue一样的问题为啥print Q->Next->Data
    Position FrontCell;
    ElementType FrontElem;
    if( IsEmpty(Q) ){
        printf("Queue empty");
        return 0;
    }
    else {
        FrontCell = Q->Front;
        if( Q->Front == Q->Rear )
            Q->Front = Q->Rear = NULL;
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell ->Data;
        free(FrontCell);
        return FrontElem;
    }
}
