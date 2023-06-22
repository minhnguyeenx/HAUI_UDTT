#include <bits/stdc++.h>

using namespace std;

float sum(float *a, int l, int r){
	if(l == r){
		if(a[l] > 0) return a[l];
		return 0;
	} else{
		int m = (l + r)/2;
		return sum(a, l, m) + sum(a, m+1, r);
	}
}

int main(){
	int n = 10;
	float *a = new float[n]{1, 2, 3, 4, 5, 6, 7, 8, 9, -10};
	cout << sum(a, 0, n-1);
}
