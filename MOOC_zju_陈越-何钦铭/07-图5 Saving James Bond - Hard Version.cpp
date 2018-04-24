#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100;
bool visited[MAX] = {false};
int path[MAX];
int N, D;

struct Node{
	int x, y;
}P[MAX];

bool jumpout(int p){
	if(50 - abs(P[p].x) <= D || 50 - abs(P[p].y) <= D)
		return true;
	return false;
}
bool jump(int x, int y){
	if(pow((double)P[x].x - P[y].x, 2) + pow((double)P[x].y - P[y].y, 2) <= D*D)
		return true;
	return false;
}
int firstjump(int p){
	return pow((double)P[p].x, 2) + pow((double)P[p].y,2) <= (D+7.5)*(D+7.5) ?
		pow((double)P[p].x, 2) + pow((double)P[p].y,2) : 0;
}

int cmp(int a, int b){
	return firstjump(a) < firstjump(b);
}
void bfs(){
	int b[MAX];
	queue<int> q;

	for(int i = 0; i < N; ++i)
		b[i] = i;
	sort(b, b+ N, cmp);
	int last;
	for(int i = 0; i < N; ++i){
		if(firstjump(b[i])){
			q.push(b[i]);
			visited[b[i]] = true;
			last = b[i];
		}
	}
	int step = 2;
	int tail;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		if(jumpout(p)){
			int k = 1;
			stack<int> s;
			printf("%d\n", step);
			while(k < step){
				s.push(p);
				p = path[p];
				k++;
			}
			while(!s.empty()){
				p = s.top();
				s.pop();
				printf("%d %d\n", P[p].x, P[p].y);
			}
			return ;
		}
		for(int i = 0; i < N; i++){
			if(!visited[i] && jump(p, i)){
				q.push(i);
				path[i] = p;
				visited[i] = true;
				tail = i;
			}
		}
		if(last == p){
			last = tail;
			step++;
		}
	}
	if(q.empty())
		printf("0\n");
}
int main(){
	scanf("%d %d", &N, &D);
	if(D+7.5 >= 50){
		printf("1\n");
		return 0;
	}
	for(int i = 0; i < N; ++i)
		scanf("%d %d", &P[i].x, &P[i].y);
	bfs();
	return 0;
}
