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
    LNode List, tmpList, tmpNode, tmp, tmp1;
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

    tmp = (LNode)malloc(sizeof(struct Node));
    tmp->next = NULL;
    tmp1 = tmp;
    int findAddress = firstAdress;
    int count = 0;//有多余结点不在链表上
    while(findAddress != -1){
        tmpList = List;
        while(tmpList->next){
            if(tmpList->next->address == findAddress){
                tmp1->next = tmpList->next;
                tmpList->next = tmpList->next->next;
                tmp1 = tmp1->next;
                findAddress = tmp1->nextAddress;
                count++;
            }else{
                tmpList = tmpList->next;
            }
        }
    }
    List = tmp;
    //reversing
    tmp = (LNode)malloc(sizeof(Node));
    tmp->next = NULL;
    LNode p3 = tmp;
    LNode p2 = List;
    LNode tail, q3;
    int n = count;
    int k = K;
    while(n >= k){
        n -= k;
        for(i=0; i < k; i++){
            p3->next = p2->next;
            p2->next = p2->next->next;
            if(i == 0)
                tail = p3->next;
            else
                p3->next->next = q3;
            q3 = p3->next;
        }
        p3 = tail;
    }
    List = tmp->next;
    while(List->next){
        printf("%05d %d %05d\n", List->address, List->data, List->nextAddress);
        List = List->next;
    }
    printf("%05d %d -1",List->address, List->data);
    return 0;
}
