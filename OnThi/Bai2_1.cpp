#include <bits/stdc++.h>

using namespace std;

//tham lam
int thamlam(float *a, int n, float c){
	int i = 0;
	while(i < n && c >= a[i]){
		c = c - a[i];
		i++;
	}
	return i;
}

//boyer moore horspool

int char_in_string(char x, string p){
	for(int i = p.length()-1; i >= 0; i--){
		if(p[i] == x) return i;
	}
	return -1;
}
bool boyer_moore_horspool(string p, string t){
	int i = p.length();
	while(i <= t.length()){
		int j = i -1;
		int k = p.length() - 1;
		while(p[k] == t[j] && k >= 0){
			k--; j--;
		}
		if(k < 0){
			return true;
		} else{
			k = char_in_string(t[j], p);
			if(k < 0){
				i = i + p.length();
			} else{
				i = i+ p.length() - k - 1;
			}
		}
	}
	return false;
}

int main(){
	int n = 8;
	float *a = new float[n]{1, 2, 3, 4, 5, 6, 7, 8};
	float C = 10;
	string Q = "hellos";
	string P = "hi hello bonjua hello xin chao";
	
	//tham lam
	int kq1 = thamlam(a, n, C);
	if(kq1 == 0) {
		cout << "Khong the lay phan tu nao de duoc gia tri M khong vuot qua C = " << C << "\n";
	} else{
		float M = 0;
		for(int i = 0; i < kq1; i++){
			M += a[i];
		}
		cout << "Co the lay " << kq1 << " phan tu de duoc M = " << M << " khong vuot qua C = " << C << "\n";
		cout << "Cac gia tri lay trong mang a: ";
		for(int i = 0; i < kq1; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	
	//boyer
	cout << "\n----------------------\n";
	bool kq2 = boyer_moore_horspool(Q, P);
	if(kq2) cout << "Q la chuoi con cua chuoi P\n";
	else cout << "Q khong la chuoi con cua chuoi P\n";
}
