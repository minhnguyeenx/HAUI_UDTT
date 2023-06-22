#include <bits/stdc++.h>

using namespace std;

void dayconchung(int *a, int n, int *b, int m, int **f){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			//cai nay la b
			if(a[i-1] == b[j-1]){
				f[i][j] = f[i-1][j-1] + 1;
			} else{
				f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		}
	}
}

int* Bai6_TruyVet(int *a, int n, int *b, int m, int **f){
	int len = f[n][m];
	int i = n, j = m;
	int k = len - 1;
	int *c = new int[len];
	while(k >= 0 && i > 0 && j > 0){
		if(a[i-1] == b[j-1]){
			c[k] = a[i-1];
			k--, i--, j--;
		} else if(f[i-1][j] > f[i][j-1]){
			i--;
		} else{
			j--;
		}
	}
	return c;
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
	dayconchung(a, n, b, m, f);
	int len = f[n][m];
	int *c = Bai6_TruyVet(a, n, b, m, f);
	cout << "Do dai day con chung la " << len << "\n";
	cout << "Day con chung gom: ";
	for(int i = 0; i < len; i++){
		cout << c[i] << " ";
	}
}
