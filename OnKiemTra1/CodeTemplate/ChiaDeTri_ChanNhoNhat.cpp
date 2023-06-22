#include <bits/stdc++.h>

using namespace std;

void printArray(int *a, int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int ChanNhoNhat(int *a, int l, int r){
	if(l == r){
		if(a[l] % 2 == 0) return a[l];
		else return INT_MAX;
	} else{
		int m = (l+r)/2;
		int lmin = ChanNhoNhat(a, l, m);
		int rmin = ChanNhoNhat(a, m+1, r);
		if(lmin == INT_MAX && rmin == INT_MAX){
			return INT_MAX;
		} else if(lmin == INT_MAX){
			return rmin;
		} else if(rmin == INT_MAX){
			return lmin;
		} else{
			return min(lmin, rmin);
		}
	}
}

int main(){
	int n, check = -1;
	n = 15;
	int *a = new int[n];
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 1;
	a[5] = 1;
	a[6] = -1;
	a[7] = 1;
	a[8] = 11;
	a[9] = -13;
	a[10] = 11;
	a[11] = 11;
	a[12] = 11;
	a[13] = 17;
	a[14] = 2147483645;
	//cout << INT_MAX;
	printArray(a, n);
	//neu return MIN_MAX -> khong co so chan trong mang
	cout << ChanNhoNhat(a, 0, n-1);
}
