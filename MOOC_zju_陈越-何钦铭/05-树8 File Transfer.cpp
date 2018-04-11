#include <cstdio>
#include <cstdlib>

int Set[10001] = {0};

int Find(int *s, int X){
	if(s[X] < 0)
		return X;
	else
		return s[X] = Find(s,s[X]);
}
void Union(int R1, int R2, int *s){
	s[R1] = R2;
}
void Initialization(int *s, int n){
	for(int i = 1; i <= n; i++)
		s[i] = -1;
}
void Input_connection(int *s){
	int u, v;
	int Root1, Root2;
	scanf("%d %d\n", &u, &v);
	Root1 = Find(s,u);
	Root2 = Find(s, v);
	if(Root1 != Root2)
		Union(Root1, Root2, s);
}
void Check_connection(int *s){
	int u, v;
	int Root1, Root2;
	scanf("%d %d\n", &u, &v);
	Root1 = Find(s, u);
	Root2 = Find(s, v);
	if(Root1 == Root2)
		printf("yes\n");
	else
		printf("no\n");
}
void Check_network(int *s, int n){
	int i, count = 0;
	for(i =1; i<= n; i++)
		if(s[i] < 0) count++;
	if(count ==1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n", count);
}
int main(){
	int N;
	char in;
	scanf("%d\n", &N);
	Initialization(Set, N);
	do{
		scanf("%c", &in);
		switch(in){
		case 'I':Input_connection(Set);break;
		case 'C':Check_connection(Set);break;
		case 'S':Check_network(Set, N);
		}
	}while(in != 'S');
	system("pause");
	return 0;
}