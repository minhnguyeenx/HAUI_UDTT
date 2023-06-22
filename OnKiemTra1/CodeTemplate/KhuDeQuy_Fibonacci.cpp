#include <iostream>

using namespace std;

int fibo(int n){
	if(n < 3) return 1;
	int fibo1 = 1, fibo2 = 1;
	int fibon;
	while(n >= 3){
		//int temp = fibo1 + fibo2;
		fibon = fibo1 + fibo2;
		fibo1 = fibo2;
		fibo2 = fibon;
		n--;
	}
	return fibon;
}

int main(){
	int n;
	cin >> n;
	cout << fibo(n);
}
