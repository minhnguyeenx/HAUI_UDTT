#include <bits/stdc++.h>

using namespace std;

//n <= 100
//co bao nhieu cach phan tich so thanh tong
//CONG THUC TRUY HOI
//f(m, n) = f(m-1, n) khi khong lay m
//		= f(m-1, n) + f(m, n-m) khi lay m

//n=5
//m=5
//n = 5 m = 5
//n = 4+1 m = 4
//n = 3 + 3 m = 3
//.. n = 2+2+ 1 m = 2
//  n = 3+1+1+1
//co 7 cach

int PhanTichSoThanhTong(int **f, int m, int n){
	f[0][0] = 1;
	
	//i bat dau bang 1
	for(int i = 1; i <= n; i++){
		f[0][i] = 0;
	}
	//i bat dau bang 1
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i > j){
				//khi m > n, khong lay so m
				f[i][j] = f[i-1][j];
			} else{
				//khi m <= n, lay so m
				f[i][j] = f[i-1][j] + f[i][j-i];
			}
		}
	}
	return f[m][n];
}

int PTSTT(int **f, int m, int n){
	f[0][0] = 1;
	for(int i = 1; i <= n; i++){
		f[0][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i > j){
				//khong lay m
				f[i][j] = f[i-1][j];
			} else{
				f[i][j] = f[i-1][j] + f[i][j-i];
			}
		}
	}
	return f[m][n];
}

int main(){
	int n = 5;
	int  m = n;
	int **f = new int *[m+1];
	for(int i = 0; i <= m; i++){
		f[i] = new int[n+1];
	}
//	cout << "Ket qua phan tich so " <<n << ": " << PhanTichSoThanhTong(f, m, n) << "\n";
	cout << "Ket qua phan tich so " <<n << ": " << PTSTT(f, m, n) << "\n";
}
