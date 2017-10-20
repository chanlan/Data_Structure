#include <stdio.h>
#include <stdlib.h>

typedef struct Node* LNode;
struct Node{
    int Adress;
    int value;
    int next;
    LNode link;
};

int main() {
    LNode head;
    head = (LNode)malloc(sizeof(struct Node));
    head->link = NULL;
    int first, i, N, K;
    scanf("%d %d %d",&first, &N, &K);
    for (i = 0; i < N; i++) {
        LNode tmp = head;
        LNode node = (LNode)malloc(sizeof(struct Node));
        scanf("\n%d %d %d", &node->Adress, &node->value, &node->next);
        node->link = NULL;
        while (tmp->link != NULL) {
            tmp = tmp->link;
        }
        tmp->link = node;
    }
    //find the first
    LNode tmp = head->link;
    LNode tmp1 = tmp;
    LNode tmp2;
    i = 0;
    while(tmp->Adress != first){
        tmp1 = tmp;
        tmp = tmp->link;
        i = 1;
    }
    if(i == 1){
        tmp1->link = tmp->link;
        tmp->link = head->link;
        head->link = tmp;
    }
    tmp = head->link;
// sort
    while(tmp->link->next != -1){
        if(tmp->next != tmp->link->Adress){
            tmp1 = tmp;
            while(tmp->next != tmp1->Adress){
                tmp2 =tmp1;
                tmp1 = tmp1->link;
            }
            tmp2->link = tmp1->link;
            tmp1 = tmp->link;
            tmp->link = tmp1;
        }
    }
    head = head->link;
    for(i = 0; i < N; i++){
        printf("%05d %d %05d\n",head->Adress, head->value, head->next);
        head = head->link;
    }
    return 0;
}
