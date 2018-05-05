void Swap(ElementType *a, ElementType *b){
    ElementType t = *a; *a = *b; *b = t;
}

void PercDown(ElementType A[], int p, int N){
    //将N个元素的数组中以A[p]为根的子堆调整为最大堆
    int Parent, Child;
    ElementType X;
    X = A[p];
    for(Parent = p; Parent*2+1 < N; Parent = Child){
        Child = Parent * 2 + 1;
        if((Child != N-1) && (A[Child]<A[Child+1]))
            ++Child;
        if(X >= A[Child]) break;
        else
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}

void HeapSort(ElementType A[], int N){
    int i;
    for(i = N/2-1; i >= 0; --i)
        PercDown(A,i,N);
    for(i = N-1; i>0; --i){
        Swap(&A[0], &A[i]);
        PercDown(A,0,i);
    }
}