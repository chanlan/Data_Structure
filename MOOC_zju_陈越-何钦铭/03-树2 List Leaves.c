#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TNode *Tree;
struct TNode {
    int v;
    Tree Left;
    Tree Right;
};
struct Node{
    int Left;
    int Right;
} array[10];

int main(){
    int n, Root;
    int check[10];
    for (int j = 0; j < 10; ++j) check[j] = 0;
    char n1,n2;
    scanf("%d\n", &n);
    for(int i=0; i<n;i++){
        scanf("%c %c\n", &n1, &n2);
        if(n1 != '-') {
            array[i].Left = n1 - '0';
            check[array[i].Left] = 1;
        }
        else
            array[i].Left = -1;
        if (n2 != '-') {
            array[i].Right = n2 - '0';
            check[array[i].Right] = 1;
        }
        else
            array[i].Right = -1;
    }
    for (int k = 0; k < n; ++k) {
        if (!check[k]) {
            Root = k;
            break;
        }
    }
    Tree T;
    T = (Tree)malloc(sizeof(struct TNode));
    T->v = Root;
    T->Left = T->Right = NULL;
    for(int i = 0;i < n-1;i++){
        Tree tmp;
        tmp = (Tree)malloc(sizeof(struct TNode));
        T->
    }
    return 0;
}
