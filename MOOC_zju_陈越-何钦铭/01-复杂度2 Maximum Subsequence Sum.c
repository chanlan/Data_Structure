#include <stdio.h>
int main() {
    int isStart = 1;
    int start1 = 0,end1 = 0;
    int start = 0, end = 0;
    int i = 0, j = 0, K = 0;
    int MaxSum = 0, ThisSum = 0;
    scanf("%d", &K);
    if (K == 1){
        scanf("%d",&j);
        start = j;
        end = j;
        MaxSum = j;
    }
    else {
        for (i = 0; i < K; i++) {
            scanf("%d", &j);
            if (i == 0) start1 = j;
            if (i == K-1) end1 = j;
            ThisSum += j;
            if (ThisSum >= MaxSum) {
                if (ThisSum > MaxSum) end = j;
                MaxSum = ThisSum;
                if (isStart) {
                    start = j;
                    isStart = 0;
                }
            } else if (ThisSum < 0) {
                ThisSum = 0;
                isStart = 1;
            }
        }
    }
    if (MaxSum > 0)
        printf("%d %d %d",MaxSum,start,end);
    else
        printf("0 %d %d", start1, end1);
    return 0;
}