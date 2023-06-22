#include <bits/stdc++.h>

using namespace std;

struct DienThoai{
	string nhanHieu;
	int kichThuoc;
	double giaBan;
};

void CaiTui(DienThoai *a, int **f, int n, int m){
	for(int i = 0; i <= m; i++){
		f[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			f[i][j] = f[i-1][j];
			int tmp = f[i-1][j-a[i].kichThuoc] + a[i].giaBan;
			if(a[i].kichThuoc <= j && f[i][j] < tmp){
				f[i][j] = tmp;
			}
		}
	}
}

void TruyVet(DienThoai *a, int **f, int n, int m){
	cout << "Gia tri lon nhat: " << f[n][m] << endl;
	int i = n, j = m;
	while(i != 0 && j > 0){
		if(f[i][j] != f[i-1][j]){
			cout << a[i].nhanHieu << " " << a[i].kichThuoc << " " << a[i].giaBan << "\n";
			j = j-a[i].kichThuoc;
		}
		i--;
	}
}

int main(){
	int s = 20;
	int n = 6;
	DienThoai *a = new DienThoai[n+1];
	a[1] = {"Iphone 13 Pro Max", 7, 1399};
	a[2] = {"Iphone 13", 6, 899};
	a[3] = {"Iphone 12 Pro Max", 6, 1299};
	a[4] = {"Iphone 12", 5, 799};
	a[5] = {"Iphone 14 Pro Max", 7 , 1499};
	a[6] = {"Iphone 14", 6, 999};
	int **f = new int *[n+1];
	for(int i = 0; i <= n; i++){
		f[i] = new int[s+1];
	}
	CaiTui(a, f, n, s);
	TruyVet(a, f, n, s);
}
