#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElementType int

typedef struct HNode *Heap;
struct HNode {
    ElementType *Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
#define MAXDATA 1000 // accoding to the need
MaxHeap CreateHeap (int MaxSize){
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType*)malloc(sizeof(struct HNode));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MAXDATA;
    return H;
}
bool IsFull(MaxHeap H){
    return (H->Size == H->Capacity);
}
bool Insert(MaxHeap H, ElementType X){
    int i;
    if(IsFull(H)){
        printf("Heap Full");
        return 0;
    }
    i = ++H->Size;
    for(;H->Data[i/2] < X; i/=2)
        H->Data[i] = H->Data[i/2];
    H->Data[i] = X;
    return 1;
}
bool IsEmpty(MaxHeap H){
    return (H->Size == 0);
}
ElementType DeleteMax(MaxHeap H){
    int Parent, Child;
    ElementType MaxItem, X;
    if(IsEmpty(H)){
        printf("MaxHeap Empty");
        return -1;
    }
    MaxItem = H->Data[1];
    X = H->Data[H->Size--];
    for(Parent=1; Parent*2 <= H->Size; Parent = Child){
        Child = Parent*2;
        if(Child != H->Data[Child] && (H->Data[Child]<H->Data[Child+1]))
            Child++;
        if(X >= H->Data[Child]) break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
    return MaxItem;
}
//Build MaxHeap
void PercDown(MaxHeap H, int p){
    int Parent, Child;
    ElementType X;
    X = H->Data[p];
    for(Parent=p; Parent*2<=H->Size;Parent =Child){
        Child = Parent * 2;
        if( X >= H->Data[Child]) break;
            Child++;
        if(X >= H->Data[Child]) break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}
void BuildHeap(MaxHeap H){
    int i;
    for(i= H->Size/2; i>0; i--)
        PercDown(H,i);
}
