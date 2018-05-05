void ShellSort(ElementType A[], int N){
//希尔排序-用Sedgewick增量序列
    int Si, D, P, i;
    ElementType Tmp;
//Sedgewick 一小部分增量
    Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
    
    for(Si = 0; Sedgewick[Si] >= N; ++Si);//Sedgewick[i]不能超过N
    
    for(D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
        for(P = D; P < N; ++P){
            Tmp = A[P];
            for(i = P; i >= D && A[i-D] > Tmp; i-= D)
                A[i] = A[i-D];
            A[i] = Tmp;
        }
}