typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
//头插法
LinkList CreatList1(LinkList &L) {
    LNode *s; int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
//尾插法
LinkList CreatList2(LinkList &L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x!=9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
LNode *GetElem(LinkList L, int i) {
    if (i == 0)
        return L;
    int j = 1;
    LNode *p = L->next;
    if (i < 1)
        return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

void Del_x_3(LinkList L, ElemType x) {
    LNode *p;
    if (L == NULL)
        return;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    }
    else
        Del_X_3(L->next, x);
}
void Del_x_1(LinkList L, ElemType x) {
    LNode *p = L->next, *pre = L, *q;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else {
            pre = p;
            p = p->next;
        }
    }
}
void Del_x_2(LinkList L, ElemType x) {
    LNode *p = L->next, *r = L, *q;
    whiel(p != NULL){
        if(p->data != x){
            r->next = p;
            r = p;
            p = p->next;
        }
        else {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}
void R_Print(LinkList L){
    if(L->next != NULL)
        R_Print(L->next);
    print(L->data);
}
//带头结点的链表找最小值
LinkList Delete_Min(LinkList &L){
    Lnode *pre = L, *p = pre->next;
    LNode *minpre = pre, *minp = p;
    while(p != NULL){
        if(p->data < minp->data){
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}
//不带头结点的链表找头结点
LinkList Delete_Min(LinkList &L){
    Lnode *pre = L, *p = pre->next;
    LNode *minpre = pre, *minp = p;
    while(p != NULL){
        if(p->data < minp->data){
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    if(minp->data > L->data){
        minpre = L;
        L=L->next;
    }
    else
        minpre->next = minp->next;
    free(minp);
    return L;
}
//不用辅助空间Reverse带头结点的链表
LinkList Reverse_l(LinkList L){
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while(p != NULL){
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}
LinkList Reverse_2(LinkList L){
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while(p != NULL){
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}
void Sort(LinkList L){
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while(p != NULL){
        r = p->next;
        pre = L;
        while(pre->next != NULL && pre->next->data<p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
