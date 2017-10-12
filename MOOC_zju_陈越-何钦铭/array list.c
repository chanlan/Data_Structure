#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100
#define ERROR -1

typedef int Position;
typedef int ElementType;
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    Position Last;
};
List MakeEmpty() {
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}
Position Find(List L, ElementType X){
    Position i = 0;
    while (i <= L->Last && L->Data[i] != X) i++;
    if(i > L->Last) return ERROR;
    else return i;
}
bool Insert(List L, ElementType X, Position P){
    Position i;
    if (L->Last == MAXSIZE-1){
        printf("list full");
        return 0;
    }
    if( P<0 || P>L->Last+1 ){
        printf("position unlegal");
        return 0;
    }
    for(i=L->Last; i>=P; i--) L->Data[i+1] = L->Data[i];
    L->Data[P] = X;
    L->Last++;
    return 1;
}
bool Delete( List L, Position P){
    Position i;
    if (P<0 || P>L->Last){
        printf("%d unexist!", P);
        return 0;
    }
    for(i=P+1; i<=L->Last; i++)
        L->Data[i-1] = L->Data[i];
    L->Last--;
    return 1;
}
