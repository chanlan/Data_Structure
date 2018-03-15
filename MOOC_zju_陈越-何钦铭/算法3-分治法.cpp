int Max3(int A, int B, int C){
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer(int List[], int left, int right){
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int center, i;
    if(left == right){
        if(List[left] > 0) return List[left];
        else return 0;
    }
    center = (left + right) / 2;

    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center, right);

    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for(int i = center; i >=left; i--){
        LeftBorderSum += List[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for(int i = center+1; i <= right; i++){
        RightBorderSum += List[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }
    return Max3(MaxLeftBorderSum, MaxRightBorderSum, MaxLeftBorderSum + MaxRightBorderSum);

}
//接口
int MaxSubseqSum3(int List[], int N){
    return DivideAndConquer(List, 0, N-1);
}