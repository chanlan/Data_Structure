ElementType Median3(ElementType A[], int Left, int Right){
    int Center = (Left + Right) / 2;
    if( A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if( A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if( A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);
    Swap(&A[Center], &A[Right-1]);
    return A[Right-1];//找到Pivot并放到Right-1
}

void Qsort(ElementType A[], int Left, int Right){
    int Pivot, Cutoff, Low, High;
    if( Cutoff <= Right-Left){//只有元素个数足够多用快排才合算当只有两个元素是必须insertsort
        Pivot = Median3(A, Left, Right);
        Low = Left; Hight = Right - 1;
        while(1){
            while( A[++Low] < Pivot);
            while( A[--High] > Pivot);
            if(Low < high) Swap(&A[Low], &A[Hight]);
            else break;
        }
        Swap(&A[Low], &A[Right-1]);
        Qsort(A, Left, Low-1);
        Qsort(A, Low+1, Right);
    }
    else InsertSort(A + Left, Right - Left + 1);
}
void QuickSort(ElementType A[], int N){
    Qsort(A, 0, N-1);
}