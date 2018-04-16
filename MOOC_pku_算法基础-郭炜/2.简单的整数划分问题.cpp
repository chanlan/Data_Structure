#include <cstdio>
#include <cstdlib>

int f(int n, int m){
	if(m > n) return f(n, n);
	if( n == 0 || m==1) return 1;
	return f(n, m-1) + f(n-m, m);
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d",f(n, n));
	system("pause");
	return 0;
}