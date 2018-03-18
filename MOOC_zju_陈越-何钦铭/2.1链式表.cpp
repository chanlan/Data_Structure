typedef struct LNode *PtrToLNode;
struct LNode{
    ElementType Data;
    PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ELementType X){
    Position p = L;
    while(p && p->Next != X)
        p = p->Next;
    if(p) return p;
    else return ERROR;
}
bool Insert(List L, ElementType X, Position P){
    Position tmp, pre;
    for(pre = L; pre && pre->Next != P; pre = pre->Next);
    if(pre == NULL){
        printf("POSITION ERROR");
        return false;
    }
    tmp = (Position)malloc(sizeof(struct LNode));
    tmp->Data = X;
    tmp->Next = P;
    pre->Next = tmp;
    return true;
}
bool Delete(List L, Position P){
    Position pre;
    for(pre = L; pre && pre->Next != P; pre = pre->Next);
    if(pre == NULL || P == NULL){
        printf("POSITION ERROR");
        return false;
    }
    pre->Next = P->Next;
    free(P);
    return true;
}