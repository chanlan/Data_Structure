#include <stdio.h>
#include <stdlib.h>

typedef struct Node* LNode;
struct Node{
    int Adress;
    int value;
    int next;
    LNode link;
};
LNode revers( LNode head, int K, int N){
    int cnt =1;
    LNode tmp,old,new;
    new = head->link;
    old = new ->link;
    while(cnt < K){
        tmp = old->link;
        old->link = new;
        new = old;
        old = tmp;
        cnt++;
    }
    head->link->link = old;
    return new;
}
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
// It is a bad idea!! SORT
    int count = 0;
    tmp = head->link;
    while(count < N-1) {
        if (tmp->next == tmp->link->Adress) {
            tmp = tmp->link;
            count++;
        } else {
            tmp1 = tmp->link->link;
            i = 0;
            while (tmp->next != tmp1->Adress) {
                tmp2 = tmp1;
                tmp1 = tmp1->link;
                i = 1;
            }
            if (i == 1) {
                tmp2->link = tmp1->link;
                tmp1->link = tmp->link;
                tmp->link = tmp1;
                tmp = tmp->link;
            } else {
                tmp->link->link = tmp1->link;
                tmp1->link = tmp->link;
                tmp->link = tmp1;
                tmp = tmp->link;
            }
            count++;
        }
    }
    //Reversing Linked List
    head = revers(head, K, N);

    return 0;
}
