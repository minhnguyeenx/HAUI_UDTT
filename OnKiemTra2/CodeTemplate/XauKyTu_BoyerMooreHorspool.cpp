#include <bits/stdc++.h>

using namespace std;

//Cho 2 xau ky tu T, P
//Kiem tra xem P co phai la xau con cua T hay khong
//PHUONG PHAP
//So sanh nguoc tu ky tu cuoi cua P ve dau

int char_in_string(char x, string p){
	for(int i = p.length() - 1; i >= 0; i--){
		if(p[i] == x){
			return i;
		}
	}
	return -1;
}

int BoyerMooreHorspool(string p, string t){
	int dem = 0, i = p.length();
	while(i <= t.length()){
		int j = i-1;
		int k = p.length() - 1;
		while(p[k] == t[j] && k >= 0){
			k--; j--;
		}
		if(k < 0){
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

int main(){
	string p = "con";
    string t = "con con day la mot chuoi co con va con";
    cout << BoyerMooreHorspool(p, t);
    return 0;
}
