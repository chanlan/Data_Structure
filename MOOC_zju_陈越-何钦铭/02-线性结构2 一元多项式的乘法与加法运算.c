#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef,expon;
    Polynomial link;
};
void Attach(int c, int e, Polynomial *pRear) {
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}
Polynomial ReadPoly(){
    Polynomial P, Rear, t;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    int c, e, N;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &c, &e);
        if (c != 0)
            Attach(c, e, &Rear);
    }
    t = P;
    P = P->link;
    free(t);
    return P;
}
Polynomial Add(Polynomial p1, Polynomial p2){
    Polynomial Rear, p, t1, t2, t;
    t1 = p1; t2 = p2;
    p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->link = NULL;
    Rear = p;
    while(t1 && t2){
        if (t1->expon == t2->expon){
            if (t1->coef+t2->coef) {
                Attach(t1->coef+t2->coef, t1->expon, &Rear);
            }
            t1 = t1->link;
            t2 = t2->link;
        }
        else if(t1->expon > t2->expon) {
            Attach(t1->coef, t1->expon, &Rear);
            t1 = t1->link; }
        else {
            Attach(t2->coef, t2->expon, &Rear);
            t2 = t2->link;
        }
    }
    while (t1) { Attach(t1->coef, t1->expon, &Rear); t1 = t1->link; }
    while (t2) { Attach(t2->coef, t2->expon, &Rear); t2 = t2 ->link;}
    t = p; p = p->link; free(t); return p;
}
Polynomial Mult(Polynomial p1, Polynomial p2) {
    if (!p1 || !p2) return NULL;
    int e, c;
    Polynomial p, Rear, t1 = p1, t2 = p2, t;
    p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->link = NULL;
    Rear = p;
    while (t2) {
        Attach(t1->coef*t2->coef, t1->expon+t2->expon, &Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while (t1) {
        t2 = p2;
        Rear = p;
        while (t2) {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while (Rear -> link && Rear->link->expon > e)
                Rear = Rear->link;
            if (Rear->link && Rear->link->expon == e) {
                if (Rear->link->coef + c)
                    Rear->link->coef += c;
                else{
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            }
            else {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear ->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = p;
    p = p->link;
    free(t2);
    return p;
}
void printPoly(Polynomial p) {
    int flag = 0;
    if (!p) {
        printf("0 0\n");
        return;
    }
    while (p) {
        if(!flag) flag = 1;
        else
            printf(" ");
        printf("%d %d", p->coef,p->expon);
        p = p->link;
    }
    printf("\n");
}

int main() {
    Polynomial P1, P2, PP, PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1, P2);
    printPoly(PP);
    PS = Add(P1, P2);
    printPoly(PS);
    return 0;
}