#include <bits/stdc++.h>

using namespace std;

void merge_sort(string *a, int l, int r){
	if(l < r){
		int m = (l+r)/2;
		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
		
		string b[r+1];
		for(int i = 0; i <= m; i++){
			b[i] = a[i];
		}
		for(int i = m+1; i <= r; i++){
			b[r + m + 1 -i] = a[i];
		}
		
		int i = l, j = r;
		for(int k = l; k <= r; k++){
			if(b[i].length() < b[j].length()){
				a[k] = b[i]; i++;
			} else{
				a[k] = b[j]; j--;
			}
		}
	}
}

bool thamlam(string *a, int n, int k, int *check){
	for(int i = 0; i < n; i++){
		check[i] = 0;
	}
	int i = n-1;
	while(k > 0 && i >= 0){
		if(a[i].length() <= k){
			k = k-a[i].length();
			check[i] = 1;
		}
		i--;
//		cout << i << "..." << k << endl;
	}
	if(k == 0) return true;
	return false;
}

int char_in_string(char x, string p){
	for(int i = p.length() - 1; i >= 0; i--){
		if(p[i] == x) return i;
	}
	return -1;
}

bool BoyerMooreHorspool(string p, string t){
	int i = p.length();
	int dem = 0;
	while(i <= t.length()){
		int k = p.length()-1;
		int j = i-1;
		while(p[k] == t[j] && k >= 0){
			k--; j--;
		}
		if(k < 0){
			return true;
			//cout << i;
			i = i + p.length();
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

int thuattoanz(string p, string t){
	string new_t = p + "$" + t;
	int l = 0, r = 0;
	int dem = 0;
	int n = new_t.length();
	int *z = new int[n];
	for(int i = 0; i < n; i++){
		z[i] = 0;
	}
	for(int i = 1; i < n; i++){
		if(i > r){
			l = r = i;
			while(r < n && new_t[r-l] == new_t[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		} else if(z[i-l] < r-i+1){
			z[i] = z[r-l];
		} else{
			l = i;
			while(r < n && new_t[r-l] == new_t[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		}
	}
	for(int i = 0; i < n; i++){
		if(z[i] == p.length()) dem++;
	}
	return dem;
}

int main(){
	int n = 6;
	string *a = new string[n]{"hi", "hi child", "children", "hello mothers", "hello father", "hello person"};
	merge_sort(a, 0, n-1);
//	for(int i = 0; i < n; i++){
//		cout << a[i] << "\n";
//	}
	int k = 21;
	string newstring = "";
	int *check = new int[n];
	if(thamlam(a, n, k, check)){
		cout << "Co the tao xau ki tu chieu dai bang " << k << "\n";
		cout << "Xau ki tu do la: ";
		for(int i = 0; i < n; i++){
			if(check[i] == 1) {
				newstring += a[i];
			}
		}
		cout << newstring;
	} else{
		cout << "Khong the tao duoc";
	}
	
	//
	int dem = 0;
	for(int i = 0; i < n; i++){
		if(BoyerMooreHorspool("child", a[i])){
			dem += 1;
		}
	}
	if(dem != 0){
		cout << "\n\nTu child xuat hien " << dem << " lan: \n";
		for(int i = 0; i < n; i++){
			if(BoyerMooreHorspool("child", a[i])){
				cout << a[i] << "\n";
			}
		}
	} else{
		cout << "Tu child khong xuat hien";
	}
	
	//
	cout << "\nSo lan xuat hien cua day " << a[0] << " la: \n";
	int dem2 = -1;
	int chk = 0;
	for(int i = 0; i < n-1; i++){
		dem2 = thuattoanz(a[0], a[i]);
		if(dem2 > 0){
			chk = 1;
			cout << a[i] << " " << dem2 << endl;
		}
	}
	if(chk == 0) cout << a[0] << " khong xuat hien";
}
