#include <cstdio>
//#include <cstdlib>

int f(int m, int n){
	if(m == 0) return 1;
	if(n <= 0) return 0;
	if(n > m) return f(m, m);
	return f(m,n-1) + f(m-n,n);
}

int main(){
	int t, m , n;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &m, &n);
		printf("%d\n", f(m,n));
	}
//	system("pause");
	return 0;
}