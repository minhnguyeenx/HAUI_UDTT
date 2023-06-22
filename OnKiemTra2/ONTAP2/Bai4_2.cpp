#include <bits/stdc++.h>

using namespace std;

struct DienThoai{
	string nhanHieu;
	int kichThuoc;
	double giaBan;
};

void Bai4_CaiTui(DienThoai *a, int n, int s, double **f){
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= s; j++){
			//j (kich thuoc con lai)
			if(a[i].kichThuoc > j){
				f[i][j] = f[i-1][j];
			} else{
				f[i][j] = max(f[i-1][j], f[i-1][j-a[i].kichThuoc] + a[i].giaBan);
			}
		}
	}
}

void Bai4_TruyVet(DienThoai *a, int n, int s, double **f){
	int i = n, j = s;
	//vi dien thoai lay index tu 1
	while(i > 0 && j > 0){
		if(f[i][j] != f[i-1][j]){
			cout << a[i].nhanHieu << " " << a[i].kichThuoc << " " << a[i].giaBan << "\n";
			j = j - a[i].kichThuoc;
		}
		i--;
		//cout << i << " " << j  << endl;
	}
}

int char_in_string(char x, string p){
	for(int i = p.length() - 1; i >= 0; i--){
		if(x == p[i]) return i;
	}
	return -1;
}

int Bai4_BoyerMooreHorspool(string p, string t){
	int i = p.length();
	int dem = 0;
	while(i <= t.length()){
		int k = p.length() - 1;
		int j = i-1;
		//while de check xem het day p hay khong
		while(p[k] == t[j] && k >= 0){
			k--; j--;
		}
		if(k < 0){
			dem++;
			//cout << i ;
			i = i + p.length();
		} else{
			// lui lai xem t[k] dang o dau nen viet ham moi char_in_string cua t[j] va p
			k = char_in_string(t[j], p);
			if(k < 0){
				i += p.length();
			} else{
				i += p.length() - k - 1;
			}
		}
	}
	return dem;
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
	
	double **f = new double *[n+1];
	for(int i = 0; i <= n; i++){
		f[i] = new double[s+1];
		for(int j = 0; j <= s; j++){
			f[i][j] = 0;
		}
	}
	Bai4_CaiTui(a, n, s, f);
	cout << "So gia tri lay duoc: " << f[n][s] << "\n";
	Bai4_TruyVet(a, n, s, f);
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += Bai4_BoyerMooreHorspool("Iphone 13", a[i].nhanHieu);
	}
	cout << "Co " << ans << " may Iphone 13\n"; 
	
}
