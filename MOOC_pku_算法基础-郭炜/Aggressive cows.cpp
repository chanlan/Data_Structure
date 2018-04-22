#include <cstdio>
#include <algorithm>

using namespace std;

int P[100001], N, C;

bool cal(int x){
	int cnt = 1, temp = P[0];
	for(int i = 1; i < N; i++)
		if(P[i] - temp >= x){
			cnt++;
			temp = P[i];
			if(cnt == C)
				return true;
		}
	return false;
}

int main(){
	scanf("%d %d", &N, &C);
	for(int i = 0; i < N; i++)
		scanf("%d", &P[i]);
	sort(P, P+N);
	int l, h = P[N-1], mid;
	while(l <= h){
		mid = (l + h) / 2;
		if(cal(mid))
			l = mid + 1;
		else
			h = mid - 1;
	}
	printf("%d\n", l-1);
	return 0;
}