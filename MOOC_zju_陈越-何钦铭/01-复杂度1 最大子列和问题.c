#include <stdio.h>

int main() {
    int i = 0, j = 0, K = 0;
    int MaxSum = 0, ThisSum = 0;

    scanf("%d", &K);

    for (i = 0; i < K; i++) {
        scanf("%d", &j);
        ThisSum += j;
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    printf("%d",MaxSum);
    return 0;
}