#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
#define MaxVertex 10000

int N, M;
bool G[10005][10005] = {false};
bool Visited[10005] = {false};

void CreatGraph(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        G[x-1][y-1] = G[y-1][x-1] = true;
    }
}

void BFS(int n){
    queue<int> Q;
    Q.push(n);
    int level = 0, last = n, tail;
    Visited[n] = true;
    int count = 1;
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        for(int i = 0; i < N; i++){
            if(!Visited[i]&&G[temp][i]){
                Q.push(i);
                Visited[i] = true;
                count++;
                tail = i;
            }
        }
        if(temp == last){
            level++;
            last = tail;
        }
        if(level == 6)
            break;
    }
    printf("%d: %.2f%%\n", (n+1), (count*100.00)/N);
}
int main(){
    CreatGraph();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Visited[j] = false;
        }
        BFS(i);
    }
    return 0;
}
