#include <stdio.h>
#include <stdlib.h>
#define ElementType int
typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode {
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};
int Max(int a, int b){
    return a > b ? a : b;
}
AVLTree SingleLeftRotation (AVLTree A){
     AVLTree B = A->Left;
     A->Left = B->Right;
     B->Right = A;
     A->Height = Max(GetHeight(A->Left),GetHeight(A->Right)) + 1;
     B->Height = Max(GetHeight(B->Left),A->Height) + 1;
     return B;
}
