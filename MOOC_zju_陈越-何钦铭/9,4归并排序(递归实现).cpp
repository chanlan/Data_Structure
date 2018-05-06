//归并排序-递归实
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd){
    int LeftEnd, NumElements, Tmp;
    int i;
    LeftEnd = R - 1;
    Tmp = L;
    NumElements = RightEnd - L + 1;
    while(L <= LeftEnd && R <= RightEnd){
        if(A[L] <= A[R])
            TmpA[Tmp++] = A[L++];
        else
            TmpA[Tmp++] = A[R++];
    }
    while(L <= LeftEnd)
        TmpA[Tmp++] = A[L++];
    while(L <= RightEnd)
        TmpA[Tmp++] = A[R++];
    for(int i = 0; i < NumElements；++i, RightEnd--)
        A[RightEnd] = TmpA[RightEnd];
}

void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd){
    int Center;
    
    if(L < RightEnd){
        Center = L + (R-L)/2;
        Msort(A, TmpA, L, Center);
        Msort(A, TmpA, Center+1, RightEnd);
    }
}

void MergeSort(ElementType A[], int N) //统一接口
{
    ElementType *TmpA;
    TmpA = (ElementType*)malloc(N*sizeof(ElementType));
    if(TmpA != NULL){
        Msort(A, TmpA, 0, N-1);
        free(TmpA);
    }
    else{
        printf("内存空间不足");
    }
} 