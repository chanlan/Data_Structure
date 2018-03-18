typedef int Position;
struct SNode{
    ElementType *Data;
    Position Top;
    int MaxSize;
};

typedef struct SNode* Stack;

Stack CreateStack( int MaxSize ){
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool isFull( Stack S ){
    return ( S->Top == S->MaxSize-1 );
}

bool Push( Stack S, ElementType X ){
    if(isFull(S)){
        printf("STACK FULL");
        return false;
    }
    S->Data[++(S->Top)] = X;
    return true;
}

bool isEmpty( Stack S ){
    return (S->Top == -1);
}

ElementType Pop( Stack S ){
    if(isEmpty(S)){
        printf("STACK EMPTY");
        return ERROR;
    }
    return (S->Data[(S->Top)--]);
}