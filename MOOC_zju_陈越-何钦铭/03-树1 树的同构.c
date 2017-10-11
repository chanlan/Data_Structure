#include <stdio.h>
#define MaxTree 10

struct TreeNode {
    char Element;
    int Left;
    int Right;
} T1[MaxTree], T2[MaxTree];

int BuildTree(struct TreeNode T[]){
    int i, N, Root = -1;
    char tmpl, tmpr;
    scanf("%d\n",&N);
    int check[N];
    if (N) {
        for (i=0; i<N; i++) check[i] = 0;
        for (i=0; i<N; i++) {
            scanf("%c %c %c\n", &T[i].Element, &tmpl, &tmpr);
            //left
            if (tmpl != '-'){
                T[i].Left = tmpl - '0';
                check[T[i].Left] = 1;
            }else T[i].Left = -1;
            //right
            if (tmpr != '-'){
                T[i].Right = tmpr - '0';
                check[T[i].Right] = 1;
            }else T[i].Right = -1;
        }
        //find Root
        for (i=0; i<N; i++)
            if(!check[i])
                break;
        Root = i;
    }
    return Root;
}
int Isomorphic (int R1, int R2){
    if ((R1==-1) && (R2==-1)) return 1;
    if (((R1==-1) && (R2!=-1)) || ((R1!=-1) && (R2==-1))) return 0;
    if (T1[R1].Element != T2[R2].Element) return 0;
    if ((T1[R1].Left==-1)&&(T2[R2].Left==-1)) return Isomorphic(T1[R1].Right, T2[R2].Right);
    if(((T1[R1].Left!=-1)&&(T2[R2].Left!=-1)) &&
       ((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
        return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
    else return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
}
int main() {
    int R1, R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if (Isomorphic(R1,R2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
