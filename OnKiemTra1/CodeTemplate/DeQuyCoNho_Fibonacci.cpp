#include <iostream>

using namespace std;

int fibo(int n, int *a){
	if(n < 3){
		a[n] = 1;
		return 1;
	}
	int res = fibo(n-1, a) + fibo(n-2, a);
	a[n] = res;
	return res;
}

int main(){
	int n; n = 8;
	int *a = new int[n+1];
	cout << fibo(n, a) << endl;
//	cout << a[n];
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
}
