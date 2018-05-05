void Bubble_Sort(ElementType A[], int N){
    for(p = N-1; p >= 0; --p){
        int flag = 0;
        for(int i = 0; i < p; ++i){
            if(A[i] > A[i+1]){
                Swap(A[i], A[i+1]);
                flag = 1;
            }
        }
        if(!flag) break;
    }
}

void Insertion_Sort(ElementType A[], int N){
    for(p = 1; p < N; ++p){
        tmp = a[p];
        for(i = p; i > 0 && a[i-1] > tmp; --i)
            a[i] = a[i-1];
        A[i] = tmp;
    }
}