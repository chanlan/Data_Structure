#include <cstdio>
#include <cstdlib>
#include <cmath>
#define MAXLEN 10200

typedef struct Node* HashTable;
struct Node{
    int TableSize;
    int *Heads;
};

int minPrime(int n){
    if(n <= 2)
        return 2;
    int p = (n % 2) ? n : n+1;
    int i;
    while( p < MAXLEN){
        for(i = sqrt(p); i >= 2; i--){
            if(!(p%i)) break;
        }
        if(i == 1)
            return p;
        else
            p += 2;
    }
    return p;
}

int Insert(HashTable H, int num){
    int p = num % H->TableSize;
    if(H->Heads[p] == -1){
        H->Heads[p] = 1;
        return p;
    }
    else{
        int i = 1;
        while(i < H->TableSize){
            if(H->Heads[(p+i*i)%H->TableSize] == -1){
                H->Heads[(p+i*i)%H->TableSize] = 1;
                return (p+i*i)%H->TableSize;
            }
            i++;
        }
        return -1;
    }
}

int main(){
    int MSize, N;
    scanf("%d %d", &MSize, &N);
    int tmp;
    HashTable H = (HashTable)malloc(sizeof(struct Node));
    H->TableSize = minPrime(MSize);
    H->Heads = (int*)malloc(sizeof(int)*H->TableSize);
    for(int i = 0; i < H->TableSize; i++)
        H->Heads[i] = -1;
    while(N--){
        scanf("%d", &tmp);
        int key = Insert(H, tmp);
        if(key != -1){
            printf("%d", key);
        }
        else{
            printf("-");
        }
        if( N != 0)
            printf(" ");
    }
    free(H->Heads);
    free(H);
    return 0;
}