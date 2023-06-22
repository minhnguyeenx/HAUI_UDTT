#include <bits/stdc++.h>

using namespace std;

struct quat{
	string hangSX;
	string mauSac;
	double giaBan;
};

void swap(quat &a, quat &b){
	quat tmp = a;
	a = b;
	b = tmp;
}

void quick_sort(quat *a, int l, int r){
	if(l < r){
		int m = (l+r)/2;
		quat pivot = a[m];
		int i = l, j = r;
		do{
			if(a[i].giaBan > pivot.giaBan) i++;
			if(a[j].giaBan < pivot.giaBan) j--;
			if(i <= j){
				swap(a[i], a[j]);
				i++; j--;
			}
		}while(i <= j);
		quick_sort(a, l, j);
		quick_sort(a, i, r);
	}
}

void mergeSort(quat *a, int l, int r){
	if(l < r){
		int m = (l+r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		
		quat b[r+1];
		for(int i = l; i <= m; i++){
			b[i] = a[i];
		}
		for(int i = m+1; i <= r; i++){
			b[r+m+1-i] = a[i];
		}
		int i = l, j = r;
		for(int k = l; k <= r; k++){
			if(b[i].giaBan > b[j].giaBan){
				a[k] = b[i];i++;
			}
			else{
				a[k] = b[j]; j--;
			}
		}
	}
}

int mua_quat(quat *a, int n, double p, int s[]){
	for(int i = 0; i < n; i++){
		s[i] = 0;
	}
	int i = 0, cnt = 0;
	while(p > 0 && i < n){
		if(p >= a[i].giaBan){
			p = p - a[i].giaBan;
			s[i] = 1;
			cnt++;
		}
		i++;
	}
	if(p == 0) return cnt;
	return -1;
}

int main(){
	double p = 400000;
	int n = 6;
	quat *a = new quat[n];
	a[0] = {"Panasonic", "Den", 150000};
	a[1] = {"Panasonic", "Do", 160000};
	a[2] = {"Panasonic", "Trang", 170000};
	a[3] = {"Media", "Den", 100000};
	a[4] = {"Senko", "Den", 120000};
	a[5] = {"Asia", "Den", 250000};
	
//	mergeSort(a, 0, n-1);
	quick_sort(a, 0, n-1);
	
	for(int i = 0; i < n; i++){
		cout << a[i].hangSX << "-" << a[i].giaBan << "\n";
	}
	
	int s[n];
	int res = mua_quat(a, n, p, s);
//	cout << res;
	if(res == -1){
		cout << "Khong du dieu kien de mua quat voi \"gia dung bang p\" \n";
	} else{
		cout << "Can ban it nhat " << res << " chiec quat\n";
		cout << "Cac quat do la: \n";
		for(int i = 0; i < n; i++){
			if(s[i] == 1){
				cout << a[i].hangSX << "-" << a[i].giaBan << ", ";
			}
		}
		cout << endl;
	}
}
