#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int

typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X){
    Position p = L;
    while(p && p->Data != X)
        p = p->Next;
    if (p) return p;
    else return NULL;
}
bool Insert(List L, ElementType X, Position P){
    Position tmp, pre;
    for(pre=L; pre&&pre->Next!=P;pre=pre->Next);
    if(pre==NULL){
        printf("Position ERROR");
        return 0;
    }
    else {
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return 1;
    }
}
bool Delte(List L, Position P){
    Position pre;
    for (pre=L; pre&&pre->Next!=P;pre=pre->Next);
    if(pre==NULL || P==NULL){
        printf("Position ERROR");
        return 0;
    }
    else {
        pre->Next = P->Next;
        free(P);
        return 1;
    }
}
