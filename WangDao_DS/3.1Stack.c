#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 50
#define ElemType int

typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;
//初始化
void InitStack(&S){
    S.top = -1;
}
//判断空栈
bool StackEmpty(S){
    if(S.top == -1)
        return true;
    return false;
}
//push
bool Push(SqStack *S, ElemType x){
    if(S->top==MaxSize-1)
        return false;
    S->data[++S->top] = x;
    return true;
}
//pop
bool Pop(SqStack *S, ElemType x){
    if(S->top == -1)
        return false;
    x = S->data[S->top--];
    return true;
}
//top
bool getTop(SqStack S, ElemType *x){
    if(S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}
//链式栈
typedef struct LinkNod{
    ElemType data;
    struct LinkNode *next;
} *LiStack;
//1B 2C 3B 4C 5A 6A 7C 8C 9D 10A 11B 12D 13D 14D 15C 16 


//3.2判断栈操作IO是否合法
bool Judge(char A[]){
    int i = 0, j = 0, k = 0;
    while(A[i] != '\0'){
        switch(A[i] != '\0'){
            case 'I': j++; break;
            case 'O': k++;
                if(k > j) {printf("NO"); exit(0)};
         }
        i++;
    }
    if(j != k){
        printf("NO\n");
        return false;
    }
    else{
        printf("YES\n");
        return true;
    }
}
//4判断链表中的元素是否对称
bool dc(LinkList L, int n){
    int i;
    char s[n/2];
    p = L->next;
    for(i = 0; i<n/2; i++){
        s[i] = p->data;
        p = p->next;
    }
    
    i--;
    if(n%2 == 1)
        p = p->next;
    
    while(p != NULL && s[i] == p->data){
        i--;
        p = p->next;
    }
    
    if (i == -1)
        return 1;
    else 
        return 0;
}

//5共享栈
//define
#define MaxSize 100
#define ElementType int
typedef struct{
    ElementType Stack[MaxSize];
    int top[2];
}stk;
stk S;
// push stack
int push(int i, ElementType x){
    if(i<0 || i>1){
        printf("stack number error\n");
        exit(0);
    }
    if(S.top[1] - S.top[0] == 1){
        printf("stack full\n");
        return 0;
    }
    switch(i){
        case 0: S.Stack[++S.top[0]] = x; return 1; break;
        case 1: S.Stack[--S.top[1]] = x; return 1; break;
    }
}
// pop stack
ElementType pop(int i){
    if(i<0 || i>1){
        printf("stack number error\n");
        exit(0);
    }
    switch(i){
        case 0: 
            if(S.top[0] == -1){
                printf("stack0 empty\n");
                return -1;
            }
            else
                return S.Stack[S.top[0]--];
        case 1:
            if(S.top[1] == MaxSize){
                printf("stack1 empty");
                return -1;
            }
            else
                return S.Stack[S.top[1]++];
    }
}


