#include <bits/stdc++.h>

using namespace std;

struct Laptop{
	string tenHang;
	string cauHinh;
	double giaBan;
};

int char_in_string(char x, string p){
	for(int i = p.length()-1; i >= 0; i--){
		if(p[i] == x) return i;
	}
	return -1;
}

bool Boyer(string p, string t){
	int i = p.length();
	//int dem = 0;
	while(i <= t.length()){
		int k = p.length() - 1;
		int j = i-1;
		while(p[k] == t[j] && k >= 0){
			k--; j--;
		}
		if(k < 0){
			return true;
			//dem++;
			//cout
			//i = i + p.length();
		} else{
			k = char_in_string(t[j], p);
			if(k < 0){
				i = i + p.length();
			} else{
				i = i + p.length() - k - 1;
			}
		}
	}
	return false;
}

bool thuatoanz(string p, string t){
	string new_t = p+"$" + t;
	int n = new_t.length();
	int l = 0, r = 0;
	int *z = new int[n];
	for(int i = 1; i < n; i++){
		z[i] = 0;
	}
	//i phai bang 1 vi cai dau tien luc nao cung co
	for(int i = 1; i < n; i++){
		if(i > r){
			l = r = i;
			while(r < n && new_t[r-l] == new_t[r]){
				r++;
			}
			z[i] = r - l;
			r--;
		} else if(z[i - l] < r-i+1){
			z[i] = z[r-l];
		} else{
			l = i;
			while(r < n && new_t[r-l] == new_t[r]){
				r++;
			}
			z[i] = r - l;
			r--;
		}
	}
	for(int i = 0; i < n; i++){
		if(z[i] == p.length()) return true;
	}
	return false;
}

int main(){
	int n = 5;
	Laptop *a = new Laptop[n]{
		{"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 999},
		{"ACER", "CPU 2.6GHz upto 3.2GHz-RAM 64GB-HHD 256GB", 1199},
		{"DELL", "CPU 2.2GHz upto 3.6GHz-RAM 32GB-SSD 512GB", 899},
		{"THINKBOOK", "CPU 2.1GHz upto 3.1GHz-RAM 16GB-HHD 256GB", 1299},
		{"MAC", "CPU 2.9GHz upto 3.5GHz-RAM 32GB-SSD 512GB", 1499},
	};
	//
	int dem1 = 0;
	cout << "\nNhung may tinh co RAM 16GB: \n";
	for(int i = 0; i < n; i++){
		if(Boyer("RAM 16GB", a[i].cauHinh)){
			dem1++;
		}
	}
	if(dem1 == 0){
		cout << "Khong co may tinh nao\n";
	} else{
		cout << "Co " << dem1 << " may tinh RAM 16GB\n";
		for(int i = 0; i < n; i++){
		 	if(Boyer("RAM 16GB", a[i].cauHinh)){
				cout << a[i].tenHang << " " << a[i].cauHinh << " " << a[i].giaBan << "\n";
			}
		 }
	}
	 //
	 int dem2 = 0;
	 cout << "\nNhung may tinh su dung o cung loai SSD: \n";
	 for(int i = 0; i < n; i++){
	 	if(thuatoanz("SSD", a[i].cauHinh)){
			dem2++;
		}
	 }
	 if(dem2 == 0){
		cout << "Khong co may tinh nao\n";
	} else{
		cout << "Co " << dem2 << " may tinh dung SSD: \n";
		for(int i = 0; i < n; i++){
		 	if(thuatoanz("SSD", a[i].cauHinh)){
				cout << a[i].tenHang << " " << a[i].cauHinh << " " << a[i].giaBan << "\n";
			}
		 }
	}
	
}
