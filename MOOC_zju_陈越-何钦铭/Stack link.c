#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;
Stack CreataStack() {
//构建一个堆栈的头结点，返回该结点指针
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
bool IsEmpty ( Stack S){
    return ( S->Next == NULL);
}
bool Push( Stack S, ElementType X){
    PtrToSNode TmpCell;
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return 1;
}
ElementType Pop( Stack S){
    PtrToSNode FirstCell;
    ElementType TopElem;
    if( IsEmpty(S) ){
        printf("Stack empty\n");
        return 0;
    }
    else {
        FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}
