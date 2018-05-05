#include <cstdio>
#include <cstring>

const int MAX = 201;

char s1[MAX], s2[MAX], s3[MAX];
int l1, l2, l3;
int v[MAX*2][MAX*2];

bool dfs(int i, int j, int k){
    if(s3[k] == '\0')
        return true;
    if(v[i][j])
        return false;
        v[i][j] = true;
    if(l1 < l3)
        if(s1[i] == s3[k] && dfs(i+1, j, k+1))
            return true;
    if(l2 < l3)
        if(s2[j] == s3[k] && dfs(i, j+1, k+1))
            return true;
    return false;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s %s %s", s1, s2, s3);
        l1 = strlen(s1);
        l2 = strlen(s2);
        l3 = strlen(s3);
        memset(v,false,sizeof(v));
        if(dfs(0,0,0))
            printf("Data set %d: yes\n", i+1);
        else
            printf("Data set %d: no\n", i+1);
    }
}