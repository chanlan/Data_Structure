#include <iostream>

using namespace std;

void Hanoi(int n, char src, char mid, char dest){
	if(n == 1){
		cout << src << "->" << dest << endl;
		return ;
	}
	Hanoi(n-1, src, dest, mid);

	cout << src << "->" <<  dest << endl;

	Hanoi(n-1, mid, src, dest);
	return ;
}

int main(){
	int n;
	cin >> n;
	Hanoi(n, 'A', 'B', 'C');
	system("pause");
	return 0;
}