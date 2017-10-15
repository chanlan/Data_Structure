#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
// Queue start
typedef struct Node *Queue;
struct Node{
    BinTree Data;
    Queue Next;
};
Queue Front=NULL, Rear=NULL;
BinTree AddQ(Queue Q, BinTree BT){
    Queue tmp;
    tmp = (Queue)malloc(sizeof(struct Node));
    tmp->Data = BT;
    tmp->Next = NULL;
    Rear->Next = tmp;
    Rear = tmp;
    return Rear->Data;
}
BinTree DeleteQ(Queue Q){
    if(Front){
        Queue tmp;
        tmp = Front;
        Front = Front->Next;
        free(tmp);
    }
    return Front->Data;
}
void InorderTraversal(BinTree BT){
    if(BT){
        InorderTraversal( BT->Left );
        printf("%d ", BT->Data);
        InorderTraversal( BT->Right );
    }
}
void PreorderTraversal(BinTree BT){
    if (BT) {
        printf("%d", BT->Data);
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}
void PosorderTraversal(BinTree BT){
    if (BT) {
        PosorderTraversal( BT->Left );
        PosorderTraversal( BT->Right );
        printf("%d", BT->Data);
    }
}
void LevelorderTraversal(BinTree BT){ //队列实现
    Queue Q = NULL;
    BinTree T;
    if ( !BT ) return;
    AddQ(Q, BT);
    while (!Front) {
        T = DeleteQ(Q);
        printf("%d ", T->Data);
        if ( T->Left ) AddQ(Q, T->Left);
        if ( T->Right ) AddQ(Q, T->Right);
    }
}
//二叉搜索树
Position Find(ElementType X, BinTree BST){
    if(!BST) return NULL;
    if(X>BST->Data)
        return Find(X,BST->Right);
    else if(X < BST->Data)
        return Find(X, BST->Left);
    else
        return BST;
}
Position FindMin(BinTree BST){
    if (!BST) return NULL;
    else if(!BST->Left) return BST;
    else return FindMin(BST->Left);
}
Position FindMax(BinTree BST){
    if(BST)
        while(BST->Right) BST=BST->Right;
    return BST;
}

BinTree Insert( BinTree BST, ElementType X){
    if (!BST) {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else {
        if(X < BST->Data)
            BST->Left = Insert(BST->Left, X);
        else if( X > BST->Data)
            BST->Right = Insert(BST->Right, X);
    }
    return BST;
}
BinTree Delete( BinTree BST, ElementType X){
    Position Tmp;
    if (!BST) {
        printf("NOT FOUND!");
    }
    else{
        if(X < BST->Data)
            BST->Left = Delete(BST->Left, X);
        else if (X > BST->Data)
            BST->Right = Delete(BST->Right, X);
        else {
            if(BST->Left && BST->Right){
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                BST->Right = Delete(BST->Right, BST->Data);
            }
            else {
                Tmp = BST;
                if(!BST->Left) BST = BST->Right;
                else BST = BST->Left;
                free(Tmp);
            }
        }
    }
    return BST;
}
