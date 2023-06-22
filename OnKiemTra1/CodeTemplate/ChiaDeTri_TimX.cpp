#include <iostream>

using namespace std;
//can sap xep truoc

int TimX(int n, int *a, int x, int l, int r, int &check){
	if(l <= r){
		int m = (l+r)/2;
		if(a[m] == x){
			check = 1;
			return m;
		}
		else if(a[m] >= x) {
			return TimX(n, a, x, l, m, check);
		}
		else{
			return TimX(n, a, x, m+1, r, check);
		}
	}
}

int main(){
	int n, x;
	n = 20;
	int *a = new int[n];
	a[0] = 1;
	a[2] = 2;
	a[3] = 4;
	a[4] = 6;
	a[5] = 8;
	a[6] = 10;
	a[7] = 11;
	a[8] = 12;
	a[9] = 13;
	a[10] = 14;
	a[11] = 15;
	a[12] = 16;
	a[13] = 17;
	a[14] = 18;
	a[15] = 19;
	a[16] = 20;
	a[17] = 22;
	a[18] = 23;
	a[19] = 25;
	x = 13;
	int check = 0;
	TimX(n, a, x, 0, n-1, check);
	if(check == 0){
		cout << "Khong tim thay x";
	} else{
		int kq = TimX(n, a, x, 0, n-1, check);
		cout << "Vi tri " << kq+1 << " la: " << a[kq];
	}
}
