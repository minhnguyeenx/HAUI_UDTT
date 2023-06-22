#include <bits/stdc++.h>

using namespace std;

int max_string(string a, string b, int **f){
	int n = a.size();
    int m = b.size();
    for(int i = 1; i <= n; i++){
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

char* TruyVet(string a, string b, int **f){
	int n = a.size();
    int m = b.size();
	int len = f[n][m];
	char *res = new char[len];
	int i = n, j = m, k = len -1;
	while(k >= 0){
		if(a[i-1] == b[j-1]){
			res[k] = a[i-1];
			i--; j--; k--;
		} else if(f[i-1][j] > f[i][j-1]){
			i--;
		} else{
			j--;
		}
	}
	return res;
}

int main(){
	string a, b;
	a = "Nhapxaxxxua:";
    b = "Nhapxaub:";
    int n = a.size();
    int m = b.size();
    int **f = new int *[n+1];
    for(int i = 0; i <= n; i++){
    	f[i] = new int[m+1];
    	for(int j = 0; j <= m; j++){
    		f[i][j] = 0;
		}
	}
	int len = max_string(a, b, f);
	cout << len << "\n";
	char *res = TruyVet(a, b, f);
	for(int i = 0; i < len; i++){
		cout << res[i];
	}
}
