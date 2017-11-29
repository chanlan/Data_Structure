#include <stdio.h>

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
//不用辅助空间Reverse链表
//头插法
LinkList Reverse_1(LinkList L){
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while(p!=NULL){
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}
//三个指针遍历插法
LinkList Reverse_2(LinkList L){
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while(r != NULL){
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}
//单链表L的结点重排序(插入排序思想)，递增有序
void Sort(LinkList &L){
    LNode *p=L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while(p!= NULL){
        r = p->next;
        pre = L;
        while(pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
//删除无序链表中介于连个值之间的元素
void RangeDelete(LinkList &L, int min, int max){
    LNode *pre = L, *p = L->next;
    while(p!=NULL)
        if(p->data > min && p->data<max){
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else{
            pre = p;
            p = p->next;
        }
}
//8.给定两个单链表找出其公共结点
LinkList Serarch_1st_Common(LinkList L1, LinkList L2){
    int dist;
    int len1 = length(L1), len2 = length(L2);
    LinkList longList, shortList;
    if(len1>len2){
        longList = L1->next; shortList = L2->next;
        dist = len1 - len2;
    }
    else{
        longList = L2->next; shortList = L1->next;
        dist = len2 - len1;
    }
    while(dist--)
        longList = longList->next;
    while(longList != NULL){
        if(longList  == shortList)
            return longList;
        else{
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}
//9.给定无序带头结点的单链表(head为头指针),递增输出各结点的data,free结点,不能用数组
void Min_Delete(LinkList &head){
    LNode *pre, *p;
    while(head->next != NULL){
        pre = head;
        p = pre->next;
        while(p->next != NULL) {
            if (p->next->data < pre->next->data)
                pre = p;
            p = p->next;
        }
        printf(pre->next->data);
        u = pre->next;
        pre->next = u->next;
        free(u);
    }
    free(u);
}
//10.将带头结点的单链表A分解为A奇序,B偶序列
LinkList DisCreat_1(LinkList &A){
    i = 0;
    B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra =A, *rb = B;
    p = A->next;
    A->next = NULL;
    while(p!=NULL){
        i++;
        if(i%2 == 0){
            rb->next = p;
            rb = p;
        }else{
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}
//11.将c = {a1,b1,...,an,bn}拆为a={a1,...,an}b={bn,...,b1}
LinkList DisCreat_2(LinkList &A){
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *p = A->next, *q;
    LNode *ra = A;
    while(p != NULL){
        ra->next = p;
        p = p->next;
        q = p->next;
        p->next = B->next;
        B->next = p;
        p = q;
    }
    ra->next = NULL;
    return B;
}
//12.删除递增单链表中相同元素只保留一个
void Del_Same(LinkList &L){
    LNode *p = L->next, *q;
    if(p==NULL)
        return;
    while(p->next != NULL){
        q = p->next;
        if(p->data == q->data){
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
}
//13.两个递增的线性表(单链表)合并为一个递减的单链表
void MergeList(LinkList &La, LinkList &Lb){
    LNode *r, *pa = La->next, *pb = Lb->next;
    La->next = NULL;
    while(pa && pb) {
        if (pa->data <= pb->data) {
            r = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = r;
        }
        else{
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }
    if(pa)
        pb = pa;
    while(pb){
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}
//14.从递增有序单链表A,B中找出公共元素组成链表C,不破坏A,B
void Get_Common(LinkList A, LinkList B){
    LNode *p = A->next, *q = B->next, *r, *s;
    LinkList C = (LinkList)malloc(sizeof(Lnode));
    r = C;
    while(p!=NULL && q!= NULL){
        if(p->data < q->data)
            p = p->next;
        else if(p->data > q->data)
            q = q->next;
        else{
            s = (LNode*)malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            q = q->next;
            p = p->next;
        }
    }
    r->next = NULL;
}
//15.求连个递增集合A,B的交集储存到A
LinkList Union(LinkList &La, LinkList &Lb){
    LNode *tmp, *pa = La->next, *pb = Lb->next, *pc = La;
    while(pa && pb){
        if(pa->data == pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            tmp = pb;
            pb = pb->next;
            free(tmp);
        }
        else if(pa->data > pb->data){
            tmp = pb;
            pb = pb->next;
            free(pb);
        }
        else{
            tmp = pa;
            pa = pa->next;
            free(tmp);
        }
    }
    if(pa)
        pb = pa;
    while(pb){
        tmp = pb;
        pb = pb->next;
        free(tmp);
    }
    pc->next = NULL;
    free(Lb);
    return La;
}
//16.B{b1,...,bn}是否为A{a1,...am}的连续子序列
bool Pattern(LinkList A, LinkList B){
    LNode *p = A;
    LNode *pre = p;
    LNode *q = B;
    while(p&&q){
        if(q->data == p->data){
            q = q->next;
            p = p->next;
        }
        else{
            pre = pre->next;
            p = pre;
            q = B;
        }
        if(q == NULL){
            return 1;
        return 0;
        }
    }
}
//17.判断一循环双链表是否对称
bool Symmetry(LinkList L){
    LNode *p = L->next, *q = L->prior;
    while(p!=q && q->next!=p){
        if(p->data == q->data){
            p = p->next;
            q = q->prior;
        }
        else
            return 0;
    }
    return 1;
}
//18.将循环单链表h2链接到h1后面
LinkList Link_H2_H1(LinkList &h1, LinkList &h2){
    LNode *p, *q;
    p = h1;
    while (p->next != h1)
        p = p->next;
    q = h2;
    while(q->next != h2)
        q = q->next;
    p->next = h2;
    q->next = h1;
    return h1;
}
//19.顺序删除循环链表中的最小值并输出
void Del_All(LinkList L){
    LNode *p, *pre, *minp, *minpre;
    while(L->next != L){
        pre = L;
        p = pre->next;
        minp = p;
        minpre = pre;
        while(p != L){
            if(p->data < minp->data){
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d", minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}
//20.双向链表按频度排序查找x并返回指针
LinkList Locate(LinkList &L, int X){
    LNode *p = L->next, *q;
    while(p&&p->data != x)
        p = p->next;
    if(!p){
        printf("not exist!");
        exit(0);
    }
    else{
        p->freq++;
        p->next->pre = p->pre;
        p->pre->next = p->next;
        q = p->pre;
        while(q!=L&&q->freq <= p->freq)
            q = q->pre;
        p->next = q->next;
        q->next->pre = p;
        p->pre = q;
        q->next = p;
    }
    return p;
}
//21
int Search_K(LinkList L, int k){
    LNode *p, *q;
    p = L->next;
    q = L->next;
    int count = 0;
    while(p!=NULL){
        if(count < k) count++;
        else q = q->next;
        p = p->next;
    }
    if(count < k)
        return 0;
    else{
        printf("%d", q->data);
        return 1;
    }
}
//22
int ListLen(LNode *head){
    int len = 0;
    while(head->next != NULL){
        len++;
        head = head->next;
    }
    return len;
}
LNode* Find_addr(LNode *str1, LNode *str2){
    int m, n;
    m = ListLen(str1), n = ListLen(str2);
    LNode *p, *q;
    for(p=str1; m>n; m--){
        p = p->next;
    }
    for(q = str2; m<n; n--){
        q = q->next;
    }
    while(p->next != NULL && p->next != q->next){
        p = p->next;
        q = q->next;
    }
    return p->next;
}
//23
void Del_same_abs(LNode *h, int n){
    LNode *p = h, *r;
    int *q, m;
    q = (int*)malloc(sizeof(int)*(n+1));
    for(int i=0; i < n+1; i++)
        *(q+i) = 0;
    while(p->next != NULL){
        m = p->next->data>0?p->next->data:-p->next->data;
        if(*(q+m) == 0){
            *(q+m) = 1;
            p = p->next;
        }
        else{
            r = p->next;
            p->next = r->next;
            free(r);
        }
    }
    free(q);
}