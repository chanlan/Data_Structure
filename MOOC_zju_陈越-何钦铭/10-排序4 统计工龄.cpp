#include <cstdio>
#define MAXLEN 100001
int HashTable[MAXLEN] = {0};

int main(){
    int N;
    scanf("%d", &N);
    while(N--){
        int tmp;
        scanf("%d", &tmp);
        HashTable[tmp]++;
    }
    for(int i = 0; i <= 50; i++){
        if(HashTable[i])
            printf("%d:%d\n", i , HashTable[i]);
    }
    return 0;
}
