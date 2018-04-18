#include <cstdio>
#include <cstdlib>
#include <cmath>
int N, D;
struct node{
	int x, y;
}p[100];

bool visit[100] = {false};
bool ans = false;
bool first(int x){
	int p1 = pow((double)p[x].x, 2);
	int p2 = pow((double)p[x].y, 2);
	int powr = pow(D+7.5, 2);
	if( p1 + p2 <= powr)
		return true;
	return false;
}

bool jump(int x, int y){
	int p1 = pow((double)p[x].x - p[y].x, 2);
	int p2 = pow((double)p[x].y - p[y].y, 2);
	if( p1 + p2 <= D*D)
		return true;
	return false;	
}

bool jumpout(int x){
	if(50-abs(p[x].x) <= D || 50-abs(p[x].y) <=D)
		return true;
	return false;
}

void dfs(int x){
	visit[x] = true;
	if(jumpout(x))
		ans = true;
	for(int i = 0; i< N; i++)
		if(!visit[i] && jump(i,x))
			dfs(i);
}

int main(){

	scanf("%d %d", &N, &D);
	
	for(int i = 0; i < N; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	if(D >=42.5){
		printf("Yes");
		return 0;
	}
	else{
		for(int i = 0; i < N; i++)
			if(!visit[i] && first(i))
				dfs(i);
	}
	if(ans) printf("Yes");
	else printf("No");
	return 0;
}