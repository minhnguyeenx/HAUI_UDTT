#include <bits/stdc++.h>

using namespace std;

int findSum(int *a, int l, int r){
	if(l == r){
		if(a[l] > 0) return a[l];
		else return 0;
	} else{
		int m = (l+r)/2;
		return findSum(a, l, m) + findSum(a, m+1, r);
	}
}

int main(){
	int n;
	n = 7;
	int *a = new int[n];
	a[0] = 1;
	a[1] = 2;
	a[2] = 2;
	a[3] = -4;
	a[4] = 6;
	a[5] = -8;
	a[6] = -10;
	cout << findSum(a, 0, n-1);
}
