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