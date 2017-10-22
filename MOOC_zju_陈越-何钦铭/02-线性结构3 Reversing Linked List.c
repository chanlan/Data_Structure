#include <stdio.h>
#include <stdlib.h>
typedef struct Node* LNode;
struct Node{
    int address;
    int data;
    int nextAddress;
    struct Node * next;
}Node;

int main() {
    LNode List, tmpList, tmpNode, tmp;
    List = (LNode) malloc(sizeof(Node));
    List->next = NULL;
    int firstAdress;
    int i, N, K;
    scanf("%d %d %d", &firstAdress, &N, &K);
    tmpList = List;
    for (i = 0; i < N; i++) {
        tmpNode = (LNode) malloc(sizeof(Node));
        scanf("%d %d %d", &tmpNode->address, &tmpNode->data, &tmpNode->nextAddress);
        tmpNode ->next = NULL;
        tmpList->next = tmpNode;
        tmpList = tmpNode;
    }
//sort
    tmpNode = (LNode)malloc(sizeof(struct Node));
    tmpNode->next = NULL;
    tmp = tmpNode;
    int findAddress = firstAdress;
    int count = 0;//有多余结点不在链表上
    while(findAddress != -1){
        tmpList = List;
        while(tmpList->next){
            if(tmpList->next->address == findAddress){
                tmp->next = tmpList->next;
                tmpList->next = tmpList->next->next;
                tmp = tmp->next;
                findAddress = tmp->nextAddress;
                count++;
            }else{
                tmpList = tmpList->next;
            }
        }
    }
    tmp->next=NULL;
    List = tmpNode;
    //reversing
    int n = count;
    LNode tail,tmpRm;
    tmpList = List;
    tmpNode = (LNode)malloc(sizeof(struct Node));
    tmpNode->next = NULL;
    tmp = tmpNode;
    while(n>=K){
        n -= K;
        for(int i=0; i< K; i++){
            tmp->next = tmpList->next;
            tmpList->next = tmpList->next->next;
            if(i==0)
                tail = tmp->next;
            else
                tmp->next->next = tmpRm;
            tmpRm = tmp->next;
        }
            tmp = tail;
    }
    tmp->next = List->next;
    tmp = tmpNode->next;

    while(tmp->next){
        printf("%05d %d %05d\n", tmp->address, tmp->data, tmp->next->address);
        tmp = tmp->next;
    }
    printf("%05d %d -1",tmp->address, tmp->data);
    return 0;
}
