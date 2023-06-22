#include <bits/stdc++.h>

using namespace std;

//cho mot xau ky tu chi gom chu cai va chu so
//Ung dung: Tim trong xau T xem co bao nhieu xau con P trong do

void ThuatToanZ(string s, int *z){
	int n = s.length();
	int l = 0, r = 0;
	
	//de i = 1 de tranh dem chuoi duong truoc dau $
	for(int i = 1; i < n; i++){
		if(i > r){
			l = r = i;
			while(r < n && s[r-l] == s[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		} else if(z[i-l] < r - i + 1){
			z[i] = z[r - l];
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
