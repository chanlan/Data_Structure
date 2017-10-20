#include <stdio.h>
#include <stdbool.h>
typedef struct TNode TNode;
struct TNode {
    int v;
    int Left;
    int Right;
}array[10];

int main(){
    int i = 0,k;
    int n, Root;
    int check[10];
    int num[10];
    for (int j = 0; j < 10; ++j) check[j] = 0;
    char n1,n2;
    scanf("%d", &n);
    for(i=0; i<n;i++){
        scanf("\n%c %c", &n1, &n2);
        array[i].v = i;
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
    for(k =0; check[k]; k++);
    Root = k;

    TNode queue[10], Node;
    int front=0,rear = -1;
    queue[++rear] = array[Root];
    i = 0;
    while(rear-front>=0){
        Node = queue[front++];
        if(Node.Left == -1 && Node.Right == -1)
            num[i++]=Node.v;
        else {
            if (Node.Left != -1)
                queue[++rear] = array[Node.Left];
            if (Node.Right != -1)
                queue[++rear] = array[Node.Right];
        }
    }
    bool isFirst = 1;
    for(int j=0; j< i; j++){
        if(isFirst){
            printf("%d", num[j]);
            isFirst = 0;
        }
        else
            printf(" %d",num[j]);
    }
    return 0;
}
