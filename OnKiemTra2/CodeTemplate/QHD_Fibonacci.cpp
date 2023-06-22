#include <bits/stdc++.h>

using namespace std;

long fibonacci(long *f, int n){
	f[1] = 1; f[2] = 1;
	for(int i = 3; i <= n; i++){
		f[i] = f[i-1]+f[i-2];
	}
	return f[n];
}

//n = 10 => f[n] = 55
//f[n] = 1 neu n < 3 ( n = 1, n = 2)
//		f[n–1] + f[n–2] neu n > 3

int main(){
	int n = 10;
	long *f = new long[n+1];
	cout << "So fibonacci thu " << n << ": " << fibonacci(f, n) << "\n";
}
