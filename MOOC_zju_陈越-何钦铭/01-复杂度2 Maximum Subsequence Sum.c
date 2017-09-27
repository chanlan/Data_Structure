#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isStart = true;
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
            ThisSum += j;
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
                end = i;
                if (isStart && i > 0) {
                    start = i;
                    isStart = false;
                }
            } else if (ThisSum < 0) {
                ThisSum = 0;
                isStart = true;
            }
        }
    }
    if (MaxSum > 0)
        printf("%d %d %d",MaxSum,start,end);
    else
        printf("0 %d %d" ,start,end);
    return 0;
}