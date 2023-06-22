#include <bits/stdc++.h>

using namespace std;

//tham lam
int thamlam(float *v, int n, float c){
	int i = 1;
	while(i <= n && c > 0){
		c = c - v[i];
		i++;
	}	
	if(c == 0) return i-1;
	return -1;
}

//cai tui
void caitui(int *m, float *v, int n, int M, float **f){
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= M; j++){
			if(m[i] > j){
				f[i][j] = f[i-1][j];
			} else{
				f[i][j] = max(f[i-1][j], f[i-1][j-m[i]]+v[i]);
			}
		}
	}
}

void truyvet(int *m, float *v, int n, int M, float **f){
	cout << "Gia tri lon nhat P = " << f[n][M] << " de khong vuot qua M = " << M << "\n";
	int i = n, j = M;
	while(i > 0 && j >= 0){
		if(f[i][j] != f[i-1][j]){
			cout << m[i] << " " << v[i] << "\n";
			j = j - m[i];
		}
		i--;
	}
}
int main(){
	int n = 8;
	int *m = new int[n+1]{0, 1, 2, 5, 8, 4, 6, 7, 3};
	float *v = new float[n+1]{0, 1, 2, 3, 4, 5, 6, 7, 8};
	float C = 10;
	
	int M = 10;
	
	//tham lam
	int kq1 = thamlam(v, n, C);
	cout << "Kq1 = " << kq1 << "\n";
	if(kq1 == -1){
		cout << "Khong co cach nao de lay\n";
	} else{
		cout << "So luong goi hang nhieu nhat duoc lay D = " << kq1 << " de duoc gia tri dung bang C = " << C << "\n";
		cout << "Cac tui do la: ";
		for(int i = 1; i <= kq1; i++){
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	
	//cai tui
	cout << "\n-------------------------------\n";
	float **f = new float *[n+1];
	for(int i = 0; i <= n; i++){
		f[i] = new float[M+1];
		for(int j = 0; j <= M; j++){
			f[i][j] = 0;
		}
	}
	caitui(m, v, n, M, f);
	truyvet(m, v, n, M, f);
}
