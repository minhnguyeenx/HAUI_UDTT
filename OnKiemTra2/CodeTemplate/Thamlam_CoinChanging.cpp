#include <bits/stdc++.h>

using namespace std;

//cho so tien n
//va mot day menh gia cua dong tien
//Output: Cho biet so luong dong tien it nhat de co tong menh gia bang n

bool coin_changing(int n, int *a, int *s, int m){
	for(int i = 0; i < m; i++){
		s[i] = 0;
	}
	int i = 0;
	while(n > 0 && i < m){
		s[i] = n/a[i];
		n = n - a[i]*s[i];
		i++;
	}
	if(n > 0) return false;
	return true;
}

int main(){
	int *a = new int[4]{10, 5, 2, 1};
	int n;
	cout << "Nhap so tien: "; cin >> n;
	int *s = new int[4];
	int m = 4;
	if(coin_changing(n, a, s, m)){
		for(int i = 0; i < m; i++){
			if(s[i] != 0){
				cout << "Lay " << s[i] << " dong " << a[i] << "\n";
			}
		}
	} else{
		cout << "Khong co phuong an nao";
	}
}
