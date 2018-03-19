#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
List Read(){
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    List Rear = head;
    int n;
    scanf("%d", &n);
    while(n--){
        List tmp = (List)malloc(sizeof(struct Node));
        scanf("%d", &(tmp->Data));
        tmp->Next = Rear->Next;
        Rear->Next = tmp;
        Rear = tmp;
    }
    return head;
}
void Print( List L){
    List tmp = L->Next;
    if(tmp == NULL){
        printf("NULL\n");
    }else {
        printf("%d", tmp->Data);
        tmp = tmp->Next;
        while (tmp) {
            printf(" %d", tmp->Data);
            tmp = tmp->Next;
        }
        printf("\n");
    }
}
/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ){
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    List Rear = head;
    List PL1 = L1->Next, PL2 = L2->Next;
    L1->Next = NULL; L2->Next = NULL;

    while(PL1 && PL2){
        if(PL1->Data <= PL2->Data){
            Rear->Next = PL1;
            Rear = PL1;
            PL1 = PL1->Next;
        }else{
            Rear->Next = PL2;
            Rear = PL2;
            PL2 = PL2->Next;
        }
    }
    Rear->Next = PL1 ? PL1 : PL2;
    return head;
}