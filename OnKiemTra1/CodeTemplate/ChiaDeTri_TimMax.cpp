#include <bits/stdc++.h>

using namespace std;

float timMax(float *a, int l, int r){
	if(l == r) return a[l];
	else{
		int m = (l+r)/2;
		return max(timMax(a, l, m), timMax(a, m+1, r));
	}
}

int timMax2(float *a, int l, int r){
	if(l == r) {
		return l;
	}
	else{
		int m = (l+r)/2;
		int vt1 = timMax2(a, l, m);
		int vt2 = timMax2(a, m+1, r);
		if(a[vt1] < a[vt2]) {
			return vt1;
		} else{
			return vt2;
		}
	}
}

void printArray(float *a, int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	int n, check = -1;
	n = 15;
	float *a = new float[n];
	a[0] = 1;
	a[1] = 2;
	a[2] = 2;
	a[3] = 4;
	a[4] = 6;
	a[5] = 8;
	a[6] = -10;
	a[7] = 11;
	a[8] = 12;
	a[9] = -13;
	a[10] = 14;
	a[11] = 15;
	a[12] = 16;
	a[13] = 17;
	a[14] = 18;
	printArray(a, n);
	//timMax2(a, 0, n-1);
	cout << "Vi tri: " << timMax2(a, 0, n-1) << endl;
	cout << a[timMax2(a, 0, n-1)];
}
