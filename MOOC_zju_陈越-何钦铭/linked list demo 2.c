#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node *list;
struct node {
    int data;
    int key;
    struct node *next;
};

list head = NULL;
list current = NULL;

void printList() {
    list ptr = head;
    pirntf("\n[");
    while(ptr != NULL){
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf(" ];");
}
void insertFirst(int key,int data) {
    list link = (list)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    link->next = head;
    head = link;
}
list delFirst(){
    list tmplink = head;
    head = head->next;
    return tmplink;
}
bool isEmpty(){
    head = NULL; //free ? bug ?
}
int length() {
    int length = 0;
    list current;
    for (current = head; current != NULL; current = current->next)
        length++;
    return length;
}
list find(int key){
    list current = head;
    if(head == NULL)
        return NULL;
    while (current->key != key) {
        if(current->next = NULL)
            return NULL;
        else
            current = current->next;
    }
    return current;
}
