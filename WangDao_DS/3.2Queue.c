#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define ElemType int

//队列的顺序存储结构
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

SqQueue Q;

//初始化
void initQueue(SqQueue Q) {
    Q.front = Q.rear = 0;
}
//判空
bool isEmpty(SqQueue Q) {
    if (Q.rear == Q.front) return true;
    return false;
}
//进队
bool EnQueue(SqQueue Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue Q, ElemType x) {
    if (Q.rear == Q.front) return false;
    x = Q.data[Q.rear];
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//队列的链式存储结构
typedef struct LinkNode{ //typedef struct {  ?
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front, *rear;
}LinkQueue;
LinkQueue LQ;
//初始化
void initLQ(LinkQueue LQ){
    LQ.front = LQ.rear = (LinkNode*)malloc(sizeof(LinkNode));
    LQ.rear->next = NULL;
}
//判空
bool IsLQEmpty(LinkQueue LQ){
    if(LQ.front == LQ.rear) return true;
    return false;
}
//进队
void EnLQueue(LinkQueue LQ, ElemType x){
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    LQ.rear->next = s;
    LQ.rear = s;
}
//出队
bool DeLQueue(LinkQueue LQ, ElemType* x){
    if(LQ.front == LQ.rear) return false;
    LinkNode* tmp = LQ.front->next;
    *x = tmp->data;
    LQ.front->next = tmp->next;
    if(LQ.rear == tmp)
        LQ.rear = LQ.front;
    free(tmp);
    return true;
}
//1D 2B 3D 4B 5D 6C 7B 8B 9C 10A 11B 12A 13A 14D 15D 16B 17C 18B

//1.tag标记01表示front rear相等时空还是满的如队出队操作
bool EnTagQueue(SqQueue Q, ElemType x){
    if(Q.front == Q.rear && Q.tag == 1) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;
    Q.tag = 1;
    return true;
}
bool DeTagQueue(SqQueue Q, ElemType* x){
    if(Q.front = Q.rear && Q.tag == 0) return false;
    *x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    Q.tag = 0;
    return true;
}

//2.队Q栈S逆置Q
void Inverser(Stack S, SqQueue Q){
    while(!IsLQEmpty(Q)){
        int x;
        DeQueue(Q, x);
        Push(S,x);
    }
    while(!StackEmpty(S)){
        int x;
        Pop(S, x);
        EnQueue(Q, x);
    }
}

//3. Push(S,x) Pop(S,x) StackEmpty(S) StackOverflow(S) 实现EnQueue DeQueue QueueEmpty
bool EnSQueue(Stack S1, Stack S2, ElemType x){
    if(!StackOverflow(S1)){
        Push(S1, x);
        return 1;
    }
    if(StackOverflow(S1)&& !StackEmpty(S2)){
        printf("Queue full");
        return 0;
    }
    if(StackOverflow(S1) && StackEmpty(S2)){
        while(!StackEmpty(S1)){
            Pop(S1,x);
            Push(S2,x);
        }
    }
}
bool DeSQueue(Stack S1, Stack S2, ElemType x){
    if(!StackEmpty(S2)){
        Pop(S2, x);
    }
    else if(StackEmpty(S1)){
        printf("Queue Empty");
    }
    else{
        while(!StackEmpty(S1)){
            Pop(S1, x);
            Push(S2, x);
        }
        Pop(S2, x);
    }
}
bool IsQueueEmpty(Stack S1, Stack S2){
    if(StackEmpty(S1)&&StackEmpty(S2))
        return 1;
    return 0;
}
//3.3栈和队列的应用
//1D 2B 3C 4B 5 6B 7B 8C 9B 10A 11A 12B 13A
