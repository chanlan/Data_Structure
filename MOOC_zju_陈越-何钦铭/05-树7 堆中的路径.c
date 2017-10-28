#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MINDATA -10001 // 哨兵
typedef struct HNode *Heap;
struct HNode{
    int *Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;

MinHeap CreateHeap (int MaxSize){
    Heap H = (Heap)malloc(sizeof(struct HNode));
    H->Data = (int*)malloc((MaxSize+1)*sizeof(int));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MINDATA;
    return H;
}
bool IsFull(Heap H){
    return (H->Size == H->Capacity);
}
//bool IsEmpty(Heap H){
//    return (H->Size == 0);
//}
bool Insert(MinHeap H, int X){
    int i;
    if(IsFull(H)){
        printf("Heap Full");
        return 0;
    }
    i = ++H->Size;
    for(;H->Data[i/2] > X; i/=2)
        H->Data[i] = H->Data[i/2];
    H->Data[i] = X;
    return 1;
}
void MHeapTraver(MinHeap H, int i){
    bool IsFirst =1;
    while(H->Data[i] != H->Data[0]){
        if(IsFirst) {
            printf("%d", H->Data[i]);
            IsFirst = 0;
        }else{
            printf(" %d", H->Data[i]);
        }
        i /= 2;
    }
}
int main(){
    int N, M;
    MinHeap H;
    scanf("%d %d", &N, &M);
    H = CreateHeap(N);
    int X;
    for(int i=0; i< N; i++) {
        scanf("%d", &X);
        Insert(H,X);
    }
    for(int i=0; i< M; i++){
        scanf("%d", &X);
        MHeapTraver(H,X);
        printf("\n");
    }
    return 0;
}
