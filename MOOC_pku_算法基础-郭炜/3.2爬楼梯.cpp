#include <cstdio>

int N;

int stairs(int n){
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	else
		return stairs(n-1) + stairs(n-2);
}

int main(){
	while(scanf("%d", &N), N)
		printf("%d\n", stairs(N));
	return 0;
}