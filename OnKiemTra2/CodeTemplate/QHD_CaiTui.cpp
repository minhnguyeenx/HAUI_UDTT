#include <bits/stdc++.h>

using namespace std;

//Trong sieu thi co n goi hang, goi hang thi co trong luong w[i], gia tri v[i]
//Ban dem ten trom dot nhap mang theo tui co trong luong toi da la m
//HOI: Can lay nhung goi hang nao de co gia tri lon nhat

//F(i, j) la gia tri lon nhat co the nhan bang cach lay cac goi (1..i) trong gioi han trong luong la j
//-> Tinh F(m, n)

//CONG THUC TRUY HOI
//f(i, j) = f(i-1, j) // khong lay goi thu i
		//= v[i] + f(i-1, j - w[i]) // lay goi thu i
		
double max(double a, double b){
	return a > b ? a : b;
}

void CaiTui(int *w, double *v, int n, int m, double **f){
	for(int j = 0; j <= m; j++){
			f[0][j] = 0;
	}
	for(int i = 1; i <= n; i++){
	    for(int j = 0; j <= m; j++){
	    	f[i][j] = f[i-1][j]; //khong lay goi thu i
	    	double temp = f[i-1][j-w[i]] + v[i];
	    	if(w[i] <= j && f[i][j] < temp){
	    		f[i][j] = temp;
			}
	    }
	}
}

void result (int *w, double *v, int n, int m, double **f){
	cout << "Gia tri lon nhat: " << f[n][m] << "\n";
	int i = n, j = m;
	while(i != 0){
		if(f[i][i] != f[i-1][j]){
			cout << w[i] << "  " << v[i] << "\n";
			j -= w[i];
		}
		i--;
	}	
}

int main(){
	int n = 5;
	int *w = new int[n+1]{0, 1, 4, 2, 5, 7};
	double *v = new double[n+1]{0, 1, 2, 3, 1, 4};
	int m = 10;
	
	double **f = new double *[n+1];
	for(int i = 0; i <= n; i++){
		f[i] = new double[m+1];
	}
	
	CaiTui(w, v, n, m, f);
	result(w, v, n, m, f);
}
