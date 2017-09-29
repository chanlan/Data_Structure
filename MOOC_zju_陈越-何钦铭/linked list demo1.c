#include <stdio.h>
#include <stdlib.h>
typedef struct node *list;
struct node {
    int date;
    list next;
}

list head;
list creat();
void print (list);
int length(list);
void search(list));
void sort(list);
void add(list);
void del(list);
void reverse(list);

int int main(int argc, char const *argv[]) {
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
    list new_one, head, prec tmp;
    in i, n;
    head = NULL;
    printf("\nHow many nodes ?:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        new_one = (list)malloc(sizeof(struct node));
        new_one->next = NULL;
        printf("\nEnter data:", );
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
        if (tmp->date == key) {
            printf("Found\n", );
            printf("<-%d->", tmp->date);
            is = 0;
        }
        tmp = tmp->date;
    }
    if (is) printf("NOT FOUNd");
}
void sort(list head) {
    list tmp, tmp_one;
    tmp = head;
    int n=0, i, j, cur;
    n = length(list);
    for (i = 0; i<n-1; i++) {
        tmp = head;
        for(j = 0; j < n-1-i; j++){
            tmp_one = tmp->next;
            if(tmp->data > tmpe_one->data){
                cur = tmp->data;
                tmp->data = tmp_one->data;
                tmp_one->data = cur;
            }
            tmp = tmp->next;
        }
    }
}
void del(list head) {
    list tmp,tmp_one;
    int del_key,k;
    printf("\n1.Delete begin\n2.Delete at end\n3.Delete in between");
    scanf("%d",&k);
   switch(k)
    {
    case 1: temp_one=head;
    temp=head->next;
    head=temp;
    temp_one->next=NULL;
    free(temp_one);
    break;
    case 2:
    temp=head;
       while(temp->next!=NULL)
         {
          temp_one=temp;
          temp=temp->next;
         }
          temp_one->next=NULL;
          free(temp);
       break;
    case 3:
    printf("\nEnter node which you want to delete:");
    scanf("%d",&del_key);
     temp=head;
     while(temp!=NULL)
       {
         if(temp->data==del_key)
     {
      temp_one->next=temp->next;
      temp->next=NULL;
      free(temp);
     }
    temp_one=temp;
    temp=temp->next;
       }
    break;
     }
}

}
void length(list head){
    list tmp;
    int i = 0;
    tmp = head;
    while (tmp) {
        tmp = tmp->next;
        i++;
    }
    return i;
}
