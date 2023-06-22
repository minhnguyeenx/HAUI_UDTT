#include <bits/stdc++.h>

using namespace std;

int char_in_string(char x, string p){
	//tim vi tri dau tien(i) x = p[i] tu cuoi len
	for(int i = p.length() - 1; i >= 0; i--){
		if(p[i] == x) return i;
	}
	return -1;
}

int Boyer(string p, string t){
	int dem = 0;
	int i = p.length();
	while(i <= t.length()){
		int k = p.length() - 1;
		int j = i - 1;
		
		//k >= 0 NHE
		while(p[k] == t[j] && k >= 0){
			k--; j--;
		}
		if(k < 0) {
			dem++;
			cout << i - p.length() + 1 << "\n";
			i += p.length();
		} else{
			k = char_in_string(t[j], p);
			if(k < 0){
				i += p.length();
			} else{
				i += p.length() - 1 - k;
			}
		}
	}
	return dem;
}

void ThuatToanZ(string s, int *z){
	int n = s.length();
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i > r){
			l = r = i;
			while(r < n && s[r-l] == s[r]){
				r++;
			}
			z[i] = r -l;
			r--;
		} else if(z[i-l] < r - i + 1){
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
//	//Boyer Moore Horspool
//	string p = "con";
//    string t = "con con day la mot chuoi co con va con";
//    cout << Boyer(p, t);

	//Thuat toan z
	string p = "con";
    string t = "con con day la mot chuoi co con va con";
    string new_t = p + "$" + t;
    cout << new_t << endl;
    int n = new_t.length();
    int *z = new int[n];
    ThuatToanZ(new_t, z);
	for(int i = 1; i < n; i++){
		cout << z[i] << " ";
	}
	cout << endl;
	int len = p.length();
	int dem = 0;
	for(int i = 1; i < n; i++){
		if(z[i] == len){
			dem++;
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "Co " << dem << " day p trong t";
	cout << endl;
}
