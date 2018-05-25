#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
int R, C;
int rooms[60][60];
int color[60][60];
int maxRoomArea = 0, roomNum = 0;
int roomArea;
void Dfs(int i, int k){
    if(color[i][k])
        return;
    ++roomArea;
    color[i][k] = roomNum;
    if((rooms[i][k] & 1) == 0) Dfs(i, k-1);
    if((rooms[i][k] & 2) == 0) Dfs(i-1, k);
    if((rooms[i][k] & 4) == 0) Dfs(i, k+1);
    if((rooms[i][k] & 8) == 0) Dfs(i+1, k);
}
int main(){
    cin >> R >> C;
    for(int i = 1; i <= R; ++i)
        for(int j = 1; j <= C; ++j)
            cin >> rooms[i][j];
    memset(color,0,sizeof(color));
    for(int i = 1; i <= R; ++i)
        for(int j = 1; j <= C; ++j)
            if(!color[i][j]){
                ++roomNum; roomArea = 0;
                Dfs(i, j);
                maxRoomArea = max(roomArea, maxRoomArea);
            }
    cout << roomNum << endl << maxRoomArea << endl;
    return 0;
}