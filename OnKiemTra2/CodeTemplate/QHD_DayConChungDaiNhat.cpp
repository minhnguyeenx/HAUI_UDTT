#include <bits/stdc++.h>

using namespace std;

int DayConChungDaiNhat(int *a, int n, int *b, int m, int **&f){
	for(int i = 1; i<= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i-1] == b[j-1]){
				f[i][j] = f[i-1][j-1] + 1;
			} else{
				f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		}
	}
	return f[n][m];
}

void TruyVet(int *a, int n, int *b, int m, int **f, int *&c, int &len){
	len = f[n][m];
	c = new int[len];
	int i = n, j = m, k = len - 1;
	while(k >= 0){
		if(a[i-1] == b[j-1]){
			c[k] = a[i-1];
			i--; j--; k--;
		} else if(f[i-1][j] > f[i][j-1]){
			i--;
		} else{
			j--;
		}
	}
}

int main(){
	int n = 6;
	int m = 5;
	int *a = new int[n]{1, 6, 2, 4, 8, 3};
	int *b = new int[m]{1, 2, 5, 6, 7};
	
	int **f = new int *[n+1];
	for(int i = 0; i <= n; i++){
		f[i] = new int[m+1];
		for(int j = 0; j <= m; j++){
			f[i][j] = 0;
		}
	}
	int *c;
	int len;
	DayConChungDaiNhat(a, n, b, m, f);
	TruyVet(a, n, b, m, f, c, len);
	cout << len << "\n";
	for(int i = 0; i < len; i++){
		cout << c[i] << " ";
	}
}
