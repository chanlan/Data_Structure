#include <stdio.h>
#include <stdlib.h>
typedef struct node *list;
struct node {
    int data;
    list next;
};

list head;
list creat();
void print (list);
int length(list);
void search(list);
void sort(list);
void add(list);
void del(list);
void reverse(list);

int main(int argc, char const *argv[]) {
    int ch;
    head = creat();
    print(head);
    do {
        printf("\nMENUE\n1.add\n2.Delete\n3.Search\n4.Recerse\n5.Sort\n6.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1: add(head); print(head); break;
            case 2: del(head); print(head); break;
            case 3: search(head); print(head); break;
            case 4: reverse(head); print(head); break;
            case 5: sort(head); print(head); break;
            case 6: exit(0);
            default: break;
        }
    } while(ch < 6);
    return 0;
}
list creat(){
    list new_one, head, prev;
    int i, n;
    head = NULL;
    printf("\nHow many nodes ?:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        new_one = (list)malloc(sizeof(struct node));
        new_one->next = NULL;
        printf("\nEnter data:");
        scanf("%d",&new_one->data);
        if (head == NULL) {
            head = new_one;
            prev = new_one;
        }
        else{
            prev->next = new_one;
            prev = new_one;
        }
    }
    return head;
}
void print(list head){
    list tmp;
    tmp = head;
    if(tmp){
        printf("\t<-%d->", tmp->data);
        tmp = tmp->next;
    }
}
void search(list head){
    list tmp;
    int is = 1;
    tmp = head;
    int key;
    printf("\nEnter Number:");
    scanf("%d", &key);
    while (tmp) {
        if (tmp->data == key) {
            printf("Found\n");
            printf("<-%d->", tmp->data);
            is = 0;
        }
        tmp = tmp->next;
    }
    if (is) printf("NOT FOUNd");
}
void sort(list head) {
    list tmp, tmp_one;
    tmp = head;
    int n=0, i, j, cur;
    n = length(head);
    for (i = 0; i<n-1; i++) {
        tmp = head;
        for(j = 0; j < n-1-i; j++){
            tmp_one = tmp->next;
            if(tmp->data > tmp_one->data){
                cur = tmp->data;
                tmp->data = tmp_one->data;
                tmp_one->data = cur;
            }
            tmp = tmp->next;
        }
    }
}
void del(list head){
    list tmp , tmp_one;
    int del_key, key;
    printf("1.Delete begin\n2.Delete end\n3.Delete k\n");
    scanf("%d",&key);
    switch (key) {
        case 1:
            tmp_one = head;
            tmp = head->next;
            head = tmp;
            tmp_one->next = NULL;
            free(tmp_one);
            break;
        case 2:
            tmp = head;
            while (tmp->next != NULL) {
                tmp_one = tmp;
                tmp = tmp->next;
            }
            tmp_one->next = NULL;
            free(tmp_one);
        case 3:
            printf("Enter the key to del\n");
            scanf("%d", &del_key);
            tmp = head;
            while (tmp != NULL) {
                if (tmp->data == del_key) {
                    tmp_one->next = tmp->next;
                    tmp->next = NULL;
                    free(tmp);
                }
                tmp_one = tmp;
                tmp = tmp->next;
            }
            break;
    }
}
void reverse(list head){
    list tmp, tmp_one, tmp_two;
    tmp = head;
    tmp_one = tmp->next;
    tmp->next = NULL;
    while (tmp_one != NULL) {
        tmp_two = tmp_one->next;
        tmp_one->next = tmp;
        tmp = tmp_one;
        tmp_one = tmp_two;
    }
    head = tmp;
}
int length(list head){
    list tmp;
    int i = 0;
    tmp = head;
    while (tmp) {
        tmp = tmp->next;
        i++;
    }
    return i;
}
void add(list head){
    list tmp, tmp_one, tmp_two;
    int key, add_key;
    tmp_two = (list)malloc(sizeof(struct node));
    printf("Enter data for new node to be added\n");
    scanf("%d",&tmp_two->data);
    tmp_two->next = NULL;
    printf("\n1.Add begin\n2.Add end\n3.Add in key\n");
    scanf("%d", &key);
    switch(key){
        case 1:
            tmp = head;
            head = tmp_two;
            head->next = tmp;
            break;
        case 2:
            if(head == NULL){
                tmp = head;
                head = tmp_two;
                tmp_two->next = NULL;
            }
            else {
                tmp = head;
                while (tmp->next != NULL){
                    tmp = tmp->next;
                }
                tmp->next = tmp_two;
                tmp = tmp_two;
            }
            break;
        case 3:
            printf("\nEnter value of node after which you want to add new node");
            scanf("%d",&add_key);
            tmp = head;
            while(tmp!=NULL){
                if(tmp->data == add_key){
                    tmp_one = tmp->next;
                    tmp->next = tmp_two;
                    tmp_two->next = tmp_one;
                }
            tmp = tmp->next;
            }
        break;
    }
}
