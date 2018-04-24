+1#include <cstdio>
#include <cstdlib>

typedef struct HNode *Heap;
#define ElementType int

struct HNode{
	ElementType *Data;
	int Size;
	int Capacity;
};

typedef Heap MaxHeap;
typedef Heap MinHeap;
#define MAXDATA 1000

MaxHeap CreateHeap(int MaxSize){
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc(sizeof(ElementType)*(MaxSize+1));
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
		printf("HEAP FULL");
		return false;
	}
	i = ++H->Size;
	for(; H->Data[i/2] < X; i/=2)
		H->Data[i] = H->Data[i/2];
	H->Data[i] = X;
	return true;
}

bool IsEmpty(MaxHeap H){
	return (H->Size == 0);
}

ElementType DeleteMax(MaxHeap H){
	int parent, child;
	ElementType X, MaxItem;
	if(IsEmpty(H)){
		printf("HEAP EMPTY");
		return false;
	}
	MaxItem = H->Data[1];
	X = H->Data[H->Size--];
	for(parent = 1; parent*2 <= H->Size; parent = child){
		child = parent *2;
		if((child != H->Size) &&  (H->Data[child] < (H->Data[child+1])))
			child++;
		if( X >= H->Data[child]) break;
		else
			H->Data[parent] = H->Data[child];
	}
	H->Data[parent] = X;
	return MaxItem;
}

void PercDown(MaxHeap H, int p){
	int parent, child;
	ElementType X;
	X = H->Data[p];
	for(parent = p; parent*2 <= H->Size; parent = child){
		child = parent*2;
		if((child != H->Size) && (H->Data[child] < H->Data[child+1]))
			child++;
		if(X >= H->Data[child]) break;
		else
			H->Data[parent] = H->Data[child];
	}
	H->Data[parent] = X;
}
void BuildHeap(MaxHeap H){
	int i;
	for( i = H->Size/2; i>0; i--)
		PercDown(H , i);
}