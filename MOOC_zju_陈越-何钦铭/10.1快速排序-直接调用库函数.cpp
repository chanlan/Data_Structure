#include <cstdlib>
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
qsort(A, N, sizeof(int), compare);

struct Node{
    int key1, key2;
}A[MAXN];

int compare2keys(const void *a, const void *b){
    int k;
    if(((const struct Node*)a)->key1 < ((const struct Node*)b)->key1)
        k = 1;
    else if(((const struct Node*)a)->key1 > ((const struct Node*)b)->key1)
        k = -1;
    else{
        if(((const struct Node*)a->kye2 < ((const struct Node*)b)->key2))
            k = -1;
        else
            k = 1;
    }
    return k;
}

qsort(A, N, sizeof(struct Node), compare2keys);