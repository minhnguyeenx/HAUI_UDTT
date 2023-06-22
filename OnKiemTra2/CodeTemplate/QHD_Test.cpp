#include <bits/stdc++.h>

using namespace std;

long fibonacci(long *f, int n){
	f[1] = f[2] = 1;
	for(int i = 3; i <= n; i++){
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}

long PhanTichSoThanhTong(int **f, int n, int m){
	//nho de f[0][0] = 1
	f[0][0] = 1;
	//i bat dau bang 1
	for(int i = 1; i <= m; i++){
		f[0][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i > j) f[i][j] = f[i-1][j];
			//do co the lay nhieu i
			else f[i][j] = f[i-1][j] + f[i][j-i];
		}
	}
	return f[m][n];
}

void DayConDonDieuTangDaiNhat(int *a, int *l, int *t, int n){
	a[0] = INT_MIN;
	a[n+1] = INT_MAX;
	l[n+1] = 1; // boi vi do dai day dai nhat bat dau tu n+1 la 1
	
	//xet bat dau tu so cuoi cung cua day
	for(int i = n; i >= 0; i--){
		int jmax = n+1;
		for(int j = i+1; j<= n+1; j++){
			if(a[i] < a[j] && l[j] > l[jmax])
				jmax = j;
		}
		//nho co +1
		l[i] = l[jmax] + 1; // a[jmax] la so ngay sau a[i] de gheps thanh 1 day nen +1
		t[i] = jmax;
	}
}

void truyvet_daycondondieu(int *a, int *l, int *t, int n){
	cout << "Day con dai nhat: " << l[0]-2 << endl;
	int i = t[0];
	while(i != n+1){
		cout << a[i] << " ";
		i = t[i];
	}
	cout << endl;
}

void CaiTui(int *w, int *v, int **f, int n, int m){
	for(int i = 0; i <= m; i++){
		f[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			f[i][j] = f[i-1][j];
			int tmp = f[i-1][j-w[i]] + v[i];
			if(w[i] <= j && f[i][j] < tmp){
				f[i][j] = tmp;
			}
		}
	}
}

void TruyVet_Caitui(int *w, int *v, int **f, int n, int m){
	cout << "Gia tri lon nhat: " << f[n][m] << "\n";
	int i = n, j = m;
	while(i != 0){
		if(f[i][j] != f[i-1][j]){
			cout << w[i] << " " << v[i] << "\n";
			j = j-w[i];
		}
		i--;
	}
}

int main(){
//	//fibonacci
//	int n = 10;
//	long *f = new long[n+1];
//	cout << fibonacci(f, n) << endl;
	
//	//Phan tich so thanh tong
//	int n = 5;
//	int m = n;
//	//f[i][j] la so chi co la so i de tao thanh so j duoc khong
//	int **f = new int *[m+1];
//	for(int i = 0; i <= m; i++){
//		f[i] = new int[n+1];
//	}
//	cout << PhanTichSoThanhTong(f, n, m);

//	//Day con don dieu tang dai nhat
//	int n = 9;
//	int *a = new int[n+2]{0, 1, 2, 8, 4, 9, 10, 5, 6, 7};
//	int *l = new int[n+2];
//	int *t = new int[n+2];
//	DayConDonDieuTangDaiNhat(a, l, t, n);
//	truyvet_daycondondieu(a, l, t, n);

	//Bai toan cai tui
	int n = 5;
	int *w = new int[n+1]{0, 1, 4, 7, 2, 3};
	int *v = new int[n+1]{0, 1, 2, 3, 6, 4};
	int **f = new int *[n+1];
	int m = 10;
	for(int i = 0; i <= n; i++){
		f[i] = new int [m+1];
	}
	CaiTui(w, v, f, n, m);
	TruyVet_Caitui(w, v, f, n, m);
}
