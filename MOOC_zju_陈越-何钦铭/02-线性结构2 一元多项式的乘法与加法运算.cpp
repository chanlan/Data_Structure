#include <cstdio>
#include <cstdlib>

typedef struct Node* PloyNode;
struct Node{
    int coef;
    int index;
    PloyNode link;
};
typedef PloyNode List;

void print(List L){
    List tmp = L->link;
    if(!tmp) printf("0 0");
    int flag = 0;
    while(tmp){
        if(flag) printf(" ");
        printf("%d %d", tmp->coef, tmp->index);
        flag = 1;
        tmp = tmp->link;
    }
    printf("\n");
}
void Attach(int c, int e, PloyNode *pRear){
    List tmp = (List)malloc(sizeof(struct Node));
    tmp->coef = c;
    tmp->index = e;
    tmp->link = NULL;
    (*pRear)->link = tmp;
    *pRear = tmp;
}
List ReadList(){
    List head = (List)malloc(sizeof(struct Node));
    head->link = NULL;
    List Rear = head;
    int n;
    scanf("%d", &n);
    while(n--){
        int c, e;
        scanf("%d %d", &c, &e);
        if(c) Attach(c, e, &Rear);
    }
    return head;
}
List Add(List L1, List L2){
    List PL1 = L1->link, PL2 = L2->link;
    List head = (List)malloc(sizeof(struct Node));
    head->link = NULL;
    List Rear = head;

    while(PL1 && PL2){
        int c, e;
        if(PL1->index > PL2->index) {
            c = PL1->coef;
            e = PL1->index;
            PL1 = PL1->link;
        }else if(PL1->index < PL2->index){
            c = PL2->coef;
            e = PL2->index;
            PL2 = PL2->link;
        }else{
            c = PL1->coef + PL2->coef;
            e = PL1->index;
            PL1 = PL1->link;
            PL2 = PL2->link;
        }
        if(c) Attach(c, e, &Rear);
    }
    Rear->link = PL1 ? PL1 : PL2;
    return head;
}

List Multiply(List L1, List L2){
    List head = (List)malloc(sizeof(struct Node));
    head->link = NULL;
    List Rear = head;
    List PL1 = L1->link;
    List PL2 = L2->link;
    if(!PL1 || !PL2) return head;
    while(PL2){
        Attach(PL1->coef*PL2->coef,PL1->index+PL2->index, &Rear);
        PL2 = PL2->link;
    }
    PL1 = PL1->link;
    while(PL1){
        PL2 = L2->link;
        Rear = head;
        while(PL2){
            int c = PL1->coef * PL2->coef;
            int e = PL1->index + PL2->index;
            while(Rear->link && Rear->link->index > e)
                Rear = Rear->link;
            if(Rear->link && Rear->link->index == e){
                if(Rear->link->coef + c)
                    Rear->link->coef += c;
                else{
                    List tmpNode = Rear->link;
                    Rear->link = tmpNode->link;
                    free(tmpNode);
                }
            }
            else{
                List tmpNode = (List)malloc(sizeof(struct Node));
                tmpNode->coef = c;
                tmpNode->index = e;
                tmpNode->link = Rear->link;
                Rear->link = tmpNode;
                Rear = tmpNode;
            }
            PL2 = PL2->link;
        }
        PL1 = PL1->link;
    }
    return head;
}


int main(){
    List L1 = ReadList();
    List L2 = ReadList();
    List L3 = Multiply(L1, L2);
    print(L3);
    List L4 = Add(L1, L2);
    print(L4);
    return 0;
}