#include <bits/stdc++.h>

using namespace std;

int odd_sum(int *a, int n){
	if(n == 0){
		return 0;
	}
	if(a[n-1] % 2 != 0) return a[n-1] + odd_sum(a, n-1);
	else return odd_sum(a, n-1);
}

int main(){
	int n = 10;
	int *a = new int[n]{1, 2, 3, 4, 5, 6, 7, 8, -9, 10};
	cout << odd_sum(a, n);
}
