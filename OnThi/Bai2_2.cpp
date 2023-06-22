#include <bits/stdc++.h>

using namespace std;

//tham lam
int thamlam(float *a, int n, float c){
	int i = n-1;
	int sum = 0;
	while(i >= 0 && sum + a[i] <= c){
		sum = sum + a[i];
		i--;
	}
	return n-i;
}

//boyer
int char_in_string(char x, string p){
	for(int i = p.length()-1; i >= 0; i--){
		if(p[i] == x) return i;
	}
	return -1;
}

int boyer(string p, string t, int *&z){
	int i = p.length();
	int dem = 0;
	while(i <= t.length()){
		int j = i-1;
		int k = p.length()-1;
		while(p[k] == t[j] && k >= 0){
			k--; j--;
		}
		if(k < 0){
			dem++;
			z[i-p.length()] = 1;
			i = i+p.length();
		} else{
			k = char_in_string(t[j], p);
			if(k < 0){
				i = i + p.length();
			} else{
				i = i + p.length() - k - 1;
			}
		}
	}
	return dem;
}

//lam them
//thuat toan z
void thuattoanz(string p, string t, int *z){
	string s = p + "$" + t;
	int n = s.length();
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i > r){
			l = r = i;
			while(r < n && s[r-l] == s[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		} else if(z[i-l] < r-i+1){
			z[i] = z[r-l];
		} else{
			l = i;
			while(r < n && s[r-l] == s[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		}
	}
}


int main(){
	int n = 8;
	float *a = new float[n]{1, 2, 3, 4, 5, 6, 7, 8};
	float C = -1;
	string P = "hao";
	string Q = "xin chao bonjua nihao hello hi";
	
	//tham lam
	int *z = new int[n];
	for(int i = 0; i <= n; i++){
		z[i] = 0;
	}
	int kq1 = thamlam(a, n, C);
//	cout << kq1 << "\n";
	if(kq1 == n+1){
		cout << "Khong the lay\n";
	} else{
		float M = 0;
		for(int i = n-1; i >= n-kq1; i--){
			M += a[i];
		}
		cout << "Co the lay it nhat " << kq1 << " phan tu de duoc M = " << M << " lon hon C = " << C << "\n";
		cout << "Cac phan tu duoc lay la: ";
		for(int i = n-1; i >= n-kq1; i--){
			cout << a[i] << " ";
		}
	}
	
	//boyer
	cout << "\n------------------\n";
	int *z2 = new int[Q.length()];
	for(int i = 0; i < Q.length(); i++){
		z2[i] = 0;
	}
	int kq2 = boyer(P, Q, z2);
//	cout << kq2 << "\n";
	if(kq2 > 0){
		cout << "P xuat hien " << kq2 << " lan trong chuoi Q\n";
		cout << "Vi tri xuat hien: ";
		for(int i = 0; i < Q.length(); i++){
			//cout << z2[i] << " ";
			if(z2[i] != 0) cout << i + 1 << " ";
		}
		cout << "\n";
	}
	
	//thuat toan z
	cout << "\n------------------\n";
	int *z3 = new int[Q.length() + P.length() + 1];
	for(int i = 0; i < Q.length() + P.length() + 1; i++){
		z3[i] = 0;
	}
	thuattoanz(P, Q, z3);
	int kq3 = 0;
	for(int i = 0; i < Q.length() + P.length() + 1; i++){
		if(z3[i] == P.length()) kq3++;
	}
	cout << "P xuat hien " << kq3 << " lan trong chuoi Q\n";
	cout << "Vi tri xuat hien: ";
	for(int i = 0; i < Q.length() + P.length() + 1; i++){
		//cout << z2[i] << " ";
		if(z3[i] == P.length()) cout << i - P.length() << " ";
	}
	cout << "\n";
}
