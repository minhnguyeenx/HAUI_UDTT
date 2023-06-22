#include <bits/stdc++.h>
#include <float.h>

using namespace std;

//l[i] la do dai day con bat dau tai a[i]
//l[n+1] la do dai day con bat dau tu a[n+1] = duong vo cung
	//-> l[n+1] = 1
//CONG THUC TRUY HOI
//Day con bat dau tai a[i] duoc tao ra bang cach ghep a[i] vao dau 1 trong nhung day con bat dau bang a[j] duong sau a[i] ma a[j] > a[i]
//-> l[i] = max l[j] + 1 voi i <= j <= n+1 va a[i] < a[j]
	//voi l[j] duoc chon, ta goi j duoc chon la jmax
//TRUY VET
//su dung mang T[0...n] de luu lai cac phuong an ung voi moi l[i]
//Tai moi buoc tinh, gan T[i] = jmax, nghia la day con bat dau tai a[i] co phan tu thu 2 la a[jmax]

void DayConDonDieuTangDaiNhat(float *a, int *l, int *t, int n){
	a[0] = INT_MIN;
	a[n+1] = INT_MAX;
	l[n+1] = 1;
	for(int i = n; i >= 0; i--){
		int jmax = n+1;
		for(int j = i+1; j <= n+1; j++){
			if(a[i] < a[j] && l[j] > l[jmax]){
				jmax = j;
			}
		}
		l[i] = l[jmax] + 1;
		t[i] = jmax;
	}
}

void result(float *a, int *t, int n){
	int i = t[0];
	while(i != n + 1){
		cout << a[i] << " ";
		i = t[i];
	}
}

void Daycon2(float *a, int *l, int *t, int n){
	a[0] = INT_MIN; a[n+1] = INT_MAX;
	l[n+1] = 1;
	for(int i = n; i >= 0; i--){
		int jmax = n+1;
		for(int j = i+1; j <= n+1; j++){
			if(a[i] < a[j] && l[j] > l[jmax]){
				jmax = j;
			}
		}
		l[i] = l[jmax] + 1;
		t[i] = jmax;
	}
}
void res2(float *a, int *t, int n){
	int i = t[0];
	while(i != n+1){
		cout << a[i] << " ";
		i = t[i];
	}
}

int main(){
	int n = 9;
	float *a = new float[n+2]{5, 2, 3, 4, 9, 10, 5, 6, 7};
	int *l = new int[n+2];
	int *t = new int[n+2];
//	DayConDonDieuTangDaiNhat(a, l, t, n);
//	cout << "Day con don dieu tang dai nhat: " << l[0] - 2 << "\n";
//	result(a, t, n);
	
	Daycon2(a, l, t, n);
	cout << "Day con don dieu tang dai nhat: " << l[0] - 2 << "\n";
	res2(a, t, n);
}
