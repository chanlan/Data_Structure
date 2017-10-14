#include <stdio.h>
#define ElementType int
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
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
    Queue Q;
    BinTree T;
    if ( !BT ) return;
    Q = CreatQueue();
    AddQ(Q, BT);
    while (!IsEmpty(Q)) {
        T = DeleteQ(Q);
        printf("%d ", T->Data);
        if ( T->Left ) AddQ(Q, T->Left);
        if ( T->Right ) AddQ(Q, T->Right);
    }
}
//二叉搜索树
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
}
