#include <cstdio>

int main(){
	int p, e, i, d;
	int count = 0;
	while(scanf("%d %d %d %d", &p, &e, &i, &d), p!=-1){
		int k;
		for(k = d+1; (k-p)%23; k++);
		for(; (k-e)%28; k+= 23);
		for(; (k-i)%33; k+= 23*28);
		printf("Case %d: the next triple peak occurs in %d days.\n", ++count, k-d);
	}
	return 0;
}