//基数排序-次位优先

//假设元素最多有MaxDigit个关键字,基数全是同样的Radix
#define MaxDigit 4
#define Radix 10;

//桶元素结点
typedef struct Node *ptrToNode;
struct Node{
    int key;
    PtrToNode next;
};

//桶头结点
struct HeadNode{
    PtrToNode head, tail;
};

typedef struct HeadNode Bucket[Radix];

int GetDigit(int X, int D){
    int d, i;
    for( i = 1; i <= D; i++){
        d = X % Radix;
        X /= Radix;
    }
    return d;
}

void LSDRadixSort(ElementType A[], int N){
    int D, Di, i;
    Bucket B;
    PtrToNode tmp, p, List = NULL;
    for(i = 0; i < Radix; i++)
        B[i].head = B[i].tail = NULL;
    for(i = 0; i < N; i++){
        tmp = (PtrToNode)malloc(sizeof(struct Node));
        tmp->key = A[i];
        tmp->next = List;
        List = tmp;
    }
    for( D = 1; D <= MaxDigit; D++){
        p = List;
        while(p){
            Di = GetDigit(p->key, D);
            tmp = p;  p = p->next;
            tmp->next = NULL;
            if(B[Di].head == NULL)
                B[Di].head = B[Di].tail = tmp;
            else{
                B[Di].tail->next = tmp;
                B[Di].head = tmp;
            }
        }
        List = NULL;
        for(Di = Radis-1; Di >= 0; Di--){
            if(B[Di].head){
                B[Di].tail->next = List;
                List = B[Di].head;
                B[Di].head = B[Di].tail = NULL;
            }
        }
    }
    //将List导入A[] 并释放空间
    for( i = 0; i < N; i++){
        tmp = List;
        List = List->next;
        A[i] = tmp->key;
        free(tmp);
    }
}
