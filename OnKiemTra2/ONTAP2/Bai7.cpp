#include <bits/stdc++.h>

using namespace std;

struct HoiThao{
	string chuDe;
	float thoiGianBatDau;
	float thoiGianKetThuc;
};

void mergesort(HoiThao *a, int l, int r){
	if(l < r){
		int m = (l+r)/2;
		mergesort(a, l, m);
		mergesort(a, m+1, r);
		
		HoiThao b[r+1];
		for(int i = 0; i <= m; i++){
			b[i] = a[i];
		}
		for(int i = m+1; i <= r; i++){
			b[r + m + 1 -i] = a[i];
		}
		
		int i = l, j = r;
		for(int k = l; k <= r; k++){
			if(b[i].thoiGianBatDau < b[j].thoiGianBatDau){
				a[k] = b[i];
				i++;
			} else{
				a[k] = b[j];
				j--;
			}
		}
	}
}

int* laplich(HoiThao *a, int n){
	int *ans = new int[n];
	for(int i = 0; i < n; i++){
		ans[i] = 0;
	}
	float lastfinish = 0;
	for(int i = 0; i < n; i++){
		if(lastfinish <= a[i].thoiGianBatDau){
			ans[i] = 1;
			lastfinish = a[i].thoiGianKetThuc;
//			cout << lastfinish << "...\n";
		}
	}
	return ans;
}

int main(){
	int n = 5;
	HoiThao *a = new HoiThao[n]{
		{"HT1", 8, 8.5},
		{"HT2", 10, 11.5},
		{"HT3", 9, 11},
		{"HT4", 12, 13},
		{"HT5", 11, 12.5},
	};
	mergesort(a, 0, n-1);
	for(int i = 0; i < n; i++){
		cout << a[i].chuDe << " " << a[i].thoiGianBatDau << " " << a[i].thoiGianKetThuc << endl;
	}
	int *ans = laplich(a, n);
	int dem = 0;
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
		if(ans[i] == 1) dem++;
	}
	cout << endl;
	cout << "So hoi thao co the tham gia: " << dem << "\n";
	cout << "Thong tin cac hoi thao: \n";
	for(int i = 0; i < n; i++){
		if(ans[i] == 1) {
			cout << a[i].chuDe << " " << a[i].thoiGianBatDau << " " << a[i].thoiGianKetThuc << endl;
		}
	}
}
