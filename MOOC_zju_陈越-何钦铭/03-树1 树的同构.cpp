#include <cstdio>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null (-1)

struct TreeNode{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];

bool isomorphism(Tree R1, Tree R2){
    if((R1 == Null) && (R2 == Null)) return true;
    if(((R1 == Null)&&(R2 != Null))||((R1 != Null)&&(R2 == Null))) return false;
    if(T1[R1].Element != T2[R2].Element) return false;
    if((T1[R1].Left == Null) && (T2[R2].Left == Null))
        return isomorphism(T1[R1].Right, T2[R2].Right);
    if(((T1[R1].Left != Null)&&(T2[R2].Left != Null))
       && ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
        return (isomorphism(T1[R1].Left, T2[R2].Left)
               && isomorphism(T1[R1].Right, T2[R2].Right));
    else return (isomorphism(T1[R1].Left, T2[R2].Right)
                 && isomorphism(T1[R1].Right, T2[R2].Left));
}

Tree BuildTree(struct TreeNode* T){
    int N;
    scanf("%d", &N);
    int check[N] = {0};
    for(int i = 0; i < N; i++){
        char cl, cr;
        scanf("\n%c %c %c", &T[i].Element, &cl, &cr);

        if(cl != '-') {
            T[i].Left = cl-'0';
            check[T[i].Left] = 1;
        }else T[i].Left = Null;

        if(cr != '-') {
            T[i].Right = cr-'0';
            check[T[i].Right] = 1;
        }else T[i].Right = Null;
    }
    for(int i = 0; i < N; i++)
        if(!check[i]) return i;
    return Null;
}

int main(){
    Tree R1, R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if(isomorphism(R1, R2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}